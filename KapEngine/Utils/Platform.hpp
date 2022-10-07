#pragma once

// Platform definitions
#if defined(_WIN32) || defined(_WIN64)
#define __WINDOWS__
#endif

#if defined(__linux__) || defined(__linux)
#define __LINUX__
#endif

#ifdef __APPLE__
#ifdef __MACH__
#define __MACOS__
#endif
#endif

#ifndef byte
typedef unsigned char byte;
#endif

#ifdef __WINDOWS__

#define NOMINMAX

#endif

#ifndef ushort
typedef unsigned short ushort;
#endif
