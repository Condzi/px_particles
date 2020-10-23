// ReSharper disable CppInconsistentNaming
#pragma once

#ifdef __gl_h_
#error Do not include OpenGL  before this header
#endif
#define __gl_h_

#include "khr/khrplatform.h"

#ifdef _WIN32
#define APIENTRY __stdcall
#else
#define APIENTRY
#endif


void gl_init();


typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef khronos_int8_t GLbyte;
typedef khronos_uint8_t GLubyte;
typedef khronos_int16_t GLshort;
typedef khronos_uint16_t GLushort;
typedef int GLint;
typedef unsigned int GLuint;
typedef khronos_int32_t GLclampx;
typedef int GLsizei;
typedef khronos_float_t GLfloat;
typedef khronos_float_t GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void* GLeglClientBufferEXT;
typedef void* GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;
#ifdef __APPLE__
typedef void* GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
typedef khronos_uint16_t GLhalf;
typedef khronos_uint16_t GLhalfARB;
typedef khronos_int32_t GLfixed;
typedef khronos_intptr_t GLintptr;
typedef khronos_intptr_t GLintptrARB;
typedef khronos_ssize_t GLsizeiptr;
typedef khronos_ssize_t GLsizeiptrARB;
typedef khronos_int64_t GLint64;
typedef khronos_int64_t GLint64EXT;
typedef khronos_uint64_t GLuint64;
typedef khronos_uint64_t GLuint64EXT;
typedef struct __GLsync* GLsync;
typedef void ( APIENTRY* GLDEBUGPROC )( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
										const GLchar* message, const void* userParam );
typedef void ( APIENTRY* GLDEBUGPROCARB )( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
										   const GLchar* message, const void* userParam );
typedef void ( APIENTRY* GLDEBUGPROCKHR )( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
										   const GLchar* message, const void* userParam );
typedef void ( APIENTRY* GLDEBUGPROCAMD )( GLuint id, GLenum category, GLenum severity, GLsizei length,
										   const GLchar* message, void* userParam );
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;
typedef void ( APIENTRY* GLVULKANPROCNV )();


