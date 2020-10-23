// ReSharper disable CppInconsistentNaming
#include "gl.hpp"
// @ErrorLog
// #include "common.hpp"

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>
#endif
#else
#include <dlfcn.h>
#endif


#ifdef _WIN32
static HMODULE gl_lib_handle;
#ifndef APIENTRY
#define APIENTRY _stdcall
#endif
#else
static void* libGL = nullptr;
#endif

#ifndef _WIN32
#define APIENTRY
#endif

#ifndef __APPLE__
void* ( APIENTRY* get_proc_address )( const char* ) = nullptr;
#endif


#ifdef _MSC_VER
#pragma warning(disable: 4996)
#else
#pragma push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif


void gl_open_lib()
{
#ifdef _WIN32
	gl_lib_handle = LoadLibraryW( L"opengl32.dll" );
#elif __APPLE__
	libGL = dlopen( "/System/Library/Frameworks/OpenGL.framework/OpenGL", RTLD_NOW | RTLD_GLOBAL );
#else
	libGL = dlopen( "libGL.so", RTLD_NOW | RTLD_GLOBAL );
#endif
	if ( gl_lib_handle == nullptr ) {
	// @ErrorLog
	//	com_error( "opengl32.dll couldn't be loaded\n" );
	}
#ifndef __APPLE__
#ifdef _WIN32
	get_proc_address = reinterpret_cast<decltype( get_proc_address )>( GetProcAddress(
		gl_lib_handle, "wglGetProcAddress" ) );
#else
	getProcAddress = (decltype( getProcAddress ))dlsym( libGL, "glXGetProcAddressARB" );
#endif
	if ( get_proc_address == nullptr ) {
	// @ErrorLog
	//	com_error( "getProcAddress is nullptr\n" );
	}
#endif
}

void deinit()
{
	if ( gl_lib_handle != nullptr ) {
#ifdef _WIN32
		FreeLibrary( static_cast<HMODULE>( gl_lib_handle ) );
#else
		dlclose( libGL );
#endif
		gl_lib_handle = nullptr;
	}
}

[[nodiscard]] static void* load( char const* name )
{
	void* result = nullptr;
	// @Assert
//	assert( gl_lib_handle != nullptr );

#ifndef __APPLE__
	if ( get_proc_address != nullptr ) {
		result = static_cast<void*>( get_proc_address( name ) );
	}
#endif

	if ( result == nullptr ) {
#ifdef _WIN32
		result = static_cast<void*>( GetProcAddress( gl_lib_handle, name ) );
#else
		result = dlsym( libGL, name );
#endif
	}

	if ( result == nullptr ) {
	// @ErrorLog
	//	com_dprintf( "'%s' failed to load.\n", name );
	}
	return result;
}

void ( APIENTRY* glActiveShaderProgram )( GLuint pipeline, GLuint program ) = nullptr;
void ( APIENTRY* glActiveTexture )( GLenum texture ) = nullptr;
void ( APIENTRY* glAttachShader )( GLuint program, GLuint shader ) = nullptr;
void ( APIENTRY* glBeginConditionalRender )( GLuint id, GLenum mode ) = nullptr;
void ( APIENTRY* glBeginQuery )( GLenum target, GLuint id ) = nullptr;
void ( APIENTRY* glBeginQueryIndexed )( GLenum target, GLuint index, GLuint id ) = nullptr;
void ( APIENTRY* glBeginTransformFeedback )( GLenum primitiveMode ) = nullptr;
void ( APIENTRY* glBindAttribLocation )( GLuint program, GLuint index, const GLchar* name ) = nullptr;
void ( APIENTRY* glBindBuffer )( GLenum target, GLuint buffer ) = nullptr;
void ( APIENTRY* glBindBufferBase )( GLenum target, GLuint index, GLuint buffer ) = nullptr;
void ( APIENTRY* glBindBufferRange )( GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size ) =
	nullptr;
void ( APIENTRY* glBindBuffersBase )( GLenum target, GLuint first, GLsizei count, const GLuint* buffers ) = nullptr;
void ( APIENTRY* glBindBuffersRange )( GLenum target, GLuint first, GLsizei count, const GLuint* buffers,
									   const GLintptr* offsets, const GLsizeiptr* sizes ) = nullptr;
void ( APIENTRY* glBindFragDataLocation )( GLuint program, GLuint color, const GLchar* name ) = nullptr;
void ( APIENTRY* glBindFragDataLocationIndexed )( GLuint program, GLuint colorNumber, GLuint index, const GLchar* name )
	= nullptr;
void ( APIENTRY* glBindFramebuffer )( GLenum target, GLuint framebuffer ) = nullptr;
void ( APIENTRY* glBindImageTexture )( GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer,
									   GLenum access, GLenum format ) = nullptr;
void ( APIENTRY* glBindImageTextures )( GLuint first, GLsizei count, const GLuint* textures ) = nullptr;
void ( APIENTRY* glBindProgramPipeline )( GLuint pipeline ) = nullptr;
void ( APIENTRY* glBindRenderbuffer )( GLenum target, GLuint renderbuffer ) = nullptr;
void ( APIENTRY* glBindSampler )( GLuint unit, GLuint sampler ) = nullptr;
void ( APIENTRY* glBindSamplers )( GLuint first, GLsizei count, const GLuint* samplers ) = nullptr;
void ( APIENTRY* glBindTexture )( GLenum target, GLuint texture ) = nullptr;
void ( APIENTRY* glBindTextureUnit )( GLuint unit, GLuint texture ) = nullptr;
void ( APIENTRY* glBindTextures )( GLuint first, GLsizei count, const GLuint* textures ) = nullptr;
void ( APIENTRY* glBindTransformFeedback )( GLenum target, GLuint id ) = nullptr;
void ( APIENTRY* glBindVertexArray )( GLuint array ) = nullptr;
void ( APIENTRY* glBindVertexBuffer )( GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride ) = nullptr;
void ( APIENTRY* glBindVertexBuffers )( GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets,
										const GLsizei* strides ) = nullptr;
void ( APIENTRY* glBlendColor )( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha ) = nullptr;
void ( APIENTRY* glBlendEquation )( GLenum mode ) = nullptr;
void ( APIENTRY* glBlendEquationSeparate )( GLenum modeRGB, GLenum modeAlpha ) = nullptr;
void ( APIENTRY* glBlendEquationSeparatei )( GLuint buf, GLenum modeRGB, GLenum modeAlpha ) = nullptr;
void ( APIENTRY* glBlendEquationi )( GLuint buf, GLenum mode ) = nullptr;
void ( APIENTRY* glBlendFunc )( GLenum sfactor, GLenum dfactor ) = nullptr;
void ( APIENTRY* glBlendFuncSeparate )( GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha )
	= nullptr;
void ( APIENTRY* glBlendFuncSeparatei )( GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha ) =
	nullptr;
void ( APIENTRY* glBlendFunci )( GLuint buf, GLenum src, GLenum dst ) = nullptr;
void ( APIENTRY* glBlitFramebuffer )( GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0,
									  GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter ) = nullptr;
void ( APIENTRY* glBlitNamedFramebuffer )( GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0,
										   GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1,
										   GLbitfield mask, GLenum filter ) = nullptr;
void ( APIENTRY* glBufferData )( GLenum target, GLsizeiptr size, const void* data, GLenum usage ) = nullptr;
void ( APIENTRY* glBufferStorage )( GLenum target, GLsizeiptr size, const void* data, GLbitfield flags ) = nullptr;
void ( APIENTRY* glBufferSubData )( GLenum target, GLintptr offset, GLsizeiptr size, const void* data ) = nullptr;
GLenum ( APIENTRY* glCheckFramebufferStatus )( GLenum target ) = nullptr;
GLenum ( APIENTRY* glCheckNamedFramebufferStatus )( GLuint framebuffer, GLenum target ) = nullptr;
void ( APIENTRY* glClampColor )( GLenum target, GLenum clamp ) = nullptr;
void ( APIENTRY* glClear )( GLbitfield mask ) = nullptr;
void ( APIENTRY* glClearBufferData )( GLenum target, GLenum internalformat, GLenum format, GLenum type,
									  const void* data ) = nullptr;
void ( APIENTRY* glClearBufferSubData )( GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size,
										 GLenum format, GLenum type, const void* data ) = nullptr;
void ( APIENTRY* glClearBufferfi )( GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil ) = nullptr;
void ( APIENTRY* glClearBufferfv )( GLenum buffer, GLint drawbuffer, const GLfloat* value ) = nullptr;
void ( APIENTRY* glClearBufferiv )( GLenum buffer, GLint drawbuffer, const GLint* value ) = nullptr;
void ( APIENTRY* glClearBufferuiv )( GLenum buffer, GLint drawbuffer, const GLuint* value ) = nullptr;
void ( APIENTRY* glClearColor )( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha ) = nullptr;
void ( APIENTRY* glClearDepth )( GLdouble depth ) = nullptr;
void ( APIENTRY* glClearDepthf )( GLfloat d ) = nullptr;
void ( APIENTRY* glClearNamedBufferData )( GLuint buffer, GLenum internalformat, GLenum format, GLenum type,
										   const void* data ) = nullptr;
void ( APIENTRY* glClearNamedBufferSubData )( GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size,
											  GLenum format, GLenum type, const void* data ) = nullptr;
void ( APIENTRY* glClearNamedFramebufferfi )( GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth,
											  GLint stencil ) = nullptr;
void ( APIENTRY* glClearNamedFramebufferfv )( GLuint framebuffer, GLenum buffer, GLint drawbuffer,
											  const GLfloat* value ) = nullptr;
void ( APIENTRY* glClearNamedFramebufferiv )( GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value )
	= nullptr;
void ( APIENTRY* glClearNamedFramebufferuiv )( GLuint framebuffer, GLenum buffer, GLint drawbuffer,
											   const GLuint* value ) = nullptr;
void ( APIENTRY* glClearStencil )( GLint s ) = nullptr;
void ( APIENTRY* glClearTexImage )( GLuint texture, GLint level, GLenum format, GLenum type, const void* data ) =
	nullptr;
void ( APIENTRY* glClearTexSubImage )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
									   GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type,
									   const void* data ) = nullptr;
GLenum ( APIENTRY* glClientWaitSync )( GLsync sync, GLbitfield flags, GLuint64 timeout ) = nullptr;
void ( APIENTRY* glClipControl )( GLenum origin, GLenum depth ) = nullptr;
void ( APIENTRY* glColorMask )( GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha ) = nullptr;
void ( APIENTRY* glColorMaski )( GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a ) = nullptr;
void ( APIENTRY* glColorP3ui )( GLenum type, GLuint color ) = nullptr;
void ( APIENTRY* glColorP3uiv )( GLenum type, const GLuint* color ) = nullptr;
void ( APIENTRY* glColorP4ui )( GLenum type, GLuint color ) = nullptr;
void ( APIENTRY* glColorP4uiv )( GLenum type, const GLuint* color ) = nullptr;
void ( APIENTRY* glCompileShader )( GLuint shader ) = nullptr;
void ( APIENTRY* glCompressedTexImage1D )( GLenum target, GLint level, GLenum internalformat, GLsizei width,
										   GLint border, GLsizei imageSize, const void* data ) = nullptr;
void ( APIENTRY* glCompressedTexImage2D )( GLenum target, GLint level, GLenum internalformat, GLsizei width,
										   GLsizei height, GLint border, GLsizei imageSize,
										   const void* data ) = nullptr;
void ( APIENTRY* glCompressedTexImage3D )( GLenum target, GLint level, GLenum internalformat, GLsizei width,
										   GLsizei height, GLsizei depth, GLint border, GLsizei imageSize,
										   const void* data ) = nullptr;
void ( APIENTRY* glCompressedTexSubImage1D )( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format,
											  GLsizei imageSize, const void* data ) = nullptr;
void ( APIENTRY* glCompressedTexSubImage2D )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
											  GLsizei height, GLenum format, GLsizei imageSize,
											  const void* data ) = nullptr;
void ( APIENTRY* glCompressedTexSubImage3D )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
											  GLsizei width, GLsizei height, GLsizei depth, GLenum format,
											  GLsizei imageSize, const void* data ) = nullptr;
void ( APIENTRY* glCompressedTextureSubImage1D )( GLuint texture, GLint level, GLint xoffset, GLsizei width,
												  GLenum format, GLsizei imageSize, const void* data ) = nullptr;
void ( APIENTRY* glCompressedTextureSubImage2D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset,
												  GLsizei width, GLsizei height, GLenum format, GLsizei imageSize,
												  const void* data ) = nullptr;
void ( APIENTRY* glCompressedTextureSubImage3D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset,
												  GLint zoffset, GLsizei width, GLsizei height, GLsizei depth,
												  GLenum format, GLsizei imageSize, const void* data ) = nullptr;
void ( APIENTRY* glCopyBufferSubData )( GLenum readTarget, GLenum writeTarget, GLintptr readOffset,
										GLintptr writeOffset, GLsizeiptr size ) = nullptr;
void ( APIENTRY* glCopyImageSubData )( GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY,
									   GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX,
									   GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight,
									   GLsizei srcDepth ) = nullptr;
void ( APIENTRY* glCopyNamedBufferSubData )( GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset,
											 GLintptr writeOffset, GLsizeiptr size ) = nullptr;
void ( APIENTRY* glCopyTexImage1D )( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width,
									 GLint border ) = nullptr;
void ( APIENTRY* glCopyTexImage2D )( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width,
									 GLsizei height, GLint border ) = nullptr;
void ( APIENTRY* glCopyTexSubImage1D )( GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width ) =
	nullptr;
void ( APIENTRY* glCopyTexSubImage2D )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y,
										GLsizei width, GLsizei height ) = nullptr;
void ( APIENTRY* glCopyTexSubImage3D )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
										GLint x, GLint y, GLsizei width, GLsizei height ) = nullptr;
void ( APIENTRY* glCopyTextureSubImage1D )( GLuint texture, GLint level, GLint xoffset, GLint x, GLint y,
											GLsizei width ) = nullptr;
void ( APIENTRY* glCopyTextureSubImage2D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y,
											GLsizei width, GLsizei height ) = nullptr;
void ( APIENTRY* glCopyTextureSubImage3D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
											GLint x, GLint y, GLsizei width, GLsizei height ) = nullptr;
void ( APIENTRY* glCreateBuffers )( GLsizei n, GLuint* buffers ) = nullptr;
void ( APIENTRY* glCreateFramebuffers )( GLsizei n, GLuint* framebuffers ) = nullptr;
GLuint ( APIENTRY* glCreateProgram )() = nullptr;
void ( APIENTRY* glCreateProgramPipelines )( GLsizei n, GLuint* pipelines ) = nullptr;
void ( APIENTRY* glCreateQueries )( GLenum target, GLsizei n, GLuint* ids ) = nullptr;
void ( APIENTRY* glCreateRenderbuffers )( GLsizei n, GLuint* renderbuffers ) = nullptr;
void ( APIENTRY* glCreateSamplers )( GLsizei n, GLuint* samplers ) = nullptr;
GLuint ( APIENTRY* glCreateShader )( GLenum type ) = nullptr;
GLuint ( APIENTRY* glCreateShaderProgramv )( GLenum type, GLsizei count, const GLchar* const* strings ) = nullptr;
void ( APIENTRY* glCreateTextures )( GLenum target, GLsizei n, GLuint* textures ) = nullptr;
void ( APIENTRY* glCreateTransformFeedbacks )( GLsizei n, GLuint* ids ) = nullptr;
void ( APIENTRY* glCreateVertexArrays )( GLsizei n, GLuint* arrays ) = nullptr;
void ( APIENTRY* glCullFace )( GLenum mode ) = nullptr;
void ( APIENTRY* glDebugMessageCallback )( GLDEBUGPROC callback, const void* userParam ) = nullptr;
void ( APIENTRY* glDebugMessageControl )( GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids,
										  GLboolean enabled ) = nullptr;
void ( APIENTRY* glDebugMessageInsert )( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
										 const GLchar* buf ) = nullptr;
void ( APIENTRY* glDeleteBuffers )( GLsizei n, const GLuint* buffers ) = nullptr;
void ( APIENTRY* glDeleteFramebuffers )( GLsizei n, const GLuint* framebuffers ) = nullptr;
void ( APIENTRY* glDeleteProgram )( GLuint program ) = nullptr;
void ( APIENTRY* glDeleteProgramPipelines )( GLsizei n, const GLuint* pipelines ) = nullptr;
void ( APIENTRY* glDeleteQueries )( GLsizei n, const GLuint* ids ) = nullptr;
void ( APIENTRY* glDeleteRenderbuffers )( GLsizei n, const GLuint* renderbuffers ) = nullptr;
void ( APIENTRY* glDeleteSamplers )( GLsizei count, const GLuint* samplers ) = nullptr;
void ( APIENTRY* glDeleteShader )( GLuint shader ) = nullptr;
void ( APIENTRY* glDeleteSync )( GLsync sync ) = nullptr;
void ( APIENTRY* glDeleteTextures )( GLsizei n, const GLuint* textures ) = nullptr;
void ( APIENTRY* glDeleteTransformFeedbacks )( GLsizei n, const GLuint* ids ) = nullptr;
void ( APIENTRY* glDeleteVertexArrays )( GLsizei n, const GLuint* arrays ) = nullptr;
void ( APIENTRY* glDepthFunc )( GLenum func ) = nullptr;
void ( APIENTRY* glDepthMask )( GLboolean flag ) = nullptr;
void ( APIENTRY* glDepthRange )( GLdouble n, GLdouble f ) = nullptr;
void ( APIENTRY* glDepthRangeArrayv )( GLuint first, GLsizei count, const GLdouble* v ) = nullptr;
void ( APIENTRY* glDepthRangeIndexed )( GLuint index, GLdouble n, GLdouble f ) = nullptr;
void ( APIENTRY* glDepthRangef )( GLfloat n, GLfloat f ) = nullptr;
void ( APIENTRY* glDetachShader )( GLuint program, GLuint shader ) = nullptr;
void ( APIENTRY* glDisable )( GLenum cap ) = nullptr;
void ( APIENTRY* glDisableVertexArrayAttrib )( GLuint vaobj, GLuint index ) = nullptr;
void ( APIENTRY* glDisableVertexAttribArray )( GLuint index ) = nullptr;
void ( APIENTRY* glDisablei )( GLenum target, GLuint index ) = nullptr;
void ( APIENTRY* glDispatchCompute )( GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z ) = nullptr;
void ( APIENTRY* glDispatchComputeIndirect )( GLintptr indirect ) = nullptr;
void ( APIENTRY* glDrawArrays )( GLenum mode, GLint first, GLsizei count ) = nullptr;
void ( APIENTRY* glDrawArraysIndirect )( GLenum mode, const void* indirect ) = nullptr;
void ( APIENTRY* glDrawArraysInstanced )( GLenum mode, GLint first, GLsizei count, GLsizei instancecount ) = nullptr;
void ( APIENTRY* glDrawArraysInstancedBaseInstance )( GLenum mode, GLint first, GLsizei count, GLsizei instancecount,
													  GLuint baseinstance ) = nullptr;
void ( APIENTRY* glDrawBuffer )( GLenum buf ) = nullptr;
void ( APIENTRY* glDrawBuffers )( GLsizei n, const GLenum* bufs ) = nullptr;
void ( APIENTRY* glDrawElements )( GLenum mode, GLsizei count, GLenum type, const void* indices ) = nullptr;
void ( APIENTRY* glDrawElementsBaseVertex )( GLenum mode, GLsizei count, GLenum type, const void* indices,
											 GLint basevertex ) = nullptr;
void ( APIENTRY* glDrawElementsIndirect )( GLenum mode, GLenum type, const void* indirect ) = nullptr;
void ( APIENTRY* glDrawElementsInstanced )( GLenum mode, GLsizei count, GLenum type, const void* indices,
											GLsizei instancecount ) = nullptr;
void ( APIENTRY* glDrawElementsInstancedBaseInstance )( GLenum mode, GLsizei count, GLenum type, const void* indices,
														GLsizei instancecount, GLuint baseinstance ) = nullptr;
void ( APIENTRY* glDrawElementsInstancedBaseVertex )( GLenum mode, GLsizei count, GLenum type, const void* indices,
													  GLsizei instancecount, GLint basevertex ) = nullptr;
void ( APIENTRY* glDrawElementsInstancedBaseVertexBaseInstance )( GLenum mode, GLsizei count, GLenum type,
																  const void* indices, GLsizei instancecount,
																  GLint basevertex, GLuint baseinstance ) = nullptr;
void ( APIENTRY* glDrawRangeElements )( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type,
										const void* indices ) = nullptr;
void ( APIENTRY* glDrawRangeElementsBaseVertex )( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type,
												  const void* indices, GLint basevertex ) = nullptr;
void ( APIENTRY* glDrawTransformFeedback )( GLenum mode, GLuint id ) = nullptr;
void ( APIENTRY* glDrawTransformFeedbackInstanced )( GLenum mode, GLuint id, GLsizei instancecount ) = nullptr;
void ( APIENTRY* glDrawTransformFeedbackStream )( GLenum mode, GLuint id, GLuint stream ) = nullptr;
void ( APIENTRY* glDrawTransformFeedbackStreamInstanced )( GLenum mode, GLuint id, GLuint stream,
														   GLsizei instancecount ) = nullptr;
