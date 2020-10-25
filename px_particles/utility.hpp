// ABOUT:
//  This file contains basic functions for logging, memory management and more.
//  We're also defining constants here.
#pragma once

//
// Constants
//
static constexpr unsigned int MAX_SIZE_STATIC_STRING = 4096;
static constexpr bool         REQUEST_DEDICATED_GPU  = true;

//
// Logging functions, work like a printf.
//

// Basic printf.
void com_printf( char const* fmt, ... );
// Printf + forcing application exit.
[[noreturn]] void com_error( char const* fmt, ... );

// Returns number of milliseconds since application startup.
// Should be called at the setup() to initialize itself.
int com_milliseconds();

//
// Wrappers for allocation and deallocation with error handling.
//

// Performs an aligned allocation. Alignment should be power of two.
[[nodiscard]] void* mem_alloc( unsigned int size, unsigned int aligment );
void mem_free( void* address );

[[nodiscard]] int com_random( int min, int max );

// Structure containing command line arguments values. 
// Names in the structure match names in the command line.
// usage: -name=value
struct EXE_Args 
{
	int win_w = 800;
	int win_h = 600;
	int fps   = 0; // 0 means no limit
	int alignment = 32;
	// @PulseDemo
	int pulse_demo = 0; // 0 is false, non-zero is true
	int pulse_min = 100;
	int pulse_max = 900;
};

[[nodiscard]] EXE_Args parse_exe_args();

// Returns the id of the instruction set detected by vectorclass library.
[[nodiscard]] int com_instruction_set_id();
[[nodiscard]] char const* com_instruction_set_name();

// Because we're storing our sf::Window object inside main,
// we have to have access to it when we want to close our application
// when an error occurs. See com_error function for usage.
// It should be defined in main.cpp
void force_window_close();