constexpr GLenum GL_DEPTH_BUFFER_BIT = 0x00000100;
constexpr GLenum GL_STENCIL_BUFFER_BIT = 0x00000400;
constexpr GLenum GL_COLOR_BUFFER_BIT = 0x00004000;
constexpr GLenum GL_DYNAMIC_STORAGE_BIT = 0x0100;
constexpr GLenum GL_CLIENT_STORAGE_BIT = 0x0200;
constexpr GLenum GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = 0x00000001;
constexpr GLenum GL_CONTEXT_FLAG_DEBUG_BIT = 0x00000002;
constexpr GLenum GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT = 0x00000004;
constexpr GLenum GL_CONTEXT_CORE_PROFILE_BIT = 0x00000001;
constexpr GLenum GL_CONTEXT_COMPATIBILITY_PROFILE_BIT = 0x00000002;
constexpr GLenum GL_MAP_READ_BIT = 0x0001;
constexpr GLenum GL_MAP_WRITE_BIT = 0x0002;
constexpr GLenum GL_MAP_INVALIDATE_RANGE_BIT = 0x0004;
constexpr GLenum GL_MAP_INVALIDATE_BUFFER_BIT = 0x0008;
constexpr GLenum GL_MAP_FLUSH_EXPLICIT_BIT = 0x0010;
constexpr GLenum GL_MAP_UNSYNCHRONIZED_BIT = 0x0020;
constexpr GLenum GL_MAP_PERSISTENT_BIT = 0x0040;
constexpr GLenum GL_MAP_COHERENT_BIT = 0x0080;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT = 0x00000001;
constexpr GLenum GL_ELEMENT_ARRAY_BARRIER_BIT = 0x00000002;
constexpr GLenum GL_UNIFORM_BARRIER_BIT = 0x00000004;
constexpr GLenum GL_TEXTURE_FETCH_BARRIER_BIT = 0x00000008;
constexpr GLenum GL_SHADER_IMAGE_ACCESS_BARRIER_BIT = 0x00000020;
constexpr GLenum GL_COMMAND_BARRIER_BIT = 0x00000040;
constexpr GLenum GL_PIXEL_BUFFER_BARRIER_BIT = 0x00000080;
constexpr GLenum GL_TEXTURE_UPDATE_BARRIER_BIT = 0x00000100;
constexpr GLenum GL_BUFFER_UPDATE_BARRIER_BIT = 0x00000200;
constexpr GLenum GL_FRAMEBUFFER_BARRIER_BIT = 0x00000400;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BARRIER_BIT = 0x00000800;
constexpr GLenum GL_ATOMIC_COUNTER_BARRIER_BIT = 0x00001000;
constexpr GLenum GL_SHADER_STORAGE_BARRIER_BIT = 0x00002000;
constexpr GLenum GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT = 0x00004000;
constexpr GLenum GL_QUERY_BUFFER_BARRIER_BIT = 0x00008000;
constexpr GLenum GL_ALL_BARRIER_BITS = 0xFFFFFFFF;
constexpr GLenum GL_SYNC_FLUSH_COMMANDS_BIT = 0x00000001;
constexpr GLenum GL_VERTEX_SHADER_BIT = 0x00000001;
constexpr GLenum GL_FRAGMENT_SHADER_BIT = 0x00000002;
constexpr GLenum GL_GEOMETRY_SHADER_BIT = 0x00000004;
constexpr GLenum GL_TESS_CONTROL_SHADER_BIT = 0x00000008;
constexpr GLenum GL_TESS_EVALUATION_SHADER_BIT = 0x00000010;
constexpr GLenum GL_COMPUTE_SHADER_BIT = 0x00000020;
constexpr GLenum GL_ALL_SHADER_BITS = 0xFFFFFFFF;
constexpr GLenum GL_FALSE = 0;
constexpr GLenum GL_NO_ERROR = 0;
constexpr GLenum GL_ZERO = 0;
constexpr GLenum GL_NONE = 0;
constexpr GLenum GL_TRUE = 1;
constexpr GLenum GL_ONE = 1;
constexpr GLenum GL_INVALID_INDEX = 0xFFFFFFFF;
constexpr GLuint64 GL_TIMEOUT_IGNORED = 0xFFFFFFFFFFFFFFFF;
constexpr GLenum GL_POINTS = 0x0000;
constexpr GLenum GL_LINES = 0x0001;
constexpr GLenum GL_LINE_LOOP = 0x0002;
constexpr GLenum GL_LINE_STRIP = 0x0003;
constexpr GLenum GL_TRIANGLES = 0x0004;
constexpr GLenum GL_TRIANGLE_STRIP = 0x0005;
constexpr GLenum GL_TRIANGLE_FAN = 0x0006;
constexpr GLenum GL_QUADS = 0x0007;
constexpr GLenum GL_LINES_ADJACENCY = 0x000A;
constexpr GLenum GL_LINE_STRIP_ADJACENCY = 0x000B;
constexpr GLenum GL_TRIANGLES_ADJACENCY = 0x000C;
constexpr GLenum GL_TRIANGLE_STRIP_ADJACENCY = 0x000D;
constexpr GLenum GL_PATCHES = 0x000E;
constexpr GLenum GL_NEVER = 0x0200;
constexpr GLenum GL_LESS = 0x0201;
constexpr GLenum GL_EQUAL = 0x0202;
constexpr GLenum GL_LEQUAL = 0x0203;
constexpr GLenum GL_GREATER = 0x0204;
constexpr GLenum GL_NOTEQUAL = 0x0205;
constexpr GLenum GL_GEQUAL = 0x0206;
constexpr GLenum GL_ALWAYS = 0x0207;
constexpr GLenum GL_SRC_COLOR = 0x0300;
constexpr GLenum GL_ONE_MINUS_SRC_COLOR = 0x0301;
constexpr GLenum GL_SRC_ALPHA = 0x0302;
constexpr GLenum GL_ONE_MINUS_SRC_ALPHA = 0x0303;
constexpr GLenum GL_DST_ALPHA = 0x0304;
constexpr GLenum GL_ONE_MINUS_DST_ALPHA = 0x0305;
constexpr GLenum GL_DST_COLOR = 0x0306;
constexpr GLenum GL_ONE_MINUS_DST_COLOR = 0x0307;
constexpr GLenum GL_SRC_ALPHA_SATURATE = 0x0308;
constexpr GLenum GL_FRONT_LEFT = 0x0400;
constexpr GLenum GL_FRONT_RIGHT = 0x0401;
constexpr GLenum GL_BACK_LEFT = 0x0402;
constexpr GLenum GL_BACK_RIGHT = 0x0403;
constexpr GLenum GL_FRONT = 0x0404;
constexpr GLenum GL_BACK = 0x0405;
constexpr GLenum GL_LEFT = 0x0406;
constexpr GLenum GL_RIGHT = 0x0407;
constexpr GLenum GL_FRONT_AND_BACK = 0x0408;
constexpr GLenum GL_INVALID_ENUM = 0x0500;
constexpr GLenum GL_INVALID_VALUE = 0x0501;
constexpr GLenum GL_INVALID_OPERATION = 0x0502;
constexpr GLenum GL_STACK_OVERFLOW = 0x0503;
constexpr GLenum GL_STACK_UNDERFLOW = 0x0504;
constexpr GLenum GL_OUT_OF_MEMORY = 0x0505;
constexpr GLenum GL_INVALID_FRAMEBUFFER_OPERATION = 0x0506;
constexpr GLenum GL_CONTEXT_LOST = 0x0507;
constexpr GLenum GL_CW = 0x0900;
constexpr GLenum GL_CCW = 0x0901;
constexpr GLenum GL_POINT_SIZE = 0x0B11;
constexpr GLenum GL_POINT_SIZE_RANGE = 0x0B12;
constexpr GLenum GL_SMOOTH_POINT_SIZE_RANGE = 0x0B12;
constexpr GLenum GL_POINT_SIZE_GRANULARITY = 0x0B13;
constexpr GLenum GL_SMOOTH_POINT_SIZE_GRANULARITY = 0x0B13;
constexpr GLenum GL_LINE_SMOOTH = 0x0B20;
constexpr GLenum GL_LINE_WIDTH = 0x0B21;
constexpr GLenum GL_LINE_WIDTH_RANGE = 0x0B22;
constexpr GLenum GL_SMOOTH_LINE_WIDTH_RANGE = 0x0B22;
constexpr GLenum GL_LINE_WIDTH_GRANULARITY = 0x0B23;
constexpr GLenum GL_SMOOTH_LINE_WIDTH_GRANULARITY = 0x0B23;
constexpr GLenum GL_POLYGON_MODE = 0x0B40;
constexpr GLenum GL_POLYGON_SMOOTH = 0x0B41;
constexpr GLenum GL_CULL_FACE = 0x0B44;
constexpr GLenum GL_CULL_FACE_MODE = 0x0B45;
constexpr GLenum GL_FRONT_FACE = 0x0B46;
constexpr GLenum GL_DEPTH_RANGE = 0x0B70;
constexpr GLenum GL_DEPTH_TEST = 0x0B71;
constexpr GLenum GL_DEPTH_WRITEMASK = 0x0B72;
constexpr GLenum GL_DEPTH_CLEAR_VALUE = 0x0B73;
constexpr GLenum GL_DEPTH_FUNC = 0x0B74;
constexpr GLenum GL_STENCIL_TEST = 0x0B90;
constexpr GLenum GL_STENCIL_CLEAR_VALUE = 0x0B91;
constexpr GLenum GL_STENCIL_FUNC = 0x0B92;
constexpr GLenum GL_STENCIL_VALUE_MASK = 0x0B93;
constexpr GLenum GL_STENCIL_FAIL = 0x0B94;
constexpr GLenum GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95;
constexpr GLenum GL_STENCIL_PASS_DEPTH_PASS = 0x0B96;
constexpr GLenum GL_STENCIL_REF = 0x0B97;
constexpr GLenum GL_STENCIL_WRITEMASK = 0x0B98;
constexpr GLenum GL_VIEWPORT = 0x0BA2;
constexpr GLenum GL_DITHER = 0x0BD0;
constexpr GLenum GL_BLEND_DST = 0x0BE0;
constexpr GLenum GL_BLEND_SRC = 0x0BE1;
constexpr GLenum GL_BLEND = 0x0BE2;
constexpr GLenum GL_LOGIC_OP_MODE = 0x0BF0;
constexpr GLenum GL_COLOR_LOGIC_OP = 0x0BF2;
constexpr GLenum GL_DRAW_BUFFER = 0x0C01;
constexpr GLenum GL_READ_BUFFER = 0x0C02;
constexpr GLenum GL_SCISSOR_BOX = 0x0C10;
constexpr GLenum GL_SCISSOR_TEST = 0x0C11;
constexpr GLenum GL_COLOR_CLEAR_VALUE = 0x0C22;
constexpr GLenum GL_COLOR_WRITEMASK = 0x0C23;
constexpr GLenum GL_DOUBLEBUFFER = 0x0C32;
constexpr GLenum GL_STEREO = 0x0C33;
constexpr GLenum GL_LINE_SMOOTH_HINT = 0x0C52;
constexpr GLenum GL_POLYGON_SMOOTH_HINT = 0x0C53;
constexpr GLenum GL_UNPACK_SWAP_BYTES = 0x0CF0;
constexpr GLenum GL_UNPACK_LSB_FIRST = 0x0CF1;
constexpr GLenum GL_UNPACK_ROW_LENGTH = 0x0CF2;
constexpr GLenum GL_UNPACK_SKIP_ROWS = 0x0CF3;
constexpr GLenum GL_UNPACK_SKIP_PIXELS = 0x0CF4;
constexpr GLenum GL_UNPACK_ALIGNMENT = 0x0CF5;
constexpr GLenum GL_PACK_SWAP_BYTES = 0x0D00;
constexpr GLenum GL_PACK_LSB_FIRST = 0x0D01;
constexpr GLenum GL_PACK_ROW_LENGTH = 0x0D02;
constexpr GLenum GL_PACK_SKIP_ROWS = 0x0D03;
constexpr GLenum GL_PACK_SKIP_PIXELS = 0x0D04;
constexpr GLenum GL_PACK_ALIGNMENT = 0x0D05;
constexpr GLenum GL_MAX_CLIP_DISTANCES = 0x0D32;
constexpr GLenum GL_MAX_TEXTURE_SIZE = 0x0D33;
constexpr GLenum GL_MAX_VIEWPORT_DIMS = 0x0D3A;
constexpr GLenum GL_SUBPIXEL_BITS = 0x0D50;
constexpr GLenum GL_TEXTURE_1D = 0x0DE0;
constexpr GLenum GL_TEXTURE_2D = 0x0DE1;
constexpr GLenum GL_TEXTURE_WIDTH = 0x1000;
constexpr GLenum GL_TEXTURE_HEIGHT = 0x1001;
constexpr GLenum GL_TEXTURE_INTERNAL_FORMAT = 0x1003;
constexpr GLenum GL_TEXTURE_BORDER_COLOR = 0x1004;
constexpr GLenum GL_TEXTURE_TARGET = 0x1006;
constexpr GLenum GL_DONT_CARE = 0x1100;
constexpr GLenum GL_FASTEST = 0x1101;
constexpr GLenum GL_NICEST = 0x1102;
constexpr GLenum GL_BYTE = 0x1400;
constexpr GLenum GL_UNSIGNED_BYTE = 0x1401;
constexpr GLenum GL_SHORT = 0x1402;
constexpr GLenum GL_UNSIGNED_SHORT = 0x1403;
constexpr GLenum GL_INT = 0x1404;
constexpr GLenum GL_UNSIGNED_INT = 0x1405;
constexpr GLenum GL_FLOAT = 0x1406;
constexpr GLenum GL_DOUBLE = 0x140A;
constexpr GLenum GL_HALF_FLOAT = 0x140B;
constexpr GLenum GL_FIXED = 0x140C;
constexpr GLenum GL_CLEAR = 0x1500;
constexpr GLenum GL_AND = 0x1501;
constexpr GLenum GL_AND_REVERSE = 0x1502;
constexpr GLenum GL_COPY = 0x1503;
constexpr GLenum GL_AND_INVERTED = 0x1504;
constexpr GLenum GL_NOOP = 0x1505;
constexpr GLenum GL_XOR = 0x1506;
constexpr GLenum GL_OR = 0x1507;
constexpr GLenum GL_NOR = 0x1508;
constexpr GLenum GL_EQUIV = 0x1509;
constexpr GLenum GL_INVERT = 0x150A;
constexpr GLenum GL_OR_REVERSE = 0x150B;
constexpr GLenum GL_COPY_INVERTED = 0x150C;
constexpr GLenum GL_OR_INVERTED = 0x150D;
constexpr GLenum GL_NAND = 0x150E;
constexpr GLenum GL_SET = 0x150F;
constexpr GLenum GL_TEXTURE = 0x1702;
constexpr GLenum GL_COLOR = 0x1800;
constexpr GLenum GL_DEPTH = 0x1801;
constexpr GLenum GL_STENCIL = 0x1802;
constexpr GLenum GL_STENCIL_INDEX = 0x1901;
constexpr GLenum GL_DEPTH_COMPONENT = 0x1902;
constexpr GLenum GL_RED = 0x1903;
constexpr GLenum GL_GREEN = 0x1904;
constexpr GLenum GL_BLUE = 0x1905;
constexpr GLenum GL_ALPHA = 0x1906;
constexpr GLenum GL_RGB = 0x1907;
constexpr GLenum GL_RGBA = 0x1908;
constexpr GLenum GL_POINT = 0x1B00;
constexpr GLenum GL_LINE = 0x1B01;
constexpr GLenum GL_FILL = 0x1B02;
constexpr GLenum GL_KEEP = 0x1E00;
constexpr GLenum GL_REPLACE = 0x1E01;
constexpr GLenum GL_INCR = 0x1E02;
constexpr GLenum GL_DECR = 0x1E03;
constexpr GLenum GL_VENDOR = 0x1F00;
constexpr GLenum GL_RENDERER = 0x1F01;
constexpr GLenum GL_VERSION = 0x1F02;
constexpr GLenum GL_EXTENSIONS = 0x1F03;
constexpr GLenum GL_NEAREST = 0x2600;
constexpr GLenum GL_LINEAR = 0x2601;
constexpr GLenum GL_NEAREST_MIPMAP_NEAREST = 0x2700;
constexpr GLenum GL_LINEAR_MIPMAP_NEAREST = 0x2701;
constexpr GLenum GL_NEAREST_MIPMAP_LINEAR = 0x2702;
constexpr GLenum GL_LINEAR_MIPMAP_LINEAR = 0x2703;
constexpr GLenum GL_TEXTURE_MAG_FILTER = 0x2800;
constexpr GLenum GL_TEXTURE_MIN_FILTER = 0x2801;
constexpr GLenum GL_TEXTURE_WRAP_S = 0x2802;
constexpr GLenum GL_TEXTURE_WRAP_T = 0x2803;
constexpr GLenum GL_REPEAT = 0x2901;
constexpr GLenum GL_POLYGON_OFFSET_UNITS = 0x2A00;
constexpr GLenum GL_POLYGON_OFFSET_POINT = 0x2A01;
constexpr GLenum GL_POLYGON_OFFSET_LINE = 0x2A02;
constexpr GLenum GL_R3_G3_B2 = 0x2A10;
constexpr GLenum GL_CLIP_DISTANCE0 = 0x3000;
constexpr GLenum GL_CLIP_DISTANCE1 = 0x3001;
constexpr GLenum GL_CLIP_DISTANCE2 = 0x3002;
constexpr GLenum GL_CLIP_DISTANCE3 = 0x3003;
constexpr GLenum GL_CLIP_DISTANCE4 = 0x3004;
constexpr GLenum GL_CLIP_DISTANCE5 = 0x3005;
constexpr GLenum GL_CLIP_DISTANCE6 = 0x3006;
constexpr GLenum GL_CLIP_DISTANCE7 = 0x3007;
constexpr GLenum GL_CONSTANT_COLOR = 0x8001;
constexpr GLenum GL_ONE_MINUS_CONSTANT_COLOR = 0x8002;
constexpr GLenum GL_CONSTANT_ALPHA = 0x8003;
constexpr GLenum GL_ONE_MINUS_CONSTANT_ALPHA = 0x8004;
constexpr GLenum GL_BLEND_COLOR = 0x8005;
constexpr GLenum GL_FUNC_ADD = 0x8006;
constexpr GLenum GL_MIN = 0x8007;
constexpr GLenum GL_MAX = 0x8008;
constexpr GLenum GL_BLEND_EQUATION = 0x8009;
constexpr GLenum GL_BLEND_EQUATION_RGB = 0x8009;
constexpr GLenum GL_FUNC_SUBTRACT = 0x800A;
constexpr GLenum GL_FUNC_REVERSE_SUBTRACT = 0x800B;
constexpr GLenum GL_UNSIGNED_BYTE_3_3_2 = 0x8032;
constexpr GLenum GL_UNSIGNED_SHORT_4_4_4_4 = 0x8033;
constexpr GLenum GL_UNSIGNED_SHORT_5_5_5_1 = 0x8034;
constexpr GLenum GL_UNSIGNED_INT_8_8_8_8 = 0x8035;
constexpr GLenum GL_UNSIGNED_INT_10_10_10_2 = 0x8036;
constexpr GLenum GL_POLYGON_OFFSET_FILL = 0x8037;
constexpr GLenum GL_POLYGON_OFFSET_FACTOR = 0x8038;
constexpr GLenum GL_RGB4 = 0x804F;
constexpr GLenum GL_RGB5 = 0x8050;
constexpr GLenum GL_RGB8 = 0x8051;
constexpr GLenum GL_RGB10 = 0x8052;
constexpr GLenum GL_RGB12 = 0x8053;
constexpr GLenum GL_RGB16 = 0x8054;
constexpr GLenum GL_RGBA2 = 0x8055;
constexpr GLenum GL_RGBA4 = 0x8056;
constexpr GLenum GL_RGB5_A1 = 0x8057;
constexpr GLenum GL_RGBA8 = 0x8058;
constexpr GLenum GL_RGB10_A2 = 0x8059;
constexpr GLenum GL_RGBA12 = 0x805A;
constexpr GLenum GL_RGBA16 = 0x805B;
constexpr GLenum GL_TEXTURE_RED_SIZE = 0x805C;
constexpr GLenum GL_TEXTURE_GREEN_SIZE = 0x805D;
constexpr GLenum GL_TEXTURE_BLUE_SIZE = 0x805E;
constexpr GLenum GL_TEXTURE_ALPHA_SIZE = 0x805F;
constexpr GLenum GL_PROXY_TEXTURE_1D = 0x8063;
constexpr GLenum GL_PROXY_TEXTURE_2D = 0x8064;
constexpr GLenum GL_TEXTURE_BINDING_1D = 0x8068;
constexpr GLenum GL_TEXTURE_BINDING_2D = 0x8069;
constexpr GLenum GL_TEXTURE_BINDING_3D = 0x806A;
constexpr GLenum GL_PACK_SKIP_IMAGES = 0x806B;
constexpr GLenum GL_PACK_IMAGE_HEIGHT = 0x806C;
constexpr GLenum GL_UNPACK_SKIP_IMAGES = 0x806D;
constexpr GLenum GL_UNPACK_IMAGE_HEIGHT = 0x806E;
constexpr GLenum GL_TEXTURE_3D = 0x806F;
constexpr GLenum GL_PROXY_TEXTURE_3D = 0x8070;
constexpr GLenum GL_TEXTURE_DEPTH = 0x8071;
constexpr GLenum GL_TEXTURE_WRAP_R = 0x8072;
constexpr GLenum GL_MAX_3D_TEXTURE_SIZE = 0x8073;
constexpr GLenum GL_VERTEX_ARRAY = 0x8074;
constexpr GLenum GL_MULTISAMPLE = 0x809D;
constexpr GLenum GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809E;
constexpr GLenum GL_SAMPLE_ALPHA_TO_ONE = 0x809F;
constexpr GLenum GL_SAMPLE_COVERAGE = 0x80A0;
constexpr GLenum GL_SAMPLE_BUFFERS = 0x80A8;
constexpr GLenum GL_SAMPLES = 0x80A9;
constexpr GLenum GL_SAMPLE_COVERAGE_VALUE = 0x80AA;
constexpr GLenum GL_SAMPLE_COVERAGE_INVERT = 0x80AB;
constexpr GLenum GL_BLEND_DST_RGB = 0x80C8;
constexpr GLenum GL_BLEND_SRC_RGB = 0x80C9;
constexpr GLenum GL_BLEND_DST_ALPHA = 0x80CA;
constexpr GLenum GL_BLEND_SRC_ALPHA = 0x80CB;
constexpr GLenum GL_BGR = 0x80E0;
constexpr GLenum GL_BGRA = 0x80E1;
constexpr GLenum GL_MAX_ELEMENTS_VERTICES = 0x80E8;
constexpr GLenum GL_MAX_ELEMENTS_INDICES = 0x80E9;
constexpr GLenum GL_POINT_FADE_THRESHOLD_SIZE = 0x8128;
constexpr GLenum GL_CLAMP_TO_BORDER = 0x812D;
constexpr GLenum GL_CLAMP_TO_EDGE = 0x812F;
constexpr GLenum GL_TEXTURE_MIN_LOD = 0x813A;
constexpr GLenum GL_TEXTURE_MAX_LOD = 0x813B;
constexpr GLenum GL_TEXTURE_BASE_LEVEL = 0x813C;
constexpr GLenum GL_TEXTURE_MAX_LEVEL = 0x813D;
constexpr GLenum GL_DEPTH_COMPONENT16 = 0x81A5;
constexpr GLenum GL_DEPTH_COMPONENT24 = 0x81A6;
constexpr GLenum GL_DEPTH_COMPONENT32 = 0x81A7;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT = 0x8218;
constexpr GLenum GL_FRAMEBUFFER_UNDEFINED = 0x8219;
constexpr GLenum GL_DEPTH_STENCIL_ATTACHMENT = 0x821A;
constexpr GLenum GL_MAJOR_VERSION = 0x821B;
constexpr GLenum GL_MINOR_VERSION = 0x821C;
constexpr GLenum GL_NUM_EXTENSIONS = 0x821D;
constexpr GLenum GL_CONTEXT_FLAGS = 0x821E;
constexpr GLenum GL_BUFFER_IMMUTABLE_STORAGE = 0x821F;
constexpr GLenum GL_BUFFER_STORAGE_FLAGS = 0x8220;
constexpr GLenum GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED = 0x8221;
constexpr GLenum GL_COMPRESSED_RED = 0x8225;
constexpr GLenum GL_COMPRESSED_RG = 0x8226;
constexpr GLenum GL_RG = 0x8227;
constexpr GLenum GL_RG_INTEGER = 0x8228;
constexpr GLenum GL_R8 = 0x8229;
constexpr GLenum GL_R16 = 0x822A;
constexpr GLenum GL_RG8 = 0x822B;
constexpr GLenum GL_RG16 = 0x822C;
constexpr GLenum GL_R16F = 0x822D;
constexpr GLenum GL_R32F = 0x822E;
constexpr GLenum GL_RG16F = 0x822F;
constexpr GLenum GL_RG32F = 0x8230;
constexpr GLenum GL_R8I = 0x8231;
constexpr GLenum GL_R8UI = 0x8232;
constexpr GLenum GL_R16I = 0x8233;
constexpr GLenum GL_R16UI = 0x8234;
constexpr GLenum GL_R32I = 0x8235;
constexpr GLenum GL_R32UI = 0x8236;
constexpr GLenum GL_RG8I = 0x8237;
constexpr GLenum GL_RG8UI = 0x8238;
constexpr GLenum GL_RG16I = 0x8239;
constexpr GLenum GL_RG16UI = 0x823A;
constexpr GLenum GL_RG32I = 0x823B;
constexpr GLenum GL_RG32UI = 0x823C;
constexpr GLenum GL_DEBUG_OUTPUT_SYNCHRONOUS = 0x8242;
constexpr GLenum GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH = 0x8243;
constexpr GLenum GL_DEBUG_CALLBACK_FUNCTION = 0x8244;
constexpr GLenum GL_DEBUG_CALLBACK_USER_PARAM = 0x8245;
constexpr GLenum GL_DEBUG_SOURCE_API = 0x8246;
constexpr GLenum GL_DEBUG_SOURCE_WINDOW_SYSTEM = 0x8247;
constexpr GLenum GL_DEBUG_SOURCE_SHADER_COMPILER = 0x8248;
constexpr GLenum GL_DEBUG_SOURCE_THIRD_PARTY = 0x8249;
constexpr GLenum GL_DEBUG_SOURCE_APPLICATION = 0x824A;
constexpr GLenum GL_DEBUG_SOURCE_OTHER = 0x824B;
constexpr GLenum GL_DEBUG_TYPE_ERROR = 0x824C;
constexpr GLenum GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR = 0x824D;
constexpr GLenum GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR = 0x824E;
constexpr GLenum GL_DEBUG_TYPE_PORTABILITY = 0x824F;
constexpr GLenum GL_DEBUG_TYPE_PERFORMANCE = 0x8250;
constexpr GLenum GL_DEBUG_TYPE_OTHER = 0x8251;
constexpr GLenum GL_LOSE_CONTEXT_ON_RESET = 0x8252;
constexpr GLenum GL_GUILTY_CONTEXT_RESET = 0x8253;
constexpr GLenum GL_INNOCENT_CONTEXT_RESET = 0x8254;
constexpr GLenum GL_UNKNOWN_CONTEXT_RESET = 0x8255;
constexpr GLenum GL_RESET_NOTIFICATION_STRATEGY = 0x8256;
constexpr GLenum GL_PROGRAM_BINARY_RETRIEVABLE_HINT = 0x8257;
constexpr GLenum GL_PROGRAM_SEPARABLE = 0x8258;
constexpr GLenum GL_ACTIVE_PROGRAM = 0x8259;
constexpr GLenum GL_PROGRAM_PIPELINE_BINDING = 0x825A;
constexpr GLenum GL_MAX_VIEWPORTS = 0x825B;
constexpr GLenum GL_VIEWPORT_SUBPIXEL_BITS = 0x825C;
constexpr GLenum GL_VIEWPORT_BOUNDS_RANGE = 0x825D;
constexpr GLenum GL_LAYER_PROVOKING_VERTEX = 0x825E;
constexpr GLenum GL_VIEWPORT_INDEX_PROVOKING_VERTEX = 0x825F;
constexpr GLenum GL_UNDEFINED_VERTEX = 0x8260;
constexpr GLenum GL_NO_RESET_NOTIFICATION = 0x8261;
constexpr GLenum GL_MAX_COMPUTE_SHARED_MEMORY_SIZE = 0x8262;
constexpr GLenum GL_MAX_COMPUTE_UNIFORM_COMPONENTS = 0x8263;
constexpr GLenum GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS = 0x8264;
constexpr GLenum GL_MAX_COMPUTE_ATOMIC_COUNTERS = 0x8265;
constexpr GLenum GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS = 0x8266;
constexpr GLenum GL_COMPUTE_WORK_GROUP_SIZE = 0x8267;
constexpr GLenum GL_DEBUG_TYPE_MARKER = 0x8268;
constexpr GLenum GL_DEBUG_TYPE_PUSH_GROUP = 0x8269;
constexpr GLenum GL_DEBUG_TYPE_POP_GROUP = 0x826A;
constexpr GLenum GL_DEBUG_SEVERITY_NOTIFICATION = 0x826B;
constexpr GLenum GL_MAX_DEBUG_GROUP_STACK_DEPTH = 0x826C;
constexpr GLenum GL_DEBUG_GROUP_STACK_DEPTH = 0x826D;
constexpr GLenum GL_MAX_UNIFORM_LOCATIONS = 0x826E;
constexpr GLenum GL_INTERNALFORMAT_SUPPORTED = 0x826F;
constexpr GLenum GL_INTERNALFORMAT_PREFERRED = 0x8270;
constexpr GLenum GL_INTERNALFORMAT_RED_SIZE = 0x8271;
constexpr GLenum GL_INTERNALFORMAT_GREEN_SIZE = 0x8272;
constexpr GLenum GL_INTERNALFORMAT_BLUE_SIZE = 0x8273;
constexpr GLenum GL_INTERNALFORMAT_ALPHA_SIZE = 0x8274;
constexpr GLenum GL_INTERNALFORMAT_DEPTH_SIZE = 0x8275;
constexpr GLenum GL_INTERNALFORMAT_STENCIL_SIZE = 0x8276;
constexpr GLenum GL_INTERNALFORMAT_SHARED_SIZE = 0x8277;
constexpr GLenum GL_INTERNALFORMAT_RED_TYPE = 0x8278;
constexpr GLenum GL_INTERNALFORMAT_GREEN_TYPE = 0x8279;
constexpr GLenum GL_INTERNALFORMAT_BLUE_TYPE = 0x827A;
constexpr GLenum GL_INTERNALFORMAT_ALPHA_TYPE = 0x827B;
constexpr GLenum GL_INTERNALFORMAT_DEPTH_TYPE = 0x827C;
constexpr GLenum GL_INTERNALFORMAT_STENCIL_TYPE = 0x827D;
constexpr GLenum GL_MAX_WIDTH = 0x827E;
constexpr GLenum GL_MAX_HEIGHT = 0x827F;
constexpr GLenum GL_MAX_DEPTH = 0x8280;
constexpr GLenum GL_MAX_LAYERS = 0x8281;
constexpr GLenum GL_MAX_COMBINED_DIMENSIONS = 0x8282;
constexpr GLenum GL_COLOR_COMPONENTS = 0x8283;
constexpr GLenum GL_DEPTH_COMPONENTS = 0x8284;
constexpr GLenum GL_STENCIL_COMPONENTS = 0x8285;
constexpr GLenum GL_COLOR_RENDERABLE = 0x8286;
constexpr GLenum GL_DEPTH_RENDERABLE = 0x8287;
constexpr GLenum GL_STENCIL_RENDERABLE = 0x8288;
constexpr GLenum GL_FRAMEBUFFER_RENDERABLE = 0x8289;
constexpr GLenum GL_FRAMEBUFFER_RENDERABLE_LAYERED = 0x828A;
constexpr GLenum GL_FRAMEBUFFER_BLEND = 0x828B;
constexpr GLenum GL_READ_PIXELS = 0x828C;
constexpr GLenum GL_READ_PIXELS_FORMAT = 0x828D;
constexpr GLenum GL_READ_PIXELS_TYPE = 0x828E;
constexpr GLenum GL_TEXTURE_IMAGE_FORMAT = 0x828F;
constexpr GLenum GL_TEXTURE_IMAGE_TYPE = 0x8290;
constexpr GLenum GL_GET_TEXTURE_IMAGE_FORMAT = 0x8291;
constexpr GLenum GL_GET_TEXTURE_IMAGE_TYPE = 0x8292;
constexpr GLenum GL_MIPMAP = 0x8293;
constexpr GLenum GL_MANUAL_GENERATE_MIPMAP = 0x8294;
constexpr GLenum GL_AUTO_GENERATE_MIPMAP = 0x8295;
constexpr GLenum GL_COLOR_ENCODING = 0x8296;
constexpr GLenum GL_SRGB_READ = 0x8297;
constexpr GLenum GL_SRGB_WRITE = 0x8298;
constexpr GLenum GL_FILTER = 0x829A;
constexpr GLenum GL_VERTEX_TEXTURE = 0x829B;
constexpr GLenum GL_TESS_CONTROL_TEXTURE = 0x829C;
constexpr GLenum GL_TESS_EVALUATION_TEXTURE = 0x829D;
constexpr GLenum GL_GEOMETRY_TEXTURE = 0x829E;
constexpr GLenum GL_FRAGMENT_TEXTURE = 0x829F;
constexpr GLenum GL_COMPUTE_TEXTURE = 0x82A0;
constexpr GLenum GL_TEXTURE_SHADOW = 0x82A1;
constexpr GLenum GL_TEXTURE_GATHER = 0x82A2;
constexpr GLenum GL_TEXTURE_GATHER_SHADOW = 0x82A3;
constexpr GLenum GL_SHADER_IMAGE_LOAD = 0x82A4;
constexpr GLenum GL_SHADER_IMAGE_STORE = 0x82A5;
constexpr GLenum GL_SHADER_IMAGE_ATOMIC = 0x82A6;
constexpr GLenum GL_IMAGE_TEXEL_SIZE = 0x82A7;
constexpr GLenum GL_IMAGE_COMPATIBILITY_CLASS = 0x82A8;
constexpr GLenum GL_IMAGE_PIXEL_FORMAT = 0x82A9;
constexpr GLenum GL_IMAGE_PIXEL_TYPE = 0x82AA;
constexpr GLenum GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST = 0x82AC;
constexpr GLenum GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST = 0x82AD;
constexpr GLenum GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE = 0x82AE;
constexpr GLenum GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE = 0x82AF;
constexpr GLenum GL_TEXTURE_COMPRESSED_BLOCK_WIDTH = 0x82B1;
constexpr GLenum GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT = 0x82B2;
constexpr GLenum GL_TEXTURE_COMPRESSED_BLOCK_SIZE = 0x82B3;
constexpr GLenum GL_CLEAR_BUFFER = 0x82B4;
constexpr GLenum GL_TEXTURE_VIEW = 0x82B5;
constexpr GLenum GL_VIEW_COMPATIBILITY_CLASS = 0x82B6;
constexpr GLenum GL_FULL_SUPPORT = 0x82B7;
constexpr GLenum GL_CAVEAT_SUPPORT = 0x82B8;
constexpr GLenum GL_IMAGE_CLASS_4_X_32 = 0x82B9;
constexpr GLenum GL_IMAGE_CLASS_2_X_32 = 0x82BA;
constexpr GLenum GL_IMAGE_CLASS_1_X_32 = 0x82BB;
constexpr GLenum GL_IMAGE_CLASS_4_X_16 = 0x82BC;
constexpr GLenum GL_IMAGE_CLASS_2_X_16 = 0x82BD;
constexpr GLenum GL_IMAGE_CLASS_1_X_16 = 0x82BE;
constexpr GLenum GL_IMAGE_CLASS_4_X_8 = 0x82BF;
constexpr GLenum GL_IMAGE_CLASS_2_X_8 = 0x82C0;
constexpr GLenum GL_IMAGE_CLASS_1_X_8 = 0x82C1;
constexpr GLenum GL_IMAGE_CLASS_11_11_10 = 0x82C2;
constexpr GLenum GL_IMAGE_CLASS_10_10_10_2 = 0x82C3;
constexpr GLenum GL_VIEW_CLASS_128_BITS = 0x82C4;
constexpr GLenum GL_VIEW_CLASS_96_BITS = 0x82C5;
constexpr GLenum GL_VIEW_CLASS_64_BITS = 0x82C6;
constexpr GLenum GL_VIEW_CLASS_48_BITS = 0x82C7;
constexpr GLenum GL_VIEW_CLASS_32_BITS = 0x82C8;
constexpr GLenum GL_VIEW_CLASS_24_BITS = 0x82C9;
constexpr GLenum GL_VIEW_CLASS_16_BITS = 0x82CA;
constexpr GLenum GL_VIEW_CLASS_8_BITS = 0x82CB;
constexpr GLenum GL_VIEW_CLASS_S3TC_DXT1_RGB = 0x82CC;
constexpr GLenum GL_VIEW_CLASS_S3TC_DXT1_RGBA = 0x82CD;
constexpr GLenum GL_VIEW_CLASS_S3TC_DXT3_RGBA = 0x82CE;
constexpr GLenum GL_VIEW_CLASS_S3TC_DXT5_RGBA = 0x82CF;
constexpr GLenum GL_VIEW_CLASS_RGTC1_RED = 0x82D0;
constexpr GLenum GL_VIEW_CLASS_RGTC2_RG = 0x82D1;
constexpr GLenum GL_VIEW_CLASS_BPTC_UNORM = 0x82D2;
constexpr GLenum GL_VIEW_CLASS_BPTC_FLOAT = 0x82D3;
constexpr GLenum GL_VERTEX_ATTRIB_BINDING = 0x82D4;
constexpr GLenum GL_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D5;
constexpr GLenum GL_VERTEX_BINDING_DIVISOR = 0x82D6;
constexpr GLenum GL_VERTEX_BINDING_OFFSET = 0x82D7;
constexpr GLenum GL_VERTEX_BINDING_STRIDE = 0x82D8;
constexpr GLenum GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D9;
constexpr GLenum GL_MAX_VERTEX_ATTRIB_BINDINGS = 0x82DA;
constexpr GLenum GL_TEXTURE_VIEW_MIN_LEVEL = 0x82DB;
constexpr GLenum GL_TEXTURE_VIEW_NUM_LEVELS = 0x82DC;
constexpr GLenum GL_TEXTURE_VIEW_MIN_LAYER = 0x82DD;
constexpr GLenum GL_TEXTURE_VIEW_NUM_LAYERS = 0x82DE;
constexpr GLenum GL_TEXTURE_IMMUTABLE_LEVELS = 0x82DF;
constexpr GLenum GL_BUFFER = 0x82E0;
constexpr GLenum GL_SHADER = 0x82E1;
constexpr GLenum GL_PROGRAM = 0x82E2;
constexpr GLenum GL_QUERY = 0x82E3;
constexpr GLenum GL_PROGRAM_PIPELINE = 0x82E4;
constexpr GLenum GL_MAX_VERTEX_ATTRIB_STRIDE = 0x82E5;
constexpr GLenum GL_SAMPLER = 0x82E6;
constexpr GLenum GL_DISPLAY_LIST = 0x82E7;
constexpr GLenum GL_MAX_LABEL_LENGTH = 0x82E8;
constexpr GLenum GL_NUM_SHADING_LANGUAGE_VERSIONS = 0x82E9;
constexpr GLenum GL_QUERY_TARGET = 0x82EA;
constexpr GLenum GL_MAX_CULL_DISTANCES = 0x82F9;
constexpr GLenum GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES = 0x82FA;
constexpr GLenum GL_CONTEXT_RELEASE_BEHAVIOR = 0x82FB;
constexpr GLenum GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH = 0x82FC;
constexpr GLenum GL_UNSIGNED_BYTE_2_3_3_REV = 0x8362;
constexpr GLenum GL_UNSIGNED_SHORT_5_6_5 = 0x8363;
constexpr GLenum GL_UNSIGNED_SHORT_5_6_5_REV = 0x8364;
constexpr GLenum GL_UNSIGNED_SHORT_4_4_4_4_REV = 0x8365;
constexpr GLenum GL_UNSIGNED_SHORT_1_5_5_5_REV = 0x8366;
constexpr GLenum GL_UNSIGNED_INT_8_8_8_8_REV = 0x8367;
constexpr GLenum GL_UNSIGNED_INT_2_10_10_10_REV = 0x8368;
constexpr GLenum GL_MIRRORED_REPEAT = 0x8370;
constexpr GLenum GL_ALIASED_LINE_WIDTH_RANGE = 0x846E;
constexpr GLenum GL_TEXTURE0 = 0x84C0;
constexpr GLenum GL_TEXTURE1 = 0x84C1;
constexpr GLenum GL_TEXTURE2 = 0x84C2;
constexpr GLenum GL_TEXTURE3 = 0x84C3;
constexpr GLenum GL_TEXTURE4 = 0x84C4;
constexpr GLenum GL_TEXTURE5 = 0x84C5;
constexpr GLenum GL_TEXTURE6 = 0x84C6;
constexpr GLenum GL_TEXTURE7 = 0x84C7;
constexpr GLenum GL_TEXTURE8 = 0x84C8;
constexpr GLenum GL_TEXTURE9 = 0x84C9;
constexpr GLenum GL_TEXTURE10 = 0x84CA;
constexpr GLenum GL_TEXTURE11 = 0x84CB;
constexpr GLenum GL_TEXTURE12 = 0x84CC;
constexpr GLenum GL_TEXTURE13 = 0x84CD;
constexpr GLenum GL_TEXTURE14 = 0x84CE;
constexpr GLenum GL_TEXTURE15 = 0x84CF;
constexpr GLenum GL_TEXTURE16 = 0x84D0;
constexpr GLenum GL_TEXTURE17 = 0x84D1;
constexpr GLenum GL_TEXTURE18 = 0x84D2;
constexpr GLenum GL_TEXTURE19 = 0x84D3;
constexpr GLenum GL_TEXTURE20 = 0x84D4;
constexpr GLenum GL_TEXTURE21 = 0x84D5;
constexpr GLenum GL_TEXTURE22 = 0x84D6;
constexpr GLenum GL_TEXTURE23 = 0x84D7;
constexpr GLenum GL_TEXTURE24 = 0x84D8;
constexpr GLenum GL_TEXTURE25 = 0x84D9;
constexpr GLenum GL_TEXTURE26 = 0x84DA;
constexpr GLenum GL_TEXTURE27 = 0x84DB;
constexpr GLenum GL_TEXTURE28 = 0x84DC;
constexpr GLenum GL_TEXTURE29 = 0x84DD;
constexpr GLenum GL_TEXTURE30 = 0x84DE;
constexpr GLenum GL_TEXTURE31 = 0x84DF;
constexpr GLenum GL_ACTIVE_TEXTURE = 0x84E0;
constexpr GLenum GL_MAX_RENDERBUFFER_SIZE = 0x84E8;
constexpr GLenum GL_COMPRESSED_RGB = 0x84ED;
constexpr GLenum GL_COMPRESSED_RGBA = 0x84EE;
constexpr GLenum GL_TEXTURE_COMPRESSION_HINT = 0x84EF;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER = 0x84F0;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x84F1;
constexpr GLenum GL_TEXTURE_RECTANGLE = 0x84F5;
constexpr GLenum GL_TEXTURE_BINDING_RECTANGLE = 0x84F6;
constexpr GLenum GL_PROXY_TEXTURE_RECTANGLE = 0x84F7;
constexpr GLenum GL_MAX_RECTANGLE_TEXTURE_SIZE = 0x84F8;
constexpr GLenum GL_DEPTH_STENCIL = 0x84F9;
constexpr GLenum GL_UNSIGNED_INT_24_8 = 0x84FA;
constexpr GLenum GL_MAX_TEXTURE_LOD_BIAS = 0x84FD;
constexpr GLenum GL_TEXTURE_LOD_BIAS = 0x8501;
constexpr GLenum GL_INCR_WRAP = 0x8507;
constexpr GLenum GL_DECR_WRAP = 0x8508;
constexpr GLenum GL_TEXTURE_CUBE_MAP = 0x8513;
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP = 0x8514;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
constexpr GLenum GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
constexpr GLenum GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A;
constexpr GLenum GL_PROXY_TEXTURE_CUBE_MAP = 0x851B;
constexpr GLenum GL_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C;
constexpr GLenum GL_SRC1_ALPHA = 0x8589;
constexpr GLenum GL_VERTEX_ARRAY_BINDING = 0x85B5;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
constexpr GLenum GL_CURRENT_VERTEX_ATTRIB = 0x8626;
constexpr GLenum GL_VERTEX_PROGRAM_POINT_SIZE = 0x8642;
constexpr GLenum GL_PROGRAM_POINT_SIZE = 0x8642;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
constexpr GLenum GL_DEPTH_CLAMP = 0x864F;
constexpr GLenum GL_TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86A0;
constexpr GLenum GL_TEXTURE_COMPRESSED = 0x86A1;
constexpr GLenum GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
constexpr GLenum GL_COMPRESSED_TEXTURE_FORMATS = 0x86A3;
constexpr GLenum GL_PROGRAM_BINARY_LENGTH = 0x8741;
constexpr GLenum GL_MIRROR_CLAMP_TO_EDGE = 0x8743;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_LONG = 0x874E;
constexpr GLenum GL_BUFFER_SIZE = 0x8764;
constexpr GLenum GL_BUFFER_USAGE = 0x8765;
constexpr GLenum GL_NUM_PROGRAM_BINARY_FORMATS = 0x87FE;
constexpr GLenum GL_PROGRAM_BINARY_FORMATS = 0x87FF;
constexpr GLenum GL_STENCIL_BACK_FUNC = 0x8800;
constexpr GLenum GL_STENCIL_BACK_FAIL = 0x8801;
constexpr GLenum GL_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
constexpr GLenum GL_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
constexpr GLenum GL_RGBA32F = 0x8814;
constexpr GLenum GL_RGB32F = 0x8815;
constexpr GLenum GL_RGBA16F = 0x881A;
constexpr GLenum GL_RGB16F = 0x881B;
constexpr GLenum GL_MAX_DRAW_BUFFERS = 0x8824;
constexpr GLenum GL_DRAW_BUFFER0 = 0x8825;
constexpr GLenum GL_DRAW_BUFFER1 = 0x8826;
constexpr GLenum GL_DRAW_BUFFER2 = 0x8827;
constexpr GLenum GL_DRAW_BUFFER3 = 0x8828;
constexpr GLenum GL_DRAW_BUFFER4 = 0x8829;
constexpr GLenum GL_DRAW_BUFFER5 = 0x882A;
constexpr GLenum GL_DRAW_BUFFER6 = 0x882B;
constexpr GLenum GL_DRAW_BUFFER7 = 0x882C;
constexpr GLenum GL_DRAW_BUFFER8 = 0x882D;
constexpr GLenum GL_DRAW_BUFFER9 = 0x882E;
constexpr GLenum GL_DRAW_BUFFER10 = 0x882F;
constexpr GLenum GL_DRAW_BUFFER11 = 0x8830;
constexpr GLenum GL_DRAW_BUFFER12 = 0x8831;
constexpr GLenum GL_DRAW_BUFFER13 = 0x8832;
constexpr GLenum GL_DRAW_BUFFER14 = 0x8833;
constexpr GLenum GL_DRAW_BUFFER15 = 0x8834;
constexpr GLenum GL_BLEND_EQUATION_ALPHA = 0x883D;
constexpr GLenum GL_TEXTURE_DEPTH_SIZE = 0x884A;
constexpr GLenum GL_TEXTURE_COMPARE_MODE = 0x884C;
constexpr GLenum GL_TEXTURE_COMPARE_FUNC = 0x884D;
constexpr GLenum GL_COMPARE_REF_TO_TEXTURE = 0x884E;
constexpr GLenum GL_TEXTURE_CUBE_MAP_SEAMLESS = 0x884F;
constexpr GLenum GL_QUERY_COUNTER_BITS = 0x8864;
constexpr GLenum GL_CURRENT_QUERY = 0x8865;
constexpr GLenum GL_QUERY_RESULT = 0x8866;
constexpr GLenum GL_QUERY_RESULT_AVAILABLE = 0x8867;
constexpr GLenum GL_MAX_VERTEX_ATTRIBS = 0x8869;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A;
constexpr GLenum GL_MAX_TESS_CONTROL_INPUT_COMPONENTS = 0x886C;
constexpr GLenum GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS = 0x886D;
constexpr GLenum GL_MAX_TEXTURE_IMAGE_UNITS = 0x8872;
constexpr GLenum GL_GEOMETRY_SHADER_INVOCATIONS = 0x887F;
constexpr GLenum GL_ARRAY_BUFFER = 0x8892;
constexpr GLenum GL_ELEMENT_ARRAY_BUFFER = 0x8893;
constexpr GLenum GL_ARRAY_BUFFER_BINDING = 0x8894;
constexpr GLenum GL_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
constexpr GLenum GL_READ_ONLY = 0x88B8;
constexpr GLenum GL_WRITE_ONLY = 0x88B9;
constexpr GLenum GL_READ_WRITE = 0x88BA;
constexpr GLenum GL_BUFFER_ACCESS = 0x88BB;
constexpr GLenum GL_BUFFER_MAPPED = 0x88BC;
constexpr GLenum GL_BUFFER_MAP_POINTER = 0x88BD;
constexpr GLenum GL_TIME_ELAPSED = 0x88BF;
constexpr GLenum GL_STREAM_DRAW = 0x88E0;
constexpr GLenum GL_STREAM_READ = 0x88E1;
constexpr GLenum GL_STREAM_COPY = 0x88E2;
constexpr GLenum GL_STATIC_DRAW = 0x88E4;
constexpr GLenum GL_STATIC_READ = 0x88E5;
constexpr GLenum GL_STATIC_COPY = 0x88E6;
constexpr GLenum GL_DYNAMIC_DRAW = 0x88E8;
constexpr GLenum GL_DYNAMIC_READ = 0x88E9;
constexpr GLenum GL_DYNAMIC_COPY = 0x88EA;
constexpr GLenum GL_PIXEL_PACK_BUFFER = 0x88EB;
constexpr GLenum GL_PIXEL_UNPACK_BUFFER = 0x88EC;
constexpr GLenum GL_PIXEL_PACK_BUFFER_BINDING = 0x88ED;
constexpr GLenum GL_PIXEL_UNPACK_BUFFER_BINDING = 0x88EF;
constexpr GLenum GL_DEPTH24_STENCIL8 = 0x88F0;
constexpr GLenum GL_TEXTURE_STENCIL_SIZE = 0x88F1;
constexpr GLenum GL_SRC1_COLOR = 0x88F9;
constexpr GLenum GL_ONE_MINUS_SRC1_COLOR = 0x88FA;
constexpr GLenum GL_ONE_MINUS_SRC1_ALPHA = 0x88FB;
constexpr GLenum GL_MAX_DUAL_SOURCE_DRAW_BUFFERS = 0x88FC;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD;
constexpr GLenum GL_VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE;
constexpr GLenum GL_MAX_ARRAY_TEXTURE_LAYERS = 0x88FF;
constexpr GLenum GL_MIN_PROGRAM_TEXEL_OFFSET = 0x8904;
constexpr GLenum GL_MAX_PROGRAM_TEXEL_OFFSET = 0x8905;
constexpr GLenum GL_SAMPLES_PASSED = 0x8914;
constexpr GLenum GL_GEOMETRY_VERTICES_OUT = 0x8916;
constexpr GLenum GL_GEOMETRY_INPUT_TYPE = 0x8917;
constexpr GLenum GL_GEOMETRY_OUTPUT_TYPE = 0x8918;
constexpr GLenum GL_SAMPLER_BINDING = 0x8919;
constexpr GLenum GL_CLAMP_READ_COLOR = 0x891C;
constexpr GLenum GL_FIXED_ONLY = 0x891D;
constexpr GLenum GL_UNIFORM_BUFFER = 0x8A11;
constexpr GLenum GL_UNIFORM_BUFFER_BINDING = 0x8A28;
constexpr GLenum GL_UNIFORM_BUFFER_START = 0x8A29;
constexpr GLenum GL_UNIFORM_BUFFER_SIZE = 0x8A2A;
constexpr GLenum GL_MAX_VERTEX_UNIFORM_BLOCKS = 0x8A2B;
constexpr GLenum GL_MAX_GEOMETRY_UNIFORM_BLOCKS = 0x8A2C;
constexpr GLenum GL_MAX_FRAGMENT_UNIFORM_BLOCKS = 0x8A2D;
constexpr GLenum GL_MAX_COMBINED_UNIFORM_BLOCKS = 0x8A2E;
constexpr GLenum GL_MAX_UNIFORM_BUFFER_BINDINGS = 0x8A2F;
constexpr GLenum GL_MAX_UNIFORM_BLOCK_SIZE = 0x8A30;
constexpr GLenum GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31;
constexpr GLenum GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = 0x8A32;
constexpr GLenum GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33;
constexpr GLenum GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34;
constexpr GLenum GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35;
constexpr GLenum GL_ACTIVE_UNIFORM_BLOCKS = 0x8A36;
constexpr GLenum GL_UNIFORM_TYPE = 0x8A37;
constexpr GLenum GL_UNIFORM_SIZE = 0x8A38;
constexpr GLenum GL_UNIFORM_NAME_LENGTH = 0x8A39;
constexpr GLenum GL_UNIFORM_BLOCK_INDEX = 0x8A3A;
constexpr GLenum GL_UNIFORM_OFFSET = 0x8A3B;
constexpr GLenum GL_UNIFORM_ARRAY_STRIDE = 0x8A3C;
constexpr GLenum GL_UNIFORM_MATRIX_STRIDE = 0x8A3D;
constexpr GLenum GL_UNIFORM_IS_ROW_MAJOR = 0x8A3E;
constexpr GLenum GL_UNIFORM_BLOCK_BINDING = 0x8A3F;
constexpr GLenum GL_UNIFORM_BLOCK_DATA_SIZE = 0x8A40;
constexpr GLenum GL_UNIFORM_BLOCK_NAME_LENGTH = 0x8A41;
constexpr GLenum GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS = 0x8A42;
constexpr GLenum GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES = 0x8A43;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER = 0x8A44;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER = 0x8A45;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46;
constexpr GLenum GL_FRAGMENT_SHADER = 0x8B30;
constexpr GLenum GL_VERTEX_SHADER = 0x8B31;
constexpr GLenum GL_MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49;
constexpr GLenum GL_MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A;
constexpr GLenum GL_MAX_VARYING_FLOATS = 0x8B4B;
constexpr GLenum GL_MAX_VARYING_COMPONENTS = 0x8B4B;
constexpr GLenum GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C;
constexpr GLenum GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
constexpr GLenum GL_SHADER_TYPE = 0x8B4F;
constexpr GLenum GL_FLOAT_VEC2 = 0x8B50;
constexpr GLenum GL_FLOAT_VEC3 = 0x8B51;
constexpr GLenum GL_FLOAT_VEC4 = 0x8B52;
constexpr GLenum GL_INT_VEC2 = 0x8B53;
constexpr GLenum GL_INT_VEC3 = 0x8B54;
constexpr GLenum GL_INT_VEC4 = 0x8B55;
constexpr GLenum GL_BOOL = 0x8B56;
constexpr GLenum GL_BOOL_VEC2 = 0x8B57;
constexpr GLenum GL_BOOL_VEC3 = 0x8B58;
constexpr GLenum GL_BOOL_VEC4 = 0x8B59;
constexpr GLenum GL_FLOAT_MAT2 = 0x8B5A;
constexpr GLenum GL_FLOAT_MAT3 = 0x8B5B;
constexpr GLenum GL_FLOAT_MAT4 = 0x8B5C;
constexpr GLenum GL_SAMPLER_1D = 0x8B5D;
constexpr GLenum GL_SAMPLER_2D = 0x8B5E;
constexpr GLenum GL_SAMPLER_3D = 0x8B5F;
constexpr GLenum GL_SAMPLER_CUBE = 0x8B60;
constexpr GLenum GL_SAMPLER_1D_SHADOW = 0x8B61;
constexpr GLenum GL_SAMPLER_2D_SHADOW = 0x8B62;
constexpr GLenum GL_SAMPLER_2D_RECT = 0x8B63;
constexpr GLenum GL_SAMPLER_2D_RECT_SHADOW = 0x8B64;
constexpr GLenum GL_FLOAT_MAT2x3 = 0x8B65;
constexpr GLenum GL_FLOAT_MAT2x4 = 0x8B66;
constexpr GLenum GL_FLOAT_MAT3x2 = 0x8B67;
constexpr GLenum GL_FLOAT_MAT3x4 = 0x8B68;
constexpr GLenum GL_FLOAT_MAT4x2 = 0x8B69;
constexpr GLenum GL_FLOAT_MAT4x3 = 0x8B6A;
constexpr GLenum GL_DELETE_STATUS = 0x8B80;
constexpr GLenum GL_COMPILE_STATUS = 0x8B81;
constexpr GLenum GL_LINK_STATUS = 0x8B82;
constexpr GLenum GL_VALIDATE_STATUS = 0x8B83;
constexpr GLenum GL_INFO_LOG_LENGTH = 0x8B84;
constexpr GLenum GL_ATTACHED_SHADERS = 0x8B85;
constexpr GLenum GL_ACTIVE_UNIFORMS = 0x8B86;
constexpr GLenum GL_ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;
constexpr GLenum GL_SHADER_SOURCE_LENGTH = 0x8B88;
constexpr GLenum GL_ACTIVE_ATTRIBUTES = 0x8B89;
constexpr GLenum GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A;
constexpr GLenum GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B;
constexpr GLenum GL_SHADING_LANGUAGE_VERSION = 0x8B8C;
constexpr GLenum GL_CURRENT_PROGRAM = 0x8B8D;
constexpr GLenum GL_IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A;
constexpr GLenum GL_IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B;
constexpr GLenum GL_TEXTURE_RED_TYPE = 0x8C10;
constexpr GLenum GL_TEXTURE_GREEN_TYPE = 0x8C11;
constexpr GLenum GL_TEXTURE_BLUE_TYPE = 0x8C12;
constexpr GLenum GL_TEXTURE_ALPHA_TYPE = 0x8C13;
constexpr GLenum GL_TEXTURE_DEPTH_TYPE = 0x8C16;
constexpr GLenum GL_UNSIGNED_NORMALIZED = 0x8C17;
constexpr GLenum GL_TEXTURE_1D_ARRAY = 0x8C18;
constexpr GLenum GL_PROXY_TEXTURE_1D_ARRAY = 0x8C19;
constexpr GLenum GL_TEXTURE_2D_ARRAY = 0x8C1A;
constexpr GLenum GL_PROXY_TEXTURE_2D_ARRAY = 0x8C1B;
constexpr GLenum GL_TEXTURE_BINDING_1D_ARRAY = 0x8C1C;
constexpr GLenum GL_TEXTURE_BINDING_2D_ARRAY = 0x8C1D;
constexpr GLenum GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29;
constexpr GLenum GL_TEXTURE_BUFFER = 0x8C2A;
constexpr GLenum GL_TEXTURE_BUFFER_BINDING = 0x8C2A;
constexpr GLenum GL_MAX_TEXTURE_BUFFER_SIZE = 0x8C2B;
constexpr GLenum GL_TEXTURE_BINDING_BUFFER = 0x8C2C;
constexpr GLenum GL_TEXTURE_BUFFER_DATA_STORE_BINDING = 0x8C2D;
constexpr GLenum GL_ANY_SAMPLES_PASSED = 0x8C2F;
constexpr GLenum GL_SAMPLE_SHADING = 0x8C36;
constexpr GLenum GL_MIN_SAMPLE_SHADING_VALUE = 0x8C37;
constexpr GLenum GL_R11F_G11F_B10F = 0x8C3A;
constexpr GLenum GL_UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B;
constexpr GLenum GL_RGB9_E5 = 0x8C3D;
constexpr GLenum GL_UNSIGNED_INT_5_9_9_9_REV = 0x8C3E;
constexpr GLenum GL_TEXTURE_SHARED_SIZE = 0x8C3F;
constexpr GLenum GL_SRGB = 0x8C40;
constexpr GLenum GL_SRGB8 = 0x8C41;
constexpr GLenum GL_SRGB_ALPHA = 0x8C42;
constexpr GLenum GL_SRGB8_ALPHA8 = 0x8C43;
constexpr GLenum GL_COMPRESSED_SRGB = 0x8C48;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA = 0x8C49;
constexpr GLenum GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F;
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80;
constexpr GLenum GL_TRANSFORM_FEEDBACK_VARYINGS = 0x8C83;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85;
constexpr GLenum GL_PRIMITIVES_GENERATED = 0x8C87;
constexpr GLenum GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88;
constexpr GLenum GL_RASTERIZER_DISCARD = 0x8C89;
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A;
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B;
constexpr GLenum GL_INTERLEAVED_ATTRIBS = 0x8C8C;
constexpr GLenum GL_SEPARATE_ATTRIBS = 0x8C8D;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER = 0x8C8E;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F;
constexpr GLenum GL_POINT_SPRITE_COORD_ORIGIN = 0x8CA0;
constexpr GLenum GL_LOWER_LEFT = 0x8CA1;
constexpr GLenum GL_UPPER_LEFT = 0x8CA2;
constexpr GLenum GL_STENCIL_BACK_REF = 0x8CA3;
constexpr GLenum GL_STENCIL_BACK_VALUE_MASK = 0x8CA4;
constexpr GLenum GL_STENCIL_BACK_WRITEMASK = 0x8CA5;
constexpr GLenum GL_DRAW_FRAMEBUFFER_BINDING = 0x8CA6;
constexpr GLenum GL_FRAMEBUFFER_BINDING = 0x8CA6;
constexpr GLenum GL_RENDERBUFFER_BINDING = 0x8CA7;
constexpr GLenum GL_READ_FRAMEBUFFER = 0x8CA8;
constexpr GLenum GL_DRAW_FRAMEBUFFER = 0x8CA9;
constexpr GLenum GL_READ_FRAMEBUFFER_BINDING = 0x8CAA;
constexpr GLenum GL_RENDERBUFFER_SAMPLES = 0x8CAB;
constexpr GLenum GL_DEPTH_COMPONENT32F = 0x8CAC;
constexpr GLenum GL_DEPTH32F_STENCIL8 = 0x8CAD;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4;
constexpr GLenum GL_FRAMEBUFFER_COMPLETE = 0x8CD5;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER = 0x8CDB;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER = 0x8CDC;
constexpr GLenum GL_FRAMEBUFFER_UNSUPPORTED = 0x8CDD;
constexpr GLenum GL_MAX_COLOR_ATTACHMENTS = 0x8CDF;
constexpr GLenum GL_COLOR_ATTACHMENT0 = 0x8CE0;
constexpr GLenum GL_COLOR_ATTACHMENT1 = 0x8CE1;
constexpr GLenum GL_COLOR_ATTACHMENT2 = 0x8CE2;
constexpr GLenum GL_COLOR_ATTACHMENT3 = 0x8CE3;
constexpr GLenum GL_COLOR_ATTACHMENT4 = 0x8CE4;
constexpr GLenum GL_COLOR_ATTACHMENT5 = 0x8CE5;
constexpr GLenum GL_COLOR_ATTACHMENT6 = 0x8CE6;
constexpr GLenum GL_COLOR_ATTACHMENT7 = 0x8CE7;
constexpr GLenum GL_COLOR_ATTACHMENT8 = 0x8CE8;
constexpr GLenum GL_COLOR_ATTACHMENT9 = 0x8CE9;
constexpr GLenum GL_COLOR_ATTACHMENT10 = 0x8CEA;
constexpr GLenum GL_COLOR_ATTACHMENT11 = 0x8CEB;
constexpr GLenum GL_COLOR_ATTACHMENT12 = 0x8CEC;
constexpr GLenum GL_COLOR_ATTACHMENT13 = 0x8CED;
constexpr GLenum GL_COLOR_ATTACHMENT14 = 0x8CEE;
constexpr GLenum GL_COLOR_ATTACHMENT15 = 0x8CEF;
constexpr GLenum GL_COLOR_ATTACHMENT16 = 0x8CF0;
constexpr GLenum GL_COLOR_ATTACHMENT17 = 0x8CF1;
constexpr GLenum GL_COLOR_ATTACHMENT18 = 0x8CF2;
constexpr GLenum GL_COLOR_ATTACHMENT19 = 0x8CF3;
constexpr GLenum GL_COLOR_ATTACHMENT20 = 0x8CF4;
constexpr GLenum GL_COLOR_ATTACHMENT21 = 0x8CF5;
constexpr GLenum GL_COLOR_ATTACHMENT22 = 0x8CF6;
constexpr GLenum GL_COLOR_ATTACHMENT23 = 0x8CF7;
constexpr GLenum GL_COLOR_ATTACHMENT24 = 0x8CF8;
constexpr GLenum GL_COLOR_ATTACHMENT25 = 0x8CF9;
constexpr GLenum GL_COLOR_ATTACHMENT26 = 0x8CFA;
constexpr GLenum GL_COLOR_ATTACHMENT27 = 0x8CFB;
constexpr GLenum GL_COLOR_ATTACHMENT28 = 0x8CFC;
constexpr GLenum GL_COLOR_ATTACHMENT29 = 0x8CFD;
constexpr GLenum GL_COLOR_ATTACHMENT30 = 0x8CFE;
constexpr GLenum GL_COLOR_ATTACHMENT31 = 0x8CFF;
constexpr GLenum GL_DEPTH_ATTACHMENT = 0x8D00;
constexpr GLenum GL_STENCIL_ATTACHMENT = 0x8D20;
constexpr GLenum GL_FRAMEBUFFER = 0x8D40;
constexpr GLenum GL_RENDERBUFFER = 0x8D41;
constexpr GLenum GL_RENDERBUFFER_WIDTH = 0x8D42;
constexpr GLenum GL_RENDERBUFFER_HEIGHT = 0x8D43;
constexpr GLenum GL_RENDERBUFFER_INTERNAL_FORMAT = 0x8D44;
constexpr GLenum GL_STENCIL_INDEX1 = 0x8D46;
constexpr GLenum GL_STENCIL_INDEX4 = 0x8D47;
constexpr GLenum GL_STENCIL_INDEX8 = 0x8D48;
constexpr GLenum GL_STENCIL_INDEX16 = 0x8D49;
constexpr GLenum GL_RENDERBUFFER_RED_SIZE = 0x8D50;
constexpr GLenum GL_RENDERBUFFER_GREEN_SIZE = 0x8D51;
constexpr GLenum GL_RENDERBUFFER_BLUE_SIZE = 0x8D52;
constexpr GLenum GL_RENDERBUFFER_ALPHA_SIZE = 0x8D53;
constexpr GLenum GL_RENDERBUFFER_DEPTH_SIZE = 0x8D54;
constexpr GLenum GL_RENDERBUFFER_STENCIL_SIZE = 0x8D55;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56;
constexpr GLenum GL_MAX_SAMPLES = 0x8D57;
constexpr GLenum GL_RGB565 = 0x8D62;
constexpr GLenum GL_PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69;
constexpr GLenum GL_ANY_SAMPLES_PASSED_CONSERVATIVE = 0x8D6A;
constexpr GLenum GL_MAX_ELEMENT_INDEX = 0x8D6B;
constexpr GLenum GL_RGBA32UI = 0x8D70;
constexpr GLenum GL_RGB32UI = 0x8D71;
constexpr GLenum GL_RGBA16UI = 0x8D76;
constexpr GLenum GL_RGB16UI = 0x8D77;
constexpr GLenum GL_RGBA8UI = 0x8D7C;
constexpr GLenum GL_RGB8UI = 0x8D7D;
constexpr GLenum GL_RGBA32I = 0x8D82;
constexpr GLenum GL_RGB32I = 0x8D83;
constexpr GLenum GL_RGBA16I = 0x8D88;
constexpr GLenum GL_RGB16I = 0x8D89;
constexpr GLenum GL_RGBA8I = 0x8D8E;
constexpr GLenum GL_RGB8I = 0x8D8F;
constexpr GLenum GL_RED_INTEGER = 0x8D94;
constexpr GLenum GL_GREEN_INTEGER = 0x8D95;
constexpr GLenum GL_BLUE_INTEGER = 0x8D96;
constexpr GLenum GL_RGB_INTEGER = 0x8D98;
constexpr GLenum GL_RGBA_INTEGER = 0x8D99;
constexpr GLenum GL_BGR_INTEGER = 0x8D9A;
constexpr GLenum GL_BGRA_INTEGER = 0x8D9B;
constexpr GLenum GL_INT_2_10_10_10_REV = 0x8D9F;
constexpr GLenum GL_FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7;
constexpr GLenum GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8;
constexpr GLenum GL_FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD;
constexpr GLenum GL_FRAMEBUFFER_SRGB = 0x8DB9;
constexpr GLenum GL_COMPRESSED_RED_RGTC1 = 0x8DBB;
constexpr GLenum GL_COMPRESSED_SIGNED_RED_RGTC1 = 0x8DBC;
constexpr GLenum GL_COMPRESSED_RG_RGTC2 = 0x8DBD;
constexpr GLenum GL_COMPRESSED_SIGNED_RG_RGTC2 = 0x8DBE;
constexpr GLenum GL_SAMPLER_1D_ARRAY = 0x8DC0;
constexpr GLenum GL_SAMPLER_2D_ARRAY = 0x8DC1;
constexpr GLenum GL_SAMPLER_BUFFER = 0x8DC2;
constexpr GLenum GL_SAMPLER_1D_ARRAY_SHADOW = 0x8DC3;
constexpr GLenum GL_SAMPLER_2D_ARRAY_SHADOW = 0x8DC4;
constexpr GLenum GL_SAMPLER_CUBE_SHADOW = 0x8DC5;
constexpr GLenum GL_UNSIGNED_INT_VEC2 = 0x8DC6;
constexpr GLenum GL_UNSIGNED_INT_VEC3 = 0x8DC7;
constexpr GLenum GL_UNSIGNED_INT_VEC4 = 0x8DC8;
constexpr GLenum GL_INT_SAMPLER_1D = 0x8DC9;
constexpr GLenum GL_INT_SAMPLER_2D = 0x8DCA;
constexpr GLenum GL_INT_SAMPLER_3D = 0x8DCB;
constexpr GLenum GL_INT_SAMPLER_CUBE = 0x8DCC;
constexpr GLenum GL_INT_SAMPLER_2D_RECT = 0x8DCD;
constexpr GLenum GL_INT_SAMPLER_1D_ARRAY = 0x8DCE;
constexpr GLenum GL_INT_SAMPLER_2D_ARRAY = 0x8DCF;
constexpr GLenum GL_INT_SAMPLER_BUFFER = 0x8DD0;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_1D = 0x8DD1;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D = 0x8DD2;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_3D = 0x8DD3;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_RECT = 0x8DD5;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_1D_ARRAY = 0x8DD6;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_BUFFER = 0x8DD8;
constexpr GLenum GL_GEOMETRY_SHADER = 0x8DD9;
constexpr GLenum GL_MAX_GEOMETRY_UNIFORM_COMPONENTS = 0x8DDF;
constexpr GLenum GL_MAX_GEOMETRY_OUTPUT_VERTICES = 0x8DE0;
constexpr GLenum GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = 0x8DE1;
constexpr GLenum GL_ACTIVE_SUBROUTINES = 0x8DE5;
constexpr GLenum GL_ACTIVE_SUBROUTINE_UNIFORMS = 0x8DE6;
constexpr GLenum GL_MAX_SUBROUTINES = 0x8DE7;
constexpr GLenum GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS = 0x8DE8;
constexpr GLenum GL_LOW_FLOAT = 0x8DF0;
constexpr GLenum GL_MEDIUM_FLOAT = 0x8DF1;
constexpr GLenum GL_HIGH_FLOAT = 0x8DF2;
constexpr GLenum GL_LOW_INT = 0x8DF3;
constexpr GLenum GL_MEDIUM_INT = 0x8DF4;
constexpr GLenum GL_HIGH_INT = 0x8DF5;
constexpr GLenum GL_SHADER_BINARY_FORMATS = 0x8DF8;
constexpr GLenum GL_NUM_SHADER_BINARY_FORMATS = 0x8DF9;
constexpr GLenum GL_SHADER_COMPILER = 0x8DFA;
constexpr GLenum GL_MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB;
constexpr GLenum GL_MAX_VARYING_VECTORS = 0x8DFC;
constexpr GLenum GL_MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD;
constexpr GLenum GL_QUERY_WAIT = 0x8E13;
constexpr GLenum GL_QUERY_NO_WAIT = 0x8E14;
constexpr GLenum GL_QUERY_BY_REGION_WAIT = 0x8E15;
constexpr GLenum GL_QUERY_BY_REGION_NO_WAIT = 0x8E16;
constexpr GLenum GL_QUERY_WAIT_INVERTED = 0x8E17;
constexpr GLenum GL_QUERY_NO_WAIT_INVERTED = 0x8E18;
constexpr GLenum GL_QUERY_BY_REGION_WAIT_INVERTED = 0x8E19;
constexpr GLenum GL_QUERY_BY_REGION_NO_WAIT_INVERTED = 0x8E1A;
constexpr GLenum GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E1E;
constexpr GLenum GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E1F;
constexpr GLenum GL_TRANSFORM_FEEDBACK = 0x8E22;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED = 0x8E23;
constexpr GLenum GL_TRANSFORM_FEEDBACK_PAUSED = 0x8E23;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE = 0x8E24;
constexpr GLenum GL_TRANSFORM_FEEDBACK_ACTIVE = 0x8E24;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BINDING = 0x8E25;
constexpr GLenum GL_TIMESTAMP = 0x8E28;
constexpr GLenum GL_TEXTURE_SWIZZLE_R = 0x8E42;
constexpr GLenum GL_TEXTURE_SWIZZLE_G = 0x8E43;
constexpr GLenum GL_TEXTURE_SWIZZLE_B = 0x8E44;
constexpr GLenum GL_TEXTURE_SWIZZLE_A = 0x8E45;
constexpr GLenum GL_TEXTURE_SWIZZLE_RGBA = 0x8E46;
constexpr GLenum GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS = 0x8E47;
constexpr GLenum GL_ACTIVE_SUBROUTINE_MAX_LENGTH = 0x8E48;
constexpr GLenum GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH = 0x8E49;
constexpr GLenum GL_NUM_COMPATIBLE_SUBROUTINES = 0x8E4A;
constexpr GLenum GL_COMPATIBLE_SUBROUTINES = 0x8E4B;
constexpr GLenum GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION = 0x8E4C;
constexpr GLenum GL_FIRST_VERTEX_CONVENTION = 0x8E4D;
constexpr GLenum GL_LAST_VERTEX_CONVENTION = 0x8E4E;
constexpr GLenum GL_PROVOKING_VERTEX = 0x8E4F;
constexpr GLenum GL_SAMPLE_POSITION = 0x8E50;
constexpr GLenum GL_SAMPLE_MASK = 0x8E51;
constexpr GLenum GL_SAMPLE_MASK_VALUE = 0x8E52;
constexpr GLenum GL_MAX_SAMPLE_MASK_WORDS = 0x8E59;
constexpr GLenum GL_MAX_GEOMETRY_SHADER_INVOCATIONS = 0x8E5A;
constexpr GLenum GL_MIN_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5B;
constexpr GLenum GL_MAX_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5C;
constexpr GLenum GL_FRAGMENT_INTERPOLATION_OFFSET_BITS = 0x8E5D;
constexpr GLenum GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5E;
constexpr GLenum GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5F;
constexpr GLenum GL_MAX_TRANSFORM_FEEDBACK_BUFFERS = 0x8E70;
constexpr GLenum GL_MAX_VERTEX_STREAMS = 0x8E71;
constexpr GLenum GL_PATCH_VERTICES = 0x8E72;
constexpr GLenum GL_PATCH_DEFAULT_INNER_LEVEL = 0x8E73;
constexpr GLenum GL_PATCH_DEFAULT_OUTER_LEVEL = 0x8E74;
constexpr GLenum GL_TESS_CONTROL_OUTPUT_VERTICES = 0x8E75;
constexpr GLenum GL_TESS_GEN_MODE = 0x8E76;
constexpr GLenum GL_TESS_GEN_SPACING = 0x8E77;
constexpr GLenum GL_TESS_GEN_VERTEX_ORDER = 0x8E78;
constexpr GLenum GL_TESS_GEN_POINT_MODE = 0x8E79;
constexpr GLenum GL_ISOLINES = 0x8E7A;
constexpr GLenum GL_FRACTIONAL_ODD = 0x8E7B;
constexpr GLenum GL_FRACTIONAL_EVEN = 0x8E7C;
constexpr GLenum GL_MAX_PATCH_VERTICES = 0x8E7D;
constexpr GLenum GL_MAX_TESS_GEN_LEVEL = 0x8E7E;
constexpr GLenum GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E7F;
constexpr GLenum GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E80;
constexpr GLenum GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS = 0x8E81;
constexpr GLenum GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS = 0x8E82;
constexpr GLenum GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS = 0x8E83;
constexpr GLenum GL_MAX_TESS_PATCH_COMPONENTS = 0x8E84;
constexpr GLenum GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS = 0x8E85;
constexpr GLenum GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS = 0x8E86;
constexpr GLenum GL_TESS_EVALUATION_SHADER = 0x8E87;
constexpr GLenum GL_TESS_CONTROL_SHADER = 0x8E88;
constexpr GLenum GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS = 0x8E89;
constexpr GLenum GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS = 0x8E8A;
constexpr GLenum GL_COMPRESSED_RGBA_BPTC_UNORM = 0x8E8C;
constexpr GLenum GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM = 0x8E8D;
constexpr GLenum GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT = 0x8E8E;
constexpr GLenum GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = 0x8E8F;
constexpr GLenum GL_COPY_READ_BUFFER = 0x8F36;
constexpr GLenum GL_COPY_READ_BUFFER_BINDING = 0x8F36;
constexpr GLenum GL_COPY_WRITE_BUFFER = 0x8F37;
constexpr GLenum GL_COPY_WRITE_BUFFER_BINDING = 0x8F37;
constexpr GLenum GL_MAX_IMAGE_UNITS = 0x8F38;
constexpr GLenum GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS = 0x8F39;
constexpr GLenum GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES = 0x8F39;
constexpr GLenum GL_IMAGE_BINDING_NAME = 0x8F3A;
constexpr GLenum GL_IMAGE_BINDING_LEVEL = 0x8F3B;
constexpr GLenum GL_IMAGE_BINDING_LAYERED = 0x8F3C;
constexpr GLenum GL_IMAGE_BINDING_LAYER = 0x8F3D;
constexpr GLenum GL_IMAGE_BINDING_ACCESS = 0x8F3E;
constexpr GLenum GL_DRAW_INDIRECT_BUFFER = 0x8F3F;
constexpr GLenum GL_DRAW_INDIRECT_BUFFER_BINDING = 0x8F43;
constexpr GLenum GL_DOUBLE_MAT2 = 0x8F46;
constexpr GLenum GL_DOUBLE_MAT3 = 0x8F47;
constexpr GLenum GL_DOUBLE_MAT4 = 0x8F48;
constexpr GLenum GL_DOUBLE_MAT2x3 = 0x8F49;
constexpr GLenum GL_DOUBLE_MAT2x4 = 0x8F4A;
constexpr GLenum GL_DOUBLE_MAT3x2 = 0x8F4B;
constexpr GLenum GL_DOUBLE_MAT3x4 = 0x8F4C;
constexpr GLenum GL_DOUBLE_MAT4x2 = 0x8F4D;
constexpr GLenum GL_DOUBLE_MAT4x3 = 0x8F4E;
constexpr GLenum GL_VERTEX_BINDING_BUFFER = 0x8F4F;
constexpr GLenum GL_R8_SNORM = 0x8F94;
constexpr GLenum GL_RG8_SNORM = 0x8F95;
constexpr GLenum GL_RGB8_SNORM = 0x8F96;
constexpr GLenum GL_RGBA8_SNORM = 0x8F97;
constexpr GLenum GL_R16_SNORM = 0x8F98;
constexpr GLenum GL_RG16_SNORM = 0x8F99;
constexpr GLenum GL_RGB16_SNORM = 0x8F9A;
constexpr GLenum GL_RGBA16_SNORM = 0x8F9B;
constexpr GLenum GL_SIGNED_NORMALIZED = 0x8F9C;
constexpr GLenum GL_PRIMITIVE_RESTART = 0x8F9D;
constexpr GLenum GL_PRIMITIVE_RESTART_INDEX = 0x8F9E;
constexpr GLenum GL_DOUBLE_VEC2 = 0x8FFC;
constexpr GLenum GL_DOUBLE_VEC3 = 0x8FFD;
constexpr GLenum GL_DOUBLE_VEC4 = 0x8FFE;
constexpr GLenum GL_TEXTURE_CUBE_MAP_ARRAY = 0x9009;
constexpr GLenum GL_TEXTURE_BINDING_CUBE_MAP_ARRAY = 0x900A;
constexpr GLenum GL_PROXY_TEXTURE_CUBE_MAP_ARRAY = 0x900B;
constexpr GLenum GL_SAMPLER_CUBE_MAP_ARRAY = 0x900C;
constexpr GLenum GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW = 0x900D;
constexpr GLenum GL_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900E;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900F;
constexpr GLenum GL_IMAGE_1D = 0x904C;
constexpr GLenum GL_IMAGE_2D = 0x904D;
constexpr GLenum GL_IMAGE_3D = 0x904E;
constexpr GLenum GL_IMAGE_2D_RECT = 0x904F;
constexpr GLenum GL_IMAGE_CUBE = 0x9050;
constexpr GLenum GL_IMAGE_BUFFER = 0x9051;
constexpr GLenum GL_IMAGE_1D_ARRAY = 0x9052;
constexpr GLenum GL_IMAGE_2D_ARRAY = 0x9053;
constexpr GLenum GL_IMAGE_CUBE_MAP_ARRAY = 0x9054;
constexpr GLenum GL_IMAGE_2D_MULTISAMPLE = 0x9055;
constexpr GLenum GL_IMAGE_2D_MULTISAMPLE_ARRAY = 0x9056;
constexpr GLenum GL_INT_IMAGE_1D = 0x9057;
constexpr GLenum GL_INT_IMAGE_2D = 0x9058;
constexpr GLenum GL_INT_IMAGE_3D = 0x9059;
constexpr GLenum GL_INT_IMAGE_2D_RECT = 0x905A;
constexpr GLenum GL_INT_IMAGE_CUBE = 0x905B;
constexpr GLenum GL_INT_IMAGE_BUFFER = 0x905C;
constexpr GLenum GL_INT_IMAGE_1D_ARRAY = 0x905D;
constexpr GLenum GL_INT_IMAGE_2D_ARRAY = 0x905E;
constexpr GLenum GL_INT_IMAGE_CUBE_MAP_ARRAY = 0x905F;
constexpr GLenum GL_INT_IMAGE_2D_MULTISAMPLE = 0x9060;
constexpr GLenum GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY = 0x9061;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_1D = 0x9062;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D = 0x9063;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_3D = 0x9064;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_RECT = 0x9065;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_CUBE = 0x9066;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_BUFFER = 0x9067;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_1D_ARRAY = 0x9068;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_ARRAY = 0x9069;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY = 0x906A;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE = 0x906B;
constexpr GLenum GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY = 0x906C;
constexpr GLenum GL_MAX_IMAGE_SAMPLES = 0x906D;
constexpr GLenum GL_IMAGE_BINDING_FORMAT = 0x906E;
constexpr GLenum GL_RGB10_A2UI = 0x906F;
constexpr GLenum GL_MIN_MAP_BUFFER_ALIGNMENT = 0x90BC;
constexpr GLenum GL_IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7;
constexpr GLenum GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE = 0x90C8;
constexpr GLenum GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS = 0x90C9;
constexpr GLenum GL_MAX_VERTEX_IMAGE_UNIFORMS = 0x90CA;
constexpr GLenum GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS = 0x90CB;
constexpr GLenum GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS = 0x90CC;
constexpr GLenum GL_MAX_GEOMETRY_IMAGE_UNIFORMS = 0x90CD;
constexpr GLenum GL_MAX_FRAGMENT_IMAGE_UNIFORMS = 0x90CE;
constexpr GLenum GL_MAX_COMBINED_IMAGE_UNIFORMS = 0x90CF;
constexpr GLenum GL_SHADER_STORAGE_BUFFER = 0x90D2;
constexpr GLenum GL_SHADER_STORAGE_BUFFER_BINDING = 0x90D3;
constexpr GLenum GL_SHADER_STORAGE_BUFFER_START = 0x90D4;
constexpr GLenum GL_SHADER_STORAGE_BUFFER_SIZE = 0x90D5;
constexpr GLenum GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS = 0x90D6;
constexpr GLenum GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS = 0x90D7;
constexpr GLenum GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS = 0x90D8;
constexpr GLenum GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = 0x90D9;
constexpr GLenum GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS = 0x90DA;
constexpr GLenum GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS = 0x90DB;
constexpr GLenum GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS = 0x90DC;
constexpr GLenum GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS = 0x90DD;
constexpr GLenum GL_MAX_SHADER_STORAGE_BLOCK_SIZE = 0x90DE;
constexpr GLenum GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT = 0x90DF;
constexpr GLenum GL_DEPTH_STENCIL_TEXTURE_MODE = 0x90EA;
constexpr GLenum GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS = 0x90EB;
constexpr GLenum GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER = 0x90EC;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER = 0x90ED;
constexpr GLenum GL_DISPATCH_INDIRECT_BUFFER = 0x90EE;
constexpr GLenum GL_DISPATCH_INDIRECT_BUFFER_BINDING = 0x90EF;
constexpr GLenum GL_TEXTURE_2D_MULTISAMPLE = 0x9100;
constexpr GLenum GL_PROXY_TEXTURE_2D_MULTISAMPLE = 0x9101;
constexpr GLenum GL_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102;
constexpr GLenum GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9103;
constexpr GLenum GL_TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104;
constexpr GLenum GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = 0x9105;
constexpr GLenum GL_TEXTURE_SAMPLES = 0x9106;
constexpr GLenum GL_TEXTURE_FIXED_SAMPLE_LOCATIONS = 0x9107;
constexpr GLenum GL_SAMPLER_2D_MULTISAMPLE = 0x9108;
constexpr GLenum GL_INT_SAMPLER_2D_MULTISAMPLE = 0x9109;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE = 0x910A;
constexpr GLenum GL_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910B;
constexpr GLenum GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910C;
constexpr GLenum GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D;
constexpr GLenum GL_MAX_COLOR_TEXTURE_SAMPLES = 0x910E;
constexpr GLenum GL_MAX_DEPTH_TEXTURE_SAMPLES = 0x910F;
constexpr GLenum GL_MAX_INTEGER_SAMPLES = 0x9110;
constexpr GLenum GL_MAX_SERVER_WAIT_TIMEOUT = 0x9111;
constexpr GLenum GL_OBJECT_TYPE = 0x9112;
constexpr GLenum GL_SYNC_CONDITION = 0x9113;
constexpr GLenum GL_SYNC_STATUS = 0x9114;
constexpr GLenum GL_SYNC_FLAGS = 0x9115;
constexpr GLenum GL_SYNC_FENCE = 0x9116;
constexpr GLenum GL_SYNC_GPU_COMMANDS_COMPLETE = 0x9117;
constexpr GLenum GL_UNSIGNALED = 0x9118;
constexpr GLenum GL_SIGNALED = 0x9119;
constexpr GLenum GL_ALREADY_SIGNALED = 0x911A;
constexpr GLenum GL_TIMEOUT_EXPIRED = 0x911B;
constexpr GLenum GL_CONDITION_SATISFIED = 0x911C;
constexpr GLenum GL_WAIT_FAILED = 0x911D;
constexpr GLenum GL_BUFFER_ACCESS_FLAGS = 0x911F;
constexpr GLenum GL_BUFFER_MAP_LENGTH = 0x9120;
constexpr GLenum GL_BUFFER_MAP_OFFSET = 0x9121;
constexpr GLenum GL_MAX_VERTEX_OUTPUT_COMPONENTS = 0x9122;
constexpr GLenum GL_MAX_GEOMETRY_INPUT_COMPONENTS = 0x9123;
constexpr GLenum GL_MAX_GEOMETRY_OUTPUT_COMPONENTS = 0x9124;
constexpr GLenum GL_MAX_FRAGMENT_INPUT_COMPONENTS = 0x9125;
constexpr GLenum GL_CONTEXT_PROFILE_MASK = 0x9126;
constexpr GLenum GL_UNPACK_COMPRESSED_BLOCK_WIDTH = 0x9127;
constexpr GLenum GL_UNPACK_COMPRESSED_BLOCK_HEIGHT = 0x9128;
constexpr GLenum GL_UNPACK_COMPRESSED_BLOCK_DEPTH = 0x9129;
constexpr GLenum GL_UNPACK_COMPRESSED_BLOCK_SIZE = 0x912A;
constexpr GLenum GL_PACK_COMPRESSED_BLOCK_WIDTH = 0x912B;
constexpr GLenum GL_PACK_COMPRESSED_BLOCK_HEIGHT = 0x912C;
constexpr GLenum GL_PACK_COMPRESSED_BLOCK_DEPTH = 0x912D;
constexpr GLenum GL_PACK_COMPRESSED_BLOCK_SIZE = 0x912E;
constexpr GLenum GL_TEXTURE_IMMUTABLE_FORMAT = 0x912F;
constexpr GLenum GL_MAX_DEBUG_MESSAGE_LENGTH = 0x9143;
constexpr GLenum GL_MAX_DEBUG_LOGGED_MESSAGES = 0x9144;
constexpr GLenum GL_DEBUG_LOGGED_MESSAGES = 0x9145;
constexpr GLenum GL_DEBUG_SEVERITY_HIGH = 0x9146;
constexpr GLenum GL_DEBUG_SEVERITY_MEDIUM = 0x9147;
constexpr GLenum GL_DEBUG_SEVERITY_LOW = 0x9148;
constexpr GLenum GL_QUERY_BUFFER = 0x9192;
constexpr GLenum GL_QUERY_BUFFER_BINDING = 0x9193;
constexpr GLenum GL_QUERY_RESULT_NO_WAIT = 0x9194;
constexpr GLenum GL_TEXTURE_BUFFER_OFFSET = 0x919D;
constexpr GLenum GL_TEXTURE_BUFFER_SIZE = 0x919E;
constexpr GLenum GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT = 0x919F;
constexpr GLenum GL_COMPUTE_SHADER = 0x91B9;
constexpr GLenum GL_MAX_COMPUTE_UNIFORM_BLOCKS = 0x91BB;
constexpr GLenum GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS = 0x91BC;
constexpr GLenum GL_MAX_COMPUTE_IMAGE_UNIFORMS = 0x91BD;
constexpr GLenum GL_MAX_COMPUTE_WORK_GROUP_COUNT = 0x91BE;
constexpr GLenum GL_MAX_COMPUTE_WORK_GROUP_SIZE = 0x91BF;
constexpr GLenum GL_COMPRESSED_R11_EAC = 0x9270;
constexpr GLenum GL_COMPRESSED_SIGNED_R11_EAC = 0x9271;
constexpr GLenum GL_COMPRESSED_RG11_EAC = 0x9272;
constexpr GLenum GL_COMPRESSED_SIGNED_RG11_EAC = 0x9273;
constexpr GLenum GL_COMPRESSED_RGB8_ETC2 = 0x9274;
constexpr GLenum GL_COMPRESSED_SRGB8_ETC2 = 0x9275;
constexpr GLenum GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9276;
constexpr GLenum GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9277;
constexpr GLenum GL_COMPRESSED_RGBA8_ETC2_EAC = 0x9278;
constexpr GLenum GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = 0x9279;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER = 0x92C0;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_BINDING = 0x92C1;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_START = 0x92C2;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_SIZE = 0x92C3;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE = 0x92C4;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS = 0x92C5;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES = 0x92C6;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER = 0x92C7;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER = 0x92C8;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x92C9;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER = 0x92CA;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER = 0x92CB;
constexpr GLenum GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS = 0x92CC;
constexpr GLenum GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS = 0x92CD;
constexpr GLenum GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS = 0x92CE;
constexpr GLenum GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS = 0x92CF;
constexpr GLenum GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS = 0x92D0;
constexpr GLenum GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS = 0x92D1;
constexpr GLenum GL_MAX_VERTEX_ATOMIC_COUNTERS = 0x92D2;
constexpr GLenum GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS = 0x92D3;
constexpr GLenum GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS = 0x92D4;
constexpr GLenum GL_MAX_GEOMETRY_ATOMIC_COUNTERS = 0x92D5;
constexpr GLenum GL_MAX_FRAGMENT_ATOMIC_COUNTERS = 0x92D6;
constexpr GLenum GL_MAX_COMBINED_ATOMIC_COUNTERS = 0x92D7;
constexpr GLenum GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE = 0x92D8;
constexpr GLenum GL_ACTIVE_ATOMIC_COUNTER_BUFFERS = 0x92D9;
constexpr GLenum GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX = 0x92DA;
constexpr GLenum GL_UNSIGNED_INT_ATOMIC_COUNTER = 0x92DB;
constexpr GLenum GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS = 0x92DC;
constexpr GLenum GL_DEBUG_OUTPUT = 0x92E0;
constexpr GLenum GL_UNIFORM = 0x92E1;
constexpr GLenum GL_UNIFORM_BLOCK = 0x92E2;
constexpr GLenum GL_PROGRAM_INPUT = 0x92E3;
constexpr GLenum GL_PROGRAM_OUTPUT = 0x92E4;
constexpr GLenum GL_BUFFER_VARIABLE = 0x92E5;
constexpr GLenum GL_SHADER_STORAGE_BLOCK = 0x92E6;
constexpr GLenum GL_IS_PER_PATCH = 0x92E7;
constexpr GLenum GL_VERTEX_SUBROUTINE = 0x92E8;
constexpr GLenum GL_TESS_CONTROL_SUBROUTINE = 0x92E9;
constexpr GLenum GL_TESS_EVALUATION_SUBROUTINE = 0x92EA;
constexpr GLenum GL_GEOMETRY_SUBROUTINE = 0x92EB;
constexpr GLenum GL_FRAGMENT_SUBROUTINE = 0x92EC;
constexpr GLenum GL_COMPUTE_SUBROUTINE = 0x92ED;
constexpr GLenum GL_VERTEX_SUBROUTINE_UNIFORM = 0x92EE;
constexpr GLenum GL_TESS_CONTROL_SUBROUTINE_UNIFORM = 0x92EF;
constexpr GLenum GL_TESS_EVALUATION_SUBROUTINE_UNIFORM = 0x92F0;
constexpr GLenum GL_GEOMETRY_SUBROUTINE_UNIFORM = 0x92F1;
constexpr GLenum GL_FRAGMENT_SUBROUTINE_UNIFORM = 0x92F2;
constexpr GLenum GL_COMPUTE_SUBROUTINE_UNIFORM = 0x92F3;
constexpr GLenum GL_TRANSFORM_FEEDBACK_VARYING = 0x92F4;
constexpr GLenum GL_ACTIVE_RESOURCES = 0x92F5;
constexpr GLenum GL_MAX_NAME_LENGTH = 0x92F6;
constexpr GLenum GL_MAX_NUM_ACTIVE_VARIABLES = 0x92F7;
constexpr GLenum GL_MAX_NUM_COMPATIBLE_SUBROUTINES = 0x92F8;
constexpr GLenum GL_NAME_LENGTH = 0x92F9;
constexpr GLenum GL_TYPE = 0x92FA;
constexpr GLenum GL_ARRAY_SIZE = 0x92FB;
constexpr GLenum GL_OFFSET = 0x92FC;
constexpr GLenum GL_BLOCK_INDEX = 0x92FD;
constexpr GLenum GL_ARRAY_STRIDE = 0x92FE;
constexpr GLenum GL_MATRIX_STRIDE = 0x92FF;
constexpr GLenum GL_IS_ROW_MAJOR = 0x9300;
constexpr GLenum GL_ATOMIC_COUNTER_BUFFER_INDEX = 0x9301;
constexpr GLenum GL_BUFFER_BINDING = 0x9302;
constexpr GLenum GL_BUFFER_DATA_SIZE = 0x9303;
constexpr GLenum GL_NUM_ACTIVE_VARIABLES = 0x9304;
constexpr GLenum GL_ACTIVE_VARIABLES = 0x9305;
constexpr GLenum GL_REFERENCED_BY_VERTEX_SHADER = 0x9306;
constexpr GLenum GL_REFERENCED_BY_TESS_CONTROL_SHADER = 0x9307;
constexpr GLenum GL_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x9308;
constexpr GLenum GL_REFERENCED_BY_GEOMETRY_SHADER = 0x9309;
constexpr GLenum GL_REFERENCED_BY_FRAGMENT_SHADER = 0x930A;
constexpr GLenum GL_REFERENCED_BY_COMPUTE_SHADER = 0x930B;
constexpr GLenum GL_TOP_LEVEL_ARRAY_SIZE = 0x930C;
constexpr GLenum GL_TOP_LEVEL_ARRAY_STRIDE = 0x930D;
constexpr GLenum GL_LOCATION = 0x930E;
constexpr GLenum GL_LOCATION_INDEX = 0x930F;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_WIDTH = 0x9310;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_HEIGHT = 0x9311;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_LAYERS = 0x9312;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_SAMPLES = 0x9313;
constexpr GLenum GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS = 0x9314;
constexpr GLenum GL_MAX_FRAMEBUFFER_WIDTH = 0x9315;
constexpr GLenum GL_MAX_FRAMEBUFFER_HEIGHT = 0x9316;
constexpr GLenum GL_MAX_FRAMEBUFFER_LAYERS = 0x9317;
constexpr GLenum GL_MAX_FRAMEBUFFER_SAMPLES = 0x9318;
constexpr GLenum GL_LOCATION_COMPONENT = 0x934A;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_INDEX = 0x934B;
constexpr GLenum GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE = 0x934C;
constexpr GLenum GL_CLIP_ORIGIN = 0x935C;
constexpr GLenum GL_CLIP_DEPTH_MODE = 0x935D;
constexpr GLenum GL_NEGATIVE_ONE_TO_ONE = 0x935E;
constexpr GLenum GL_ZERO_TO_ONE = 0x935F;
constexpr GLenum GL_CLEAR_TEXTURE = 0x9365;
constexpr GLenum GL_NUM_SAMPLE_COUNTS = 0x9380;