void ( APIENTRY* glEnable )( GLenum cap ) = nullptr;
void ( APIENTRY* glEnableVertexArrayAttrib )( GLuint vaobj, GLuint index ) = nullptr;
void ( APIENTRY* glEnableVertexAttribArray )( GLuint index ) = nullptr;
void ( APIENTRY* glEnablei )( GLenum target, GLuint index ) = nullptr;
void ( APIENTRY* glEndConditionalRender )() = nullptr;
void ( APIENTRY* glEndQuery )( GLenum target ) = nullptr;
void ( APIENTRY* glEndQueryIndexed )( GLenum target, GLuint index ) = nullptr;
void ( APIENTRY* glEndTransformFeedback )() = nullptr;
GLsync ( APIENTRY* glFenceSync )( GLenum condition, GLbitfield flags ) = nullptr;
void ( APIENTRY* glFinish )() = nullptr;
void ( APIENTRY* glFlush )() = nullptr;
void ( APIENTRY* glFlushMappedBufferRange )( GLenum target, GLintptr offset, GLsizeiptr length ) = nullptr;
void ( APIENTRY* glFlushMappedNamedBufferRange )( GLuint buffer, GLintptr offset, GLsizeiptr length ) = nullptr;
void ( APIENTRY* glFramebufferParameteri )( GLenum target, GLenum pname, GLint param ) = nullptr;
void ( APIENTRY* glFramebufferRenderbuffer )( GLenum target, GLenum attachment, GLenum renderbuffertarget,
											  GLuint renderbuffer ) = nullptr;
void ( APIENTRY* glFramebufferTexture )( GLenum target, GLenum attachment, GLuint texture, GLint level ) = nullptr;
void ( APIENTRY* glFramebufferTexture1D )( GLenum target, GLenum attachment, GLenum textarget, GLuint texture,
										   GLint level ) = nullptr;
void ( APIENTRY* glFramebufferTexture2D )( GLenum target, GLenum attachment, GLenum textarget, GLuint texture,
										   GLint level ) = nullptr;
void ( APIENTRY* glFramebufferTexture3D )( GLenum target, GLenum attachment, GLenum textarget, GLuint texture,
										   GLint level, GLint zoffset ) = nullptr;
void ( APIENTRY* glFramebufferTextureLayer )( GLenum target, GLenum attachment, GLuint texture, GLint level,
											  GLint layer ) = nullptr;
void ( APIENTRY* glFrontFace )( GLenum mode ) = nullptr;
void ( APIENTRY* glGenBuffers )( GLsizei n, GLuint* buffers ) = nullptr;
void ( APIENTRY* glGenFramebuffers )( GLsizei n, GLuint* framebuffers ) = nullptr;
void ( APIENTRY* glGenProgramPipelines )( GLsizei n, GLuint* pipelines ) = nullptr;
void ( APIENTRY* glGenQueries )( GLsizei n, GLuint* ids ) = nullptr;
void ( APIENTRY* glGenRenderbuffers )( GLsizei n, GLuint* renderbuffers ) = nullptr;
void ( APIENTRY* glGenSamplers )( GLsizei count, GLuint* samplers ) = nullptr;
void ( APIENTRY* glGenTextures )( GLsizei n, GLuint* textures ) = nullptr;
void ( APIENTRY* glGenTransformFeedbacks )( GLsizei n, GLuint* ids ) = nullptr;
void ( APIENTRY* glGenVertexArrays )( GLsizei n, GLuint* arrays ) = nullptr;
void ( APIENTRY* glGenerateMipmap )( GLenum target ) = nullptr;
void ( APIENTRY* glGenerateTextureMipmap )( GLuint texture ) = nullptr;
void ( APIENTRY* glGetActiveAtomicCounterBufferiv )( GLuint program, GLuint bufferIndex, GLenum pname, GLint* params ) =
	nullptr;
void ( APIENTRY* glGetActiveAttrib )( GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size,
									  GLenum* type, GLchar* name ) = nullptr;
void ( APIENTRY* glGetActiveSubroutineName )( GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize,
											  GLsizei* length, GLchar* name ) = nullptr;
void ( APIENTRY* glGetActiveSubroutineUniformName )( GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize,
													 GLsizei* length, GLchar* name ) = nullptr;
void ( APIENTRY* glGetActiveSubroutineUniformiv )( GLuint program, GLenum shadertype, GLuint index, GLenum pname,
												   GLint* values ) = nullptr;
void ( APIENTRY* glGetActiveUniform )( GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size,
									   GLenum* type, GLchar* name ) = nullptr;
void ( APIENTRY* glGetActiveUniformBlockName )( GLuint program, GLuint uniformBlockIndex, GLsizei bufSize,
												GLsizei* length, GLchar* uniformBlockName ) = nullptr;
void ( APIENTRY* glGetActiveUniformBlockiv )( GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params ) =
	nullptr;
void ( APIENTRY* glGetActiveUniformName )( GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length,
										   GLchar* uniformName ) = nullptr;
void ( APIENTRY* glGetActiveUniformsiv )( GLuint program, GLsizei uniformCount, const GLuint* uniformIndices,
										  GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetAttachedShaders )( GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders ) = nullptr;
GLint ( APIENTRY* glGetAttribLocation )( GLuint program, const GLchar* name ) = nullptr;
void ( APIENTRY* glGetBooleani_v )( GLenum target, GLuint index, GLboolean* data ) = nullptr;
void ( APIENTRY* glGetBooleanv )( GLenum pname, GLboolean* data ) = nullptr;
void ( APIENTRY* glGetBufferParameteri64v )( GLenum target, GLenum pname, GLint64* params ) = nullptr;
void ( APIENTRY* glGetBufferParameteriv )( GLenum target, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetBufferPointerv )( GLenum target, GLenum pname, void** params ) = nullptr;
void ( APIENTRY* glGetBufferSubData )( GLenum target, GLintptr offset, GLsizeiptr size, void* data ) = nullptr;
void ( APIENTRY* glGetCompressedTexImage )( GLenum target, GLint level, void* img ) = nullptr;
void ( APIENTRY* glGetCompressedTextureImage )( GLuint texture, GLint level, GLsizei bufSize, void* pixels ) = nullptr;
void ( APIENTRY* glGetCompressedTextureSubImage )( GLuint texture, GLint level, GLint xoffset, GLint yoffset,
												   GLint zoffset, GLsizei width, GLsizei height, GLsizei depth,
												   GLsizei bufSize, void* pixels ) = nullptr;
GLuint ( APIENTRY* glGetDebugMessageLog )( GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids,
										   GLenum* severities, GLsizei* lengths, GLchar* messageLog ) = nullptr;
void ( APIENTRY* glGetDoublei_v )( GLenum target, GLuint index, GLdouble* data ) = nullptr;
void ( APIENTRY* glGetDoublev )( GLenum pname, GLdouble* data ) = nullptr;
GLenum ( APIENTRY* glGetError )() = nullptr;
void ( APIENTRY* glGetFloati_v )( GLenum target, GLuint index, GLfloat* data ) = nullptr;
void ( APIENTRY* glGetFloatv )( GLenum pname, GLfloat* data ) = nullptr;
GLint ( APIENTRY* glGetFragDataIndex )( GLuint program, const GLchar* name ) = nullptr;
GLint ( APIENTRY* glGetFragDataLocation )( GLuint program, const GLchar* name ) = nullptr;
void ( APIENTRY* glGetFramebufferAttachmentParameteriv )( GLenum target, GLenum attachment, GLenum pname,
														  GLint* params ) = nullptr;
void ( APIENTRY* glGetFramebufferParameteriv )( GLenum target, GLenum pname, GLint* params ) = nullptr;
GLenum ( APIENTRY* glGetGraphicsResetStatus )() = nullptr;
void ( APIENTRY* glGetInteger64i_v )( GLenum target, GLuint index, GLint64* data ) = nullptr;
void ( APIENTRY* glGetInteger64v )( GLenum pname, GLint64* data ) = nullptr;
void ( APIENTRY* glGetIntegeri_v )( GLenum target, GLuint index, GLint* data ) = nullptr;
void ( APIENTRY* glGetIntegerv )( GLenum pname, GLint* data ) = nullptr;
void ( APIENTRY* glGetInternalformati64v )( GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize,
											GLint64* params ) = nullptr;
void ( APIENTRY* glGetInternalformativ )( GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize,
										  GLint* params ) = nullptr;
void ( APIENTRY* glGetMultisamplefv )( GLenum pname, GLuint index, GLfloat* val ) = nullptr;
void ( APIENTRY* glGetNamedBufferParameteri64v )( GLuint buffer, GLenum pname, GLint64* params ) = nullptr;
void ( APIENTRY* glGetNamedBufferParameteriv )( GLuint buffer, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetNamedBufferPointerv )( GLuint buffer, GLenum pname, void** params ) = nullptr;
void ( APIENTRY* glGetNamedBufferSubData )( GLuint buffer, GLintptr offset, GLsizeiptr size, void* data ) = nullptr;
void ( APIENTRY* glGetNamedFramebufferAttachmentParameteriv )( GLuint framebuffer, GLenum attachment, GLenum pname,
															   GLint* params ) = nullptr;
void ( APIENTRY* glGetNamedFramebufferParameteriv )( GLuint framebuffer, GLenum pname, GLint* param ) = nullptr;
void ( APIENTRY* glGetNamedRenderbufferParameteriv )( GLuint renderbuffer, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetObjectLabel )( GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label ) =
	nullptr;
void ( APIENTRY* glGetObjectPtrLabel )( const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label ) = nullptr;
void ( APIENTRY* glGetPointerv )( GLenum pname, void** params ) = nullptr;
void ( APIENTRY* glGetProgramBinary )( GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat,
									   void* binary ) = nullptr;
void ( APIENTRY* glGetProgramInfoLog )( GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog ) = nullptr;
void ( APIENTRY* glGetProgramInterfaceiv )( GLuint program, GLenum programInterface, GLenum pname, GLint* params ) =
	nullptr;
void ( APIENTRY* glGetProgramPipelineInfoLog )( GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog ) =
	nullptr;
void ( APIENTRY* glGetProgramPipelineiv )( GLuint pipeline, GLenum pname, GLint* params ) = nullptr;
GLuint ( APIENTRY* glGetProgramResourceIndex )( GLuint program, GLenum programInterface, const GLchar* name ) = nullptr;
GLint ( APIENTRY* glGetProgramResourceLocation )( GLuint program, GLenum programInterface, const GLchar* name ) =
	nullptr;
GLint ( APIENTRY* glGetProgramResourceLocationIndex )( GLuint program, GLenum programInterface, const GLchar* name ) =
	nullptr;
void ( APIENTRY* glGetProgramResourceName )( GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize,
											 GLsizei* length, GLchar* name ) = nullptr;
void ( APIENTRY* glGetProgramResourceiv )( GLuint program, GLenum programInterface, GLuint index, GLsizei propCount,
										   const GLenum* props, GLsizei bufSize, GLsizei* length,
										   GLint* params ) = nullptr;
void ( APIENTRY* glGetProgramStageiv )( GLuint program, GLenum shadertype, GLenum pname, GLint* values ) = nullptr;
void ( APIENTRY* glGetProgramiv )( GLuint program, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetQueryBufferObjecti64v )( GLuint id, GLuint buffer, GLenum pname, GLintptr offset ) = nullptr;
void ( APIENTRY* glGetQueryBufferObjectiv )( GLuint id, GLuint buffer, GLenum pname, GLintptr offset ) = nullptr;
void ( APIENTRY* glGetQueryBufferObjectui64v )( GLuint id, GLuint buffer, GLenum pname, GLintptr offset ) = nullptr;
void ( APIENTRY* glGetQueryBufferObjectuiv )( GLuint id, GLuint buffer, GLenum pname, GLintptr offset ) = nullptr;
void ( APIENTRY* glGetQueryIndexediv )( GLenum target, GLuint index, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetQueryObjecti64v )( GLuint id, GLenum pname, GLint64* params ) = nullptr;
void ( APIENTRY* glGetQueryObjectiv )( GLuint id, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetQueryObjectui64v )( GLuint id, GLenum pname, GLuint64* params ) = nullptr;
void ( APIENTRY* glGetQueryObjectuiv )( GLuint id, GLenum pname, GLuint* params ) = nullptr;
void ( APIENTRY* glGetQueryiv )( GLenum target, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetRenderbufferParameteriv )( GLenum target, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetSamplerParameterIiv )( GLuint sampler, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetSamplerParameterIuiv )( GLuint sampler, GLenum pname, GLuint* params ) = nullptr;
void ( APIENTRY* glGetSamplerParameterfv )( GLuint sampler, GLenum pname, GLfloat* params ) = nullptr;
void ( APIENTRY* glGetSamplerParameteriv )( GLuint sampler, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetShaderInfoLog )( GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog ) = nullptr;
void ( APIENTRY* glGetShaderPrecisionFormat )( GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision )
	= nullptr;
void ( APIENTRY* glGetShaderSource )( GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source ) = nullptr;
void ( APIENTRY* glGetShaderiv )( GLuint shader, GLenum pname, GLint* params ) = nullptr;
const GLubyte* ( APIENTRY* glGetString )( GLenum name ) = nullptr;
const GLubyte* ( APIENTRY* glGetStringi )( GLenum name, GLuint index ) = nullptr;
GLuint ( APIENTRY* glGetSubroutineIndex )( GLuint program, GLenum shadertype, const GLchar* name ) = nullptr;
GLint ( APIENTRY* glGetSubroutineUniformLocation )( GLuint program, GLenum shadertype, const GLchar* name ) = nullptr;
void ( APIENTRY* glGetSynciv )( GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values ) = nullptr;
void ( APIENTRY* glGetTexImage )( GLenum target, GLint level, GLenum format, GLenum type, void* pixels ) = nullptr;
void ( APIENTRY* glGetTexLevelParameterfv )( GLenum target, GLint level, GLenum pname, GLfloat* params ) = nullptr;
void ( APIENTRY* glGetTexLevelParameteriv )( GLenum target, GLint level, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetTexParameterIiv )( GLenum target, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetTexParameterIuiv )( GLenum target, GLenum pname, GLuint* params ) = nullptr;
void ( APIENTRY* glGetTexParameterfv )( GLenum target, GLenum pname, GLfloat* params ) = nullptr;
void ( APIENTRY* glGetTexParameteriv )( GLenum target, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetTextureImage )( GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize,
									  void* pixels ) = nullptr;
void ( APIENTRY* glGetTextureLevelParameterfv )( GLuint texture, GLint level, GLenum pname, GLfloat* params ) = nullptr;
void ( APIENTRY* glGetTextureLevelParameteriv )( GLuint texture, GLint level, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetTextureParameterIiv )( GLuint texture, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetTextureParameterIuiv )( GLuint texture, GLenum pname, GLuint* params ) = nullptr;
void ( APIENTRY* glGetTextureParameterfv )( GLuint texture, GLenum pname, GLfloat* params ) = nullptr;
void ( APIENTRY* glGetTextureParameteriv )( GLuint texture, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetTextureSubImage )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
										 GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type,
										 GLsizei bufSize, void* pixels ) = nullptr;
void ( APIENTRY* glGetTransformFeedbackVarying )( GLuint program, GLuint index, GLsizei bufSize, GLsizei* length,
												  GLsizei* size, GLenum* type, GLchar* name ) = nullptr;
void ( APIENTRY* glGetTransformFeedbacki64_v )( GLuint xfb, GLenum pname, GLuint index, GLint64* param ) = nullptr;
void ( APIENTRY* glGetTransformFeedbacki_v )( GLuint xfb, GLenum pname, GLuint index, GLint* param ) = nullptr;
void ( APIENTRY* glGetTransformFeedbackiv )( GLuint xfb, GLenum pname, GLint* param ) = nullptr;
GLuint ( APIENTRY* glGetUniformBlockIndex )( GLuint program, const GLchar* uniformBlockName ) = nullptr;
void ( APIENTRY* glGetUniformIndices )( GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames,
										GLuint* uniformIndices ) = nullptr;
GLint ( APIENTRY* glGetUniformLocation )( GLuint program, const GLchar* name ) = nullptr;
void ( APIENTRY* glGetUniformSubroutineuiv )( GLenum shadertype, GLint location, GLuint* params ) = nullptr;
void ( APIENTRY* glGetUniformdv )( GLuint program, GLint location, GLdouble* params ) = nullptr;
void ( APIENTRY* glGetUniformfv )( GLuint program, GLint location, GLfloat* params ) = nullptr;
void ( APIENTRY* glGetUniformiv )( GLuint program, GLint location, GLint* params ) = nullptr;
void ( APIENTRY* glGetUniformuiv )( GLuint program, GLint location, GLuint* params ) = nullptr;
void ( APIENTRY* glGetVertexArrayIndexed64iv )( GLuint vaobj, GLuint index, GLenum pname, GLint64* param ) = nullptr;
void ( APIENTRY* glGetVertexArrayIndexediv )( GLuint vaobj, GLuint index, GLenum pname, GLint* param ) = nullptr;
void ( APIENTRY* glGetVertexArrayiv )( GLuint vaobj, GLenum pname, GLint* param ) = nullptr;
void ( APIENTRY* glGetVertexAttribIiv )( GLuint index, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetVertexAttribIuiv )( GLuint index, GLenum pname, GLuint* params ) = nullptr;
void ( APIENTRY* glGetVertexAttribLdv )( GLuint index, GLenum pname, GLdouble* params ) = nullptr;
void ( APIENTRY* glGetVertexAttribPointerv )( GLuint index, GLenum pname, void** pointer ) = nullptr;
void ( APIENTRY* glGetVertexAttribdv )( GLuint index, GLenum pname, GLdouble* params ) = nullptr;
void ( APIENTRY* glGetVertexAttribfv )( GLuint index, GLenum pname, GLfloat* params ) = nullptr;
void ( APIENTRY* glGetVertexAttribiv )( GLuint index, GLenum pname, GLint* params ) = nullptr;
void ( APIENTRY* glGetnColorTable )( GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table ) =
	nullptr;
void ( APIENTRY* glGetnCompressedTexImage )( GLenum target, GLint lod, GLsizei bufSize, void* pixels ) = nullptr;
void ( APIENTRY* glGetnConvolutionFilter )( GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image ) =
	nullptr;
void ( APIENTRY* glGetnHistogram )( GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize,
									void* values ) = nullptr;
void ( APIENTRY* glGetnMapdv )( GLenum target, GLenum query, GLsizei bufSize, GLdouble* v ) = nullptr;
void ( APIENTRY* glGetnMapfv )( GLenum target, GLenum query, GLsizei bufSize, GLfloat* v ) = nullptr;
void ( APIENTRY* glGetnMapiv )( GLenum target, GLenum query, GLsizei bufSize, GLint* v ) = nullptr;
void ( APIENTRY* glGetnMinmax )( GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize,
								 void* values ) = nullptr;
void ( APIENTRY* glGetnPixelMapfv )( GLenum map, GLsizei bufSize, GLfloat* values ) = nullptr;
void ( APIENTRY* glGetnPixelMapuiv )( GLenum map, GLsizei bufSize, GLuint* values ) = nullptr;
void ( APIENTRY* glGetnPixelMapusv )( GLenum map, GLsizei bufSize, GLushort* values ) = nullptr;
void ( APIENTRY* glGetnPolygonStipple )( GLsizei bufSize, GLubyte* pattern ) = nullptr;
void ( APIENTRY* glGetnSeparableFilter )( GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void* row,
										  GLsizei columnBufSize, void* column, void* span ) = nullptr;
void ( APIENTRY* glGetnTexImage )( GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize,
								   void* pixels ) = nullptr;
void ( APIENTRY* glGetnUniformdv )( GLuint program, GLint location, GLsizei bufSize, GLdouble* params ) = nullptr;
void ( APIENTRY* glGetnUniformfv )( GLuint program, GLint location, GLsizei bufSize, GLfloat* params ) = nullptr;
void ( APIENTRY* glGetnUniformiv )( GLuint program, GLint location, GLsizei bufSize, GLint* params ) = nullptr;
void ( APIENTRY* glGetnUniformuiv )( GLuint program, GLint location, GLsizei bufSize, GLuint* params ) = nullptr;
void ( APIENTRY* glHint )( GLenum target, GLenum mode ) = nullptr;
void ( APIENTRY* glInvalidateBufferData )( GLuint buffer ) = nullptr;
void ( APIENTRY* glInvalidateBufferSubData )( GLuint buffer, GLintptr offset, GLsizeiptr length ) = nullptr;
void ( APIENTRY* glInvalidateFramebuffer )( GLenum target, GLsizei numAttachments, const GLenum* attachments ) =
	nullptr;
void ( APIENTRY* glInvalidateNamedFramebufferData )( GLuint framebuffer, GLsizei numAttachments,
													 const GLenum* attachments ) = nullptr;
void ( APIENTRY* glInvalidateNamedFramebufferSubData )( GLuint framebuffer, GLsizei numAttachments,
														const GLenum* attachments, GLint x, GLint y, GLsizei width,
														GLsizei height ) = nullptr;
void ( APIENTRY* glInvalidateSubFramebuffer )( GLenum target, GLsizei numAttachments, const GLenum* attachments,
											   GLint x, GLint y, GLsizei width, GLsizei height ) = nullptr;
void ( APIENTRY* glInvalidateTexImage )( GLuint texture, GLint level ) = nullptr;
void ( APIENTRY* glInvalidateTexSubImage )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
											GLsizei width, GLsizei height, GLsizei depth ) = nullptr;
