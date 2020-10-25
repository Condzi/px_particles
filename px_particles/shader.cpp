#include "shader.hpp"

#include <cassert>
#include <cstring>

#include "utility.hpp"

GLuint create_shader()
{
	com_printf( "Creating shader.\n" );
	//
	// We load the shaders source from memory, compile it (and fire assert if an error occurs) and return the compiled shader.
	//
	GLchar const* const vert_shader_source = "#version 330\nlayout (location=0) in vec2 l_position;\nout vec2 pos;\nvoid main() { gl_Position = vec4( l_position, 0.1f, 1.0f ); pos = l_position; }";
	GLchar const* const frag_shader_source = "#version 330\nout vec4 color;\nin vec2 pos;\n void main() { float d = distance( pos, vec2(0,0)); color = vec4( 0.5, d, 0.9, 1.0 ); }";

	GLint const vert_shader_source_length = strlen( vert_shader_source );
	GLint const frag_shader_source_length = strlen( frag_shader_source );

	GLuint const shader_program  = glCreateProgram();
	GLuint const vertex_shader   = glCreateShader( GL_VERTEX_SHADER );
	GLuint const fragment_shader = glCreateShader( GL_FRAGMENT_SHADER );

	char shader_info_log[MAX_SIZE_STATIC_STRING] ={};
	GLint compilation_success = GL_FALSE;

	// Compile and check VERTEX SHADER.
	glShaderSource( vertex_shader, 1, &vert_shader_source, &vert_shader_source_length );
	glCompileShader( vertex_shader );

	glGetShaderiv( vertex_shader, GL_COMPILE_STATUS, &compilation_success );
	if ( compilation_success == GL_FALSE ){
		glGetShaderInfoLog( vertex_shader, sizeof( shader_info_log ), nullptr, shader_info_log );
		com_error( "FRAGMENT shader failed to compile. Info:\n%s\n", shader_info_log );
	};

	// Compile and check FRAGMENT SHADER.
	glShaderSource( fragment_shader, 1, &frag_shader_source, &frag_shader_source_length );
	glCompileShader( fragment_shader );

	glGetShaderiv( fragment_shader, GL_COMPILE_STATUS, &compilation_success );
	if ( compilation_success == GL_FALSE ){
		glGetShaderInfoLog( fragment_shader, sizeof( shader_info_log ), nullptr, shader_info_log );
		com_error( "FRAGMENT shader failed to compile. Info:\n%s\n", shader_info_log );
	};

	// LINK shaders.
	glAttachShader( shader_program, vertex_shader );
	glAttachShader( shader_program, fragment_shader );
	glLinkProgram( shader_program );

	glDeleteShader( vertex_shader );
	glDeleteShader( fragment_shader );

	com_printf( "Shader created.\n" );

	return shader_program;
}
