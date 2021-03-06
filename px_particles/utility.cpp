#include "utility.hpp"

#include <cassert>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <random>

#include <SIMD/instrset.h>

void com_printf( char const* fmt, ... )
{
	// @Improvement: use variadic template arguments. When I tried to
	// use them at the time of writing this comment it gives me internal
	// compiler error. F. ~condzi, 26.10.2020
	va_list argptr;
	char msg[MAX_SIZE_STATIC_STRING];

	va_start( argptr, fmt );
	int const chars_written  = vsnprintf_s( msg, MAX_SIZE_STATIC_STRING, MAX_SIZE_STATIC_STRING-1, fmt, argptr );
	va_end( argptr );

	if ( chars_written == -1 ){
		com_printf( "!!! WARNING: vsnprintf_s returned -1!\n" );
		return;
	}
	if ( (unsigned)chars_written > MAX_SIZE_STATIC_STRING ){
		com_printf( "!!! WARNING: message buffer overflow!\n" );
		msg[MAX_SIZE_STATIC_STRING - 2] = '\n';
		msg[MAX_SIZE_STATIC_STRING - 1] = '\0';
	}

	bool const fputs_success = fputs( msg, stdout ) >= 0;
	assert( fputs_success );
}


void com_error( char const* fmt, ... )
{
	static bool com_error_entered = false;
	static char com_error_message[MAX_SIZE_STATIC_STRING];

	if ( com_error_entered ){
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

void* mem_alloc( unsigned int size, unsigned int alignment )
{
	// @CrossPlatform: MSVC seem to not have std::aligned_alloc implemented. Weird. One solution
	// To this problem is to have an #ifndef _MSVC or something like that, then use _algined_malloc
	// in MSVC and std::aligned_alloc in other compilers.
	void* mem = _aligned_malloc( size, alignment );

	if ( mem == nullptr ){
		com_error( "mem_alloc got nullptr. size = %d, alignment = %d.\n", size, alignment );
	}

	return mem;
}

void mem_free( void* address )
{
	// @CrossPlatform: we have to use _aligned_free when we use _aligned_malloc.
	_aligned_free( address );

	// std::free( address );
}

int com_random( int min, int max )
{
	using namespace std::chrono;
	// Use the milliseconds as the seed
	static std::mt19937 rng{ static_cast<unsigned int>( duration_cast<milliseconds>( high_resolution_clock::now().time_since_epoch() ).count() ) };

	std::uniform_int_distribution<int> const bounds{ min, max };

	return bounds( rng );
}


EXE_Args parse_exe_args()
{
	// @Safety: check arguments for correctness.
	char** argv = __argv;
	unsigned int argc = __argc;
	EXE_Args args;

	if ( argc < 2 ){
		com_printf( "No command line arguments provided.\n" );
		return args;
	}
	com_printf( "%u command line arguments provided.\n", argc - 1 );

	// Starting from 1 because first argument it's the exe name.
	unsigned int i = 1;
	// Helper lambda, using memcmp we can easily make a mistake. 
	auto try_to_get_argument = [&]( char const* arg_name, auto& arg_to_assign ){
		size_t const arg_len = strlen( arg_name );

		if ( memcmp( argv[i], arg_name, arg_len ) == 0 ){
			if ( sscanf_s( argv[i] + arg_len, "%d", &arg_to_assign ) < 1 ){
				com_error( "sscanf_s failed for argument %s\n", argv[i] );
			}
			return true;
		}
		return false;
	};

	for ( ; i < argc; ++i ){
		if        ( try_to_get_argument( "-win_w=", args.win_w ) ){
			com_printf( " Window width  = %d\n", args.win_w );
		} else if ( try_to_get_argument( "-win_h=", args.win_h ) ){
			com_printf( " Window height = %d\n", args.win_h );
		} else if ( try_to_get_argument( "-fps=", args.fps ) ){
			com_printf( " FPS limit     = %d\n", args.fps );
		} else if ( try_to_get_argument( "-alignment=", args.alignment ) ) {
			com_printf( " Alignment     = %d\n", args.alignment );
		} else if ( try_to_get_argument( "-pulse_demo=", args.pulse_demo ) ) {
			com_printf( " Pulse demo    = %d (0 means off, non-zero means on)\n", args.pulse_demo );
		} else if ( try_to_get_argument( "-pulse_min=", args.pulse_min ) ) {
			com_printf( " Pulse min     = %dms\n", args.pulse_min );		
		} else if ( try_to_get_argument( "-pulse_max=", args.pulse_max ) ) {
			com_printf( " Pulse max     = %dms\n", args.pulse_max );
		} else if ( try_to_get_argument( "-use_lines=", args.use_lines ) ) {
			com_printf( " Use lines     = %d (0 means off, non-zero means on)\n", args.use_lines );
		}
	}

	return args;
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