extern void ( APIENTRY* glActiveShaderProgram )( GLuint pipeline, GLuint program );
extern void ( APIENTRY* glActiveTexture )( GLenum texture );
extern void ( APIENTRY* glAttachShader )( GLuint program, GLuint shader );
extern void ( APIENTRY* glBeginConditionalRender )( GLuint id, GLenum mode );
extern void ( APIENTRY* glBeginQuery )( GLenum target, GLuint id );
extern void ( APIENTRY* glBeginQueryIndexed )( GLenum target, GLuint index, GLuint id );
extern void ( APIENTRY* glBeginTransformFeedback )( GLenum primitiveMode );
extern void ( APIENTRY* glBindAttribLocation )( GLuint program, GLuint index, const GLchar* name );
extern void ( APIENTRY* glBindBuffer )( GLenum target, GLuint buffer );
extern void ( APIENTRY* glBindBufferBase )( GLenum target, GLuint index, GLuint buffer );
extern void ( APIENTRY* glBindBufferRange )( GLenum target, GLuint index, GLuint buffer, GLintptr offset,
											 GLsizeiptr size );
extern void ( APIENTRY* glBindBuffersBase )( GLenum target, GLuint first, GLsizei count, const GLuint* buffers );
extern void ( APIENTRY* glBindBuffersRange )( GLenum target, GLuint first, GLsizei count, const GLuint* buffers,
											  const GLintptr* offsets, const GLsizeiptr* sizes );