GLboolean ( APIENTRY* glIsBuffer )( GLuint buffer ) = nullptr;
GLboolean ( APIENTRY* glIsEnabled )( GLenum cap ) = nullptr;
GLboolean ( APIENTRY* glIsEnabledi )( GLenum target, GLuint index ) = nullptr;
GLboolean ( APIENTRY* glIsFramebuffer )( GLuint framebuffer ) = nullptr;
GLboolean ( APIENTRY* glIsProgram )( GLuint program ) = nullptr;
GLboolean ( APIENTRY* glIsProgramPipeline )( GLuint pipeline ) = nullptr;
GLboolean ( APIENTRY* glIsQuery )( GLuint id ) = nullptr;
GLboolean ( APIENTRY* glIsRenderbuffer )( GLuint renderbuffer ) = nullptr;
GLboolean ( APIENTRY* glIsSampler )( GLuint sampler ) = nullptr;
GLboolean ( APIENTRY* glIsShader )( GLuint shader ) = nullptr;
GLboolean ( APIENTRY* glIsSync )( GLsync sync ) = nullptr;
GLboolean ( APIENTRY* glIsTexture )( GLuint texture ) = nullptr;
GLboolean ( APIENTRY* glIsTransformFeedback )( GLuint id ) = nullptr;
GLboolean ( APIENTRY* glIsVertexArray )( GLuint array ) = nullptr;
void ( APIENTRY* glLineWidth )( GLfloat width ) = nullptr;
void ( APIENTRY* glLinkProgram )( GLuint program ) = nullptr;
void ( APIENTRY* glLogicOp )( GLenum opcode ) = nullptr;
void* ( APIENTRY* glMapBuffer )( GLenum target, GLenum access ) = nullptr;
void* ( APIENTRY* glMapBufferRange )( GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access ) = nullptr;
void* ( APIENTRY* glMapNamedBuffer )( GLuint buffer, GLenum access ) = nullptr;
void* ( APIENTRY* glMapNamedBufferRange )( GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access ) =
	nullptr;
void ( APIENTRY* glMemoryBarrier )( GLbitfield barriers ) = nullptr;
void ( APIENTRY* glMemoryBarrierByRegion )( GLbitfield barriers ) = nullptr;
void ( APIENTRY* glMinSampleShading )( GLfloat value ) = nullptr;
void ( APIENTRY* glMultiDrawArrays )( GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount ) =
	nullptr;
void ( APIENTRY* glMultiDrawArraysIndirect )( GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride ) =
	nullptr;
void ( APIENTRY* glMultiDrawElements )( GLenum mode, const GLsizei* count, GLenum type, const void* const* indices,
										GLsizei drawcount ) = nullptr;
void ( APIENTRY* glMultiDrawElementsBaseVertex )( GLenum mode, const GLsizei* count, GLenum type,
												  const void* const* indices, GLsizei drawcount,
												  const GLint* basevertex ) = nullptr;
void ( APIENTRY* glMultiDrawElementsIndirect )( GLenum mode, GLenum type, const void* indirect, GLsizei drawcount,
												GLsizei stride ) = nullptr;
void ( APIENTRY* glMultiTexCoordP1ui )( GLenum texture, GLenum type, GLuint coords ) = nullptr;
void ( APIENTRY* glMultiTexCoordP1uiv )( GLenum texture, GLenum type, const GLuint* coords ) = nullptr;
void ( APIENTRY* glMultiTexCoordP2ui )( GLenum texture, GLenum type, GLuint coords ) = nullptr;
void ( APIENTRY* glMultiTexCoordP2uiv )( GLenum texture, GLenum type, const GLuint* coords ) = nullptr;
void ( APIENTRY* glMultiTexCoordP3ui )( GLenum texture, GLenum type, GLuint coords ) = nullptr;
void ( APIENTRY* glMultiTexCoordP3uiv )( GLenum texture, GLenum type, const GLuint* coords ) = nullptr;
void ( APIENTRY* glMultiTexCoordP4ui )( GLenum texture, GLenum type, GLuint coords ) = nullptr;
void ( APIENTRY* glMultiTexCoordP4uiv )( GLenum texture, GLenum type, const GLuint* coords ) = nullptr;
void ( APIENTRY* glNamedBufferData )( GLuint buffer, GLsizeiptr size, const void* data, GLenum usage ) = nullptr;
void ( APIENTRY* glNamedBufferStorage )( GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags ) = nullptr;
void ( APIENTRY* glNamedBufferSubData )( GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data ) = nullptr;
void ( APIENTRY* glNamedFramebufferDrawBuffer )( GLuint framebuffer, GLenum buf ) = nullptr;
void ( APIENTRY* glNamedFramebufferDrawBuffers )( GLuint framebuffer, GLsizei n, const GLenum* bufs ) = nullptr;
void ( APIENTRY* glNamedFramebufferParameteri )( GLuint framebuffer, GLenum pname, GLint param ) = nullptr;
void ( APIENTRY* glNamedFramebufferReadBuffer )( GLuint framebuffer, GLenum src ) = nullptr;
void ( APIENTRY* glNamedFramebufferRenderbuffer )( GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget,
												   GLuint renderbuffer ) = nullptr;
void ( APIENTRY* glNamedFramebufferTexture )( GLuint framebuffer, GLenum attachment, GLuint texture, GLint level ) =
	nullptr;
void ( APIENTRY* glNamedFramebufferTextureLayer )( GLuint framebuffer, GLenum attachment, GLuint texture, GLint level,
												   GLint layer ) = nullptr;
void ( APIENTRY* glNamedRenderbufferStorage )( GLuint renderbuffer, GLenum internalformat, GLsizei width,
											   GLsizei height ) = nullptr;
void ( APIENTRY* glNamedRenderbufferStorageMultisample )( GLuint renderbuffer, GLsizei samples, GLenum internalformat,
														  GLsizei width, GLsizei height ) = nullptr;
void ( APIENTRY* glNormalP3ui )( GLenum type, GLuint coords ) = nullptr;
void ( APIENTRY* glNormalP3uiv )( GLenum type, const GLuint* coords ) = nullptr;
void ( APIENTRY* glObjectLabel )( GLenum identifier, GLuint name, GLsizei length, const GLchar* label ) = nullptr;
void ( APIENTRY* glObjectPtrLabel )( const void* ptr, GLsizei length, const GLchar* label ) = nullptr;
void ( APIENTRY* glPatchParameterfv )( GLenum pname, const GLfloat* values ) = nullptr;
void ( APIENTRY* glPatchParameteri )( GLenum pname, GLint value ) = nullptr;
void ( APIENTRY* glPauseTransformFeedback )() = nullptr;
void ( APIENTRY* glPixelStoref )( GLenum pname, GLfloat param ) = nullptr;
void ( APIENTRY* glPixelStorei )( GLenum pname, GLint param ) = nullptr;
void ( APIENTRY* glPointParameterf )( GLenum pname, GLfloat param ) = nullptr;
void ( APIENTRY* glPointParameterfv )( GLenum pname, const GLfloat* params ) = nullptr;
void ( APIENTRY* glPointParameteri )( GLenum pname, GLint param ) = nullptr;
void ( APIENTRY* glPointParameteriv )( GLenum pname, const GLint* params ) = nullptr;
void ( APIENTRY* glPointSize )( GLfloat size ) = nullptr;
void ( APIENTRY* glPolygonMode )( GLenum face, GLenum mode ) = nullptr;
void ( APIENTRY* glPolygonOffset )( GLfloat factor, GLfloat units ) = nullptr;
void ( APIENTRY* glPopDebugGroup )() = nullptr;
void ( APIENTRY* glPrimitiveRestartIndex )( GLuint index ) = nullptr;
void ( APIENTRY* glProgramBinary )( GLuint program, GLenum binaryFormat, const void* binary, GLsizei length ) = nullptr;
void ( APIENTRY* glProgramParameteri )( GLuint program, GLenum pname, GLint value ) = nullptr;
void ( APIENTRY* glProgramUniform1d )( GLuint program, GLint location, GLdouble v0 ) = nullptr;
void ( APIENTRY* glProgramUniform1dv )( GLuint program, GLint location, GLsizei count, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glProgramUniform1f )( GLuint program, GLint location, GLfloat v0 ) = nullptr;
void ( APIENTRY* glProgramUniform1fv )( GLuint program, GLint location, GLsizei count, const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniform1i )( GLuint program, GLint location, GLint v0 ) = nullptr;
void ( APIENTRY* glProgramUniform1iv )( GLuint program, GLint location, GLsizei count, const GLint* value ) = nullptr;
void ( APIENTRY* glProgramUniform1ui )( GLuint program, GLint location, GLuint v0 ) = nullptr;
void ( APIENTRY* glProgramUniform1uiv )( GLuint program, GLint location, GLsizei count, const GLuint* value ) = nullptr;
void ( APIENTRY* glProgramUniform2d )( GLuint program, GLint location, GLdouble v0, GLdouble v1 ) = nullptr;
void ( APIENTRY* glProgramUniform2dv )( GLuint program, GLint location, GLsizei count, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glProgramUniform2f )( GLuint program, GLint location, GLfloat v0, GLfloat v1 ) = nullptr;
void ( APIENTRY* glProgramUniform2fv )( GLuint program, GLint location, GLsizei count, const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniform2i )( GLuint program, GLint location, GLint v0, GLint v1 ) = nullptr;
void ( APIENTRY* glProgramUniform2iv )( GLuint program, GLint location, GLsizei count, const GLint* value ) = nullptr;
void ( APIENTRY* glProgramUniform2ui )( GLuint program, GLint location, GLuint v0, GLuint v1 ) = nullptr;
void ( APIENTRY* glProgramUniform2uiv )( GLuint program, GLint location, GLsizei count, const GLuint* value ) = nullptr;
void ( APIENTRY* glProgramUniform3d )( GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2 ) =
	nullptr;
void ( APIENTRY* glProgramUniform3dv )( GLuint program, GLint location, GLsizei count, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glProgramUniform3f )( GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2 ) = nullptr;
void ( APIENTRY* glProgramUniform3fv )( GLuint program, GLint location, GLsizei count, const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniform3i )( GLuint program, GLint location, GLint v0, GLint v1, GLint v2 ) = nullptr;
void ( APIENTRY* glProgramUniform3iv )( GLuint program, GLint location, GLsizei count, const GLint* value ) = nullptr;
void ( APIENTRY* glProgramUniform3ui )( GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2 ) = nullptr;
void ( APIENTRY* glProgramUniform3uiv )( GLuint program, GLint location, GLsizei count, const GLuint* value ) = nullptr;
void ( APIENTRY* glProgramUniform4d )( GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2,
									   GLdouble v3 ) = nullptr;
void ( APIENTRY* glProgramUniform4dv )( GLuint program, GLint location, GLsizei count, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glProgramUniform4f )( GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3 )
	= nullptr;
void ( APIENTRY* glProgramUniform4fv )( GLuint program, GLint location, GLsizei count, const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniform4i )( GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3 ) =
	nullptr;
void ( APIENTRY* glProgramUniform4iv )( GLuint program, GLint location, GLsizei count, const GLint* value ) = nullptr;
void ( APIENTRY* glProgramUniform4ui )( GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3 ) =
	nullptr;
void ( APIENTRY* glProgramUniform4uiv )( GLuint program, GLint location, GLsizei count, const GLuint* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix2dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
											  const GLdouble* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix2fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
											  const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix2x3dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix2x3fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix2x4dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix2x4fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix3dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
											  const GLdouble* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix3fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
											  const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix3x2dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix3x2fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix3x4dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix3x4fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix4dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
											  const GLdouble* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix4fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
											  const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix4x2dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix4x2fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix4x3dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value ) = nullptr;
void ( APIENTRY* glProgramUniformMatrix4x3fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value ) = nullptr;
void ( APIENTRY* glProvokingVertex )( GLenum mode ) = nullptr;
void ( APIENTRY* glPushDebugGroup )( GLenum source, GLuint id, GLsizei length, const GLchar* message ) = nullptr;
void ( APIENTRY* glQueryCounter )( GLuint id, GLenum target ) = nullptr;
void ( APIENTRY* glReadBuffer )( GLenum src ) = nullptr;
void ( APIENTRY* glReadPixels )( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type,
								 void* pixels ) = nullptr;
void ( APIENTRY* glReadnPixels )( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type,
								  GLsizei bufSize, void* data ) = nullptr;
void ( APIENTRY* glReleaseShaderCompiler )() = nullptr;
void ( APIENTRY* glRenderbufferStorage )( GLenum target, GLenum internalformat, GLsizei width, GLsizei height ) =
	nullptr;
void ( APIENTRY* glRenderbufferStorageMultisample )( GLenum target, GLsizei samples, GLenum internalformat,
													 GLsizei width, GLsizei height ) = nullptr;
void ( APIENTRY* glResumeTransformFeedback )() = nullptr;
void ( APIENTRY* glSampleCoverage )( GLfloat value, GLboolean invert ) = nullptr;
void ( APIENTRY* glSampleMaski )( GLuint maskNumber, GLbitfield mask ) = nullptr;
void ( APIENTRY* glSamplerParameterIiv )( GLuint sampler, GLenum pname, const GLint* param ) = nullptr;
void ( APIENTRY* glSamplerParameterIuiv )( GLuint sampler, GLenum pname, const GLuint* param ) = nullptr;
void ( APIENTRY* glSamplerParameterf )( GLuint sampler, GLenum pname, GLfloat param ) = nullptr;
void ( APIENTRY* glSamplerParameterfv )( GLuint sampler, GLenum pname, const GLfloat* param ) = nullptr;
void ( APIENTRY* glSamplerParameteri )( GLuint sampler, GLenum pname, GLint param ) = nullptr;
void ( APIENTRY* glSamplerParameteriv )( GLuint sampler, GLenum pname, const GLint* param ) = nullptr;
void ( APIENTRY* glScissor )( GLint x, GLint y, GLsizei width, GLsizei height ) = nullptr;
void ( APIENTRY* glScissorArrayv )( GLuint first, GLsizei count, const GLint* v ) = nullptr;
void ( APIENTRY* glScissorIndexed )( GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height ) = nullptr;
void ( APIENTRY* glScissorIndexedv )( GLuint index, const GLint* v ) = nullptr;
void ( APIENTRY* glSecondaryColorP3ui )( GLenum type, GLuint color ) = nullptr;
void ( APIENTRY* glSecondaryColorP3uiv )( GLenum type, const GLuint* color ) = nullptr;
void ( APIENTRY* glShaderBinary )( GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary,
								   GLsizei length ) = nullptr;
void ( APIENTRY* glShaderSource )( GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length ) =
	nullptr;
void ( APIENTRY* glShaderStorageBlockBinding )( GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding ) =
	nullptr;
void ( APIENTRY* glStencilFunc )( GLenum func, GLint ref, GLuint mask ) = nullptr;
void ( APIENTRY* glStencilFuncSeparate )( GLenum face, GLenum func, GLint ref, GLuint mask ) = nullptr;
void ( APIENTRY* glStencilMask )( GLuint mask ) = nullptr;
void ( APIENTRY* glStencilMaskSeparate )( GLenum face, GLuint mask ) = nullptr;
void ( APIENTRY* glStencilOp )( GLenum fail, GLenum zfail, GLenum zpass ) = nullptr;
void ( APIENTRY* glStencilOpSeparate )( GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass ) = nullptr;
void ( APIENTRY* glTexBuffer )( GLenum target, GLenum internalformat, GLuint buffer ) = nullptr;
void ( APIENTRY* glTexBufferRange )( GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset,
									 GLsizeiptr size ) = nullptr;
void ( APIENTRY* glTexCoordP1ui )( GLenum type, GLuint coords ) = nullptr;
void ( APIENTRY* glTexCoordP1uiv )( GLenum type, const GLuint* coords ) = nullptr;
void ( APIENTRY* glTexCoordP2ui )( GLenum type, GLuint coords ) = nullptr;
void ( APIENTRY* glTexCoordP2uiv )( GLenum type, const GLuint* coords ) = nullptr;
void ( APIENTRY* glTexCoordP3ui )( GLenum type, GLuint coords ) = nullptr;
void ( APIENTRY* glTexCoordP3uiv )( GLenum type, const GLuint* coords ) = nullptr;
void ( APIENTRY* glTexCoordP4ui )( GLenum type, GLuint coords ) = nullptr;
void ( APIENTRY* glTexCoordP4uiv )( GLenum type, const GLuint* coords ) = nullptr;
void ( APIENTRY* glTexImage1D )( GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border,
								 GLenum format, GLenum type, const void* pixels ) = nullptr;
void ( APIENTRY* glTexImage2D )( GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
								 GLint border, GLenum format, GLenum type, const void* pixels ) = nullptr;
void ( APIENTRY* glTexImage2DMultisample )( GLenum target, GLsizei samples, GLenum internalformat, GLsizei width,
											GLsizei height, GLboolean fixedsamplelocations ) = nullptr;
void ( APIENTRY* glTexImage3D )( GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
								 GLsizei depth, GLint border, GLenum format, GLenum type,
								 const void* pixels ) = nullptr;
void ( APIENTRY* glTexImage3DMultisample )( GLenum target, GLsizei samples, GLenum internalformat, GLsizei width,
											GLsizei height, GLsizei depth, GLboolean fixedsamplelocations ) = nullptr;
void ( APIENTRY* glTexParameterIiv )( GLenum target, GLenum pname, const GLint* params ) = nullptr;
void ( APIENTRY* glTexParameterIuiv )( GLenum target, GLenum pname, const GLuint* params ) = nullptr;
void ( APIENTRY* glTexParameterf )( GLenum target, GLenum pname, GLfloat param ) = nullptr;
void ( APIENTRY* glTexParameterfv )( GLenum target, GLenum pname, const GLfloat* params ) = nullptr;
void ( APIENTRY* glTexParameteri )( GLenum target, GLenum pname, GLint param ) = nullptr;
void ( APIENTRY* glTexParameteriv )( GLenum target, GLenum pname, const GLint* params ) = nullptr;
void ( APIENTRY* glTexStorage1D )( GLenum target, GLsizei levels, GLenum internalformat, GLsizei width ) = nullptr;
void ( APIENTRY* glTexStorage2D )( GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height )
	= nullptr;
void ( APIENTRY* glTexStorage2DMultisample )( GLenum target, GLsizei samples, GLenum internalformat, GLsizei width,
											  GLsizei height, GLboolean fixedsamplelocations ) = nullptr;
void ( APIENTRY* glTexStorage3D )( GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height,
								   GLsizei depth ) = nullptr;
void ( APIENTRY* glTexStorage3DMultisample )( GLenum target, GLsizei samples, GLenum internalformat, GLsizei width,
											  GLsizei height, GLsizei depth, GLboolean fixedsamplelocations ) = nullptr;
void ( APIENTRY* glTexSubImage1D )( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format,
									GLenum type, const void* pixels ) = nullptr;
void ( APIENTRY* glTexSubImage2D )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
									GLsizei height, GLenum format, GLenum type, const void* pixels ) = nullptr;
void ( APIENTRY* glTexSubImage3D )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
									GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type,
									const void* pixels ) = nullptr;
void ( APIENTRY* glTextureBarrier )() = nullptr;
void ( APIENTRY* glTextureBuffer )( GLuint texture, GLenum internalformat, GLuint buffer ) = nullptr;
void ( APIENTRY* glTextureBufferRange )( GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset,
										 GLsizeiptr size ) = nullptr;
void ( APIENTRY* glTextureParameterIiv )( GLuint texture, GLenum pname, const GLint* params ) = nullptr;
void ( APIENTRY* glTextureParameterIuiv )( GLuint texture, GLenum pname, const GLuint* params ) = nullptr;
void ( APIENTRY* glTextureParameterf )( GLuint texture, GLenum pname, GLfloat param ) = nullptr;
void ( APIENTRY* glTextureParameterfv )( GLuint texture, GLenum pname, const GLfloat* param ) = nullptr;
void ( APIENTRY* glTextureParameteri )( GLuint texture, GLenum pname, GLint param ) = nullptr;
void ( APIENTRY* glTextureParameteriv )( GLuint texture, GLenum pname, const GLint* param ) = nullptr;
void ( APIENTRY* glTextureStorage1D )( GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width ) = nullptr;
void ( APIENTRY* glTextureStorage2D )( GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width,
									   GLsizei height ) = nullptr;
void ( APIENTRY* glTextureStorage2DMultisample )( GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width,
												  GLsizei height, GLboolean fixedsamplelocations ) = nullptr;
void ( APIENTRY* glTextureStorage3D )( GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width,
									   GLsizei height, GLsizei depth ) = nullptr;
void ( APIENTRY* glTextureStorage3DMultisample )( GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width,
												  GLsizei height, GLsizei depth,
												  GLboolean fixedsamplelocations ) = nullptr;
void ( APIENTRY* glTextureSubImage1D )( GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format,
										GLenum type, const void* pixels ) = nullptr;
void ( APIENTRY* glTextureSubImage2D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
										GLsizei height, GLenum format, GLenum type, const void* pixels ) = nullptr;
void ( APIENTRY* glTextureSubImage3D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
										GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type,
										const void* pixels ) = nullptr;
void ( APIENTRY* glTextureView )( GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat,
								  GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers ) = nullptr;
void ( APIENTRY* glTransformFeedbackBufferBase )( GLuint xfb, GLuint index, GLuint buffer ) = nullptr;
void ( APIENTRY* glTransformFeedbackBufferRange )( GLuint xfb, GLuint index, GLuint buffer, GLintptr offset,
												   GLsizeiptr size ) = nullptr;
void ( APIENTRY* glTransformFeedbackVaryings )( GLuint program, GLsizei count, const GLchar* const* varyings,
												GLenum bufferMode ) = nullptr;
