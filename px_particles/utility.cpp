#include "utility.hpp"

#include <cassert>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <chrono>

#include <SIMD/instrset.h>

void com_printf( char const* fmt, ... )
{
	va_list argptr;
	char msg[MAX_SIZE_STATIC_STRING];

	va_start( argptr, fmt );
	int const chars_written  = vsnprintf_s( msg, MAX_SIZE_STATIC_STRING, MAX_SIZE_STATIC_STRING-1, fmt, argptr );
	va_end( argptr );

	if ( (unsigned)chars_written > MAX_SIZE_STATIC_STRING ) {
		com_printf( "!!! WARNING: message buffer overflow!\n" );
		msg[MAX_SIZE_STATIC_STRING - 2] = '\n';
		msg[MAX_SIZE_STATIC_STRING - 1] = '\0';
	}
	if ( chars_written == -1 ) {
		com_printf( "!!! WARNING: vsnprintf_s returned -1!\n" );
		return;
	}

	bool const fputs_success = fputs( msg, stdout ) >= 0;
	assert( fputs_success );
}

bool com_error_entered = false;
char com_error_message[MAX_SIZE_STATIC_STRING];

void com_error( char const* fmt, ... )
{
	if ( com_error_entered ) {
		com_printf( "!!! Recursive error after '%s'", com_error_message );
		// @DebugBreak
		assert( false );
	}

	com_error_entered = true;

	va_list argptr;

	va_start( argptr, fmt );
	vsprintf_s( com_error_message, fmt, argptr );
	va_end( argptr );

	com_printf( "!!! ERROR: %s", com_error_message );

	force_window_close();
	// @DebugBreak
	assert( false );

	std::exit( EXIT_FAILURE );
}

int com_milliseconds()
{
	using namespace std::chrono;
	auto const duration = high_resolution_clock::now().time_since_epoch();
	static auto const start_time = duration_cast<milliseconds>( duration ).count();
	auto const now = duration_cast<milliseconds>( duration ).count();

	return static_cast<int>( now - start_time );
}

void* mem_alloc( unsigned int size, unsigned int aligment )
{
	// @CrossPlatform: MSVC seem to not have std::aligned_alloc implemented. Weird. One solution
	// To this problem is to have an #ifndef _MSVC or something like that, then use _algined_malloc
	// in MSVC and std::aligned_alloc in other compilers.
	void* mem = _aligned_malloc( size, aligment );

	if ( mem == nullptr ) {
		com_error( "mem_alloc got nullptr. size = %d, aligment = %d.\n", size, aligment );
	}

	return mem;
}

void mem_free( void* address )
{
	// @CrossPlatform: we have to use _aligned_free when we use _aligned_malloc.
	_aligned_free( address );

	// std::free( address );
}

int com_instruction_set_id()
{
	static int instr_set = instrset_detect();
	return instr_set;
}

char const* com_instruction_set_name()
{
	switch ( com_instruction_set_id() ){
	case 0: return "80386 instruction set";
	case 1: return "SSE (XMM) supported by CPU (not testing for OS support)";
	case 2: return "SSE2";
	case 3: return "SSE3";
	case 4: return "Supplementary SSE3 (SSSE3)";
	case 5: return "SSE4.1";
	case 6: return "SSE4.2";
	case 7: return "AVX supported by CPU and operating system";
	case 8: return "AVX2";
	case 9: return "AVX512F";
	case 10: return  "AVX512VL, AVX512BW, AVX512DQ";

	default: return "unknown instruction set.";
	}
}