extern void ( APIENTRY* glBindFragDataLocation )( GLuint program, GLuint color, const GLchar* name );
extern void ( APIENTRY* glBindFragDataLocationIndexed )( GLuint program, GLuint colorNumber, GLuint index,
														 const GLchar* name );
extern void ( APIENTRY* glBindFramebuffer )( GLenum target, GLuint framebuffer );
extern void ( APIENTRY* glBindImageTexture )( GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer,
											  GLenum access, GLenum format );
extern void ( APIENTRY* glBindImageTextures )( GLuint first, GLsizei count, const GLuint* textures );
extern void ( APIENTRY* glBindProgramPipeline )( GLuint pipeline );
extern void ( APIENTRY* glBindRenderbuffer )( GLenum target, GLuint renderbuffer );
extern void ( APIENTRY* glBindSampler )( GLuint unit, GLuint sampler );
extern void ( APIENTRY* glBindSamplers )( GLuint first, GLsizei count, const GLuint* samplers );
extern void ( APIENTRY* glBindTexture )( GLenum target, GLuint texture );
extern void ( APIENTRY* glBindTextureUnit )( GLuint unit, GLuint texture );
extern void ( APIENTRY* glBindTextures )( GLuint first, GLsizei count, const GLuint* textures );
extern void ( APIENTRY* glBindTransformFeedback )( GLenum target, GLuint id );
extern void ( APIENTRY* glBindVertexArray )( GLuint array );
extern void ( APIENTRY* glBindVertexBuffer )( GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride );
extern void ( APIENTRY* glBindVertexBuffers )( GLuint first, GLsizei count, const GLuint* buffers,
											   const GLintptr* offsets, const GLsizei* strides );
