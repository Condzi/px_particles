#include <cassert>

#include "shader.hpp"
#include "gl.hpp"
#include "SIMD/vectorclass.h"
#include <iostream>
#include <SFML/Window.hpp>

extern "C"
{
	__declspec( dllexport ) unsigned int AmdPowerXpressRequestHighPerformance = 1;
	__declspec( dllexport ) unsigned int NvOptimusEnablement = 1;
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
	Vector* position; // Only positions are used to rendering.
	Vector* velocity;
};

//
// Functions
//

int  instruction_set();
void setup( sf::Window& window, Particles_GL& particles_gl, Particles_Arrays& particles_arrays );
void shutdown();

int main()
{
	sf::Window window;
	sf::Event ev;

	Particles_GL particles_gl;
	Particles_Arrays particles_arrays;

	setup( window, particles_gl, particles_arrays );
	GLuint shader = create_shader();

	while ( window.isOpen() ){
		while ( window.pollEvent( ev ) ){
			if ( ev.type == sf::Event::Closed ){
				window.close();
			}
		}

		glClear( GL_COLOR_BUFFER_BIT );

		glUseProgram( shader );
		glBindVertexArray( particles_gl.vao );
		glDrawArrays( GL_POINTS, 0, particles_arrays.length );

		window.display();
	}

	shutdown();
}

int instruction_set()
{
	static int instr_set = instrset_detect();
	return instr_set;
}

void setup( sf::Window& window, Particles_GL& particles_gl, Particles_Arrays& particles_arrays )
{
	std::cout << "Setup." << std::endl;

	sf::ContextSettings settings;
	settings.majorVersion = 4;
	settings.minorVersion = 4;
	settings.attributeFlags = sf::ContextSettings::Debug;

	// Read this values from program parametrs or from the input.
	unsigned int window_width = 800, window_height = 600;

	window.create( sf::VideoMode{ window_width, window_height }, "SFML Window", sf::Style::Close, settings );
	gl_init();
	glViewport( 0, 0, 800, 600 );

	int const instrset = instruction_set();
	std::cout << "Instruction set is: " << instrset << ", ";
	switch ( instrset ){
	case 0: std::cout << "80386 instruction set"; break;
	case 1: std::cout << "SSE (XMM) supported by CPU (not testing for OS support)"; break;
	case 2: std::cout << "SSE2"; break;
	case 3: std::cout << "SSE3"; break;
	case 4: std::cout << "Supplementary SSE3 (SSSE3)"; break;
	case 5: std::cout << "SSE4.1"; break;
	case 6: std::cout << "SSE4.2"; break;
	case 7: std::cout << "AVX supported by CPU and operating system"; break;
	case 8: std::cout << "AVX2"; break;
	case 9: std::cout << "AVX512F"; break;
	case 10: std::cout << "AVX512VL, AVX512BW, AVX512DQ"; break;

	default: std::cout << "unknown instruction set.";
	}
	std::cout << std::endl;

	particles_arrays.length = window_width * window_height;
	// @Assert
	// We demand that because we're using 8 element vector operations ( 2 floats per Vector).
	assert( particles_arrays.length % 4 == 0 );
	std::cout << "Allocating memory, one particle per px = " << particles_arrays.length << " particles * 4*sizeof( float )" << std::endl;

	// @Safety @Aligment
	particles_arrays.position = static_cast<Vector*>( malloc( particles_arrays.length * sizeof( Vector ) ) );
	particles_arrays.velocity = static_cast<Vector*>( malloc( particles_arrays.length * sizeof( Vector ) ) );
	memset( particles_arrays.velocity, 0, sizeof( Vector ) * particles_arrays.length );

	std::cout << "Setting particles positions." << std::endl;

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


			particles_arrays.position[idx_0] = Vector{ static_cast<float>( x ), static_cast<float>( y ) };
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
	// I really don't know how to name this things.
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

	std::cout << "Creating OpenGL objects" << std::endl;

	glGenVertexArrays( 1, &particles_gl.vao );
	glCreateBuffers( 1, &particles_gl.vbo );
	glBindVertexArray( particles_gl.vao );

	glBindBuffer( GL_ARRAY_BUFFER, particles_gl.vbo );
	glBufferData( GL_ARRAY_BUFFER, sizeof( Vector ) * particles_arrays.length, particles_arrays.position, GL_DYNAMIC_DRAW );

	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, sizeof( Vector ), (void*)0 );

	std::cout << "Setup finished." << std::endl;
}

void shutdown()
{
	std::cout << "Shutdown" << std::endl;

	// @Safety: free memory here, destroy GL objects.
	std::cout << "Shutdown finished." << std::endl;
}
