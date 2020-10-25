#include <cassert>
#include <SFML/Window.hpp>
#include <SIMD/vectorclass.h>

#include "utility.hpp"
#include "shader.hpp"
#include "gl.hpp"

// Request dedicated GPU.
extern "C"
{
	__declspec( dllexport ) unsigned int AmdPowerXpressRequestHighPerformance = REQUEST_DEDICATED_GPU ? 1 : 0;
	__declspec( dllexport ) unsigned int NvOptimusEnablement = REQUEST_DEDICATED_GPU ? 1 : 0;
}

//
// Structures
//

struct Particles_GL
{
	GLuint vao, vbo;
};

struct Vector
{
	float x, y;
};

struct Particles_Arrays
{
	unsigned int length;
	Vector* position; // Only positions are used for rendering.
	Vector* velocity;
};

//
// Functions
//

void setup( sf::Window& window, Particles_GL& particles_gl, Particles_Arrays& particles_arrays );
void shutdown( Particles_GL& particles_gl, Particles_Arrays& particles_arrays );

// We need a global pointer for force_window_close() function.
sf::Window* window_ptr;

int main()
{
	sf::Window window;
	window_ptr = &window;
	sf::Event ev;

	Particles_GL particles_gl;
	Particles_Arrays particles_arrays;

	setup( window, particles_gl, particles_arrays );
	GLuint const shader = create_shader();

	// click coords are in range <-1, 1> (that's the OpenGL space).
	float click_x, click_y;
	bool new_click = false;
	float frame_dt = 0;
	int frame_start = com_milliseconds();
	int frame_end = 0;
	while ( window.isOpen() ){
		//
		// Handle input.
		//
		while ( window.pollEvent( ev ) ){
			if ( ev.type == sf::Event::Closed || ( ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape ) ){
				window.close();
			}
			if ( ev.type == sf::Event::MouseButtonPressed &&
				 ev.mouseButton.button == sf::Mouse::Left ){

				// Convert mouse position from window space to OpenGL space.
				click_x = 2.0f/window.getSize().x * ev.mouseButton.x - 1;
				click_y = 2.0f/window.getSize().y * ( window.getSize().y - ev.mouseButton.y ) - 1; // we have to convert to our coordinate sytem, where Y is up not down.
				new_click = true;

				com_printf( "Click at [%d, %d] => [%f, %f]\n", ev.mouseButton.x, ( window.getSize().y - ev.mouseButton.y ), click_x, click_y );
			}
		}

		// Variables used in update loops, taken out to avoid constructing on every iteration.
		Vec8f position;
		Vec8f velocity;

		//
		// Attract the particles towards cursor position, if new_click has been registered.
		//
		if ( new_click ){
			new_click = false;
			Vec8f const click_pos( click_x, click_y, click_x, click_y, click_x, click_y, click_x, click_y );
			// Direction vectors: x1, y1,  x2, y2...
			Vec8f direction;

			// @Speed: this is a performance killer.
			for ( unsigned int i = 0; i < particles_arrays.length; i += 4 ){
				position.load( reinterpret_cast<float*>( &particles_arrays.position[i] ) );
				direction = click_pos - position;
				Vec4f const x_coord( direction[0], direction[2], direction[4], direction[6] );
				Vec4f const y_coord( direction[1], direction[3], direction[5], direction[7] );
				Vec4f const x_squared( square( x_coord ) );
				Vec4f const y_squared( square( y_coord ) );

				Vec4f length = sqrt( x_squared + y_squared );
				// Add a tiny tiny epsilon to not divide by 0.
				length += 0.001f;
				// We need 8 element vector.
				Vec8f const length_8( length[0], length[0], length[1], length[1], length[2], length[2], length[3], length[3] );

				direction /= length_8;
				// We have to add an impulse, so we do just that.
				// @MagicNumber
				direction *= 0.4f;
				velocity.load( reinterpret_cast<float*>( &particles_arrays.velocity[i] ) );
				velocity += direction;
				velocity.store( reinterpret_cast<float*>( &particles_arrays.velocity[i] ) );
			}
		}

		//
		// Update the positions.
		//
		for ( unsigned int i = 0; i < particles_arrays.length; i += 4 ){
			position.load( reinterpret_cast<float*>( &particles_arrays.position[i] ) );
			velocity.load( reinterpret_cast<float*>( &particles_arrays.velocity[i] ) );

			position += velocity * frame_dt;
			position.store( reinterpret_cast<float*>( &particles_arrays.position[i] ) );
		}

		//
		// Update OpenGL particles data.
		//
		glBindVertexArray( particles_gl.vao );
		glBindBuffer( GL_ARRAY_BUFFER, particles_gl.vbo );
		glBufferData( GL_ARRAY_BUFFER, sizeof( Vector ) * particles_arrays.length, particles_arrays.position, GL_DYNAMIC_DRAW );

		//
		// Render.
		//
		glClear( GL_COLOR_BUFFER_BIT );
		glUseProgram( shader );
		glBindVertexArray( particles_gl.vao );
		glDrawArrays( GL_POINTS, 0, particles_arrays.length );

		window.display();

		frame_end = com_milliseconds();
		frame_dt = ( frame_end - frame_start ) / 1000.0f;
		frame_start = frame_end;
	}

	shutdown( particles_gl, particles_arrays );
}