extern void ( APIENTRY* glBlendColor )( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha );
extern void ( APIENTRY* glBlendEquation )( GLenum mode );
extern void ( APIENTRY* glBlendEquationSeparate )( GLenum modeRGB, GLenum modeAlpha );
extern void ( APIENTRY* glBlendEquationSeparatei )( GLuint buf, GLenum modeRGB, GLenum modeAlpha );
extern void ( APIENTRY* glBlendEquationi )( GLuint buf, GLenum mode );
extern void ( APIENTRY* glBlendFunc )( GLenum sfactor, GLenum dfactor );
extern void ( APIENTRY* glBlendFuncSeparate )( GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha,
											   GLenum dfactorAlpha );
extern void ( APIENTRY* glBlendFuncSeparatei )( GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha,
												GLenum dstAlpha );
extern void ( APIENTRY* glBlendFunci )( GLuint buf, GLenum src, GLenum dst );
extern void ( APIENTRY* glBlitFramebuffer )( GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0,
											 GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter );
extern void ( APIENTRY* glBlitNamedFramebuffer )( GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0,
												  GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0,
												  GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter );
extern void ( APIENTRY* glBufferData )( GLenum target, GLsizeiptr size, const void* data, GLenum usage );
extern void ( APIENTRY* glBufferStorage )( GLenum target, GLsizeiptr size, const void* data, GLbitfield flags );
extern void ( APIENTRY* glBufferSubData )( GLenum target, GLintptr offset, GLsizeiptr size, const void* data );
extern GLenum ( APIENTRY* glCheckFramebufferStatus )( GLenum target );
extern GLenum ( APIENTRY* glCheckNamedFramebufferStatus )( GLuint framebuffer, GLenum target );
extern void ( APIENTRY* glClampColor )( GLenum target, GLenum clamp );
extern void ( APIENTRY* glClear )( GLbitfield mask );
extern void ( APIENTRY* glClearBufferData )( GLenum target, GLenum internalformat, GLenum format, GLenum type,
											 const void* data );
extern void ( APIENTRY* glClearBufferSubData )( GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size,
												GLenum format, GLenum type, const void* data );
extern void ( APIENTRY* glClearBufferfi )( GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil );
extern void ( APIENTRY* glClearBufferfv )( GLenum buffer, GLint drawbuffer, const GLfloat* value );
extern void ( APIENTRY* glClearBufferiv )( GLenum buffer, GLint drawbuffer, const GLint* value );
extern void ( APIENTRY* glClearBufferuiv )( GLenum buffer, GLint drawbuffer, const GLuint* value );
extern void ( APIENTRY* glClearColor )( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha );
extern void ( APIENTRY* glClearDepth )( GLdouble depth );
extern void ( APIENTRY* glClearDepthf )( GLfloat d );
extern void ( APIENTRY* glClearNamedBufferData )( GLuint buffer, GLenum internalformat, GLenum format, GLenum type,
												  const void* data );
extern void ( APIENTRY* glClearNamedBufferSubData )( GLuint buffer, GLenum internalformat, GLintptr offset,
													 GLsizeiptr size, GLenum format, GLenum type, const void* data );
extern void ( APIENTRY* glClearNamedFramebufferfi )( GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth,
													 GLint stencil );
extern void ( APIENTRY* glClearNamedFramebufferfv )( GLuint framebuffer, GLenum buffer, GLint drawbuffer,
													 const GLfloat* value );
extern void ( APIENTRY* glClearNamedFramebufferiv )( GLuint framebuffer, GLenum buffer, GLint drawbuffer,
													 const GLint* value );
extern void ( APIENTRY* glClearNamedFramebufferuiv )( GLuint framebuffer, GLenum buffer, GLint drawbuffer,
													  const GLuint* value );
extern void ( APIENTRY* glClearStencil )( GLint s );
extern void ( APIENTRY* glClearTexImage )( GLuint texture, GLint level, GLenum format, GLenum type, const void* data );
extern void ( APIENTRY* glClearTexSubImage )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
											  GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type,
											  const void* data );
extern GLenum ( APIENTRY* glClientWaitSync )( GLsync sync, GLbitfield flags, GLuint64 timeout );
extern void ( APIENTRY* glClipControl )( GLenum origin, GLenum depth );
extern void ( APIENTRY* glColorMask )( GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha );
extern void ( APIENTRY* glColorMaski )( GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a );
extern void ( APIENTRY* glColorP3ui )( GLenum type, GLuint color );
extern void ( APIENTRY* glColorP3uiv )( GLenum type, const GLuint* color );
extern void ( APIENTRY* glColorP4ui )( GLenum type, GLuint color );
extern void ( APIENTRY* glColorP4uiv )( GLenum type, const GLuint* color );
extern void ( APIENTRY* glCompileShader )( GLuint shader );
extern void ( APIENTRY* glCompressedTexImage1D )( GLenum target, GLint level, GLenum internalformat, GLsizei width,
												  GLint border, GLsizei imageSize, const void* data );
extern void ( APIENTRY* glCompressedTexImage2D )( GLenum target, GLint level, GLenum internalformat, GLsizei width,
												  GLsizei height, GLint border, GLsizei imageSize, const void* data );
extern void ( APIENTRY* glCompressedTexImage3D )( GLenum target, GLint level, GLenum internalformat, GLsizei width,
												  GLsizei height, GLsizei depth, GLint border, GLsizei imageSize,
												  const void* data );
extern void ( APIENTRY* glCompressedTexSubImage1D )( GLenum target, GLint level, GLint xoffset, GLsizei width,
													 GLenum format, GLsizei imageSize, const void* data );
extern void ( APIENTRY* glCompressedTexSubImage2D )( GLenum target, GLint level, GLint xoffset, GLint yoffset,
													 GLsizei width, GLsizei height, GLenum format, GLsizei imageSize,
													 const void* data );
extern void ( APIENTRY* glCompressedTexSubImage3D )( GLenum target, GLint level, GLint xoffset, GLint yoffset,
													 GLint zoffset, GLsizei width, GLsizei height, GLsizei depth,
													 GLenum format, GLsizei imageSize, const void* data );
extern void ( APIENTRY* glCompressedTextureSubImage1D )( GLuint texture, GLint level, GLint xoffset, GLsizei width,
														 GLenum format, GLsizei imageSize, const void* data );
extern void ( APIENTRY* glCompressedTextureSubImage2D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset,
														 GLsizei width, GLsizei height, GLenum format,
														 GLsizei imageSize, const void* data );
extern void ( APIENTRY* glCompressedTextureSubImage3D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset,
														 GLint zoffset, GLsizei width, GLsizei height, GLsizei depth,
														 GLenum format, GLsizei imageSize, const void* data );
extern void ( APIENTRY* glCopyBufferSubData )( GLenum readTarget, GLenum writeTarget, GLintptr readOffset,
											   GLintptr writeOffset, GLsizeiptr size );
