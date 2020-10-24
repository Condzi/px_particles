#include "shader.hpp"

#include <cassert>
#include <cstring>

GLuint create_shader()
{
	GLchar const* const vert_shader_source = "#version 330\nlayout (location=0) in vec2 l_position;\nout vec2 pos;\nvoid main() { gl_Position = vec4( l_position, 0.1f, 1.0f ); pos = l_position; }";
	GLchar const* const frag_shader_source = "#version 330\nout vec4 color;\nin vec2 pos;\n void main() { float d = distance( pos, vec2(0,0)); color = vec4( 0.5, d, 0.9, 1.0 ); }";

	GLint const vert_shader_source_length = strlen( vert_shader_source );
	GLint const frag_shader_source_length = strlen( frag_shader_source );

	GLuint const shader_program  = glCreateProgram();
	GLuint const vertex_shader   = glCreateShader( GL_VERTEX_SHADER );
	GLuint const fragment_shader = glCreateShader( GL_FRAGMENT_SHADER );

	char shader_info_log[2000] ={}; // @MagicNumber
	GLint compilation_success = GL_FALSE;

	// Compile and check VERTEX SHADER.
	glShaderSource( vertex_shader, 1, &vert_shader_source, &vert_shader_source_length );
	glCompileShader( vertex_shader );

	glGetShaderiv( vertex_shader, GL_COMPILE_STATUS, &compilation_success );
	if ( compilation_success == GL_FALSE ){
		glGetShaderInfoLog( vertex_shader, sizeof( shader_info_log ), nullptr, shader_info_log );
		// @ErrorLog
		// com_error( "VERTEX shader failed to compile. Info:\n%s\n", shader_info_log );
		assert( false );
	};

	glShaderSource( fragment_shader, 1, &frag_shader_source, &frag_shader_source_length );
	glCompileShader( fragment_shader );

	glGetShaderiv( fragment_shader, GL_COMPILE_STATUS, &compilation_success );
	if ( compilation_success == GL_FALSE ){
		glGetShaderInfoLog( fragment_shader, sizeof( shader_info_log ), nullptr, shader_info_log );
		// @ErrorLog
		// com_error( "FRAGMENT shader failed to compile. Info:\n%s\n", shader_info_log );
		assert( false );
	};

	// LINK shaders.
	glAttachShader( shader_program, vertex_shader );
	glAttachShader( shader_program, fragment_shader );
	glLinkProgram( shader_program );

	glDeleteShader( vertex_shader );
	glDeleteShader( fragment_shader );

	return shader_program;
}