void setup( sf::Window& window, Particles_GL& particles_gl, Particles_Arrays& particles_arrays )
{
	// Initialize the timer.
	com_milliseconds();

	com_printf( "Setup.\n" );

	sf::ContextSettings settings;
	settings.majorVersion = 4;
	settings.minorVersion = 4;
	// @GL_Debug: don't ask for debug context when in release mode.
#ifdef NDEBUG
	settings.attributeFlags = sf::ContextSettings::Core;
#else
	settings.attributeFlags = sf::ContextSettings::Debug;
#endif

	// Read this values from program parameters or from the input.
	// @MagicNumber
	unsigned int window_width = 1600, window_height = 900;

	window.create( sf::VideoMode{ window_width, window_height }, "Particles!", sf::Style::Close, settings );
	gl_init();

	glViewport( 0, 0, window_width, window_height );

	com_printf( "Instruction set is: %d, %s\n", com_instruction_set_id(), com_instruction_set_name() );
	
	particles_arrays.length = window_width * window_height;
	// We demand that because we're using 8 element vector operations ( 2 floats per Vector).
	assert( particles_arrays.length % 4 == 0 );
	com_printf( "Allocating memory. %d particles. We use %d bytes per one particle.\n", particles_arrays.length, sizeof( Vector ) * 2 );

	// @MagicNumber: alignment should be customizable? Maybe it should adapt to
	// the instruction set selected?
	particles_arrays.position = static_cast<Vector*>( mem_alloc( particles_arrays.length * sizeof( Vector ), 32 ) );
	particles_arrays.velocity = static_cast<Vector*>( mem_alloc( particles_arrays.length * sizeof( Vector ), 32 ) );
	memset( particles_arrays.velocity, 0, particles_arrays.length * sizeof( Vector ) );

	com_printf( "Setting particles initial positions.\n" );

	// Set up their real positions, e.g in our window coordinates.
	// We're assuming (0,0) is bottom left and (win_w, win_h) is top right.

	// We need that for pararell instruction execution. I think. @Speed.
	assert( window_width % 4 == 0 );

	for ( unsigned int y = 0; y < window_height; ){
		for ( unsigned int x = 0; x < window_width; ){
			unsigned int const idx_0 = window_width * y + x;
			unsigned int const idx_1 = window_width * y + x + 1;
			unsigned int const idx_2 = window_width * y + x + 2;
			unsigned int const idx_3 = window_width * y + x + 3;


			particles_arrays.position[idx_0] = Vector{ static_cast<float>( x ),     static_cast<float>( y ) };
			particles_arrays.position[idx_1] = Vector{ static_cast<float>( x + 1 ), static_cast<float>( y ) };
			particles_arrays.position[idx_2] = Vector{ static_cast<float>( x + 2 ), static_cast<float>( y ) };
			particles_arrays.position[idx_3] = Vector{ static_cast<float>( x + 3 ), static_cast<float>( y ) };

			x += 4;
		}
		++y;
	}


	// Setting up values for manual calculation of the projection matrix.
	float const win_w = static_cast<float>( window_width );
	float const win_h = static_cast<float>( window_height );
	// I really don't know how to name this things. We're basically converting from Cartesian coordinates
	// to OpenGL ones.
	Vec8f const twos( 2.0f );
	Vec8f const win_size( win_w, win_h, win_w, win_h, win_w, win_h, win_w, win_h );
	Vec8f const fraction = twos / win_size;

	// @Speed: signed int is faster to convert to 32 bit floating point.
	for ( unsigned int i = 0; i < particles_arrays.length; ){
		Vec8f positions;

		positions.load( reinterpret_cast<float*>( &particles_arrays.position[i] ) );
		positions *= fraction;
		positions -= 1;
		positions.store( reinterpret_cast<float*>( &particles_arrays.position[i] ) );
		i += 4;
	}

	com_printf( "Creating OpenGL objects.\n" );

	glGenVertexArrays( 1, &particles_gl.vao );
	glCreateBuffers( 1, &particles_gl.vbo );
	glBindVertexArray( particles_gl.vao );

	glBindBuffer( GL_ARRAY_BUFFER, particles_gl.vbo );
	glBufferData( GL_ARRAY_BUFFER, sizeof( Vector ) * particles_arrays.length, particles_arrays.position, GL_DYNAMIC_DRAW );

	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, sizeof( Vector ), (void*)0 );

	com_printf( "Setup finished.\n\n" );
}

void shutdown( Particles_GL& particles_gl, Particles_Arrays& particles_arrays )
{
	com_printf( "Shutdown.\n" );

	glDeleteVertexArrays( 1, &particles_gl.vao );
	glDeleteBuffers( 1, &particles_gl.vbo );
	mem_free( particles_arrays.position );
	mem_free( particles_arrays.velocity );

	com_printf( "Shutdown finished.\n" );
}

void force_window_close()
{
	if ( window_ptr ) {
		window_ptr->close();
	}
}