extern void ( APIENTRY* glCopyImageSubData )( GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY,
											  GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX,
											  GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight,
											  GLsizei srcDepth );
extern void ( APIENTRY* glCopyNamedBufferSubData )( GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset,
													GLintptr writeOffset, GLsizeiptr size );
extern void ( APIENTRY* glCopyTexImage1D )( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y,
											GLsizei width, GLint border );
extern void ( APIENTRY* glCopyTexImage2D )( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y,
											GLsizei width, GLsizei height, GLint border );
extern void ( APIENTRY* glCopyTexSubImage1D )( GLenum target, GLint level, GLint xoffset, GLint x, GLint y,
											   GLsizei width );
extern void ( APIENTRY* glCopyTexSubImage2D )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x,
											   GLint y, GLsizei width, GLsizei height );
extern void ( APIENTRY* glCopyTexSubImage3D )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
											   GLint x, GLint y, GLsizei width, GLsizei height );
extern void ( APIENTRY* glCopyTextureSubImage1D )( GLuint texture, GLint level, GLint xoffset, GLint x, GLint y,
												   GLsizei width );
extern void ( APIENTRY* glCopyTextureSubImage2D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x,
												   GLint y, GLsizei width, GLsizei height );
extern void ( APIENTRY* glCopyTextureSubImage3D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset,
												   GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height );
extern void ( APIENTRY* glCreateBuffers )( GLsizei n, GLuint* buffers );
extern void ( APIENTRY* glCreateFramebuffers )( GLsizei n, GLuint* framebuffers );
extern GLuint ( APIENTRY* glCreateProgram )();
extern void ( APIENTRY* glCreateProgramPipelines )( GLsizei n, GLuint* pipelines );
extern void ( APIENTRY* glCreateQueries )( GLenum target, GLsizei n, GLuint* ids );
extern void ( APIENTRY* glCreateRenderbuffers )( GLsizei n, GLuint* renderbuffers );
extern void ( APIENTRY* glCreateSamplers )( GLsizei n, GLuint* samplers );
extern GLuint ( APIENTRY* glCreateShader )( GLenum type );
extern GLuint ( APIENTRY* glCreateShaderProgramv )( GLenum type, GLsizei count, const GLchar* const* strings );
extern void ( APIENTRY* glCreateTextures )( GLenum target, GLsizei n, GLuint* textures );
extern void ( APIENTRY* glCreateTransformFeedbacks )( GLsizei n, GLuint* ids );
extern void ( APIENTRY* glCreateVertexArrays )( GLsizei n, GLuint* arrays );
extern void ( APIENTRY* glCullFace )( GLenum mode );
extern void ( APIENTRY* glDebugMessageCallback )( GLDEBUGPROC callback, const void* userParam );
extern void ( APIENTRY* glDebugMessageControl )( GLenum source, GLenum type, GLenum severity, GLsizei count,
												 const GLuint* ids, GLboolean enabled );
extern void ( APIENTRY* glDebugMessageInsert )( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
												const GLchar* buf );
extern void ( APIENTRY* glDeleteBuffers )( GLsizei n, const GLuint* buffers );
extern void ( APIENTRY* glDeleteFramebuffers )( GLsizei n, const GLuint* framebuffers );
extern void ( APIENTRY* glDeleteProgram )( GLuint program );
extern void ( APIENTRY* glDeleteProgramPipelines )( GLsizei n, const GLuint* pipelines );
extern void ( APIENTRY* glDeleteQueries )( GLsizei n, const GLuint* ids );
extern void ( APIENTRY* glDeleteRenderbuffers )( GLsizei n, const GLuint* renderbuffers );
extern void ( APIENTRY* glDeleteSamplers )( GLsizei count, const GLuint* samplers );
extern void ( APIENTRY* glDeleteShader )( GLuint shader );
extern void ( APIENTRY* glDeleteSync )( GLsync sync );
extern void ( APIENTRY* glDeleteTextures )( GLsizei n, const GLuint* textures );
extern void ( APIENTRY* glDeleteTransformFeedbacks )( GLsizei n, const GLuint* ids );
extern void ( APIENTRY* glDeleteVertexArrays )( GLsizei n, const GLuint* arrays );
extern void ( APIENTRY* glDepthFunc )( GLenum func );
extern void ( APIENTRY* glDepthMask )( GLboolean flag );
extern void ( APIENTRY* glDepthRange )( GLdouble n, GLdouble f );
extern void ( APIENTRY* glDepthRangeArrayv )( GLuint first, GLsizei count, const GLdouble* v );
extern void ( APIENTRY* glDepthRangeIndexed )( GLuint index, GLdouble n, GLdouble f );
extern void ( APIENTRY* glDepthRangef )( GLfloat n, GLfloat f );
extern void ( APIENTRY* glDetachShader )( GLuint program, GLuint shader );
extern void ( APIENTRY* glDisable )( GLenum cap );
extern void ( APIENTRY* glDisableVertexArrayAttrib )( GLuint vaobj, GLuint index );
extern void ( APIENTRY* glDisableVertexAttribArray )( GLuint index );
extern void ( APIENTRY* glDisablei )( GLenum target, GLuint index );
extern void ( APIENTRY* glDispatchCompute )( GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z );
extern void ( APIENTRY* glDispatchComputeIndirect )( GLintptr indirect );
extern void ( APIENTRY* glDrawArrays )( GLenum mode, GLint first, GLsizei count );
extern void ( APIENTRY* glDrawArraysIndirect )( GLenum mode, const void* indirect );
extern void ( APIENTRY* glDrawArraysInstanced )( GLenum mode, GLint first, GLsizei count, GLsizei instancecount );
extern void ( APIENTRY* glDrawArraysInstancedBaseInstance )( GLenum mode, GLint first, GLsizei count,
															 GLsizei instancecount, GLuint baseinstance );
extern void ( APIENTRY* glDrawBuffer )( GLenum buf );
extern void ( APIENTRY* glDrawBuffers )( GLsizei n, const GLenum* bufs );
extern void ( APIENTRY* glDrawElements )( GLenum mode, GLsizei count, GLenum type, const void* indices );
extern void ( APIENTRY* glDrawElementsBaseVertex )( GLenum mode, GLsizei count, GLenum type, const void* indices,
													GLint basevertex );
extern void ( APIENTRY* glDrawElementsIndirect )( GLenum mode, GLenum type, const void* indirect );
extern void ( APIENTRY* glDrawElementsInstanced )( GLenum mode, GLsizei count, GLenum type, const void* indices,
												   GLsizei instancecount );
extern void ( APIENTRY* glDrawElementsInstancedBaseInstance )( GLenum mode, GLsizei count, GLenum type,
															   const void* indices, GLsizei instancecount,
															   GLuint baseinstance );
extern void ( APIENTRY* glDrawElementsInstancedBaseVertex )( GLenum mode, GLsizei count, GLenum type,
															 const void* indices, GLsizei instancecount,
															 GLint basevertex );
extern void ( APIENTRY* glDrawElementsInstancedBaseVertexBaseInstance )(
	GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex,
	GLuint baseinstance );
extern void ( APIENTRY* glDrawRangeElements )( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type,
											   const void* indices );
extern void ( APIENTRY* glDrawRangeElementsBaseVertex )( GLenum mode, GLuint start, GLuint end, GLsizei count,
														 GLenum type, const void* indices, GLint basevertex );
extern void ( APIENTRY* glDrawTransformFeedback )( GLenum mode, GLuint id );
extern void ( APIENTRY* glDrawTransformFeedbackInstanced )( GLenum mode, GLuint id, GLsizei instancecount );
extern void ( APIENTRY* glDrawTransformFeedbackStream )( GLenum mode, GLuint id, GLuint stream );
extern void ( APIENTRY* glDrawTransformFeedbackStreamInstanced )( GLenum mode, GLuint id, GLuint stream,
																  GLsizei instancecount );
extern void ( APIENTRY* glEnable )( GLenum cap );
extern void ( APIENTRY* glEnableVertexArrayAttrib )( GLuint vaobj, GLuint index );
extern void ( APIENTRY* glEnableVertexAttribArray )( GLuint index );
extern void ( APIENTRY* glEnablei )( GLenum target, GLuint index );
extern void ( APIENTRY* glEndConditionalRender )();
extern void ( APIENTRY* glEndQuery )( GLenum target );
extern void ( APIENTRY* glEndQueryIndexed )( GLenum target, GLuint index );
extern void ( APIENTRY* glEndTransformFeedback )();
extern GLsync ( APIENTRY* glFenceSync )( GLenum condition, GLbitfield flags );
extern void ( APIENTRY* glFinish )();
extern void ( APIENTRY* glFlush )();
extern void ( APIENTRY* glFlushMappedBufferRange )( GLenum target, GLintptr offset, GLsizeiptr length );
extern void ( APIENTRY* glFlushMappedNamedBufferRange )( GLuint buffer, GLintptr offset, GLsizeiptr length );
extern void ( APIENTRY* glFramebufferParameteri )( GLenum target, GLenum pname, GLint param );
extern void ( APIENTRY* glFramebufferRenderbuffer )( GLenum target, GLenum attachment, GLenum renderbuffertarget,
													 GLuint renderbuffer );
extern void ( APIENTRY* glFramebufferTexture )( GLenum target, GLenum attachment, GLuint texture, GLint level );
extern void ( APIENTRY* glFramebufferTexture1D )( GLenum target, GLenum attachment, GLenum textarget, GLuint texture,
												  GLint level );
extern void ( APIENTRY* glFramebufferTexture2D )( GLenum target, GLenum attachment, GLenum textarget, GLuint texture,
												  GLint level );
extern void ( APIENTRY* glFramebufferTexture3D )( GLenum target, GLenum attachment, GLenum textarget, GLuint texture,
												  GLint level, GLint zoffset );
extern void ( APIENTRY* glFramebufferTextureLayer )( GLenum target, GLenum attachment, GLuint texture, GLint level,
													 GLint layer );
extern void ( APIENTRY* glFrontFace )( GLenum mode );
extern void ( APIENTRY* glGenBuffers )( GLsizei n, GLuint* buffers );
extern void ( APIENTRY* glGenFramebuffers )( GLsizei n, GLuint* framebuffers );
extern void ( APIENTRY* glGenProgramPipelines )( GLsizei n, GLuint* pipelines );
extern void ( APIENTRY* glGenQueries )( GLsizei n, GLuint* ids );
extern void ( APIENTRY* glGenRenderbuffers )( GLsizei n, GLuint* renderbuffers );
extern void ( APIENTRY* glGenSamplers )( GLsizei count, GLuint* samplers );
extern void ( APIENTRY* glGenTextures )( GLsizei n, GLuint* textures );
extern void ( APIENTRY* glGenTransformFeedbacks )( GLsizei n, GLuint* ids );
extern void ( APIENTRY* glGenVertexArrays )( GLsizei n, GLuint* arrays );
extern void ( APIENTRY* glGenerateMipmap )( GLenum target );
extern void ( APIENTRY* glGenerateTextureMipmap )( GLuint texture );
extern void ( APIENTRY* glGetActiveAtomicCounterBufferiv )( GLuint program, GLuint bufferIndex, GLenum pname,
															GLint* params );
extern void ( APIENTRY* glGetActiveAttrib )( GLuint program, GLuint index, GLsizei bufSize, GLsizei* length,
											 GLint* size, GLenum* type, GLchar* name );
extern void ( APIENTRY* glGetActiveSubroutineName )( GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize,
													 GLsizei* length, GLchar* name );
extern void ( APIENTRY* glGetActiveSubroutineUniformName )( GLuint program, GLenum shadertype, GLuint index,
															GLsizei bufsize, GLsizei* length, GLchar* name );
extern void ( APIENTRY* glGetActiveSubroutineUniformiv )( GLuint program, GLenum shadertype, GLuint index, GLenum pname,
														  GLint* values );
extern void ( APIENTRY* glGetActiveUniform )( GLuint program, GLuint index, GLsizei bufSize, GLsizei* length,
											  GLint* size, GLenum* type, GLchar* name );
extern void ( APIENTRY* glGetActiveUniformBlockName )( GLuint program, GLuint uniformBlockIndex, GLsizei bufSize,
													   GLsizei* length, GLchar* uniformBlockName );
extern void ( APIENTRY* glGetActiveUniformBlockiv )( GLuint program, GLuint uniformBlockIndex, GLenum pname,
													 GLint* params );
extern void ( APIENTRY* glGetActiveUniformName )( GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length,
												  GLchar* uniformName );
extern void ( APIENTRY* glGetActiveUniformsiv )( GLuint program, GLsizei uniformCount, const GLuint* uniformIndices,
												 GLenum pname, GLint* params );
extern void ( APIENTRY* glGetAttachedShaders )( GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders );
extern GLint ( APIENTRY* glGetAttribLocation )( GLuint program, const GLchar* name );
extern void ( APIENTRY* glGetBooleani_v )( GLenum target, GLuint index, GLboolean* data );
extern void ( APIENTRY* glGetBooleanv )( GLenum pname, GLboolean* data );
extern void ( APIENTRY* glGetBufferParameteri64v )( GLenum target, GLenum pname, GLint64* params );
extern void ( APIENTRY* glGetBufferParameteriv )( GLenum target, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetBufferPointerv )( GLenum target, GLenum pname, void** params );
extern void ( APIENTRY* glGetBufferSubData )( GLenum target, GLintptr offset, GLsizeiptr size, void* data );
extern void ( APIENTRY* glGetCompressedTexImage )( GLenum target, GLint level, void* img );
extern void ( APIENTRY* glGetCompressedTextureImage )( GLuint texture, GLint level, GLsizei bufSize, void* pixels );
extern void ( APIENTRY* glGetCompressedTextureSubImage )( GLuint texture, GLint level, GLint xoffset, GLint yoffset,
														  GLint zoffset, GLsizei width, GLsizei height, GLsizei depth,
														  GLsizei bufSize, void* pixels );
extern GLuint ( APIENTRY* glGetDebugMessageLog )( GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types,
												  GLuint* ids, GLenum* severities, GLsizei* lengths,
												  GLchar* messageLog );
extern void ( APIENTRY* glGetDoublei_v )( GLenum target, GLuint index, GLdouble* data );
extern void ( APIENTRY* glGetDoublev )( GLenum pname, GLdouble* data );
extern GLenum ( APIENTRY* glGetError )();
extern void ( APIENTRY* glGetFloati_v )( GLenum target, GLuint index, GLfloat* data );
extern void ( APIENTRY* glGetFloatv )( GLenum pname, GLfloat* data );
extern GLint ( APIENTRY* glGetFragDataIndex )( GLuint program, const GLchar* name );
extern GLint ( APIENTRY* glGetFragDataLocation )( GLuint program, const GLchar* name );
extern void ( APIENTRY* glGetFramebufferAttachmentParameteriv )( GLenum target, GLenum attachment, GLenum pname,
																 GLint* params );
extern void ( APIENTRY* glGetFramebufferParameteriv )( GLenum target, GLenum pname, GLint* params );
extern GLenum ( APIENTRY* glGetGraphicsResetStatus )();
extern void ( APIENTRY* glGetInteger64i_v )( GLenum target, GLuint index, GLint64* data );
extern void ( APIENTRY* glGetInteger64v )( GLenum pname, GLint64* data );
extern void ( APIENTRY* glGetIntegeri_v )( GLenum target, GLuint index, GLint* data );
extern void ( APIENTRY* glGetIntegerv )( GLenum pname, GLint* data );
extern void ( APIENTRY* glGetInternalformati64v )( GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize,
												   GLint64* params );
extern void ( APIENTRY* glGetInternalformativ )( GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize,
												 GLint* params );
extern void ( APIENTRY* glGetMultisamplefv )( GLenum pname, GLuint index, GLfloat* val );
extern void ( APIENTRY* glGetNamedBufferParameteri64v )( GLuint buffer, GLenum pname, GLint64* params );
extern void ( APIENTRY* glGetNamedBufferParameteriv )( GLuint buffer, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetNamedBufferPointerv )( GLuint buffer, GLenum pname, void** params );
extern void ( APIENTRY* glGetNamedBufferSubData )( GLuint buffer, GLintptr offset, GLsizeiptr size, void* data );
extern void ( APIENTRY* glGetNamedFramebufferAttachmentParameteriv )( GLuint framebuffer, GLenum attachment,
																	  GLenum pname, GLint* params );
extern void ( APIENTRY* glGetNamedFramebufferParameteriv )( GLuint framebuffer, GLenum pname, GLint* param );
extern void ( APIENTRY* glGetNamedRenderbufferParameteriv )( GLuint renderbuffer, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetObjectLabel )( GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length,
											GLchar* label );
extern void ( APIENTRY* glGetObjectPtrLabel )( const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label );
extern void ( APIENTRY* glGetPointerv )( GLenum pname, void** params );
extern void ( APIENTRY* glGetProgramBinary )( GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat,
											  void* binary );
extern void ( APIENTRY* glGetProgramInfoLog )( GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog );
extern void ( APIENTRY* glGetProgramInterfaceiv )( GLuint program, GLenum programInterface, GLenum pname,
												   GLint* params );
extern void ( APIENTRY* glGetProgramPipelineInfoLog )( GLuint pipeline, GLsizei bufSize, GLsizei* length,
													   GLchar* infoLog );
extern void ( APIENTRY* glGetProgramPipelineiv )( GLuint pipeline, GLenum pname, GLint* params );
extern GLuint ( APIENTRY* glGetProgramResourceIndex )( GLuint program, GLenum programInterface, const GLchar* name );
extern GLint ( APIENTRY* glGetProgramResourceLocation )( GLuint program, GLenum programInterface, const GLchar* name );
extern GLint ( APIENTRY* glGetProgramResourceLocationIndex )( GLuint program, GLenum programInterface,
															  const GLchar* name );
extern void ( APIENTRY* glGetProgramResourceName )( GLuint program, GLenum programInterface, GLuint index,
													GLsizei bufSize, GLsizei* length, GLchar* name );
extern void ( APIENTRY* glGetProgramResourceiv )( GLuint program, GLenum programInterface, GLuint index,
												  GLsizei propCount, const GLenum* props, GLsizei bufSize,
												  GLsizei* length, GLint* params );
extern void ( APIENTRY* glGetProgramStageiv )( GLuint program, GLenum shadertype, GLenum pname, GLint* values );
extern void ( APIENTRY* glGetProgramiv )( GLuint program, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetQueryBufferObjecti64v )( GLuint id, GLuint buffer, GLenum pname, GLintptr offset );
extern void ( APIENTRY* glGetQueryBufferObjectiv )( GLuint id, GLuint buffer, GLenum pname, GLintptr offset );
extern void ( APIENTRY* glGetQueryBufferObjectui64v )( GLuint id, GLuint buffer, GLenum pname, GLintptr offset );
extern void ( APIENTRY* glGetQueryBufferObjectuiv )( GLuint id, GLuint buffer, GLenum pname, GLintptr offset );
extern void ( APIENTRY* glGetQueryIndexediv )( GLenum target, GLuint index, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetQueryObjecti64v )( GLuint id, GLenum pname, GLint64* params );
extern void ( APIENTRY* glGetQueryObjectiv )( GLuint id, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetQueryObjectui64v )( GLuint id, GLenum pname, GLuint64* params );
extern void ( APIENTRY* glGetQueryObjectuiv )( GLuint id, GLenum pname, GLuint* params );
extern void ( APIENTRY* glGetQueryiv )( GLenum target, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetRenderbufferParameteriv )( GLenum target, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetSamplerParameterIiv )( GLuint sampler, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetSamplerParameterIuiv )( GLuint sampler, GLenum pname, GLuint* params );
extern void ( APIENTRY* glGetSamplerParameterfv )( GLuint sampler, GLenum pname, GLfloat* params );
extern void ( APIENTRY* glGetSamplerParameteriv )( GLuint sampler, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetShaderInfoLog )( GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog );
extern void ( APIENTRY* glGetShaderPrecisionFormat )( GLenum shadertype, GLenum precisiontype, GLint* range,
													  GLint* precision );
extern void ( APIENTRY* glGetShaderSource )( GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source );
extern void ( APIENTRY* glGetShaderiv )( GLuint shader, GLenum pname, GLint* params );
extern const GLubyte* ( APIENTRY* glGetString )( GLenum name );
extern const GLubyte* ( APIENTRY* glGetStringi )( GLenum name, GLuint index );
extern GLuint ( APIENTRY* glGetSubroutineIndex )( GLuint program, GLenum shadertype, const GLchar* name );
extern GLint ( APIENTRY* glGetSubroutineUniformLocation )( GLuint program, GLenum shadertype, const GLchar* name );
extern void ( APIENTRY* glGetSynciv )( GLsync sync, GLenum pname, GLsizei bufSize, GLsizei* length, GLint* values );
extern void ( APIENTRY* glGetTexImage )( GLenum target, GLint level, GLenum format, GLenum type, void* pixels );
extern void ( APIENTRY* glGetTexLevelParameterfv )( GLenum target, GLint level, GLenum pname, GLfloat* params );
extern void ( APIENTRY* glGetTexLevelParameteriv )( GLenum target, GLint level, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetTexParameterIiv )( GLenum target, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetTexParameterIuiv )( GLenum target, GLenum pname, GLuint* params );
extern void ( APIENTRY* glGetTexParameterfv )( GLenum target, GLenum pname, GLfloat* params );
extern void ( APIENTRY* glGetTexParameteriv )( GLenum target, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetTextureImage )( GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize,
											 void* pixels );
extern void ( APIENTRY* glGetTextureLevelParameterfv )( GLuint texture, GLint level, GLenum pname, GLfloat* params );
extern void ( APIENTRY* glGetTextureLevelParameteriv )( GLuint texture, GLint level, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetTextureParameterIiv )( GLuint texture, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetTextureParameterIuiv )( GLuint texture, GLenum pname, GLuint* params );
extern void ( APIENTRY* glGetTextureParameterfv )( GLuint texture, GLenum pname, GLfloat* params );
extern void ( APIENTRY* glGetTextureParameteriv )( GLuint texture, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetTextureSubImage )( GLuint texture, GLint level, GLint xoffset, GLint yoffset,
												GLint zoffset, GLsizei width, GLsizei height, GLsizei depth,
												GLenum format, GLenum type, GLsizei bufSize, void* pixels );