void ( APIENTRY* glUniform1d )( GLint location, GLdouble x ) = nullptr;
void ( APIENTRY* glUniform1dv )( GLint location, GLsizei count, const GLdouble* value ) = nullptr;
void ( APIENTRY* glUniform1f )( GLint location, GLfloat v0 ) = nullptr;
void ( APIENTRY* glUniform1fv )( GLint location, GLsizei count, const GLfloat* value ) = nullptr;
void ( APIENTRY* glUniform1i )( GLint location, GLint v0 ) = nullptr;
void ( APIENTRY* glUniform1iv )( GLint location, GLsizei count, const GLint* value ) = nullptr;
void ( APIENTRY* glUniform1ui )( GLint location, GLuint v0 ) = nullptr;
void ( APIENTRY* glUniform1uiv )( GLint location, GLsizei count, const GLuint* value ) = nullptr;
void ( APIENTRY* glUniform2d )( GLint location, GLdouble x, GLdouble y ) = nullptr;
void ( APIENTRY* glUniform2dv )( GLint location, GLsizei count, const GLdouble* value ) = nullptr;
void ( APIENTRY* glUniform2f )( GLint location, GLfloat v0, GLfloat v1 ) = nullptr;
void ( APIENTRY* glUniform2fv )( GLint location, GLsizei count, const GLfloat* value ) = nullptr;
void ( APIENTRY* glUniform2i )( GLint location, GLint v0, GLint v1 ) = nullptr;
void ( APIENTRY* glUniform2iv )( GLint location, GLsizei count, const GLint* value ) = nullptr;
void ( APIENTRY* glUniform2ui )( GLint location, GLuint v0, GLuint v1 ) = nullptr;
void ( APIENTRY* glUniform2uiv )( GLint location, GLsizei count, const GLuint* value ) = nullptr;
void ( APIENTRY* glUniform3d )( GLint location, GLdouble x, GLdouble y, GLdouble z ) = nullptr;
void ( APIENTRY* glUniform3dv )( GLint location, GLsizei count, const GLdouble* value ) = nullptr;
void ( APIENTRY* glUniform3f )( GLint location, GLfloat v0, GLfloat v1, GLfloat v2 ) = nullptr;
void ( APIENTRY* glUniform3fv )( GLint location, GLsizei count, const GLfloat* value ) = nullptr;
void ( APIENTRY* glUniform3i )( GLint location, GLint v0, GLint v1, GLint v2 ) = nullptr;
void ( APIENTRY* glUniform3iv )( GLint location, GLsizei count, const GLint* value ) = nullptr;
void ( APIENTRY* glUniform3ui )( GLint location, GLuint v0, GLuint v1, GLuint v2 ) = nullptr;
void ( APIENTRY* glUniform3uiv )( GLint location, GLsizei count, const GLuint* value ) = nullptr;
void ( APIENTRY* glUniform4d )( GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w ) = nullptr;
void ( APIENTRY* glUniform4dv )( GLint location, GLsizei count, const GLdouble* value ) = nullptr;
void ( APIENTRY* glUniform4f )( GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3 ) = nullptr;
void ( APIENTRY* glUniform4fv )( GLint location, GLsizei count, const GLfloat* value ) = nullptr;
void ( APIENTRY* glUniform4i )( GLint location, GLint v0, GLint v1, GLint v2, GLint v3 ) = nullptr;
void ( APIENTRY* glUniform4iv )( GLint location, GLsizei count, const GLint* value ) = nullptr;
void ( APIENTRY* glUniform4ui )( GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3 ) = nullptr;
void ( APIENTRY* glUniform4uiv )( GLint location, GLsizei count, const GLuint* value ) = nullptr;
void ( APIENTRY* glUniformBlockBinding )( GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding ) =
	nullptr;
void ( APIENTRY* glUniformMatrix2dv )( GLint location, GLsizei count, GLboolean transpose, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix2fv )( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix2x3dv )( GLint location, GLsizei count, GLboolean transpose, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix2x3fv )( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix2x4dv )( GLint location, GLsizei count, GLboolean transpose, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix2x4fv )( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix3dv )( GLint location, GLsizei count, GLboolean transpose, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix3fv )( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix3x2dv )( GLint location, GLsizei count, GLboolean transpose, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix3x2fv )( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix3x4dv )( GLint location, GLsizei count, GLboolean transpose, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix3x4fv )( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix4dv )( GLint location, GLsizei count, GLboolean transpose, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix4fv )( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix4x2dv )( GLint location, GLsizei count, GLboolean transpose, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix4x2fv )( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix4x3dv )( GLint location, GLsizei count, GLboolean transpose, const GLdouble* value ) =
	nullptr;
void ( APIENTRY* glUniformMatrix4x3fv )( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value ) =
	nullptr;
void ( APIENTRY* glUniformSubroutinesuiv )( GLenum shadertype, GLsizei count, const GLuint* indices ) = nullptr;
GLboolean ( APIENTRY* glUnmapBuffer )( GLenum target ) = nullptr;
GLboolean ( APIENTRY* glUnmapNamedBuffer )( GLuint buffer ) = nullptr;
void ( APIENTRY* glUseProgram )( GLuint program ) = nullptr;
void ( APIENTRY* glUseProgramStages )( GLuint pipeline, GLbitfield stages, GLuint program ) = nullptr;
void ( APIENTRY* glValidateProgram )( GLuint program ) = nullptr;
void ( APIENTRY* glValidateProgramPipeline )( GLuint pipeline ) = nullptr;
void ( APIENTRY* glVertexArrayAttribBinding )( GLuint vaobj, GLuint attribindex, GLuint bindingindex ) = nullptr;
void ( APIENTRY* glVertexArrayAttribFormat )( GLuint vaobj, GLuint attribindex, GLint size, GLenum type,
											  GLboolean normalized, GLuint relativeoffset ) = nullptr;
void ( APIENTRY* glVertexArrayAttribIFormat )( GLuint vaobj, GLuint attribindex, GLint size, GLenum type,
											   GLuint relativeoffset ) = nullptr;
void ( APIENTRY* glVertexArrayAttribLFormat )( GLuint vaobj, GLuint attribindex, GLint size, GLenum type,
											   GLuint relativeoffset ) = nullptr;
void ( APIENTRY* glVertexArrayBindingDivisor )( GLuint vaobj, GLuint bindingindex, GLuint divisor ) = nullptr;
void ( APIENTRY* glVertexArrayElementBuffer )( GLuint vaobj, GLuint buffer ) = nullptr;
void ( APIENTRY* glVertexArrayVertexBuffer )( GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset,
											  GLsizei stride ) = nullptr;
void ( APIENTRY* glVertexArrayVertexBuffers )( GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers,
											   const GLintptr* offsets, const GLsizei* strides ) = nullptr;
void ( APIENTRY* glVertexAttrib1d )( GLuint index, GLdouble x ) = nullptr;
void ( APIENTRY* glVertexAttrib1dv )( GLuint index, const GLdouble* v ) = nullptr;
void ( APIENTRY* glVertexAttrib1f )( GLuint index, GLfloat x ) = nullptr;
void ( APIENTRY* glVertexAttrib1fv )( GLuint index, const GLfloat* v ) = nullptr;
void ( APIENTRY* glVertexAttrib1s )( GLuint index, GLshort x ) = nullptr;
void ( APIENTRY* glVertexAttrib1sv )( GLuint index, const GLshort* v ) = nullptr;
void ( APIENTRY* glVertexAttrib2d )( GLuint index, GLdouble x, GLdouble y ) = nullptr;
void ( APIENTRY* glVertexAttrib2dv )( GLuint index, const GLdouble* v ) = nullptr;
void ( APIENTRY* glVertexAttrib2f )( GLuint index, GLfloat x, GLfloat y ) = nullptr;
void ( APIENTRY* glVertexAttrib2fv )( GLuint index, const GLfloat* v ) = nullptr;
void ( APIENTRY* glVertexAttrib2s )( GLuint index, GLshort x, GLshort y ) = nullptr;
void ( APIENTRY* glVertexAttrib2sv )( GLuint index, const GLshort* v ) = nullptr;
void ( APIENTRY* glVertexAttrib3d )( GLuint index, GLdouble x, GLdouble y, GLdouble z ) = nullptr;
void ( APIENTRY* glVertexAttrib3dv )( GLuint index, const GLdouble* v ) = nullptr;
void ( APIENTRY* glVertexAttrib3f )( GLuint index, GLfloat x, GLfloat y, GLfloat z ) = nullptr;
void ( APIENTRY* glVertexAttrib3fv )( GLuint index, const GLfloat* v ) = nullptr;
void ( APIENTRY* glVertexAttrib3s )( GLuint index, GLshort x, GLshort y, GLshort z ) = nullptr;
void ( APIENTRY* glVertexAttrib3sv )( GLuint index, const GLshort* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4Nbv )( GLuint index, const GLbyte* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4Niv )( GLuint index, const GLint* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4Nsv )( GLuint index, const GLshort* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4Nub )( GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w ) = nullptr;
void ( APIENTRY* glVertexAttrib4Nubv )( GLuint index, const GLubyte* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4Nuiv )( GLuint index, const GLuint* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4Nusv )( GLuint index, const GLushort* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4bv )( GLuint index, const GLbyte* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4d )( GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w ) = nullptr;
void ( APIENTRY* glVertexAttrib4dv )( GLuint index, const GLdouble* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4f )( GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w ) = nullptr;
void ( APIENTRY* glVertexAttrib4fv )( GLuint index, const GLfloat* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4iv )( GLuint index, const GLint* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4s )( GLuint index, GLshort x, GLshort y, GLshort z, GLshort w ) = nullptr;
void ( APIENTRY* glVertexAttrib4sv )( GLuint index, const GLshort* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4ubv )( GLuint index, const GLubyte* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4uiv )( GLuint index, const GLuint* v ) = nullptr;
void ( APIENTRY* glVertexAttrib4usv )( GLuint index, const GLushort* v ) = nullptr;
void ( APIENTRY* glVertexAttribBinding )( GLuint attribindex, GLuint bindingindex ) = nullptr;
void ( APIENTRY* glVertexAttribDivisor )( GLuint index, GLuint divisor ) = nullptr;
void ( APIENTRY* glVertexAttribFormat )( GLuint attribindex, GLint size, GLenum type, GLboolean normalized,
										 GLuint relativeoffset ) = nullptr;
void ( APIENTRY* glVertexAttribI1i )( GLuint index, GLint x ) = nullptr;
void ( APIENTRY* glVertexAttribI1iv )( GLuint index, const GLint* v ) = nullptr;
void ( APIENTRY* glVertexAttribI1ui )( GLuint index, GLuint x ) = nullptr;
void ( APIENTRY* glVertexAttribI1uiv )( GLuint index, const GLuint* v ) = nullptr;
void ( APIENTRY* glVertexAttribI2i )( GLuint index, GLint x, GLint y ) = nullptr;
void ( APIENTRY* glVertexAttribI2iv )( GLuint index, const GLint* v ) = nullptr;
void ( APIENTRY* glVertexAttribI2ui )( GLuint index, GLuint x, GLuint y ) = nullptr;
void ( APIENTRY* glVertexAttribI2uiv )( GLuint index, const GLuint* v ) = nullptr;
void ( APIENTRY* glVertexAttribI3i )( GLuint index, GLint x, GLint y, GLint z ) = nullptr;
void ( APIENTRY* glVertexAttribI3iv )( GLuint index, const GLint* v ) = nullptr;
void ( APIENTRY* glVertexAttribI3ui )( GLuint index, GLuint x, GLuint y, GLuint z ) = nullptr;
void ( APIENTRY* glVertexAttribI3uiv )( GLuint index, const GLuint* v ) = nullptr;
void ( APIENTRY* glVertexAttribI4bv )( GLuint index, const GLbyte* v ) = nullptr;
void ( APIENTRY* glVertexAttribI4i )( GLuint index, GLint x, GLint y, GLint z, GLint w ) = nullptr;
void ( APIENTRY* glVertexAttribI4iv )( GLuint index, const GLint* v ) = nullptr;
void ( APIENTRY* glVertexAttribI4sv )( GLuint index, const GLshort* v ) = nullptr;
void ( APIENTRY* glVertexAttribI4ubv )( GLuint index, const GLubyte* v ) = nullptr;
void ( APIENTRY* glVertexAttribI4ui )( GLuint index, GLuint x, GLuint y, GLuint z, GLuint w ) = nullptr;
void ( APIENTRY* glVertexAttribI4uiv )( GLuint index, const GLuint* v ) = nullptr;
void ( APIENTRY* glVertexAttribI4usv )( GLuint index, const GLushort* v ) = nullptr;
void ( APIENTRY* glVertexAttribIFormat )( GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset ) =
	nullptr;
void ( APIENTRY* glVertexAttribIPointer )( GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer )
	= nullptr;
void ( APIENTRY* glVertexAttribL1d )( GLuint index, GLdouble x ) = nullptr;
void ( APIENTRY* glVertexAttribL1dv )( GLuint index, const GLdouble* v ) = nullptr;
void ( APIENTRY* glVertexAttribL2d )( GLuint index, GLdouble x, GLdouble y ) = nullptr;
void ( APIENTRY* glVertexAttribL2dv )( GLuint index, const GLdouble* v ) = nullptr;
void ( APIENTRY* glVertexAttribL3d )( GLuint index, GLdouble x, GLdouble y, GLdouble z ) = nullptr;
void ( APIENTRY* glVertexAttribL3dv )( GLuint index, const GLdouble* v ) = nullptr;
void ( APIENTRY* glVertexAttribL4d )( GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w ) = nullptr;
void ( APIENTRY* glVertexAttribL4dv )( GLuint index, const GLdouble* v ) = nullptr;
void ( APIENTRY* glVertexAttribLFormat )( GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset ) =
	nullptr;
void ( APIENTRY* glVertexAttribLPointer )( GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer )
	= nullptr;
void ( APIENTRY* glVertexAttribP1ui )( GLuint index, GLenum type, GLboolean normalized, GLuint value ) = nullptr;
void ( APIENTRY* glVertexAttribP1uiv )( GLuint index, GLenum type, GLboolean normalized, const GLuint* value ) =
	nullptr;
void ( APIENTRY* glVertexAttribP2ui )( GLuint index, GLenum type, GLboolean normalized, GLuint value ) = nullptr;
void ( APIENTRY* glVertexAttribP2uiv )( GLuint index, GLenum type, GLboolean normalized, const GLuint* value ) =
	nullptr;
void ( APIENTRY* glVertexAttribP3ui )( GLuint index, GLenum type, GLboolean normalized, GLuint value ) = nullptr;
void ( APIENTRY* glVertexAttribP3uiv )( GLuint index, GLenum type, GLboolean normalized, const GLuint* value ) =
	nullptr;
void ( APIENTRY* glVertexAttribP4ui )( GLuint index, GLenum type, GLboolean normalized, GLuint value ) = nullptr;
void ( APIENTRY* glVertexAttribP4uiv )( GLuint index, GLenum type, GLboolean normalized, const GLuint* value ) =
	nullptr;
void ( APIENTRY* glVertexAttribPointer )( GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride,
										  const void* pointer ) = nullptr;
void ( APIENTRY* glVertexBindingDivisor )( GLuint bindingindex, GLuint divisor ) = nullptr;
void ( APIENTRY* glVertexP2ui )( GLenum type, GLuint value ) = nullptr;
void ( APIENTRY* glVertexP2uiv )( GLenum type, const GLuint* value ) = nullptr;
void ( APIENTRY* glVertexP3ui )( GLenum type, GLuint value ) = nullptr;
void ( APIENTRY* glVertexP3uiv )( GLenum type, const GLuint* value ) = nullptr;
void ( APIENTRY* glVertexP4ui )( GLenum type, GLuint value ) = nullptr;
void ( APIENTRY* glVertexP4uiv )( GLenum type, const GLuint* value ) = nullptr;
void ( APIENTRY* glViewport )( GLint x, GLint y, GLsizei width, GLsizei height ) = nullptr;
void ( APIENTRY* glViewportArrayv )( GLuint first, GLsizei count, const GLfloat* v ) = nullptr;
void ( APIENTRY* glViewportIndexedf )( GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h ) = nullptr;
void ( APIENTRY* glViewportIndexedfv )( GLuint index, const GLfloat* v ) = nullptr;
void ( APIENTRY* glWaitSync )( GLsync sync, GLbitfield flags, GLuint64 timeout ) = nullptr;