extern void ( APIENTRY* glGetTransformFeedbackVarying )( GLuint program, GLuint index, GLsizei bufSize, GLsizei* length,
														 GLsizei* size, GLenum* type, GLchar* name );
extern void ( APIENTRY* glGetTransformFeedbacki64_v )( GLuint xfb, GLenum pname, GLuint index, GLint64* param );
extern void ( APIENTRY* glGetTransformFeedbacki_v )( GLuint xfb, GLenum pname, GLuint index, GLint* param );
extern void ( APIENTRY* glGetTransformFeedbackiv )( GLuint xfb, GLenum pname, GLint* param );
extern GLuint ( APIENTRY* glGetUniformBlockIndex )( GLuint program, const GLchar* uniformBlockName );
extern void ( APIENTRY* glGetUniformIndices )( GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames,
											   GLuint* uniformIndices );
extern GLint ( APIENTRY* glGetUniformLocation )( GLuint program, const GLchar* name );
extern void ( APIENTRY* glGetUniformSubroutineuiv )( GLenum shadertype, GLint location, GLuint* params );
extern void ( APIENTRY* glGetUniformdv )( GLuint program, GLint location, GLdouble* params );
extern void ( APIENTRY* glGetUniformfv )( GLuint program, GLint location, GLfloat* params );
extern void ( APIENTRY* glGetUniformiv )( GLuint program, GLint location, GLint* params );
extern void ( APIENTRY* glGetUniformuiv )( GLuint program, GLint location, GLuint* params );
extern void ( APIENTRY* glGetVertexArrayIndexed64iv )( GLuint vaobj, GLuint index, GLenum pname, GLint64* param );
extern void ( APIENTRY* glGetVertexArrayIndexediv )( GLuint vaobj, GLuint index, GLenum pname, GLint* param );
extern void ( APIENTRY* glGetVertexArrayiv )( GLuint vaobj, GLenum pname, GLint* param );
extern void ( APIENTRY* glGetVertexAttribIiv )( GLuint index, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetVertexAttribIuiv )( GLuint index, GLenum pname, GLuint* params );
extern void ( APIENTRY* glGetVertexAttribLdv )( GLuint index, GLenum pname, GLdouble* params );
extern void ( APIENTRY* glGetVertexAttribPointerv )( GLuint index, GLenum pname, void** pointer );
extern void ( APIENTRY* glGetVertexAttribdv )( GLuint index, GLenum pname, GLdouble* params );
extern void ( APIENTRY* glGetVertexAttribfv )( GLuint index, GLenum pname, GLfloat* params );
extern void ( APIENTRY* glGetVertexAttribiv )( GLuint index, GLenum pname, GLint* params );
extern void ( APIENTRY* glGetnColorTable )( GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table );
extern void ( APIENTRY* glGetnCompressedTexImage )( GLenum target, GLint lod, GLsizei bufSize, void* pixels );
extern void ( APIENTRY* glGetnConvolutionFilter )( GLenum target, GLenum format, GLenum type, GLsizei bufSize,
												   void* image );
extern void ( APIENTRY* glGetnHistogram )( GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize,
										   void* values );
extern void ( APIENTRY* glGetnMapdv )( GLenum target, GLenum query, GLsizei bufSize, GLdouble* v );
extern void ( APIENTRY* glGetnMapfv )( GLenum target, GLenum query, GLsizei bufSize, GLfloat* v );
extern void ( APIENTRY* glGetnMapiv )( GLenum target, GLenum query, GLsizei bufSize, GLint* v );
extern void ( APIENTRY* glGetnMinmax )( GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize,
										void* values );
extern void ( APIENTRY* glGetnPixelMapfv )( GLenum map, GLsizei bufSize, GLfloat* values );
extern void ( APIENTRY* glGetnPixelMapuiv )( GLenum map, GLsizei bufSize, GLuint* values );
extern void ( APIENTRY* glGetnPixelMapusv )( GLenum map, GLsizei bufSize, GLushort* values );
extern void ( APIENTRY* glGetnPolygonStipple )( GLsizei bufSize, GLubyte* pattern );
extern void ( APIENTRY* glGetnSeparableFilter )( GLenum target, GLenum format, GLenum type, GLsizei rowBufSize,
												 void* row, GLsizei columnBufSize, void* column, void* span );
extern void ( APIENTRY* glGetnTexImage )( GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize,
										  void* pixels );
extern void ( APIENTRY* glGetnUniformdv )( GLuint program, GLint location, GLsizei bufSize, GLdouble* params );
extern void ( APIENTRY* glGetnUniformfv )( GLuint program, GLint location, GLsizei bufSize, GLfloat* params );
extern void ( APIENTRY* glGetnUniformiv )( GLuint program, GLint location, GLsizei bufSize, GLint* params );
extern void ( APIENTRY* glGetnUniformuiv )( GLuint program, GLint location, GLsizei bufSize, GLuint* params );
extern void ( APIENTRY* glHint )( GLenum target, GLenum mode );
extern void ( APIENTRY* glInvalidateBufferData )( GLuint buffer );
extern void ( APIENTRY* glInvalidateBufferSubData )( GLuint buffer, GLintptr offset, GLsizeiptr length );
extern void ( APIENTRY* glInvalidateFramebuffer )( GLenum target, GLsizei numAttachments, const GLenum* attachments );
extern void ( APIENTRY* glInvalidateNamedFramebufferData )( GLuint framebuffer, GLsizei numAttachments,
															const GLenum* attachments );
extern void ( APIENTRY* glInvalidateNamedFramebufferSubData )( GLuint framebuffer, GLsizei numAttachments,
															   const GLenum* attachments, GLint x, GLint y,
															   GLsizei width, GLsizei height );
extern void ( APIENTRY* glInvalidateSubFramebuffer )( GLenum target, GLsizei numAttachments, const GLenum* attachments,
													  GLint x, GLint y, GLsizei width, GLsizei height );
extern void ( APIENTRY* glInvalidateTexImage )( GLuint texture, GLint level );
extern void ( APIENTRY* glInvalidateTexSubImage )( GLuint texture, GLint level, GLint xoffset, GLint yoffset,
												   GLint zoffset, GLsizei width, GLsizei height, GLsizei depth );
extern GLboolean ( APIENTRY* glIsBuffer )( GLuint buffer );
extern GLboolean ( APIENTRY* glIsEnabled )( GLenum cap );
extern GLboolean ( APIENTRY* glIsEnabledi )( GLenum target, GLuint index );
extern GLboolean ( APIENTRY* glIsFramebuffer )( GLuint framebuffer );
extern GLboolean ( APIENTRY* glIsProgram )( GLuint program );
extern GLboolean ( APIENTRY* glIsProgramPipeline )( GLuint pipeline );
extern GLboolean ( APIENTRY* glIsQuery )( GLuint id );
extern GLboolean ( APIENTRY* glIsRenderbuffer )( GLuint renderbuffer );
extern GLboolean ( APIENTRY* glIsSampler )( GLuint sampler );
extern GLboolean ( APIENTRY* glIsShader )( GLuint shader );
extern GLboolean ( APIENTRY* glIsSync )( GLsync sync );
extern GLboolean ( APIENTRY* glIsTexture )( GLuint texture );
extern GLboolean ( APIENTRY* glIsTransformFeedback )( GLuint id );
extern GLboolean ( APIENTRY* glIsVertexArray )( GLuint array );
extern void ( APIENTRY* glLineWidth )( GLfloat width );
extern void ( APIENTRY* glLinkProgram )( GLuint program );
extern void ( APIENTRY* glLogicOp )( GLenum opcode );
extern void* ( APIENTRY* glMapBuffer )( GLenum target, GLenum access );
extern void* ( APIENTRY* glMapBufferRange )( GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access );
extern void* ( APIENTRY* glMapNamedBuffer )( GLuint buffer, GLenum access );
extern void* ( APIENTRY* glMapNamedBufferRange
)( GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access );
extern void ( APIENTRY* glMemoryBarrier )( GLbitfield barriers );
extern void ( APIENTRY* glMemoryBarrierByRegion )( GLbitfield barriers );
extern void ( APIENTRY* glMinSampleShading )( GLfloat value );
extern void ( APIENTRY* glMultiDrawArrays )( GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount );
extern void ( APIENTRY* glMultiDrawArraysIndirect )( GLenum mode, const void* indirect, GLsizei drawcount,
													 GLsizei stride );
extern void ( APIENTRY* glMultiDrawElements )( GLenum mode, const GLsizei* count, GLenum type,
											   const void* const* indices, GLsizei drawcount );
extern void ( APIENTRY* glMultiDrawElementsBaseVertex )( GLenum mode, const GLsizei* count, GLenum type,
														 const void* const* indices, GLsizei drawcount,
														 const GLint* basevertex );
extern void ( APIENTRY* glMultiDrawElementsIndirect )( GLenum mode, GLenum type, const void* indirect,
													   GLsizei drawcount, GLsizei stride );
extern void ( APIENTRY* glMultiTexCoordP1ui )( GLenum texture, GLenum type, GLuint coords );
extern void ( APIENTRY* glMultiTexCoordP1uiv )( GLenum texture, GLenum type, const GLuint* coords );
extern void ( APIENTRY* glMultiTexCoordP2ui )( GLenum texture, GLenum type, GLuint coords );
extern void ( APIENTRY* glMultiTexCoordP2uiv )( GLenum texture, GLenum type, const GLuint* coords );
extern void ( APIENTRY* glMultiTexCoordP3ui )( GLenum texture, GLenum type, GLuint coords );
extern void ( APIENTRY* glMultiTexCoordP3uiv )( GLenum texture, GLenum type, const GLuint* coords );
extern void ( APIENTRY* glMultiTexCoordP4ui )( GLenum texture, GLenum type, GLuint coords );
extern void ( APIENTRY* glMultiTexCoordP4uiv )( GLenum texture, GLenum type, const GLuint* coords );
extern void ( APIENTRY* glNamedBufferData )( GLuint buffer, GLsizeiptr size, const void* data, GLenum usage );
extern void ( APIENTRY* glNamedBufferStorage )( GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags );
extern void ( APIENTRY* glNamedBufferSubData )( GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data );
extern void ( APIENTRY* glNamedFramebufferDrawBuffer )( GLuint framebuffer, GLenum buf );
extern void ( APIENTRY* glNamedFramebufferDrawBuffers )( GLuint framebuffer, GLsizei n, const GLenum* bufs );
extern void ( APIENTRY* glNamedFramebufferParameteri )( GLuint framebuffer, GLenum pname, GLint param );
extern void ( APIENTRY* glNamedFramebufferReadBuffer )( GLuint framebuffer, GLenum src );
extern void ( APIENTRY* glNamedFramebufferRenderbuffer )( GLuint framebuffer, GLenum attachment,
														  GLenum renderbuffertarget, GLuint renderbuffer );
extern void ( APIENTRY* glNamedFramebufferTexture )( GLuint framebuffer, GLenum attachment, GLuint texture,
													 GLint level );
extern void ( APIENTRY* glNamedFramebufferTextureLayer )( GLuint framebuffer, GLenum attachment, GLuint texture,
														  GLint level, GLint layer );
extern void ( APIENTRY* glNamedRenderbufferStorage )( GLuint renderbuffer, GLenum internalformat, GLsizei width,
													  GLsizei height );
extern void ( APIENTRY* glNamedRenderbufferStorageMultisample )( GLuint renderbuffer, GLsizei samples,
																 GLenum internalformat, GLsizei width, GLsizei height );
extern void ( APIENTRY* glNormalP3ui )( GLenum type, GLuint coords );
extern void ( APIENTRY* glNormalP3uiv )( GLenum type, const GLuint* coords );
extern void ( APIENTRY* glObjectLabel )( GLenum identifier, GLuint name, GLsizei length, const GLchar* label );
extern void ( APIENTRY* glObjectPtrLabel )( const void* ptr, GLsizei length, const GLchar* label );
extern void ( APIENTRY* glPatchParameterfv )( GLenum pname, const GLfloat* values );
extern void ( APIENTRY* glPatchParameteri )( GLenum pname, GLint value );
extern void ( APIENTRY* glPauseTransformFeedback )();
extern void ( APIENTRY* glPixelStoref )( GLenum pname, GLfloat param );
extern void ( APIENTRY* glPixelStorei )( GLenum pname, GLint param );
extern void ( APIENTRY* glPointParameterf )( GLenum pname, GLfloat param );
extern void ( APIENTRY* glPointParameterfv )( GLenum pname, const GLfloat* params );
extern void ( APIENTRY* glPointParameteri )( GLenum pname, GLint param );
extern void ( APIENTRY* glPointParameteriv )( GLenum pname, const GLint* params );
extern void ( APIENTRY* glPointSize )( GLfloat size );
extern void ( APIENTRY* glPolygonMode )( GLenum face, GLenum mode );
extern void ( APIENTRY* glPolygonOffset )( GLfloat factor, GLfloat units );
extern void ( APIENTRY* glPopDebugGroup )();
extern void ( APIENTRY* glPrimitiveRestartIndex )( GLuint index );
extern void ( APIENTRY* glProgramBinary )( GLuint program, GLenum binaryFormat, const void* binary, GLsizei length );
extern void ( APIENTRY* glProgramParameteri )( GLuint program, GLenum pname, GLint value );
extern void ( APIENTRY* glProgramUniform1d )( GLuint program, GLint location, GLdouble v0 );
extern void ( APIENTRY* glProgramUniform1dv )( GLuint program, GLint location, GLsizei count, const GLdouble* value );
extern void ( APIENTRY* glProgramUniform1f )( GLuint program, GLint location, GLfloat v0 );
extern void ( APIENTRY* glProgramUniform1fv )( GLuint program, GLint location, GLsizei count, const GLfloat* value );
extern void ( APIENTRY* glProgramUniform1i )( GLuint program, GLint location, GLint v0 );
extern void ( APIENTRY* glProgramUniform1iv )( GLuint program, GLint location, GLsizei count, const GLint* value );
extern void ( APIENTRY* glProgramUniform1ui )( GLuint program, GLint location, GLuint v0 );
extern void ( APIENTRY* glProgramUniform1uiv )( GLuint program, GLint location, GLsizei count, const GLuint* value );
extern void ( APIENTRY* glProgramUniform2d )( GLuint program, GLint location, GLdouble v0, GLdouble v1 );
extern void ( APIENTRY* glProgramUniform2dv )( GLuint program, GLint location, GLsizei count, const GLdouble* value );
extern void ( APIENTRY* glProgramUniform2f )( GLuint program, GLint location, GLfloat v0, GLfloat v1 );
extern void ( APIENTRY* glProgramUniform2fv )( GLuint program, GLint location, GLsizei count, const GLfloat* value );
extern void ( APIENTRY* glProgramUniform2i )( GLuint program, GLint location, GLint v0, GLint v1 );
extern void ( APIENTRY* glProgramUniform2iv )( GLuint program, GLint location, GLsizei count, const GLint* value );
extern void ( APIENTRY* glProgramUniform2ui )( GLuint program, GLint location, GLuint v0, GLuint v1 );
extern void ( APIENTRY* glProgramUniform2uiv )( GLuint program, GLint location, GLsizei count, const GLuint* value );
extern void ( APIENTRY* glProgramUniform3d )( GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2 );
extern void ( APIENTRY* glProgramUniform3dv )( GLuint program, GLint location, GLsizei count, const GLdouble* value );
extern void ( APIENTRY* glProgramUniform3f )( GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2 );
extern void ( APIENTRY* glProgramUniform3fv )( GLuint program, GLint location, GLsizei count, const GLfloat* value );
extern void ( APIENTRY* glProgramUniform3i )( GLuint program, GLint location, GLint v0, GLint v1, GLint v2 );
extern void ( APIENTRY* glProgramUniform3iv )( GLuint program, GLint location, GLsizei count, const GLint* value );
extern void ( APIENTRY* glProgramUniform3ui )( GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2 );
extern void ( APIENTRY* glProgramUniform3uiv )( GLuint program, GLint location, GLsizei count, const GLuint* value );
extern void ( APIENTRY* glProgramUniform4d )( GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2,
											  GLdouble v3 );
extern void ( APIENTRY* glProgramUniform4dv )( GLuint program, GLint location, GLsizei count, const GLdouble* value );
extern void ( APIENTRY* glProgramUniform4f )( GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2,
											  GLfloat v3 );
extern void ( APIENTRY* glProgramUniform4fv )( GLuint program, GLint location, GLsizei count, const GLfloat* value );
extern void ( APIENTRY* glProgramUniform4i )( GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3 );
extern void ( APIENTRY* glProgramUniform4iv )( GLuint program, GLint location, GLsizei count, const GLint* value );
extern void ( APIENTRY* glProgramUniform4ui )( GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2,
											   GLuint v3 );
extern void ( APIENTRY* glProgramUniform4uiv )( GLuint program, GLint location, GLsizei count, const GLuint* value );
extern void ( APIENTRY* glProgramUniformMatrix2dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
													 const GLdouble* value );
extern void ( APIENTRY* glProgramUniformMatrix2fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
													 const GLfloat* value );
extern void ( APIENTRY* glProgramUniformMatrix2x3dv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLdouble* value );
extern void ( APIENTRY* glProgramUniformMatrix2x3fv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLfloat* value );
extern void ( APIENTRY* glProgramUniformMatrix2x4dv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLdouble* value );
extern void ( APIENTRY* glProgramUniformMatrix2x4fv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLfloat* value );
extern void ( APIENTRY* glProgramUniformMatrix3dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
													 const GLdouble* value );
extern void ( APIENTRY* glProgramUniformMatrix3fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
													 const GLfloat* value );
extern void ( APIENTRY* glProgramUniformMatrix3x2dv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLdouble* value );
extern void ( APIENTRY* glProgramUniformMatrix3x2fv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLfloat* value );
extern void ( APIENTRY* glProgramUniformMatrix3x4dv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLdouble* value );
extern void ( APIENTRY* glProgramUniformMatrix3x4fv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLfloat* value );
extern void ( APIENTRY* glProgramUniformMatrix4dv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
													 const GLdouble* value );
extern void ( APIENTRY* glProgramUniformMatrix4fv )( GLuint program, GLint location, GLsizei count, GLboolean transpose,
													 const GLfloat* value );
extern void ( APIENTRY* glProgramUniformMatrix4x2dv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLdouble* value );
extern void ( APIENTRY* glProgramUniformMatrix4x2fv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLfloat* value );
extern void ( APIENTRY* glProgramUniformMatrix4x3dv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLdouble* value );
extern void ( APIENTRY* glProgramUniformMatrix4x3fv )( GLuint program, GLint location, GLsizei count,
													   GLboolean transpose, const GLfloat* value );
extern void ( APIENTRY* glProvokingVertex )( GLenum mode );
extern void ( APIENTRY* glPushDebugGroup )( GLenum source, GLuint id, GLsizei length, const GLchar* message );
extern void ( APIENTRY* glQueryCounter )( GLuint id, GLenum target );
extern void ( APIENTRY* glReadBuffer )( GLenum src );
extern void ( APIENTRY* glReadPixels )( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type,
										void* pixels );
extern void ( APIENTRY* glReadnPixels )( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type,
										 GLsizei bufSize, void* data );
extern void ( APIENTRY* glReleaseShaderCompiler )();
extern void ( APIENTRY* glRenderbufferStorage )( GLenum target, GLenum internalformat, GLsizei width, GLsizei height );
extern void ( APIENTRY* glRenderbufferStorageMultisample )( GLenum target, GLsizei samples, GLenum internalformat,
															GLsizei width, GLsizei height );
extern void ( APIENTRY* glResumeTransformFeedback )();
extern void ( APIENTRY* glSampleCoverage )( GLfloat value, GLboolean invert );
extern void ( APIENTRY* glSampleMaski )( GLuint maskNumber, GLbitfield mask );
extern void ( APIENTRY* glSamplerParameterIiv )( GLuint sampler, GLenum pname, const GLint* param );
extern void ( APIENTRY* glSamplerParameterIuiv )( GLuint sampler, GLenum pname, const GLuint* param );
extern void ( APIENTRY* glSamplerParameterf )( GLuint sampler, GLenum pname, GLfloat param );
extern void ( APIENTRY* glSamplerParameterfv )( GLuint sampler, GLenum pname, const GLfloat* param );
extern void ( APIENTRY* glSamplerParameteri )( GLuint sampler, GLenum pname, GLint param );
extern void ( APIENTRY* glSamplerParameteriv )( GLuint sampler, GLenum pname, const GLint* param );
extern void ( APIENTRY* glScissor )( GLint x, GLint y, GLsizei width, GLsizei height );
extern void ( APIENTRY* glScissorArrayv )( GLuint first, GLsizei count, const GLint* v );
extern void ( APIENTRY* glScissorIndexed )( GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height );
extern void ( APIENTRY* glScissorIndexedv )( GLuint index, const GLint* v );
extern void ( APIENTRY* glSecondaryColorP3ui )( GLenum type, GLuint color );
extern void ( APIENTRY* glSecondaryColorP3uiv )( GLenum type, const GLuint* color );
extern void ( APIENTRY* glShaderBinary )( GLsizei count, const GLuint* shaders, GLenum binaryformat, const void* binary,
										  GLsizei length );
extern void ( APIENTRY* glShaderSource )( GLuint shader, GLsizei count, const GLchar* const* string,
										  const GLint* length );
extern void ( APIENTRY* glShaderStorageBlockBinding )( GLuint program, GLuint storageBlockIndex,
													   GLuint storageBlockBinding );
extern void ( APIENTRY* glStencilFunc )( GLenum func, GLint ref, GLuint mask );
extern void ( APIENTRY* glStencilFuncSeparate )( GLenum face, GLenum func, GLint ref, GLuint mask );
extern void ( APIENTRY* glStencilMask )( GLuint mask );
extern void ( APIENTRY* glStencilMaskSeparate )( GLenum face, GLuint mask );
extern void ( APIENTRY* glStencilOp )( GLenum fail, GLenum zfail, GLenum zpass );
extern void ( APIENTRY* glStencilOpSeparate )( GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass );
extern void ( APIENTRY* glTexBuffer )( GLenum target, GLenum internalformat, GLuint buffer );
extern void ( APIENTRY* glTexBufferRange )( GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset,
											GLsizeiptr size );
extern void ( APIENTRY* glTexCoordP1ui )( GLenum type, GLuint coords );
extern void ( APIENTRY* glTexCoordP1uiv )( GLenum type, const GLuint* coords );
extern void ( APIENTRY* glTexCoordP2ui )( GLenum type, GLuint coords );
extern void ( APIENTRY* glTexCoordP2uiv )( GLenum type, const GLuint* coords );
extern void ( APIENTRY* glTexCoordP3ui )( GLenum type, GLuint coords );
extern void ( APIENTRY* glTexCoordP3uiv )( GLenum type, const GLuint* coords );
extern void ( APIENTRY* glTexCoordP4ui )( GLenum type, GLuint coords );
extern void ( APIENTRY* glTexCoordP4uiv )( GLenum type, const GLuint* coords );
extern void ( APIENTRY* glTexImage1D )( GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border,
										GLenum format, GLenum type, const void* pixels );
extern void ( APIENTRY* glTexImage2D )( GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
										GLint border, GLenum format, GLenum type, const void* pixels );
extern void ( APIENTRY* glTexImage2DMultisample )( GLenum target, GLsizei samples, GLenum internalformat, GLsizei width,
												   GLsizei height, GLboolean fixedsamplelocations );
extern void ( APIENTRY* glTexImage3D )( GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
										GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels );
extern void ( APIENTRY* glTexImage3DMultisample )( GLenum target, GLsizei samples, GLenum internalformat, GLsizei width,
												   GLsizei height, GLsizei depth, GLboolean fixedsamplelocations );
extern void ( APIENTRY* glTexParameterIiv )( GLenum target, GLenum pname, const GLint* params );
extern void ( APIENTRY* glTexParameterIuiv )( GLenum target, GLenum pname, const GLuint* params );
extern void ( APIENTRY* glTexParameterf )( GLenum target, GLenum pname, GLfloat param );
extern void ( APIENTRY* glTexParameterfv )( GLenum target, GLenum pname, const GLfloat* params );
extern void ( APIENTRY* glTexParameteri )( GLenum target, GLenum pname, GLint param );
extern void ( APIENTRY* glTexParameteriv )( GLenum target, GLenum pname, const GLint* params );
extern void ( APIENTRY* glTexStorage1D )( GLenum target, GLsizei levels, GLenum internalformat, GLsizei width );
extern void ( APIENTRY* glTexStorage2D )( GLenum target, GLsizei levels, GLenum internalformat, GLsizei width,
										  GLsizei height );
extern void ( APIENTRY* glTexStorage2DMultisample )( GLenum target, GLsizei samples, GLenum internalformat,
													 GLsizei width, GLsizei height, GLboolean fixedsamplelocations );
extern void ( APIENTRY* glTexStorage3D )( GLenum target, GLsizei levels, GLenum internalformat, GLsizei width,
										  GLsizei height, GLsizei depth );
extern void ( APIENTRY* glTexStorage3DMultisample )( GLenum target, GLsizei samples, GLenum internalformat,
													 GLsizei width, GLsizei height, GLsizei depth,
													 GLboolean fixedsamplelocations );
extern void ( APIENTRY* glTexSubImage1D )( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format,
										   GLenum type, const void* pixels );
extern void ( APIENTRY* glTexSubImage2D )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
										   GLsizei height, GLenum format, GLenum type, const void* pixels );
extern void ( APIENTRY* glTexSubImage3D )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
										   GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type,
										   const void* pixels );
extern void ( APIENTRY* glTextureBarrier )();
extern void ( APIENTRY* glTextureBuffer )( GLuint texture, GLenum internalformat, GLuint buffer );
extern void ( APIENTRY* glTextureBufferRange )( GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset,
												GLsizeiptr size );
extern void ( APIENTRY* glTextureParameterIiv )( GLuint texture, GLenum pname, const GLint* params );
extern void ( APIENTRY* glTextureParameterIuiv )( GLuint texture, GLenum pname, const GLuint* params );
extern void ( APIENTRY* glTextureParameterf )( GLuint texture, GLenum pname, GLfloat param );
extern void ( APIENTRY* glTextureParameterfv )( GLuint texture, GLenum pname, const GLfloat* param );
extern void ( APIENTRY* glTextureParameteri )( GLuint texture, GLenum pname, GLint param );
extern void ( APIENTRY* glTextureParameteriv )( GLuint texture, GLenum pname, const GLint* param );
extern void ( APIENTRY* glTextureStorage1D )( GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width );
extern void ( APIENTRY* glTextureStorage2D )( GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width,
											  GLsizei height );
extern void ( APIENTRY* glTextureStorage2DMultisample )( GLuint texture, GLsizei samples, GLenum internalformat,
														 GLsizei width, GLsizei height,
														 GLboolean fixedsamplelocations );
extern void ( APIENTRY* glTextureStorage3D )( GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width,
											  GLsizei height, GLsizei depth );
extern void ( APIENTRY* glTextureStorage3DMultisample )( GLuint texture, GLsizei samples, GLenum internalformat,
														 GLsizei width, GLsizei height, GLsizei depth,
														 GLboolean fixedsamplelocations );
extern void ( APIENTRY* glTextureSubImage1D )( GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format,
											   GLenum type, const void* pixels );
extern void ( APIENTRY* glTextureSubImage2D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
											   GLsizei height, GLenum format, GLenum type, const void* pixels );
extern void ( APIENTRY* glTextureSubImage3D )( GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
											   GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type,
											   const void* pixels );
extern void ( APIENTRY* glTextureView )( GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat,
										 GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers );
extern void ( APIENTRY* glTransformFeedbackBufferBase )( GLuint xfb, GLuint index, GLuint buffer );
extern void ( APIENTRY* glTransformFeedbackBufferRange )( GLuint xfb, GLuint index, GLuint buffer, GLintptr offset,
														  GLsizeiptr size );
extern void ( APIENTRY* glTransformFeedbackVaryings )( GLuint program, GLsizei count, const GLchar* const* varyings,
													   GLenum bufferMode );
extern void ( APIENTRY* glUniform1d )( GLint location, GLdouble x );
extern void ( APIENTRY* glUniform1dv )( GLint location, GLsizei count, const GLdouble* value );
extern void ( APIENTRY* glUniform1f )( GLint location, GLfloat v0 );
extern void ( APIENTRY* glUniform1fv )( GLint location, GLsizei count, const GLfloat* value );
extern void ( APIENTRY* glUniform1i )( GLint location, GLint v0 );
extern void ( APIENTRY* glUniform1iv )( GLint location, GLsizei count, const GLint* value );
extern void ( APIENTRY* glUniform1ui )( GLint location, GLuint v0 );
extern void ( APIENTRY* glUniform1uiv )( GLint location, GLsizei count, const GLuint* value );
extern void ( APIENTRY* glUniform2d )( GLint location, GLdouble x, GLdouble y );
extern void ( APIENTRY* glUniform2dv )( GLint location, GLsizei count, const GLdouble* value );
extern void ( APIENTRY* glUniform2f )( GLint location, GLfloat v0, GLfloat v1 );
extern void ( APIENTRY* glUniform2fv )( GLint location, GLsizei count, const GLfloat* value );
extern void ( APIENTRY* glUniform2i )( GLint location, GLint v0, GLint v1 );
extern void ( APIENTRY* glUniform2iv )( GLint location, GLsizei count, const GLint* value );
extern void ( APIENTRY* glUniform2ui )( GLint location, GLuint v0, GLuint v1 );
extern void ( APIENTRY* glUniform2uiv )( GLint location, GLsizei count, const GLuint* value );
extern void ( APIENTRY* glUniform3d )( GLint location, GLdouble x, GLdouble y, GLdouble z );
extern void ( APIENTRY* glUniform3dv )( GLint location, GLsizei count, const GLdouble* value );
extern void ( APIENTRY* glUniform3f )( GLint location, GLfloat v0, GLfloat v1, GLfloat v2 );
extern void ( APIENTRY* glUniform3fv )( GLint location, GLsizei count, const GLfloat* value );
extern void ( APIENTRY* glUniform3i )( GLint location, GLint v0, GLint v1, GLint v2 );
extern void ( APIENTRY* glUniform3iv )( GLint location, GLsizei count, const GLint* value );
extern void ( APIENTRY* glUniform3ui )( GLint location, GLuint v0, GLuint v1, GLuint v2 );
extern void ( APIENTRY* glUniform3uiv )( GLint location, GLsizei count, const GLuint* value );
extern void ( APIENTRY* glUniform4d )( GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w );
extern void ( APIENTRY* glUniform4dv )( GLint location, GLsizei count, const GLdouble* value );
extern void ( APIENTRY* glUniform4f )( GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3 );
extern void ( APIENTRY* glUniform4fv )( GLint location, GLsizei count, const GLfloat* value );
extern void ( APIENTRY* glUniform4i )( GLint location, GLint v0, GLint v1, GLint v2, GLint v3 );
extern void ( APIENTRY* glUniform4iv )( GLint location, GLsizei count, const GLint* value );
extern void ( APIENTRY* glUniform4ui )( GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3 );
extern void ( APIENTRY* glUniform4uiv )( GLint location, GLsizei count, const GLuint* value );
extern void ( APIENTRY* glUniformBlockBinding )( GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding );
extern void ( APIENTRY* glUniformMatrix2dv )( GLint location, GLsizei count, GLboolean transpose,
											  const GLdouble* value );
extern void ( APIENTRY* glUniformMatrix2fv
)( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value );
extern void ( APIENTRY* glUniformMatrix2x3dv )( GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value );
extern void ( APIENTRY* glUniformMatrix2x3fv )( GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value );
extern void ( APIENTRY* glUniformMatrix2x4dv )( GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value );
extern void ( APIENTRY* glUniformMatrix2x4fv )( GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value );
extern void ( APIENTRY* glUniformMatrix3dv )( GLint location, GLsizei count, GLboolean transpose,
											  const GLdouble* value );
extern void ( APIENTRY* glUniformMatrix3fv
)( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value );
extern void ( APIENTRY* glUniformMatrix3x2dv )( GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value );
extern void ( APIENTRY* glUniformMatrix3x2fv )( GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value );
extern void ( APIENTRY* glUniformMatrix3x4dv )( GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value );
extern void ( APIENTRY* glUniformMatrix3x4fv )( GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value );
extern void ( APIENTRY* glUniformMatrix4dv )( GLint location, GLsizei count, GLboolean transpose,
											  const GLdouble* value );
extern void ( APIENTRY* glUniformMatrix4fv
)( GLint location, GLsizei count, GLboolean transpose, const GLfloat* value );
extern void ( APIENTRY* glUniformMatrix4x2dv )( GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value );
extern void ( APIENTRY* glUniformMatrix4x2fv )( GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value );
extern void ( APIENTRY* glUniformMatrix4x3dv )( GLint location, GLsizei count, GLboolean transpose,
												const GLdouble* value );
extern void ( APIENTRY* glUniformMatrix4x3fv )( GLint location, GLsizei count, GLboolean transpose,
												const GLfloat* value );
extern void ( APIENTRY* glUniformSubroutinesuiv )( GLenum shadertype, GLsizei count, const GLuint* indices );
extern GLboolean ( APIENTRY* glUnmapBuffer )( GLenum target );
extern GLboolean ( APIENTRY* glUnmapNamedBuffer )( GLuint buffer );
extern void ( APIENTRY* glUseProgram )( GLuint program );
extern void ( APIENTRY* glUseProgramStages )( GLuint pipeline, GLbitfield stages, GLuint program );
extern void ( APIENTRY* glValidateProgram )( GLuint program );
extern void ( APIENTRY* glValidateProgramPipeline )( GLuint pipeline );
extern void ( APIENTRY* glVertexArrayAttribBinding )( GLuint vaobj, GLuint attribindex, GLuint bindingindex );
extern void ( APIENTRY* glVertexArrayAttribFormat )( GLuint vaobj, GLuint attribindex, GLint size, GLenum type,
													 GLboolean normalized, GLuint relativeoffset );
extern void ( APIENTRY* glVertexArrayAttribIFormat )( GLuint vaobj, GLuint attribindex, GLint size, GLenum type,
													  GLuint relativeoffset );
extern void ( APIENTRY* glVertexArrayAttribLFormat )( GLuint vaobj, GLuint attribindex, GLint size, GLenum type,
													  GLuint relativeoffset );
extern void ( APIENTRY* glVertexArrayBindingDivisor )( GLuint vaobj, GLuint bindingindex, GLuint divisor );
extern void ( APIENTRY* glVertexArrayElementBuffer )( GLuint vaobj, GLuint buffer );
extern void ( APIENTRY* glVertexArrayVertexBuffer )( GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset,
													 GLsizei stride );
extern void ( APIENTRY* glVertexArrayVertexBuffers )( GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers,
													  const GLintptr* offsets, const GLsizei* strides );
extern void ( APIENTRY* glVertexAttrib1d )( GLuint index, GLdouble x );
extern void ( APIENTRY* glVertexAttrib1dv )( GLuint index, const GLdouble* v );
extern void ( APIENTRY* glVertexAttrib1f )( GLuint index, GLfloat x );
extern void ( APIENTRY* glVertexAttrib1fv )( GLuint index, const GLfloat* v );
extern void ( APIENTRY* glVertexAttrib1s )( GLuint index, GLshort x );
extern void ( APIENTRY* glVertexAttrib1sv )( GLuint index, const GLshort* v );
extern void ( APIENTRY* glVertexAttrib2d )( GLuint index, GLdouble x, GLdouble y );
extern void ( APIENTRY* glVertexAttrib2dv )( GLuint index, const GLdouble* v );
extern void ( APIENTRY* glVertexAttrib2f )( GLuint index, GLfloat x, GLfloat y );
extern void ( APIENTRY* glVertexAttrib2fv )( GLuint index, const GLfloat* v );
extern void ( APIENTRY* glVertexAttrib2s )( GLuint index, GLshort x, GLshort y );
extern void ( APIENTRY* glVertexAttrib2sv )( GLuint index, const GLshort* v );
extern void ( APIENTRY* glVertexAttrib3d )( GLuint index, GLdouble x, GLdouble y, GLdouble z );
extern void ( APIENTRY* glVertexAttrib3dv )( GLuint index, const GLdouble* v );
extern void ( APIENTRY* glVertexAttrib3f )( GLuint index, GLfloat x, GLfloat y, GLfloat z );
extern void ( APIENTRY* glVertexAttrib3fv )( GLuint index, const GLfloat* v );
extern void ( APIENTRY* glVertexAttrib3s )( GLuint index, GLshort x, GLshort y, GLshort z );
extern void ( APIENTRY* glVertexAttrib3sv )( GLuint index, const GLshort* v );
extern void ( APIENTRY* glVertexAttrib4Nbv )( GLuint index, const GLbyte* v );
extern void ( APIENTRY* glVertexAttrib4Niv )( GLuint index, const GLint* v );
extern void ( APIENTRY* glVertexAttrib4Nsv )( GLuint index, const GLshort* v );
extern void ( APIENTRY* glVertexAttrib4Nub )( GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w );
extern void ( APIENTRY* glVertexAttrib4Nubv )( GLuint index, const GLubyte* v );
extern void ( APIENTRY* glVertexAttrib4Nuiv )( GLuint index, const GLuint* v );
extern void ( APIENTRY* glVertexAttrib4Nusv )( GLuint index, const GLushort* v );
extern void ( APIENTRY* glVertexAttrib4bv )( GLuint index, const GLbyte* v );
extern void ( APIENTRY* glVertexAttrib4d )( GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w );
extern void ( APIENTRY* glVertexAttrib4dv )( GLuint index, const GLdouble* v );
extern void ( APIENTRY* glVertexAttrib4f )( GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w );
extern void ( APIENTRY* glVertexAttrib4fv )( GLuint index, const GLfloat* v );
extern void ( APIENTRY* glVertexAttrib4iv )( GLuint index, const GLint* v );
extern void ( APIENTRY* glVertexAttrib4s )( GLuint index, GLshort x, GLshort y, GLshort z, GLshort w );
extern void ( APIENTRY* glVertexAttrib4sv )( GLuint index, const GLshort* v );
extern void ( APIENTRY* glVertexAttrib4ubv )( GLuint index, const GLubyte* v );
extern void ( APIENTRY* glVertexAttrib4uiv )( GLuint index, const GLuint* v );
extern void ( APIENTRY* glVertexAttrib4usv )( GLuint index, const GLushort* v );
extern void ( APIENTRY* glVertexAttribBinding )( GLuint attribindex, GLuint bindingindex );
extern void ( APIENTRY* glVertexAttribDivisor )( GLuint index, GLuint divisor );
extern void ( APIENTRY* glVertexAttribFormat )( GLuint attribindex, GLint size, GLenum type, GLboolean normalized,
												GLuint relativeoffset );
extern void ( APIENTRY* glVertexAttribI1i )( GLuint index, GLint x );
extern void ( APIENTRY* glVertexAttribI1iv )( GLuint index, const GLint* v );
extern void ( APIENTRY* glVertexAttribI1ui )( GLuint index, GLuint x );
extern void ( APIENTRY* glVertexAttribI1uiv )( GLuint index, const GLuint* v );
extern void ( APIENTRY* glVertexAttribI2i )( GLuint index, GLint x, GLint y );
extern void ( APIENTRY* glVertexAttribI2iv )( GLuint index, const GLint* v );
extern void ( APIENTRY* glVertexAttribI2ui )( GLuint index, GLuint x, GLuint y );
extern void ( APIENTRY* glVertexAttribI2uiv )( GLuint index, const GLuint* v );
extern void ( APIENTRY* glVertexAttribI3i )( GLuint index, GLint x, GLint y, GLint z );
extern void ( APIENTRY* glVertexAttribI3iv )( GLuint index, const GLint* v );
extern void ( APIENTRY* glVertexAttribI3ui )( GLuint index, GLuint x, GLuint y, GLuint z );
extern void ( APIENTRY* glVertexAttribI3uiv )( GLuint index, const GLuint* v );
extern void ( APIENTRY* glVertexAttribI4bv )( GLuint index, const GLbyte* v );
extern void ( APIENTRY* glVertexAttribI4i )( GLuint index, GLint x, GLint y, GLint z, GLint w );
extern void ( APIENTRY* glVertexAttribI4iv )( GLuint index, const GLint* v );
extern void ( APIENTRY* glVertexAttribI4sv )( GLuint index, const GLshort* v );
extern void ( APIENTRY* glVertexAttribI4ubv )( GLuint index, const GLubyte* v );
extern void ( APIENTRY* glVertexAttribI4ui )( GLuint index, GLuint x, GLuint y, GLuint z, GLuint w );
extern void ( APIENTRY* glVertexAttribI4uiv )( GLuint index, const GLuint* v );
extern void ( APIENTRY* glVertexAttribI4usv )( GLuint index, const GLushort* v );
extern void ( APIENTRY* glVertexAttribIFormat )( GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset );
extern void ( APIENTRY* glVertexAttribIPointer )( GLuint index, GLint size, GLenum type, GLsizei stride,
												  const void* pointer );
extern void ( APIENTRY* glVertexAttribL1d )( GLuint index, GLdouble x );
extern void ( APIENTRY* glVertexAttribL1dv )( GLuint index, const GLdouble* v );
extern void ( APIENTRY* glVertexAttribL2d )( GLuint index, GLdouble x, GLdouble y );
extern void ( APIENTRY* glVertexAttribL2dv )( GLuint index, const GLdouble* v );
extern void ( APIENTRY* glVertexAttribL3d )( GLuint index, GLdouble x, GLdouble y, GLdouble z );
extern void ( APIENTRY* glVertexAttribL3dv )( GLuint index, const GLdouble* v );
extern void ( APIENTRY* glVertexAttribL4d )( GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w );
extern void ( APIENTRY* glVertexAttribL4dv )( GLuint index, const GLdouble* v );
extern void ( APIENTRY* glVertexAttribLFormat )( GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset );
extern void ( APIENTRY* glVertexAttribLPointer )( GLuint index, GLint size, GLenum type, GLsizei stride,
												  const void* pointer );
extern void ( APIENTRY* glVertexAttribP1ui )( GLuint index, GLenum type, GLboolean normalized, GLuint value );
extern void ( APIENTRY* glVertexAttribP1uiv )( GLuint index, GLenum type, GLboolean normalized, const GLuint* value );
extern void ( APIENTRY* glVertexAttribP2ui )( GLuint index, GLenum type, GLboolean normalized, GLuint value );
extern void ( APIENTRY* glVertexAttribP2uiv )( GLuint index, GLenum type, GLboolean normalized, const GLuint* value );
extern void ( APIENTRY* glVertexAttribP3ui )( GLuint index, GLenum type, GLboolean normalized, GLuint value );
extern void ( APIENTRY* glVertexAttribP3uiv )( GLuint index, GLenum type, GLboolean normalized, const GLuint* value );
extern void ( APIENTRY* glVertexAttribP4ui )( GLuint index, GLenum type, GLboolean normalized, GLuint value );
extern void ( APIENTRY* glVertexAttribP4uiv )( GLuint index, GLenum type, GLboolean normalized, const GLuint* value );
extern void ( APIENTRY* glVertexAttribPointer )( GLuint index, GLint size, GLenum type, GLboolean normalized,
												 GLsizei stride, const void* pointer );
extern void ( APIENTRY* glVertexBindingDivisor )( GLuint bindingindex, GLuint divisor );
extern void ( APIENTRY* glVertexP2ui )( GLenum type, GLuint value );
extern void ( APIENTRY* glVertexP2uiv )( GLenum type, const GLuint* value );
extern void ( APIENTRY* glVertexP3ui )( GLenum type, GLuint value );
extern void ( APIENTRY* glVertexP3uiv )( GLenum type, const GLuint* value );
extern void ( APIENTRY* glVertexP4ui )( GLenum type, GLuint value );
extern void ( APIENTRY* glVertexP4uiv )( GLenum type, const GLuint* value );
extern void ( APIENTRY* glViewport )( GLint x, GLint y, GLsizei width, GLsizei height );
extern void ( APIENTRY* glViewportArrayv )( GLuint first, GLsizei count, const GLfloat* v );
extern void ( APIENTRY* glViewportIndexedf )( GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h );
extern void ( APIENTRY* glViewportIndexedfv )( GLuint index, const GLfloat* v );
extern void ( APIENTRY* glWaitSync )( GLsync sync, GLbitfield flags, GLuint64 timeout );

#undef APIENTRY