void gl_init()
{
	// com_printf( "Initializing OpenGL function pointers...\n" );

	gl_open_lib();

	glActiveShaderProgram = static_cast<decltype( glActiveShaderProgram )>( load( "glActiveShaderProgram" ) );
	glActiveTexture = static_cast<decltype( glActiveTexture )>( load( "glActiveTexture" ) );
	glAttachShader = static_cast<decltype( glAttachShader )>( load( "glAttachShader" ) );
	glBeginConditionalRender = static_cast<decltype( glBeginConditionalRender )>( load( "glBeginConditionalRender" ) );
	glBeginQuery = static_cast<decltype( glBeginQuery )>( load( "glBeginQuery" ) );
	glBeginQueryIndexed = static_cast<decltype( glBeginQueryIndexed )>( load( "glBeginQueryIndexed" ) );
	glBeginTransformFeedback = static_cast<decltype( glBeginTransformFeedback )>( load( "glBeginTransformFeedback" ) );
	glBindAttribLocation = static_cast<decltype( glBindAttribLocation )>( load( "glBindAttribLocation" ) );
	glBindBuffer = static_cast<decltype( glBindBuffer )>( load( "glBindBuffer" ) );
	glBindBufferBase = static_cast<decltype( glBindBufferBase )>( load( "glBindBufferBase" ) );
	glBindBufferRange = static_cast<decltype( glBindBufferRange )>( load( "glBindBufferRange" ) );
	glBindBuffersBase = static_cast<decltype( glBindBuffersBase )>( load( "glBindBuffersBase" ) );
	glBindBuffersRange = static_cast<decltype( glBindBuffersRange )>( load( "glBindBuffersRange" ) );
	glBindFragDataLocation = static_cast<decltype( glBindFragDataLocation )>( load( "glBindFragDataLocation" ) );
	glBindFragDataLocationIndexed = static_cast<decltype( glBindFragDataLocationIndexed )>( load(
		"glBindFragDataLocationIndexed" ) );
	glBindFramebuffer = static_cast<decltype( glBindFramebuffer )>( load( "glBindFramebuffer" ) );
	glBindImageTexture = static_cast<decltype( glBindImageTexture )>( load( "glBindImageTexture" ) );
	glBindImageTextures = static_cast<decltype( glBindImageTextures )>( load( "glBindImageTextures" ) );
	glBindProgramPipeline = static_cast<decltype( glBindProgramPipeline )>( load( "glBindProgramPipeline" ) );
	glBindRenderbuffer = static_cast<decltype( glBindRenderbuffer )>( load( "glBindRenderbuffer" ) );
	glBindSampler = static_cast<decltype( glBindSampler )>( load( "glBindSampler" ) );
	glBindSamplers = static_cast<decltype( glBindSamplers )>( load( "glBindSamplers" ) );
	glBindTexture = static_cast<decltype( glBindTexture )>( load( "glBindTexture" ) );
	glBindTextureUnit = static_cast<decltype( glBindTextureUnit )>( load( "glBindTextureUnit" ) );
	glBindTextures = static_cast<decltype( glBindTextures )>( load( "glBindTextures" ) );
	glBindTransformFeedback = static_cast<decltype( glBindTransformFeedback )>( load( "glBindTransformFeedback" ) );
	glBindVertexArray = static_cast<decltype( glBindVertexArray )>( load( "glBindVertexArray" ) );
	glBindVertexBuffer = static_cast<decltype( glBindVertexBuffer )>( load( "glBindVertexBuffer" ) );
	glBindVertexBuffers = static_cast<decltype( glBindVertexBuffers )>( load( "glBindVertexBuffers" ) );
	glBlendColor = static_cast<decltype( glBlendColor )>( load( "glBlendColor" ) );
	glBlendEquation = static_cast<decltype( glBlendEquation )>( load( "glBlendEquation" ) );
	glBlendEquationSeparate = static_cast<decltype( glBlendEquationSeparate )>( load( "glBlendEquationSeparate" ) );
	glBlendEquationSeparatei = static_cast<decltype( glBlendEquationSeparatei )>( load( "glBlendEquationSeparatei" ) );
	glBlendEquationi = static_cast<decltype( glBlendEquationi )>( load( "glBlendEquationi" ) );
	glBlendFunc = static_cast<decltype( glBlendFunc )>( load( "glBlendFunc" ) );
	glBlendFuncSeparate = static_cast<decltype( glBlendFuncSeparate )>( load( "glBlendFuncSeparate" ) );
	glBlendFuncSeparatei = static_cast<decltype( glBlendFuncSeparatei )>( load( "glBlendFuncSeparatei" ) );
	glBlendFunci = static_cast<decltype( glBlendFunci )>( load( "glBlendFunci" ) );
	glBlitFramebuffer = static_cast<decltype( glBlitFramebuffer )>( load( "glBlitFramebuffer" ) );
	glBlitNamedFramebuffer = static_cast<decltype( glBlitNamedFramebuffer )>( load( "glBlitNamedFramebuffer" ) );
	glBufferData = static_cast<decltype( glBufferData )>( load( "glBufferData" ) );
	glBufferStorage = static_cast<decltype( glBufferStorage )>( load( "glBufferStorage" ) );
	glBufferSubData = static_cast<decltype( glBufferSubData )>( load( "glBufferSubData" ) );
	glCheckFramebufferStatus = static_cast<decltype( glCheckFramebufferStatus )>( load( "glCheckFramebufferStatus" ) );
	glCheckNamedFramebufferStatus = static_cast<decltype( glCheckNamedFramebufferStatus )>( load(
		"glCheckNamedFramebufferStatus" ) );
	glClampColor = static_cast<decltype( glClampColor )>( load( "glClampColor" ) );
	glClear = static_cast<decltype( glClear )>( load( "glClear" ) );
	glClearBufferData = static_cast<decltype( glClearBufferData )>( load( "glClearBufferData" ) );
	glClearBufferSubData = static_cast<decltype( glClearBufferSubData )>( load( "glClearBufferSubData" ) );
	glClearBufferfi = static_cast<decltype( glClearBufferfi )>( load( "glClearBufferfi" ) );
	glClearBufferfv = static_cast<decltype( glClearBufferfv )>( load( "glClearBufferfv" ) );
	glClearBufferiv = static_cast<decltype( glClearBufferiv )>( load( "glClearBufferiv" ) );
	glClearBufferuiv = static_cast<decltype( glClearBufferuiv )>( load( "glClearBufferuiv" ) );
	glClearColor = static_cast<decltype( glClearColor )>( load( "glClearColor" ) );
	glClearDepth = static_cast<decltype( glClearDepth )>( load( "glClearDepth" ) );
	glClearDepthf = static_cast<decltype( glClearDepthf )>( load( "glClearDepthf" ) );
	glClearNamedBufferData = static_cast<decltype( glClearNamedBufferData )>( load( "glClearNamedBufferData" ) );
	glClearNamedBufferSubData = static_cast<decltype( glClearNamedBufferSubData )>( load( "glClearNamedBufferSubData" )
	);
	glClearNamedFramebufferfi = static_cast<decltype( glClearNamedFramebufferfi )>( load( "glClearNamedFramebufferfi" )
	);
	glClearNamedFramebufferfv = static_cast<decltype( glClearNamedFramebufferfv )>( load( "glClearNamedFramebufferfv" )
	);
	glClearNamedFramebufferiv = static_cast<decltype( glClearNamedFramebufferiv )>( load( "glClearNamedFramebufferiv" )
	);
	glClearNamedFramebufferuiv = static_cast<decltype( glClearNamedFramebufferuiv )>( load(
		"glClearNamedFramebufferuiv" ) );
	glClearStencil = static_cast<decltype( glClearStencil )>( load( "glClearStencil" ) );
	glClearTexImage = static_cast<decltype( glClearTexImage )>( load( "glClearTexImage" ) );
	glClearTexSubImage = static_cast<decltype( glClearTexSubImage )>( load( "glClearTexSubImage" ) );
	glClientWaitSync = static_cast<decltype( glClientWaitSync )>( load( "glClientWaitSync" ) );
	glClipControl = static_cast<decltype( glClipControl )>( load( "glClipControl" ) );
	glColorMask = static_cast<decltype( glColorMask )>( load( "glColorMask" ) );
	glColorMaski = static_cast<decltype( glColorMaski )>( load( "glColorMaski" ) );
	glColorP3ui = static_cast<decltype( glColorP3ui )>( load( "glColorP3ui" ) );
	glColorP3uiv = static_cast<decltype( glColorP3uiv )>( load( "glColorP3uiv" ) );
	glColorP4ui = static_cast<decltype( glColorP4ui )>( load( "glColorP4ui" ) );
	glColorP4uiv = static_cast<decltype( glColorP4uiv )>( load( "glColorP4uiv" ) );
	glCompileShader = static_cast<decltype( glCompileShader )>( load( "glCompileShader" ) );
	glCompressedTexImage1D = static_cast<decltype( glCompressedTexImage1D )>( load( "glCompressedTexImage1D" ) );
	glCompressedTexImage2D = static_cast<decltype( glCompressedTexImage2D )>( load( "glCompressedTexImage2D" ) );
	glCompressedTexImage3D = static_cast<decltype( glCompressedTexImage3D )>( load( "glCompressedTexImage3D" ) );
	glCompressedTexSubImage1D = static_cast<decltype( glCompressedTexSubImage1D )>( load( "glCompressedTexSubImage1D" )
	);
	glCompressedTexSubImage2D = static_cast<decltype( glCompressedTexSubImage2D )>( load( "glCompressedTexSubImage2D" )
	);
	glCompressedTexSubImage3D = static_cast<decltype( glCompressedTexSubImage3D )>( load( "glCompressedTexSubImage3D" )
	);
	glCompressedTextureSubImage1D = static_cast<decltype( glCompressedTextureSubImage1D )>( load(
		"glCompressedTextureSubImage1D" ) );
	glCompressedTextureSubImage2D = static_cast<decltype( glCompressedTextureSubImage2D )>( load(
		"glCompressedTextureSubImage2D" ) );
	glCompressedTextureSubImage3D = static_cast<decltype( glCompressedTextureSubImage3D )>( load(
		"glCompressedTextureSubImage3D" ) );
	glCopyBufferSubData = static_cast<decltype( glCopyBufferSubData )>( load( "glCopyBufferSubData" ) );
	glCopyImageSubData = static_cast<decltype( glCopyImageSubData )>( load( "glCopyImageSubData" ) );
	glCopyNamedBufferSubData = static_cast<decltype( glCopyNamedBufferSubData )>( load( "glCopyNamedBufferSubData" ) );
	glCopyTexImage1D = static_cast<decltype( glCopyTexImage1D )>( load( "glCopyTexImage1D" ) );
	glCopyTexImage2D = static_cast<decltype( glCopyTexImage2D )>( load( "glCopyTexImage2D" ) );
	glCopyTexSubImage1D = static_cast<decltype( glCopyTexSubImage1D )>( load( "glCopyTexSubImage1D" ) );
	glCopyTexSubImage2D = static_cast<decltype( glCopyTexSubImage2D )>( load( "glCopyTexSubImage2D" ) );
	glCopyTexSubImage3D = static_cast<decltype( glCopyTexSubImage3D )>( load( "glCopyTexSubImage3D" ) );
	glCopyTextureSubImage1D = static_cast<decltype( glCopyTextureSubImage1D )>( load( "glCopyTextureSubImage1D" ) );
	glCopyTextureSubImage2D = static_cast<decltype( glCopyTextureSubImage2D )>( load( "glCopyTextureSubImage2D" ) );
	glCopyTextureSubImage3D = static_cast<decltype( glCopyTextureSubImage3D )>( load( "glCopyTextureSubImage3D" ) );
	glCreateBuffers = static_cast<decltype( glCreateBuffers )>( load( "glCreateBuffers" ) );
	glCreateFramebuffers = static_cast<decltype( glCreateFramebuffers )>( load( "glCreateFramebuffers" ) );
	glCreateProgram = static_cast<decltype( glCreateProgram )>( load( "glCreateProgram" ) );
	glCreateProgramPipelines = static_cast<decltype( glCreateProgramPipelines )>( load( "glCreateProgramPipelines" ) );
	glCreateQueries = static_cast<decltype( glCreateQueries )>( load( "glCreateQueries" ) );
	glCreateRenderbuffers = static_cast<decltype( glCreateRenderbuffers )>( load( "glCreateRenderbuffers" ) );
	glCreateSamplers = static_cast<decltype( glCreateSamplers )>( load( "glCreateSamplers" ) );
	glCreateShader = static_cast<decltype( glCreateShader )>( load( "glCreateShader" ) );
	glCreateShaderProgramv = static_cast<decltype( glCreateShaderProgramv )>( load( "glCreateShaderProgramv" ) );
	glCreateTextures = static_cast<decltype( glCreateTextures )>( load( "glCreateTextures" ) );
	glCreateTransformFeedbacks = static_cast<decltype( glCreateTransformFeedbacks )>( load(
		"glCreateTransformFeedbacks" ) );
	glCreateVertexArrays = static_cast<decltype( glCreateVertexArrays )>( load( "glCreateVertexArrays" ) );
	glCullFace = static_cast<decltype( glCullFace )>( load( "glCullFace" ) );
	glDebugMessageCallback = static_cast<decltype( glDebugMessageCallback )>( load( "glDebugMessageCallback" ) );
	glDebugMessageControl = static_cast<decltype( glDebugMessageControl )>( load( "glDebugMessageControl" ) );
	glDebugMessageInsert = static_cast<decltype( glDebugMessageInsert )>( load( "glDebugMessageInsert" ) );
	glDeleteBuffers = static_cast<decltype( glDeleteBuffers )>( load( "glDeleteBuffers" ) );
	glDeleteFramebuffers = static_cast<decltype( glDeleteFramebuffers )>( load( "glDeleteFramebuffers" ) );
	glDeleteProgram = static_cast<decltype( glDeleteProgram )>( load( "glDeleteProgram" ) );
	glDeleteProgramPipelines = static_cast<decltype( glDeleteProgramPipelines )>( load( "glDeleteProgramPipelines" ) );
	glDeleteQueries = static_cast<decltype( glDeleteQueries )>( load( "glDeleteQueries" ) );
	glDeleteRenderbuffers = static_cast<decltype( glDeleteRenderbuffers )>( load( "glDeleteRenderbuffers" ) );
	glDeleteSamplers = static_cast<decltype( glDeleteSamplers )>( load( "glDeleteSamplers" ) );
	glDeleteShader = static_cast<decltype( glDeleteShader )>( load( "glDeleteShader" ) );
	glDeleteSync = static_cast<decltype( glDeleteSync )>( load( "glDeleteSync" ) );
	glDeleteTextures = static_cast<decltype( glDeleteTextures )>( load( "glDeleteTextures" ) );
	glDeleteTransformFeedbacks = static_cast<decltype( glDeleteTransformFeedbacks )>( load(
		"glDeleteTransformFeedbacks" ) );
	glDeleteVertexArrays = static_cast<decltype( glDeleteVertexArrays )>( load( "glDeleteVertexArrays" ) );
	glDepthFunc = static_cast<decltype( glDepthFunc )>( load( "glDepthFunc" ) );
	glDepthMask = static_cast<decltype( glDepthMask )>( load( "glDepthMask" ) );
	glDepthRange = static_cast<decltype( glDepthRange )>( load( "glDepthRange" ) );
	glDepthRangeArrayv = static_cast<decltype( glDepthRangeArrayv )>( load( "glDepthRangeArrayv" ) );
	glDepthRangeIndexed = static_cast<decltype( glDepthRangeIndexed )>( load( "glDepthRangeIndexed" ) );
	glDepthRangef = static_cast<decltype( glDepthRangef )>( load( "glDepthRangef" ) );
	glDetachShader = static_cast<decltype( glDetachShader )>( load( "glDetachShader" ) );
	glDisable = static_cast<decltype( glDisable )>( load( "glDisable" ) );
	glDisableVertexArrayAttrib = static_cast<decltype( glDisableVertexArrayAttrib )>( load(
		"glDisableVertexArrayAttrib" ) );
	glDisableVertexAttribArray = static_cast<decltype( glDisableVertexAttribArray )>( load(
		"glDisableVertexAttribArray" ) );
	glDisablei = static_cast<decltype( glDisablei )>( load( "glDisablei" ) );
	glDispatchCompute = static_cast<decltype( glDispatchCompute )>( load( "glDispatchCompute" ) );
	glDispatchComputeIndirect = static_cast<decltype( glDispatchComputeIndirect )>( load( "glDispatchComputeIndirect" )
	);
	glDrawArrays = static_cast<decltype( glDrawArrays )>( load( "glDrawArrays" ) );
	glDrawArraysIndirect = static_cast<decltype( glDrawArraysIndirect )>( load( "glDrawArraysIndirect" ) );
	glDrawArraysInstanced = static_cast<decltype( glDrawArraysInstanced )>( load( "glDrawArraysInstanced" ) );
	glDrawArraysInstancedBaseInstance = static_cast<decltype( glDrawArraysInstancedBaseInstance )>( load(
		"glDrawArraysInstancedBaseInstance" ) );
	glDrawBuffer = static_cast<decltype( glDrawBuffer )>( load( "glDrawBuffer" ) );
	glDrawBuffers = static_cast<decltype( glDrawBuffers )>( load( "glDrawBuffers" ) );
	glDrawElements = static_cast<decltype( glDrawElements )>( load( "glDrawElements" ) );
	glDrawElementsBaseVertex = static_cast<decltype( glDrawElementsBaseVertex )>( load( "glDrawElementsBaseVertex" ) );
	glDrawElementsIndirect = static_cast<decltype( glDrawElementsIndirect )>( load( "glDrawElementsIndirect" ) );
	glDrawElementsInstanced = static_cast<decltype( glDrawElementsInstanced )>( load( "glDrawElementsInstanced" ) );
	glDrawElementsInstancedBaseInstance = static_cast<decltype( glDrawElementsInstancedBaseInstance )>( load(
		"glDrawElementsInstancedBaseInstance" ) );
	glDrawElementsInstancedBaseVertex = static_cast<decltype( glDrawElementsInstancedBaseVertex )>( load(
		"glDrawElementsInstancedBaseVertex" ) );
	glDrawElementsInstancedBaseVertexBaseInstance = static_cast<decltype( glDrawElementsInstancedBaseVertexBaseInstance
	)>( load(
		"glDrawElementsInstancedBaseVertexBaseInstance" ) );
	glDrawRangeElements = static_cast<decltype( glDrawRangeElements )>( load( "glDrawRangeElements" ) );
	glDrawRangeElementsBaseVertex = static_cast<decltype( glDrawRangeElementsBaseVertex )>( load(
		"glDrawRangeElementsBaseVertex" ) );
	glDrawTransformFeedback = static_cast<decltype( glDrawTransformFeedback )>( load( "glDrawTransformFeedback" ) );
	glDrawTransformFeedbackInstanced = static_cast<decltype( glDrawTransformFeedbackInstanced )>( load(
		"glDrawTransformFeedbackInstanced" ) );
	glDrawTransformFeedbackStream = static_cast<decltype( glDrawTransformFeedbackStream )>( load(
		"glDrawTransformFeedbackStream" ) );
	glDrawTransformFeedbackStreamInstanced = static_cast<decltype( glDrawTransformFeedbackStreamInstanced )>( load(
		"glDrawTransformFeedbackStreamInstanced" ) );
	glEnable = static_cast<decltype( glEnable )>( load( "glEnable" ) );
	glEnableVertexArrayAttrib = static_cast<decltype( glEnableVertexArrayAttrib )>( load( "glEnableVertexArrayAttrib" )
	);
	glEnableVertexAttribArray = static_cast<decltype( glEnableVertexAttribArray )>( load( "glEnableVertexAttribArray" )
	);
	glEnablei = static_cast<decltype( glEnablei )>( load( "glEnablei" ) );
	glEndConditionalRender = static_cast<decltype( glEndConditionalRender )>( load( "glEndConditionalRender" ) );
	glEndQuery = static_cast<decltype( glEndQuery )>( load( "glEndQuery" ) );
	glEndQueryIndexed = static_cast<decltype( glEndQueryIndexed )>( load( "glEndQueryIndexed" ) );
	glEndTransformFeedback = static_cast<decltype( glEndTransformFeedback )>( load( "glEndTransformFeedback" ) );
	glFenceSync = static_cast<decltype( glFenceSync )>( load( "glFenceSync" ) );
	glFinish = static_cast<decltype( glFinish )>( load( "glFinish" ) );
	glFlush = static_cast<decltype( glFlush )>( load( "glFlush" ) );
	glFlushMappedBufferRange = static_cast<decltype( glFlushMappedBufferRange )>( load( "glFlushMappedBufferRange" ) );
	glFlushMappedNamedBufferRange = static_cast<decltype( glFlushMappedNamedBufferRange )>( load(
		"glFlushMappedNamedBufferRange" ) );
	glFramebufferParameteri = static_cast<decltype( glFramebufferParameteri )>( load( "glFramebufferParameteri" ) );
	glFramebufferRenderbuffer = static_cast<decltype( glFramebufferRenderbuffer )>( load( "glFramebufferRenderbuffer" )
	);
	glFramebufferTexture = static_cast<decltype( glFramebufferTexture )>( load( "glFramebufferTexture" ) );
	glFramebufferTexture1D = static_cast<decltype( glFramebufferTexture1D )>( load( "glFramebufferTexture1D" ) );
	glFramebufferTexture2D = static_cast<decltype( glFramebufferTexture2D )>( load( "glFramebufferTexture2D" ) );
	glFramebufferTexture3D = static_cast<decltype( glFramebufferTexture3D )>( load( "glFramebufferTexture3D" ) );
	glFramebufferTextureLayer = static_cast<decltype( glFramebufferTextureLayer )>( load( "glFramebufferTextureLayer" )
	);
	glFrontFace = static_cast<decltype( glFrontFace )>( load( "glFrontFace" ) );
	glGenBuffers = static_cast<decltype( glGenBuffers )>( load( "glGenBuffers" ) );
	glGenFramebuffers = static_cast<decltype( glGenFramebuffers )>( load( "glGenFramebuffers" ) );
	glGenProgramPipelines = static_cast<decltype( glGenProgramPipelines )>( load( "glGenProgramPipelines" ) );
	glGenQueries = static_cast<decltype( glGenQueries )>( load( "glGenQueries" ) );
	glGenRenderbuffers = static_cast<decltype( glGenRenderbuffers )>( load( "glGenRenderbuffers" ) );
	glGenSamplers = static_cast<decltype( glGenSamplers )>( load( "glGenSamplers" ) );
	glGenTextures = static_cast<decltype( glGenTextures )>( load( "glGenTextures" ) );
	glGenTransformFeedbacks = static_cast<decltype( glGenTransformFeedbacks )>( load( "glGenTransformFeedbacks" ) );
	glGenVertexArrays = static_cast<decltype( glGenVertexArrays )>( load( "glGenVertexArrays" ) );
	glGenerateMipmap = static_cast<decltype( glGenerateMipmap )>( load( "glGenerateMipmap" ) );
	glGenerateTextureMipmap = static_cast<decltype( glGenerateTextureMipmap )>( load( "glGenerateTextureMipmap" ) );
	glGetActiveAtomicCounterBufferiv = static_cast<decltype( glGetActiveAtomicCounterBufferiv )>( load(
		"glGetActiveAtomicCounterBufferiv" ) );
	glGetActiveAttrib = static_cast<decltype( glGetActiveAttrib )>( load( "glGetActiveAttrib" ) );
	glGetActiveSubroutineName = static_cast<decltype( glGetActiveSubroutineName )>( load( "glGetActiveSubroutineName" )
	);
	glGetActiveSubroutineUniformName = static_cast<decltype( glGetActiveSubroutineUniformName )>( load(
		"glGetActiveSubroutineUniformName" ) );
	glGetActiveSubroutineUniformiv = static_cast<decltype( glGetActiveSubroutineUniformiv )>( load(
		"glGetActiveSubroutineUniformiv" ) );
	glGetActiveUniform = static_cast<decltype( glGetActiveUniform )>( load( "glGetActiveUniform" ) );
	glGetActiveUniformBlockName = static_cast<decltype( glGetActiveUniformBlockName )>( load(
		"glGetActiveUniformBlockName" ) );
	glGetActiveUniformBlockiv = static_cast<decltype( glGetActiveUniformBlockiv )>( load( "glGetActiveUniformBlockiv" )
	);
	glGetActiveUniformName = static_cast<decltype( glGetActiveUniformName )>( load( "glGetActiveUniformName" ) );
	glGetActiveUniformsiv = static_cast<decltype( glGetActiveUniformsiv )>( load( "glGetActiveUniformsiv" ) );
	glGetAttachedShaders = static_cast<decltype( glGetAttachedShaders )>( load( "glGetAttachedShaders" ) );
	glGetAttribLocation = static_cast<decltype( glGetAttribLocation )>( load( "glGetAttribLocation" ) );
	glGetBooleani_v = static_cast<decltype( glGetBooleani_v )>( load( "glGetBooleani_v" ) );
	glGetBooleanv = static_cast<decltype( glGetBooleanv )>( load( "glGetBooleanv" ) );
	glGetBufferParameteri64v = static_cast<decltype( glGetBufferParameteri64v )>( load( "glGetBufferParameteri64v" ) );
	glGetBufferParameteriv = static_cast<decltype( glGetBufferParameteriv )>( load( "glGetBufferParameteriv" ) );
	glGetBufferPointerv = static_cast<decltype( glGetBufferPointerv )>( load( "glGetBufferPointerv" ) );
	glGetBufferSubData = static_cast<decltype( glGetBufferSubData )>( load( "glGetBufferSubData" ) );
	glGetCompressedTexImage = static_cast<decltype( glGetCompressedTexImage )>( load( "glGetCompressedTexImage" ) );
	glGetCompressedTextureImage = static_cast<decltype( glGetCompressedTextureImage )>( load(
		"glGetCompressedTextureImage" ) );
	glGetCompressedTextureSubImage = static_cast<decltype( glGetCompressedTextureSubImage )>( load(
		"glGetCompressedTextureSubImage" ) );
	glGetDebugMessageLog = static_cast<decltype( glGetDebugMessageLog )>( load( "glGetDebugMessageLog" ) );
	glGetDoublei_v = static_cast<decltype( glGetDoublei_v )>( load( "glGetDoublei_v" ) );
	glGetDoublev = static_cast<decltype( glGetDoublev )>( load( "glGetDoublev" ) );
	glGetError = static_cast<decltype( glGetError )>( load( "glGetError" ) );
	glGetFloati_v = static_cast<decltype( glGetFloati_v )>( load( "glGetFloati_v" ) );
	glGetFloatv = static_cast<decltype( glGetFloatv )>( load( "glGetFloatv" ) );
	glGetFragDataIndex = static_cast<decltype( glGetFragDataIndex )>( load( "glGetFragDataIndex" ) );
	glGetFragDataLocation = static_cast<decltype( glGetFragDataLocation )>( load( "glGetFragDataLocation" ) );
	glGetFramebufferAttachmentParameteriv = static_cast<decltype( glGetFramebufferAttachmentParameteriv )>( load(
		"glGetFramebufferAttachmentParameteriv" ) );
	glGetFramebufferParameteriv = static_cast<decltype( glGetFramebufferParameteriv )>( load(
		"glGetFramebufferParameteriv" ) );
	glGetGraphicsResetStatus = static_cast<decltype( glGetGraphicsResetStatus )>( load( "glGetGraphicsResetStatus" ) );
	glGetInteger64i_v = static_cast<decltype( glGetInteger64i_v )>( load( "glGetInteger64i_v" ) );
	glGetInteger64v = static_cast<decltype( glGetInteger64v )>( load( "glGetInteger64v" ) );
	glGetIntegeri_v = static_cast<decltype( glGetIntegeri_v )>( load( "glGetIntegeri_v" ) );
	glGetIntegerv = static_cast<decltype( glGetIntegerv )>( load( "glGetIntegerv" ) );
	glGetInternalformati64v = static_cast<decltype( glGetInternalformati64v )>( load( "glGetInternalformati64v" ) );
	glGetInternalformativ = static_cast<decltype( glGetInternalformativ )>( load( "glGetInternalformativ" ) );
	glGetMultisamplefv = static_cast<decltype( glGetMultisamplefv )>( load( "glGetMultisamplefv" ) );
	glGetNamedBufferParameteri64v = static_cast<decltype( glGetNamedBufferParameteri64v )>( load(
		"glGetNamedBufferParameteri64v" ) );
	glGetNamedBufferParameteriv = static_cast<decltype( glGetNamedBufferParameteriv )>( load(
		"glGetNamedBufferParameteriv" ) );
	glGetNamedBufferPointerv = static_cast<decltype( glGetNamedBufferPointerv )>( load( "glGetNamedBufferPointerv" ) );
	glGetNamedBufferSubData = static_cast<decltype( glGetNamedBufferSubData )>( load( "glGetNamedBufferSubData" ) );
	glGetNamedFramebufferAttachmentParameteriv = static_cast<decltype( glGetNamedFramebufferAttachmentParameteriv )>(
		load( "glGetNamedFramebufferAttachmentParameteriv" ) );
	glGetNamedFramebufferParameteriv = static_cast<decltype( glGetNamedFramebufferParameteriv )>( load(
		"glGetNamedFramebufferParameteriv" ) );
	glGetNamedRenderbufferParameteriv = static_cast<decltype( glGetNamedRenderbufferParameteriv )>( load(
		"glGetNamedRenderbufferParameteriv" ) );
	glGetObjectLabel = static_cast<decltype( glGetObjectLabel )>( load( "glGetObjectLabel" ) );
	glGetObjectPtrLabel = static_cast<decltype( glGetObjectPtrLabel )>( load( "glGetObjectPtrLabel" ) );
	glGetPointerv = static_cast<decltype( glGetPointerv )>( load( "glGetPointerv" ) );
	glGetProgramBinary = static_cast<decltype( glGetProgramBinary )>( load( "glGetProgramBinary" ) );
	glGetProgramInfoLog = static_cast<decltype( glGetProgramInfoLog )>( load( "glGetProgramInfoLog" ) );
	glGetProgramInterfaceiv = static_cast<decltype( glGetProgramInterfaceiv )>( load( "glGetProgramInterfaceiv" ) );
	glGetProgramPipelineInfoLog = static_cast<decltype( glGetProgramPipelineInfoLog )>( load(
		"glGetProgramPipelineInfoLog" ) );
	glGetProgramPipelineiv = static_cast<decltype( glGetProgramPipelineiv )>( load( "glGetProgramPipelineiv" ) );
	glGetProgramResourceIndex = static_cast<decltype( glGetProgramResourceIndex )>( load( "glGetProgramResourceIndex" )
	);
	glGetProgramResourceLocation = static_cast<decltype( glGetProgramResourceLocation )>( load(
		"glGetProgramResourceLocation" ) );
	glGetProgramResourceLocationIndex = static_cast<decltype( glGetProgramResourceLocationIndex )>( load(
		"glGetProgramResourceLocationIndex" ) );
	glGetProgramResourceName = static_cast<decltype( glGetProgramResourceName )>( load( "glGetProgramResourceName" ) );
	glGetProgramResourceiv = static_cast<decltype( glGetProgramResourceiv )>( load( "glGetProgramResourceiv" ) );
	glGetProgramStageiv = static_cast<decltype( glGetProgramStageiv )>( load( "glGetProgramStageiv" ) );
	glGetProgramiv = static_cast<decltype( glGetProgramiv )>( load( "glGetProgramiv" ) );
	glGetQueryBufferObjecti64v = static_cast<decltype( glGetQueryBufferObjecti64v )>( load(
		"glGetQueryBufferObjecti64v" ) );
	glGetQueryBufferObjectiv = static_cast<decltype( glGetQueryBufferObjectiv )>( load( "glGetQueryBufferObjectiv" ) );
	glGetQueryBufferObjectui64v = static_cast<decltype( glGetQueryBufferObjectui64v )>( load(
		"glGetQueryBufferObjectui64v" ) );
	glGetQueryBufferObjectuiv = static_cast<decltype( glGetQueryBufferObjectuiv )>( load( "glGetQueryBufferObjectuiv" )
	);
	glGetQueryIndexediv = static_cast<decltype( glGetQueryIndexediv )>( load( "glGetQueryIndexediv" ) );
	glGetQueryObjecti64v = static_cast<decltype( glGetQueryObjecti64v )>( load( "glGetQueryObjecti64v" ) );
	glGetQueryObjectiv = static_cast<decltype( glGetQueryObjectiv )>( load( "glGetQueryObjectiv" ) );
	glGetQueryObjectui64v = static_cast<decltype( glGetQueryObjectui64v )>( load( "glGetQueryObjectui64v" ) );
	glGetQueryObjectuiv = static_cast<decltype( glGetQueryObjectuiv )>( load( "glGetQueryObjectuiv" ) );
	glGetQueryiv = static_cast<decltype( glGetQueryiv )>( load( "glGetQueryiv" ) );
	glGetRenderbufferParameteriv = static_cast<decltype( glGetRenderbufferParameteriv )>( load(
		"glGetRenderbufferParameteriv" ) );
	glGetSamplerParameterIiv = static_cast<decltype( glGetSamplerParameterIiv )>( load( "glGetSamplerParameterIiv" ) );
	glGetSamplerParameterIuiv = static_cast<decltype( glGetSamplerParameterIuiv )>( load( "glGetSamplerParameterIuiv" )
	);
	glGetSamplerParameterfv = static_cast<decltype( glGetSamplerParameterfv )>( load( "glGetSamplerParameterfv" ) );
	glGetSamplerParameteriv = static_cast<decltype( glGetSamplerParameteriv )>( load( "glGetSamplerParameteriv" ) );
	glGetShaderInfoLog = static_cast<decltype( glGetShaderInfoLog )>( load( "glGetShaderInfoLog" ) );
	glGetShaderPrecisionFormat = static_cast<decltype( glGetShaderPrecisionFormat )>( load(
		"glGetShaderPrecisionFormat" ) );
	glGetShaderSource = static_cast<decltype( glGetShaderSource )>( load( "glGetShaderSource" ) );
	glGetShaderiv = static_cast<decltype( glGetShaderiv )>( load( "glGetShaderiv" ) );
	glGetString = static_cast<decltype( glGetString )>( load( "glGetString" ) );
	glGetStringi = static_cast<decltype( glGetStringi )>( load( "glGetStringi" ) );
	glGetSubroutineIndex = static_cast<decltype( glGetSubroutineIndex )>( load( "glGetSubroutineIndex" ) );
	glGetSubroutineUniformLocation = static_cast<decltype( glGetSubroutineUniformLocation )>( load(
		"glGetSubroutineUniformLocation" ) );
	glGetSynciv = static_cast<decltype( glGetSynciv )>( load( "glGetSynciv" ) );
	glGetTexImage = static_cast<decltype( glGetTexImage )>( load( "glGetTexImage" ) );
	glGetTexLevelParameterfv = static_cast<decltype( glGetTexLevelParameterfv )>( load( "glGetTexLevelParameterfv" ) );
	glGetTexLevelParameteriv = static_cast<decltype( glGetTexLevelParameteriv )>( load( "glGetTexLevelParameteriv" ) );
	glGetTexParameterIiv = static_cast<decltype( glGetTexParameterIiv )>( load( "glGetTexParameterIiv" ) );
	glGetTexParameterIuiv = static_cast<decltype( glGetTexParameterIuiv )>( load( "glGetTexParameterIuiv" ) );
	glGetTexParameterfv = static_cast<decltype( glGetTexParameterfv )>( load( "glGetTexParameterfv" ) );
	glGetTexParameteriv = static_cast<decltype( glGetTexParameteriv )>( load( "glGetTexParameteriv" ) );
	glGetTextureImage = static_cast<decltype( glGetTextureImage )>( load( "glGetTextureImage" ) );
	glGetTextureLevelParameterfv = static_cast<decltype( glGetTextureLevelParameterfv )>( load(
		"glGetTextureLevelParameterfv" ) );
	glGetTextureLevelParameteriv = static_cast<decltype( glGetTextureLevelParameteriv )>( load(
		"glGetTextureLevelParameteriv" ) );
	glGetTextureParameterIiv = static_cast<decltype( glGetTextureParameterIiv )>( load( "glGetTextureParameterIiv" ) );
	glGetTextureParameterIuiv = static_cast<decltype( glGetTextureParameterIuiv )>( load( "glGetTextureParameterIuiv" )
	);
	glGetTextureParameterfv = static_cast<decltype( glGetTextureParameterfv )>( load( "glGetTextureParameterfv" ) );
	glGetTextureParameteriv = static_cast<decltype( glGetTextureParameteriv )>( load( "glGetTextureParameteriv" ) );
	glGetTextureSubImage = static_cast<decltype( glGetTextureSubImage )>( load( "glGetTextureSubImage" ) );
	glGetTransformFeedbackVarying = static_cast<decltype( glGetTransformFeedbackVarying )>( load(
		"glGetTransformFeedbackVarying" ) );
	glGetTransformFeedbacki64_v = static_cast<decltype( glGetTransformFeedbacki64_v )>( load(
		"glGetTransformFeedbacki64_v" ) );
	glGetTransformFeedbacki_v = static_cast<decltype( glGetTransformFeedbacki_v )>( load( "glGetTransformFeedbacki_v" )
	);
	glGetTransformFeedbackiv = static_cast<decltype( glGetTransformFeedbackiv )>( load( "glGetTransformFeedbackiv" ) );
	glGetUniformBlockIndex = static_cast<decltype( glGetUniformBlockIndex )>( load( "glGetUniformBlockIndex" ) );
	glGetUniformIndices = static_cast<decltype( glGetUniformIndices )>( load( "glGetUniformIndices" ) );
	glGetUniformLocation = static_cast<decltype( glGetUniformLocation )>( load( "glGetUniformLocation" ) );
	glGetUniformSubroutineuiv = static_cast<decltype( glGetUniformSubroutineuiv )>( load( "glGetUniformSubroutineuiv" )
	);
	glGetUniformdv = static_cast<decltype( glGetUniformdv )>( load( "glGetUniformdv" ) );
	glGetUniformfv = static_cast<decltype( glGetUniformfv )>( load( "glGetUniformfv" ) );
	glGetUniformiv = static_cast<decltype( glGetUniformiv )>( load( "glGetUniformiv" ) );
	glGetUniformuiv = static_cast<decltype( glGetUniformuiv )>( load( "glGetUniformuiv" ) );
	glGetVertexArrayIndexed64iv = static_cast<decltype( glGetVertexArrayIndexed64iv )>( load(
		"glGetVertexArrayIndexed64iv" ) );
	glGetVertexArrayIndexediv = static_cast<decltype( glGetVertexArrayIndexediv )>( load( "glGetVertexArrayIndexediv" )
	);
	glGetVertexArrayiv = static_cast<decltype( glGetVertexArrayiv )>( load( "glGetVertexArrayiv" ) );
	glGetVertexAttribIiv = static_cast<decltype( glGetVertexAttribIiv )>( load( "glGetVertexAttribIiv" ) );
	glGetVertexAttribIuiv = static_cast<decltype( glGetVertexAttribIuiv )>( load( "glGetVertexAttribIuiv" ) );
	glGetVertexAttribLdv = static_cast<decltype( glGetVertexAttribLdv )>( load( "glGetVertexAttribLdv" ) );
	glGetVertexAttribPointerv = static_cast<decltype( glGetVertexAttribPointerv )>( load( "glGetVertexAttribPointerv" )
	);
	glGetVertexAttribdv = static_cast<decltype( glGetVertexAttribdv )>( load( "glGetVertexAttribdv" ) );
	glGetVertexAttribfv = static_cast<decltype( glGetVertexAttribfv )>( load( "glGetVertexAttribfv" ) );
	glGetVertexAttribiv = static_cast<decltype( glGetVertexAttribiv )>( load( "glGetVertexAttribiv" ) );
	glGetnColorTable = static_cast<decltype( glGetnColorTable )>( load( "glGetnColorTable" ) );
	glGetnCompressedTexImage = static_cast<decltype( glGetnCompressedTexImage )>( load( "glGetnCompressedTexImage" ) );
	glGetnConvolutionFilter = static_cast<decltype( glGetnConvolutionFilter )>( load( "glGetnConvolutionFilter" ) );
	glGetnHistogram = static_cast<decltype( glGetnHistogram )>( load( "glGetnHistogram" ) );
	glGetnMapdv = static_cast<decltype( glGetnMapdv )>( load( "glGetnMapdv" ) );
	glGetnMapfv = static_cast<decltype( glGetnMapfv )>( load( "glGetnMapfv" ) );
	glGetnMapiv = static_cast<decltype( glGetnMapiv )>( load( "glGetnMapiv" ) );
	glGetnMinmax = static_cast<decltype( glGetnMinmax )>( load( "glGetnMinmax" ) );
	glGetnPixelMapfv = static_cast<decltype( glGetnPixelMapfv )>( load( "glGetnPixelMapfv" ) );
	glGetnPixelMapuiv = static_cast<decltype( glGetnPixelMapuiv )>( load( "glGetnPixelMapuiv" ) );
	glGetnPixelMapusv = static_cast<decltype( glGetnPixelMapusv )>( load( "glGetnPixelMapusv" ) );
	glGetnPolygonStipple = static_cast<decltype( glGetnPolygonStipple )>( load( "glGetnPolygonStipple" ) );
	glGetnSeparableFilter = static_cast<decltype( glGetnSeparableFilter )>( load( "glGetnSeparableFilter" ) );
	glGetnTexImage = static_cast<decltype( glGetnTexImage )>( load( "glGetnTexImage" ) );
	glGetnUniformdv = static_cast<decltype( glGetnUniformdv )>( load( "glGetnUniformdv" ) );
	glGetnUniformfv = static_cast<decltype( glGetnUniformfv )>( load( "glGetnUniformfv" ) );
	glGetnUniformiv = static_cast<decltype( glGetnUniformiv )>( load( "glGetnUniformiv" ) );
	glGetnUniformuiv = static_cast<decltype( glGetnUniformuiv )>( load( "glGetnUniformuiv" ) );
	glHint = static_cast<decltype( glHint )>( load( "glHint" ) );
	glInvalidateBufferData = static_cast<decltype( glInvalidateBufferData )>( load( "glInvalidateBufferData" ) );
	glInvalidateBufferSubData = static_cast<decltype( glInvalidateBufferSubData )>( load( "glInvalidateBufferSubData" )
	);
	glInvalidateFramebuffer = static_cast<decltype( glInvalidateFramebuffer )>( load( "glInvalidateFramebuffer" ) );
	glInvalidateNamedFramebufferData = static_cast<decltype( glInvalidateNamedFramebufferData )>( load(
		"glInvalidateNamedFramebufferData" ) );
	glInvalidateNamedFramebufferSubData = static_cast<decltype( glInvalidateNamedFramebufferSubData )>( load(
		"glInvalidateNamedFramebufferSubData" ) );
	glInvalidateSubFramebuffer = static_cast<decltype( glInvalidateSubFramebuffer )>( load(
		"glInvalidateSubFramebuffer" ) );
	glInvalidateTexImage = static_cast<decltype( glInvalidateTexImage )>( load( "glInvalidateTexImage" ) );
	glInvalidateTexSubImage = static_cast<decltype( glInvalidateTexSubImage )>( load( "glInvalidateTexSubImage" ) );
	glIsBuffer = static_cast<decltype( glIsBuffer )>( load( "glIsBuffer" ) );
	glIsEnabled = static_cast<decltype( glIsEnabled )>( load( "glIsEnabled" ) );
	glIsEnabledi = static_cast<decltype( glIsEnabledi )>( load( "glIsEnabledi" ) );
	glIsFramebuffer = static_cast<decltype( glIsFramebuffer )>( load( "glIsFramebuffer" ) );
	glIsProgram = static_cast<decltype( glIsProgram )>( load( "glIsProgram" ) );
	glIsProgramPipeline = static_cast<decltype( glIsProgramPipeline )>( load( "glIsProgramPipeline" ) );
	glIsQuery = static_cast<decltype( glIsQuery )>( load( "glIsQuery" ) );
	glIsRenderbuffer = static_cast<decltype( glIsRenderbuffer )>( load( "glIsRenderbuffer" ) );
	glIsSampler = static_cast<decltype( glIsSampler )>( load( "glIsSampler" ) );
	glIsShader = static_cast<decltype( glIsShader )>( load( "glIsShader" ) );
	glIsSync = static_cast<decltype( glIsSync )>( load( "glIsSync" ) );
	glIsTexture = static_cast<decltype( glIsTexture )>( load( "glIsTexture" ) );
	glIsTransformFeedback = static_cast<decltype( glIsTransformFeedback )>( load( "glIsTransformFeedback" ) );
	glIsVertexArray = static_cast<decltype( glIsVertexArray )>( load( "glIsVertexArray" ) );
	glLineWidth = static_cast<decltype( glLineWidth )>( load( "glLineWidth" ) );
	glLinkProgram = static_cast<decltype( glLinkProgram )>( load( "glLinkProgram" ) );
	glLogicOp = static_cast<decltype( glLogicOp )>( load( "glLogicOp" ) );
	glMapBuffer = static_cast<decltype( glMapBuffer )>( load( "glMapBuffer" ) );
	glMapBufferRange = static_cast<decltype( glMapBufferRange )>( load( "glMapBufferRange" ) );
	glMapNamedBuffer = static_cast<decltype( glMapNamedBuffer )>( load( "glMapNamedBuffer" ) );
	glMapNamedBufferRange = static_cast<decltype( glMapNamedBufferRange )>( load( "glMapNamedBufferRange" ) );
	glMemoryBarrier = static_cast<decltype( glMemoryBarrier )>( load( "glMemoryBarrier" ) );
	glMemoryBarrierByRegion = static_cast<decltype( glMemoryBarrierByRegion )>( load( "glMemoryBarrierByRegion" ) );
	glMinSampleShading = static_cast<decltype( glMinSampleShading )>( load( "glMinSampleShading" ) );
	glMultiDrawArrays = static_cast<decltype( glMultiDrawArrays )>( load( "glMultiDrawArrays" ) );
	glMultiDrawArraysIndirect = static_cast<decltype( glMultiDrawArraysIndirect )>( load( "glMultiDrawArraysIndirect" )
	);
	glMultiDrawElements = static_cast<decltype( glMultiDrawElements )>( load( "glMultiDrawElements" ) );
	glMultiDrawElementsBaseVertex = static_cast<decltype( glMultiDrawElementsBaseVertex )>( load(
		"glMultiDrawElementsBaseVertex" ) );
	glMultiDrawElementsIndirect = static_cast<decltype( glMultiDrawElementsIndirect )>( load(
		"glMultiDrawElementsIndirect" ) );
	glMultiTexCoordP1ui = static_cast<decltype( glMultiTexCoordP1ui )>( load( "glMultiTexCoordP1ui" ) );
	glMultiTexCoordP1uiv = static_cast<decltype( glMultiTexCoordP1uiv )>( load( "glMultiTexCoordP1uiv" ) );
	glMultiTexCoordP2ui = static_cast<decltype( glMultiTexCoordP2ui )>( load( "glMultiTexCoordP2ui" ) );
	glMultiTexCoordP2uiv = static_cast<decltype( glMultiTexCoordP2uiv )>( load( "glMultiTexCoordP2uiv" ) );
	glMultiTexCoordP3ui = static_cast<decltype( glMultiTexCoordP3ui )>( load( "glMultiTexCoordP3ui" ) );
	glMultiTexCoordP3uiv = static_cast<decltype( glMultiTexCoordP3uiv )>( load( "glMultiTexCoordP3uiv" ) );
	glMultiTexCoordP4ui = static_cast<decltype( glMultiTexCoordP4ui )>( load( "glMultiTexCoordP4ui" ) );
	glMultiTexCoordP4uiv = static_cast<decltype( glMultiTexCoordP4uiv )>( load( "glMultiTexCoordP4uiv" ) );
	glNamedBufferData = static_cast<decltype( glNamedBufferData )>( load( "glNamedBufferData" ) );
	glNamedBufferStorage = static_cast<decltype( glNamedBufferStorage )>( load( "glNamedBufferStorage" ) );
	glNamedBufferSubData = static_cast<decltype( glNamedBufferSubData )>( load( "glNamedBufferSubData" ) );
	glNamedFramebufferDrawBuffer = static_cast<decltype( glNamedFramebufferDrawBuffer )>( load(
		"glNamedFramebufferDrawBuffer" ) );
	glNamedFramebufferDrawBuffers = static_cast<decltype( glNamedFramebufferDrawBuffers )>( load(
		"glNamedFramebufferDrawBuffers" ) );
	glNamedFramebufferParameteri = static_cast<decltype( glNamedFramebufferParameteri )>( load(
		"glNamedFramebufferParameteri" ) );
	glNamedFramebufferReadBuffer = static_cast<decltype( glNamedFramebufferReadBuffer )>( load(
		"glNamedFramebufferReadBuffer" ) );
	glNamedFramebufferRenderbuffer = static_cast<decltype( glNamedFramebufferRenderbuffer )>( load(
		"glNamedFramebufferRenderbuffer" ) );
	glNamedFramebufferTexture = static_cast<decltype( glNamedFramebufferTexture )>( load( "glNamedFramebufferTexture" )
	);
	glNamedFramebufferTextureLayer = static_cast<decltype( glNamedFramebufferTextureLayer )>( load(
		"glNamedFramebufferTextureLayer" ) );
	glNamedRenderbufferStorage = static_cast<decltype( glNamedRenderbufferStorage )>( load(
		"glNamedRenderbufferStorage" ) );
	glNamedRenderbufferStorageMultisample = static_cast<decltype( glNamedRenderbufferStorageMultisample )>( load(
		"glNamedRenderbufferStorageMultisample" ) );
	glNormalP3ui = static_cast<decltype( glNormalP3ui )>( load( "glNormalP3ui" ) );
	glNormalP3uiv = static_cast<decltype( glNormalP3uiv )>( load( "glNormalP3uiv" ) );
	glObjectLabel = static_cast<decltype( glObjectLabel )>( load( "glObjectLabel" ) );
	glObjectPtrLabel = static_cast<decltype( glObjectPtrLabel )>( load( "glObjectPtrLabel" ) );
	glPatchParameterfv = static_cast<decltype( glPatchParameterfv )>( load( "glPatchParameterfv" ) );
	glPatchParameteri = static_cast<decltype( glPatchParameteri )>( load( "glPatchParameteri" ) );
	glPauseTransformFeedback = static_cast<decltype( glPauseTransformFeedback )>( load( "glPauseTransformFeedback" ) );
	glPixelStoref = static_cast<decltype( glPixelStoref )>( load( "glPixelStoref" ) );
	glPixelStorei = static_cast<decltype( glPixelStorei )>( load( "glPixelStorei" ) );
	glPointParameterf = static_cast<decltype( glPointParameterf )>( load( "glPointParameterf" ) );
	glPointParameterfv = static_cast<decltype( glPointParameterfv )>( load( "glPointParameterfv" ) );
	glPointParameteri = static_cast<decltype( glPointParameteri )>( load( "glPointParameteri" ) );
	glPointParameteriv = static_cast<decltype( glPointParameteriv )>( load( "glPointParameteriv" ) );
	glPointSize = static_cast<decltype( glPointSize )>( load( "glPointSize" ) );
	glPolygonMode = static_cast<decltype( glPolygonMode )>( load( "glPolygonMode" ) );
	glPolygonOffset = static_cast<decltype( glPolygonOffset )>( load( "glPolygonOffset" ) );
	glPopDebugGroup = static_cast<decltype( glPopDebugGroup )>( load( "glPopDebugGroup" ) );
	glPrimitiveRestartIndex = static_cast<decltype( glPrimitiveRestartIndex )>( load( "glPrimitiveRestartIndex" ) );
	glProgramBinary = static_cast<decltype( glProgramBinary )>( load( "glProgramBinary" ) );
	glProgramParameteri = static_cast<decltype( glProgramParameteri )>( load( "glProgramParameteri" ) );
	glProgramUniform1d = static_cast<decltype( glProgramUniform1d )>( load( "glProgramUniform1d" ) );
	glProgramUniform1dv = static_cast<decltype( glProgramUniform1dv )>( load( "glProgramUniform1dv" ) );
	glProgramUniform1f = static_cast<decltype( glProgramUniform1f )>( load( "glProgramUniform1f" ) );
	glProgramUniform1fv = static_cast<decltype( glProgramUniform1fv )>( load( "glProgramUniform1fv" ) );
	glProgramUniform1i = static_cast<decltype( glProgramUniform1i )>( load( "glProgramUniform1i" ) );
	glProgramUniform1iv = static_cast<decltype( glProgramUniform1iv )>( load( "glProgramUniform1iv" ) );
	glProgramUniform1ui = static_cast<decltype( glProgramUniform1ui )>( load( "glProgramUniform1ui" ) );
	glProgramUniform1uiv = static_cast<decltype( glProgramUniform1uiv )>( load( "glProgramUniform1uiv" ) );
	glProgramUniform2d = static_cast<decltype( glProgramUniform2d )>( load( "glProgramUniform2d" ) );
	glProgramUniform2dv = static_cast<decltype( glProgramUniform2dv )>( load( "glProgramUniform2dv" ) );
	glProgramUniform2f = static_cast<decltype( glProgramUniform2f )>( load( "glProgramUniform2f" ) );
	glProgramUniform2fv = static_cast<decltype( glProgramUniform2fv )>( load( "glProgramUniform2fv" ) );
	glProgramUniform2i = static_cast<decltype( glProgramUniform2i )>( load( "glProgramUniform2i" ) );
	glProgramUniform2iv = static_cast<decltype( glProgramUniform2iv )>( load( "glProgramUniform2iv" ) );
	glProgramUniform2ui = static_cast<decltype( glProgramUniform2ui )>( load( "glProgramUniform2ui" ) );
	glProgramUniform2uiv = static_cast<decltype( glProgramUniform2uiv )>( load( "glProgramUniform2uiv" ) );
	glProgramUniform3d = static_cast<decltype( glProgramUniform3d )>( load( "glProgramUniform3d" ) );
	glProgramUniform3dv = static_cast<decltype( glProgramUniform3dv )>( load( "glProgramUniform3dv" ) );
	glProgramUniform3f = static_cast<decltype( glProgramUniform3f )>( load( "glProgramUniform3f" ) );
	glProgramUniform3fv = static_cast<decltype( glProgramUniform3fv )>( load( "glProgramUniform3fv" ) );
	glProgramUniform3i = static_cast<decltype( glProgramUniform3i )>( load( "glProgramUniform3i" ) );
	glProgramUniform3iv = static_cast<decltype( glProgramUniform3iv )>( load( "glProgramUniform3iv" ) );
	glProgramUniform3ui = static_cast<decltype( glProgramUniform3ui )>( load( "glProgramUniform3ui" ) );
	glProgramUniform3uiv = static_cast<decltype( glProgramUniform3uiv )>( load( "glProgramUniform3uiv" ) );
	glProgramUniform4d = static_cast<decltype( glProgramUniform4d )>( load( "glProgramUniform4d" ) );
	glProgramUniform4dv = static_cast<decltype( glProgramUniform4dv )>( load( "glProgramUniform4dv" ) );
	glProgramUniform4f = static_cast<decltype( glProgramUniform4f )>( load( "glProgramUniform4f" ) );
	glProgramUniform4fv = static_cast<decltype( glProgramUniform4fv )>( load( "glProgramUniform4fv" ) );
	glProgramUniform4i = static_cast<decltype( glProgramUniform4i )>( load( "glProgramUniform4i" ) );
	glProgramUniform4iv = static_cast<decltype( glProgramUniform4iv )>( load( "glProgramUniform4iv" ) );
	glProgramUniform4ui = static_cast<decltype( glProgramUniform4ui )>( load( "glProgramUniform4ui" ) );
	glProgramUniform4uiv = static_cast<decltype( glProgramUniform4uiv )>( load( "glProgramUniform4uiv" ) );
	glProgramUniformMatrix2dv = static_cast<decltype( glProgramUniformMatrix2dv )>( load( "glProgramUniformMatrix2dv" )
	);
	glProgramUniformMatrix2fv = static_cast<decltype( glProgramUniformMatrix2fv )>( load( "glProgramUniformMatrix2fv" )
	);
	glProgramUniformMatrix2x3dv = static_cast<decltype( glProgramUniformMatrix2x3dv )>( load(
		"glProgramUniformMatrix2x3dv" ) );
	glProgramUniformMatrix2x3fv = static_cast<decltype( glProgramUniformMatrix2x3fv )>( load(
		"glProgramUniformMatrix2x3fv" ) );
	glProgramUniformMatrix2x4dv = static_cast<decltype( glProgramUniformMatrix2x4dv )>( load(
		"glProgramUniformMatrix2x4dv" ) );
	glProgramUniformMatrix2x4fv = static_cast<decltype( glProgramUniformMatrix2x4fv )>( load(
		"glProgramUniformMatrix2x4fv" ) );
	glProgramUniformMatrix3dv = static_cast<decltype( glProgramUniformMatrix3dv )>( load( "glProgramUniformMatrix3dv" )
	);
	glProgramUniformMatrix3fv = static_cast<decltype( glProgramUniformMatrix3fv )>( load( "glProgramUniformMatrix3fv" )
	);
	glProgramUniformMatrix3x2dv = static_cast<decltype( glProgramUniformMatrix3x2dv )>( load(
		"glProgramUniformMatrix3x2dv" ) );
	glProgramUniformMatrix3x2fv = static_cast<decltype( glProgramUniformMatrix3x2fv )>( load(
		"glProgramUniformMatrix3x2fv" ) );
	glProgramUniformMatrix3x4dv = static_cast<decltype( glProgramUniformMatrix3x4dv )>( load(
		"glProgramUniformMatrix3x4dv" ) );
	glProgramUniformMatrix3x4fv = static_cast<decltype( glProgramUniformMatrix3x4fv )>( load(
		"glProgramUniformMatrix3x4fv" ) );
	glProgramUniformMatrix4dv = static_cast<decltype( glProgramUniformMatrix4dv )>( load( "glProgramUniformMatrix4dv" )
	);
	glProgramUniformMatrix4fv = static_cast<decltype( glProgramUniformMatrix4fv )>( load( "glProgramUniformMatrix4fv" )
	);
	glProgramUniformMatrix4x2dv = static_cast<decltype( glProgramUniformMatrix4x2dv )>( load(
		"glProgramUniformMatrix4x2dv" ) );
	glProgramUniformMatrix4x2fv = static_cast<decltype( glProgramUniformMatrix4x2fv )>( load(
		"glProgramUniformMatrix4x2fv" ) );
	glProgramUniformMatrix4x3dv = static_cast<decltype( glProgramUniformMatrix4x3dv )>( load(
		"glProgramUniformMatrix4x3dv" ) );
	glProgramUniformMatrix4x3fv = static_cast<decltype( glProgramUniformMatrix4x3fv )>( load(
		"glProgramUniformMatrix4x3fv" ) );
	glProvokingVertex = static_cast<decltype( glProvokingVertex )>( load( "glProvokingVertex" ) );
	glPushDebugGroup = static_cast<decltype( glPushDebugGroup )>( load( "glPushDebugGroup" ) );
	glQueryCounter = static_cast<decltype( glQueryCounter )>( load( "glQueryCounter" ) );
	glReadBuffer = static_cast<decltype( glReadBuffer )>( load( "glReadBuffer" ) );
	glReadPixels = static_cast<decltype( glReadPixels )>( load( "glReadPixels" ) );
	glReadnPixels = static_cast<decltype( glReadnPixels )>( load( "glReadnPixels" ) );
	glReleaseShaderCompiler = static_cast<decltype( glReleaseShaderCompiler )>( load( "glReleaseShaderCompiler" ) );
	glRenderbufferStorage = static_cast<decltype( glRenderbufferStorage )>( load( "glRenderbufferStorage" ) );
	glRenderbufferStorageMultisample = static_cast<decltype( glRenderbufferStorageMultisample )>( load(
		"glRenderbufferStorageMultisample" ) );
	glResumeTransformFeedback = static_cast<decltype( glResumeTransformFeedback )>( load( "glResumeTransformFeedback" )
	);
	glSampleCoverage = static_cast<decltype( glSampleCoverage )>( load( "glSampleCoverage" ) );
	glSampleMaski = static_cast<decltype( glSampleMaski )>( load( "glSampleMaski" ) );
	glSamplerParameterIiv = static_cast<decltype( glSamplerParameterIiv )>( load( "glSamplerParameterIiv" ) );
	glSamplerParameterIuiv = static_cast<decltype( glSamplerParameterIuiv )>( load( "glSamplerParameterIuiv" ) );
	glSamplerParameterf = static_cast<decltype( glSamplerParameterf )>( load( "glSamplerParameterf" ) );
	glSamplerParameterfv = static_cast<decltype( glSamplerParameterfv )>( load( "glSamplerParameterfv" ) );
	glSamplerParameteri = static_cast<decltype( glSamplerParameteri )>( load( "glSamplerParameteri" ) );
	glSamplerParameteriv = static_cast<decltype( glSamplerParameteriv )>( load( "glSamplerParameteriv" ) );
	glScissor = static_cast<decltype( glScissor )>( load( "glScissor" ) );
	glScissorArrayv = static_cast<decltype( glScissorArrayv )>( load( "glScissorArrayv" ) );
	glScissorIndexed = static_cast<decltype( glScissorIndexed )>( load( "glScissorIndexed" ) );
	glScissorIndexedv = static_cast<decltype( glScissorIndexedv )>( load( "glScissorIndexedv" ) );
	glSecondaryColorP3ui = static_cast<decltype( glSecondaryColorP3ui )>( load( "glSecondaryColorP3ui" ) );
	glSecondaryColorP3uiv = static_cast<decltype( glSecondaryColorP3uiv )>( load( "glSecondaryColorP3uiv" ) );
	glShaderBinary = static_cast<decltype( glShaderBinary )>( load( "glShaderBinary" ) );
	glShaderSource = static_cast<decltype( glShaderSource )>( load( "glShaderSource" ) );
	glShaderStorageBlockBinding = static_cast<decltype( glShaderStorageBlockBinding )>( load(
		"glShaderStorageBlockBinding" ) );
	glStencilFunc = static_cast<decltype( glStencilFunc )>( load( "glStencilFunc" ) );
	glStencilFuncSeparate = static_cast<decltype( glStencilFuncSeparate )>( load( "glStencilFuncSeparate" ) );
	glStencilMask = static_cast<decltype( glStencilMask )>( load( "glStencilMask" ) );
	glStencilMaskSeparate = static_cast<decltype( glStencilMaskSeparate )>( load( "glStencilMaskSeparate" ) );
	glStencilOp = static_cast<decltype( glStencilOp )>( load( "glStencilOp" ) );
	glStencilOpSeparate = static_cast<decltype( glStencilOpSeparate )>( load( "glStencilOpSeparate" ) );
	glTexBuffer = static_cast<decltype( glTexBuffer )>( load( "glTexBuffer" ) );
	glTexBufferRange = static_cast<decltype( glTexBufferRange )>( load( "glTexBufferRange" ) );
	glTexCoordP1ui = static_cast<decltype( glTexCoordP1ui )>( load( "glTexCoordP1ui" ) );
	glTexCoordP1uiv = static_cast<decltype( glTexCoordP1uiv )>( load( "glTexCoordP1uiv" ) );
	glTexCoordP2ui = static_cast<decltype( glTexCoordP2ui )>( load( "glTexCoordP2ui" ) );
	glTexCoordP2uiv = static_cast<decltype( glTexCoordP2uiv )>( load( "glTexCoordP2uiv" ) );
	glTexCoordP3ui = static_cast<decltype( glTexCoordP3ui )>( load( "glTexCoordP3ui" ) );
	glTexCoordP3uiv = static_cast<decltype( glTexCoordP3uiv )>( load( "glTexCoordP3uiv" ) );
	glTexCoordP4ui = static_cast<decltype( glTexCoordP4ui )>( load( "glTexCoordP4ui" ) );
	glTexCoordP4uiv = static_cast<decltype( glTexCoordP4uiv )>( load( "glTexCoordP4uiv" ) );
	glTexImage1D = static_cast<decltype( glTexImage1D )>( load( "glTexImage1D" ) );
	glTexImage2D = static_cast<decltype( glTexImage2D )>( load( "glTexImage2D" ) );
	glTexImage2DMultisample = static_cast<decltype( glTexImage2DMultisample )>( load( "glTexImage2DMultisample" ) );
	glTexImage3D = static_cast<decltype( glTexImage3D )>( load( "glTexImage3D" ) );
	glTexImage3DMultisample = static_cast<decltype( glTexImage3DMultisample )>( load( "glTexImage3DMultisample" ) );
	glTexParameterIiv = static_cast<decltype( glTexParameterIiv )>( load( "glTexParameterIiv" ) );
	glTexParameterIuiv = static_cast<decltype( glTexParameterIuiv )>( load( "glTexParameterIuiv" ) );
	glTexParameterf = static_cast<decltype( glTexParameterf )>( load( "glTexParameterf" ) );
	glTexParameterfv = static_cast<decltype( glTexParameterfv )>( load( "glTexParameterfv" ) );
	glTexParameteri = static_cast<decltype( glTexParameteri )>( load( "glTexParameteri" ) );
	glTexParameteriv = static_cast<decltype( glTexParameteriv )>( load( "glTexParameteriv" ) );
	glTexStorage1D = static_cast<decltype( glTexStorage1D )>( load( "glTexStorage1D" ) );
	glTexStorage2D = static_cast<decltype( glTexStorage2D )>( load( "glTexStorage2D" ) );
	glTexStorage2DMultisample = static_cast<decltype( glTexStorage2DMultisample )>( load( "glTexStorage2DMultisample" )
	);
	glTexStorage3D = static_cast<decltype( glTexStorage3D )>( load( "glTexStorage3D" ) );
	glTexStorage3DMultisample = static_cast<decltype( glTexStorage3DMultisample )>( load( "glTexStorage3DMultisample" )
	);
	glTexSubImage1D = static_cast<decltype( glTexSubImage1D )>( load( "glTexSubImage1D" ) );
	glTexSubImage2D = static_cast<decltype( glTexSubImage2D )>( load( "glTexSubImage2D" ) );
	glTexSubImage3D = static_cast<decltype( glTexSubImage3D )>( load( "glTexSubImage3D" ) );
	glTextureBarrier = static_cast<decltype( glTextureBarrier )>( load( "glTextureBarrier" ) );
	glTextureBuffer = static_cast<decltype( glTextureBuffer )>( load( "glTextureBuffer" ) );
	glTextureBufferRange = static_cast<decltype( glTextureBufferRange )>( load( "glTextureBufferRange" ) );
	glTextureParameterIiv = static_cast<decltype( glTextureParameterIiv )>( load( "glTextureParameterIiv" ) );
	glTextureParameterIuiv = static_cast<decltype( glTextureParameterIuiv )>( load( "glTextureParameterIuiv" ) );
	glTextureParameterf = static_cast<decltype( glTextureParameterf )>( load( "glTextureParameterf" ) );
	glTextureParameterfv = static_cast<decltype( glTextureParameterfv )>( load( "glTextureParameterfv" ) );
	glTextureParameteri = static_cast<decltype( glTextureParameteri )>( load( "glTextureParameteri" ) );
	glTextureParameteriv = static_cast<decltype( glTextureParameteriv )>( load( "glTextureParameteriv" ) );
	glTextureStorage1D = static_cast<decltype( glTextureStorage1D )>( load( "glTextureStorage1D" ) );
	glTextureStorage2D = static_cast<decltype( glTextureStorage2D )>( load( "glTextureStorage2D" ) );
	glTextureStorage2DMultisample = static_cast<decltype( glTextureStorage2DMultisample )>( load(
		"glTextureStorage2DMultisample" ) );
	glTextureStorage3D = static_cast<decltype( glTextureStorage3D )>( load( "glTextureStorage3D" ) );
	glTextureStorage3DMultisample = static_cast<decltype( glTextureStorage3DMultisample )>( load(
		"glTextureStorage3DMultisample" ) );
	glTextureSubImage1D = static_cast<decltype( glTextureSubImage1D )>( load( "glTextureSubImage1D" ) );
	glTextureSubImage2D = static_cast<decltype( glTextureSubImage2D )>( load( "glTextureSubImage2D" ) );
	glTextureSubImage3D = static_cast<decltype( glTextureSubImage3D )>( load( "glTextureSubImage3D" ) );
	glTextureView = static_cast<decltype( glTextureView )>( load( "glTextureView" ) );
	glTransformFeedbackBufferBase = static_cast<decltype( glTransformFeedbackBufferBase )>( load(
		"glTransformFeedbackBufferBase" ) );
	glTransformFeedbackBufferRange = static_cast<decltype( glTransformFeedbackBufferRange )>( load(
		"glTransformFeedbackBufferRange" ) );
	glTransformFeedbackVaryings = static_cast<decltype( glTransformFeedbackVaryings )>( load(
		"glTransformFeedbackVaryings" ) );
	glUniform1d = static_cast<decltype( glUniform1d )>( load( "glUniform1d" ) );
	glUniform1dv = static_cast<decltype( glUniform1dv )>( load( "glUniform1dv" ) );
	glUniform1f = static_cast<decltype( glUniform1f )>( load( "glUniform1f" ) );
	glUniform1fv = static_cast<decltype( glUniform1fv )>( load( "glUniform1fv" ) );
	glUniform1i = static_cast<decltype( glUniform1i )>( load( "glUniform1i" ) );
	glUniform1iv = static_cast<decltype( glUniform1iv )>( load( "glUniform1iv" ) );
	glUniform1ui = static_cast<decltype( glUniform1ui )>( load( "glUniform1ui" ) );
	glUniform1uiv = static_cast<decltype( glUniform1uiv )>( load( "glUniform1uiv" ) );
	glUniform2d = static_cast<decltype( glUniform2d )>( load( "glUniform2d" ) );
	glUniform2dv = static_cast<decltype( glUniform2dv )>( load( "glUniform2dv" ) );
	glUniform2f = static_cast<decltype( glUniform2f )>( load( "glUniform2f" ) );
	glUniform2fv = static_cast<decltype( glUniform2fv )>( load( "glUniform2fv" ) );
	glUniform2i = static_cast<decltype( glUniform2i )>( load( "glUniform2i" ) );
	glUniform2iv = static_cast<decltype( glUniform2iv )>( load( "glUniform2iv" ) );
	glUniform2ui = static_cast<decltype( glUniform2ui )>( load( "glUniform2ui" ) );
	glUniform2uiv = static_cast<decltype( glUniform2uiv )>( load( "glUniform2uiv" ) );
	glUniform3d = static_cast<decltype( glUniform3d )>( load( "glUniform3d" ) );
	glUniform3dv = static_cast<decltype( glUniform3dv )>( load( "glUniform3dv" ) );
	glUniform3f = static_cast<decltype( glUniform3f )>( load( "glUniform3f" ) );
	glUniform3fv = static_cast<decltype( glUniform3fv )>( load( "glUniform3fv" ) );
	glUniform3i = static_cast<decltype( glUniform3i )>( load( "glUniform3i" ) );
	glUniform3iv = static_cast<decltype( glUniform3iv )>( load( "glUniform3iv" ) );
	glUniform3ui = static_cast<decltype( glUniform3ui )>( load( "glUniform3ui" ) );
	glUniform3uiv = static_cast<decltype( glUniform3uiv )>( load( "glUniform3uiv" ) );
	glUniform4d = static_cast<decltype( glUniform4d )>( load( "glUniform4d" ) );
	glUniform4dv = static_cast<decltype( glUniform4dv )>( load( "glUniform4dv" ) );
	glUniform4f = static_cast<decltype( glUniform4f )>( load( "glUniform4f" ) );
	glUniform4fv = static_cast<decltype( glUniform4fv )>( load( "glUniform4fv" ) );
	glUniform4i = static_cast<decltype( glUniform4i )>( load( "glUniform4i" ) );
	glUniform4iv = static_cast<decltype( glUniform4iv )>( load( "glUniform4iv" ) );
	glUniform4ui = static_cast<decltype( glUniform4ui )>( load( "glUniform4ui" ) );
	glUniform4uiv = static_cast<decltype( glUniform4uiv )>( load( "glUniform4uiv" ) );
	glUniformBlockBinding = static_cast<decltype( glUniformBlockBinding )>( load( "glUniformBlockBinding" ) );
	glUniformMatrix2dv = static_cast<decltype( glUniformMatrix2dv )>( load( "glUniformMatrix2dv" ) );
	glUniformMatrix2fv = static_cast<decltype( glUniformMatrix2fv )>( load( "glUniformMatrix2fv" ) );
	glUniformMatrix2x3dv = static_cast<decltype( glUniformMatrix2x3dv )>( load( "glUniformMatrix2x3dv" ) );
	glUniformMatrix2x3fv = static_cast<decltype( glUniformMatrix2x3fv )>( load( "glUniformMatrix2x3fv" ) );
	glUniformMatrix2x4dv = static_cast<decltype( glUniformMatrix2x4dv )>( load( "glUniformMatrix2x4dv" ) );
	glUniformMatrix2x4fv = static_cast<decltype( glUniformMatrix2x4fv )>( load( "glUniformMatrix2x4fv" ) );
	glUniformMatrix3dv = static_cast<decltype( glUniformMatrix3dv )>( load( "glUniformMatrix3dv" ) );
	glUniformMatrix3fv = static_cast<decltype( glUniformMatrix3fv )>( load( "glUniformMatrix3fv" ) );
	glUniformMatrix3x2dv = static_cast<decltype( glUniformMatrix3x2dv )>( load( "glUniformMatrix3x2dv" ) );
	glUniformMatrix3x2fv = static_cast<decltype( glUniformMatrix3x2fv )>( load( "glUniformMatrix3x2fv" ) );
	glUniformMatrix3x4dv = static_cast<decltype( glUniformMatrix3x4dv )>( load( "glUniformMatrix3x4dv" ) );
	glUniformMatrix3x4fv = static_cast<decltype( glUniformMatrix3x4fv )>( load( "glUniformMatrix3x4fv" ) );
	glUniformMatrix4dv = static_cast<decltype( glUniformMatrix4dv )>( load( "glUniformMatrix4dv" ) );
	glUniformMatrix4fv = static_cast<decltype( glUniformMatrix4fv )>( load( "glUniformMatrix4fv" ) );
	glUniformMatrix4x2dv = static_cast<decltype( glUniformMatrix4x2dv )>( load( "glUniformMatrix4x2dv" ) );
	glUniformMatrix4x2fv = static_cast<decltype( glUniformMatrix4x2fv )>( load( "glUniformMatrix4x2fv" ) );
	glUniformMatrix4x3dv = static_cast<decltype( glUniformMatrix4x3dv )>( load( "glUniformMatrix4x3dv" ) );
	glUniformMatrix4x3fv = static_cast<decltype( glUniformMatrix4x3fv )>( load( "glUniformMatrix4x3fv" ) );
	glUniformSubroutinesuiv = static_cast<decltype( glUniformSubroutinesuiv )>( load( "glUniformSubroutinesuiv" ) );
	glUnmapBuffer = static_cast<decltype( glUnmapBuffer )>( load( "glUnmapBuffer" ) );
	glUnmapNamedBuffer = static_cast<decltype( glUnmapNamedBuffer )>( load( "glUnmapNamedBuffer" ) );
	glUseProgram = static_cast<decltype( glUseProgram )>( load( "glUseProgram" ) );
	glUseProgramStages = static_cast<decltype( glUseProgramStages )>( load( "glUseProgramStages" ) );
	glValidateProgram = static_cast<decltype( glValidateProgram )>( load( "glValidateProgram" ) );
	glValidateProgramPipeline = static_cast<decltype( glValidateProgramPipeline )>( load( "glValidateProgramPipeline" )
	);
	glVertexArrayAttribBinding = static_cast<decltype( glVertexArrayAttribBinding )>( load(
		"glVertexArrayAttribBinding" ) );
	glVertexArrayAttribFormat = static_cast<decltype( glVertexArrayAttribFormat )>( load( "glVertexArrayAttribFormat" )
	);
	glVertexArrayAttribIFormat = static_cast<decltype( glVertexArrayAttribIFormat )>( load(
		"glVertexArrayAttribIFormat" ) );
	glVertexArrayAttribLFormat = static_cast<decltype( glVertexArrayAttribLFormat )>( load(
		"glVertexArrayAttribLFormat" ) );
	glVertexArrayBindingDivisor = static_cast<decltype( glVertexArrayBindingDivisor )>( load(
		"glVertexArrayBindingDivisor" ) );
	glVertexArrayElementBuffer = static_cast<decltype( glVertexArrayElementBuffer )>( load(
		"glVertexArrayElementBuffer" ) );
	glVertexArrayVertexBuffer = static_cast<decltype( glVertexArrayVertexBuffer )>( load( "glVertexArrayVertexBuffer" )
	);
	glVertexArrayVertexBuffers = static_cast<decltype( glVertexArrayVertexBuffers )>( load(
		"glVertexArrayVertexBuffers" ) );
	glVertexAttrib1d = static_cast<decltype( glVertexAttrib1d )>( load( "glVertexAttrib1d" ) );
	glVertexAttrib1dv = static_cast<decltype( glVertexAttrib1dv )>( load( "glVertexAttrib1dv" ) );
	glVertexAttrib1f = static_cast<decltype( glVertexAttrib1f )>( load( "glVertexAttrib1f" ) );
	glVertexAttrib1fv = static_cast<decltype( glVertexAttrib1fv )>( load( "glVertexAttrib1fv" ) );
	glVertexAttrib1s = static_cast<decltype( glVertexAttrib1s )>( load( "glVertexAttrib1s" ) );
	glVertexAttrib1sv = static_cast<decltype( glVertexAttrib1sv )>( load( "glVertexAttrib1sv" ) );
	glVertexAttrib2d = static_cast<decltype( glVertexAttrib2d )>( load( "glVertexAttrib2d" ) );
	glVertexAttrib2dv = static_cast<decltype( glVertexAttrib2dv )>( load( "glVertexAttrib2dv" ) );
	glVertexAttrib2f = static_cast<decltype( glVertexAttrib2f )>( load( "glVertexAttrib2f" ) );
	glVertexAttrib2fv = static_cast<decltype( glVertexAttrib2fv )>( load( "glVertexAttrib2fv" ) );
	glVertexAttrib2s = static_cast<decltype( glVertexAttrib2s )>( load( "glVertexAttrib2s" ) );
	glVertexAttrib2sv = static_cast<decltype( glVertexAttrib2sv )>( load( "glVertexAttrib2sv" ) );
	glVertexAttrib3d = static_cast<decltype( glVertexAttrib3d )>( load( "glVertexAttrib3d" ) );
	glVertexAttrib3dv = static_cast<decltype( glVertexAttrib3dv )>( load( "glVertexAttrib3dv" ) );
	glVertexAttrib3f = static_cast<decltype( glVertexAttrib3f )>( load( "glVertexAttrib3f" ) );
	glVertexAttrib3fv = static_cast<decltype( glVertexAttrib3fv )>( load( "glVertexAttrib3fv" ) );
	glVertexAttrib3s = static_cast<decltype( glVertexAttrib3s )>( load( "glVertexAttrib3s" ) );
	glVertexAttrib3sv = static_cast<decltype( glVertexAttrib3sv )>( load( "glVertexAttrib3sv" ) );
	glVertexAttrib4Nbv = static_cast<decltype( glVertexAttrib4Nbv )>( load( "glVertexAttrib4Nbv" ) );
	glVertexAttrib4Niv = static_cast<decltype( glVertexAttrib4Niv )>( load( "glVertexAttrib4Niv" ) );
	glVertexAttrib4Nsv = static_cast<decltype( glVertexAttrib4Nsv )>( load( "glVertexAttrib4Nsv" ) );
	glVertexAttrib4Nub = static_cast<decltype( glVertexAttrib4Nub )>( load( "glVertexAttrib4Nub" ) );
	glVertexAttrib4Nubv = static_cast<decltype( glVertexAttrib4Nubv )>( load( "glVertexAttrib4Nubv" ) );
	glVertexAttrib4Nuiv = static_cast<decltype( glVertexAttrib4Nuiv )>( load( "glVertexAttrib4Nuiv" ) );
	glVertexAttrib4Nusv = static_cast<decltype( glVertexAttrib4Nusv )>( load( "glVertexAttrib4Nusv" ) );
	glVertexAttrib4bv = static_cast<decltype( glVertexAttrib4bv )>( load( "glVertexAttrib4bv" ) );
	glVertexAttrib4d = static_cast<decltype( glVertexAttrib4d )>( load( "glVertexAttrib4d" ) );
	glVertexAttrib4dv = static_cast<decltype( glVertexAttrib4dv )>( load( "glVertexAttrib4dv" ) );
	glVertexAttrib4f = static_cast<decltype( glVertexAttrib4f )>( load( "glVertexAttrib4f" ) );
	glVertexAttrib4fv = static_cast<decltype( glVertexAttrib4fv )>( load( "glVertexAttrib4fv" ) );
	glVertexAttrib4iv = static_cast<decltype( glVertexAttrib4iv )>( load( "glVertexAttrib4iv" ) );
	glVertexAttrib4s = static_cast<decltype( glVertexAttrib4s )>( load( "glVertexAttrib4s" ) );
	glVertexAttrib4sv = static_cast<decltype( glVertexAttrib4sv )>( load( "glVertexAttrib4sv" ) );
	glVertexAttrib4ubv = static_cast<decltype( glVertexAttrib4ubv )>( load( "glVertexAttrib4ubv" ) );
	glVertexAttrib4uiv = static_cast<decltype( glVertexAttrib4uiv )>( load( "glVertexAttrib4uiv" ) );
	glVertexAttrib4usv = static_cast<decltype( glVertexAttrib4usv )>( load( "glVertexAttrib4usv" ) );
	glVertexAttribBinding = static_cast<decltype( glVertexAttribBinding )>( load( "glVertexAttribBinding" ) );
	glVertexAttribDivisor = static_cast<decltype( glVertexAttribDivisor )>( load( "glVertexAttribDivisor" ) );
	glVertexAttribFormat = static_cast<decltype( glVertexAttribFormat )>( load( "glVertexAttribFormat" ) );
	glVertexAttribI1i = static_cast<decltype( glVertexAttribI1i )>( load( "glVertexAttribI1i" ) );
	glVertexAttribI1iv = static_cast<decltype( glVertexAttribI1iv )>( load( "glVertexAttribI1iv" ) );
	glVertexAttribI1ui = static_cast<decltype( glVertexAttribI1ui )>( load( "glVertexAttribI1ui" ) );
	glVertexAttribI1uiv = static_cast<decltype( glVertexAttribI1uiv )>( load( "glVertexAttribI1uiv" ) );
	glVertexAttribI2i = static_cast<decltype( glVertexAttribI2i )>( load( "glVertexAttribI2i" ) );
	glVertexAttribI2iv = static_cast<decltype( glVertexAttribI2iv )>( load( "glVertexAttribI2iv" ) );
	glVertexAttribI2ui = static_cast<decltype( glVertexAttribI2ui )>( load( "glVertexAttribI2ui" ) );
	glVertexAttribI2uiv = static_cast<decltype( glVertexAttribI2uiv )>( load( "glVertexAttribI2uiv" ) );
	glVertexAttribI3i = static_cast<decltype( glVertexAttribI3i )>( load( "glVertexAttribI3i" ) );
	glVertexAttribI3iv = static_cast<decltype( glVertexAttribI3iv )>( load( "glVertexAttribI3iv" ) );
	glVertexAttribI3ui = static_cast<decltype( glVertexAttribI3ui )>( load( "glVertexAttribI3ui" ) );
	glVertexAttribI3uiv = static_cast<decltype( glVertexAttribI3uiv )>( load( "glVertexAttribI3uiv" ) );
	glVertexAttribI4bv = static_cast<decltype( glVertexAttribI4bv )>( load( "glVertexAttribI4bv" ) );
	glVertexAttribI4i = static_cast<decltype( glVertexAttribI4i )>( load( "glVertexAttribI4i" ) );
	glVertexAttribI4iv = static_cast<decltype( glVertexAttribI4iv )>( load( "glVertexAttribI4iv" ) );
	glVertexAttribI4sv = static_cast<decltype( glVertexAttribI4sv )>( load( "glVertexAttribI4sv" ) );
	glVertexAttribI4ubv = static_cast<decltype( glVertexAttribI4ubv )>( load( "glVertexAttribI4ubv" ) );
	glVertexAttribI4ui = static_cast<decltype( glVertexAttribI4ui )>( load( "glVertexAttribI4ui" ) );
	glVertexAttribI4uiv = static_cast<decltype( glVertexAttribI4uiv )>( load( "glVertexAttribI4uiv" ) );
	glVertexAttribI4usv = static_cast<decltype( glVertexAttribI4usv )>( load( "glVertexAttribI4usv" ) );
	glVertexAttribIFormat = static_cast<decltype( glVertexAttribIFormat )>( load( "glVertexAttribIFormat" ) );
	glVertexAttribIPointer = static_cast<decltype( glVertexAttribIPointer )>( load( "glVertexAttribIPointer" ) );
	glVertexAttribL1d = static_cast<decltype( glVertexAttribL1d )>( load( "glVertexAttribL1d" ) );
	glVertexAttribL1dv = static_cast<decltype( glVertexAttribL1dv )>( load( "glVertexAttribL1dv" ) );
	glVertexAttribL2d = static_cast<decltype( glVertexAttribL2d )>( load( "glVertexAttribL2d" ) );
	glVertexAttribL2dv = static_cast<decltype( glVertexAttribL2dv )>( load( "glVertexAttribL2dv" ) );
	glVertexAttribL3d = static_cast<decltype( glVertexAttribL3d )>( load( "glVertexAttribL3d" ) );
	glVertexAttribL3dv = static_cast<decltype( glVertexAttribL3dv )>( load( "glVertexAttribL3dv" ) );
	glVertexAttribL4d = static_cast<decltype( glVertexAttribL4d )>( load( "glVertexAttribL4d" ) );
	glVertexAttribL4dv = static_cast<decltype( glVertexAttribL4dv )>( load( "glVertexAttribL4dv" ) );
	glVertexAttribLFormat = static_cast<decltype( glVertexAttribLFormat )>( load( "glVertexAttribLFormat" ) );
	glVertexAttribLPointer = static_cast<decltype( glVertexAttribLPointer )>( load( "glVertexAttribLPointer" ) );
	glVertexAttribP1ui = static_cast<decltype( glVertexAttribP1ui )>( load( "glVertexAttribP1ui" ) );
	glVertexAttribP1uiv = static_cast<decltype( glVertexAttribP1uiv )>( load( "glVertexAttribP1uiv" ) );
	glVertexAttribP2ui = static_cast<decltype( glVertexAttribP2ui )>( load( "glVertexAttribP2ui" ) );
	glVertexAttribP2uiv = static_cast<decltype( glVertexAttribP2uiv )>( load( "glVertexAttribP2uiv" ) );
	glVertexAttribP3ui = static_cast<decltype( glVertexAttribP3ui )>( load( "glVertexAttribP3ui" ) );
	glVertexAttribP3uiv = static_cast<decltype( glVertexAttribP3uiv )>( load( "glVertexAttribP3uiv" ) );
	glVertexAttribP4ui = static_cast<decltype( glVertexAttribP4ui )>( load( "glVertexAttribP4ui" ) );
	glVertexAttribP4uiv = static_cast<decltype( glVertexAttribP4uiv )>( load( "glVertexAttribP4uiv" ) );
	glVertexAttribPointer = static_cast<decltype( glVertexAttribPointer )>( load( "glVertexAttribPointer" ) );
	glVertexBindingDivisor = static_cast<decltype( glVertexBindingDivisor )>( load( "glVertexBindingDivisor" ) );
	glVertexP2ui = static_cast<decltype( glVertexP2ui )>( load( "glVertexP2ui" ) );
	glVertexP2uiv = static_cast<decltype( glVertexP2uiv )>( load( "glVertexP2uiv" ) );
	glVertexP3ui = static_cast<decltype( glVertexP3ui )>( load( "glVertexP3ui" ) );
	glVertexP3uiv = static_cast<decltype( glVertexP3uiv )>( load( "glVertexP3uiv" ) );
	glVertexP4ui = static_cast<decltype( glVertexP4ui )>( load( "glVertexP4ui" ) );
	glVertexP4uiv = static_cast<decltype( glVertexP4uiv )>( load( "glVertexP4uiv" ) );
	glViewport = static_cast<decltype( glViewport )>( load( "glViewport" ) );
	glViewportArrayv = static_cast<decltype( glViewportArrayv )>( load( "glViewportArrayv" ) );
	glViewportIndexedf = static_cast<decltype( glViewportIndexedf )>( load( "glViewportIndexedf" ) );
	glViewportIndexedfv = static_cast<decltype( glViewportIndexedfv )>( load( "glViewportIndexedfv" ) );
	glWaitSync = static_cast<decltype( glWaitSync )>( load( "glWaitSync" ) );

	deinit();

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	// @GLDebug

	// 
	// Register OpenGL debug callback. Should be do only for 4.4 or higher.
	//

	glEnable( GL_DEBUG_OUTPUT );
	glEnable( GL_DEBUG_OUTPUT_SYNCHRONOUS );

	glDebugMessageCallback( []( GLenum, GLenum const type, GLuint const id, GLenum, GLsizei, GLchar const* message, void const* )
	{
		char const* type_str = [&type]
		{
			switch ( type ) {
			case GL_DEBUG_TYPE_PERFORMANCE:
				return "PERFORMANCE";

			case GL_DEBUG_TYPE_OTHER:
				return "OTHER";

			case GL_DEBUG_TYPE_MARKER:
				return "MARKER";

			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
				return "DEPRECATED";

			case GL_DEBUG_TYPE_PORTABILITY:
				return "PORTABILITY";

			case GL_DEBUG_TYPE_ERROR:
				return "ERROR";

			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
				return "U.B.";

			default:
				return "UNKNOWN";
			}
		}();

		// @ErrorLog
		// com_printf( "OpenGL: %s(%d): '%s'\n", type_str, id, message );
	}, nullptr );

	// @ErrorLog
	// com_printf( "OpenGL function pointers initialized.\n" );
}

#ifdef _MSC_VER
#pragma warning(push)
#else
#pragma pop
#endif
