#ifndef KAPENGINE_PLATFORM_HPP
#define KAPENGINE_PLATFORM_HPP

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

//define KapEngine version
/**
 * @brief KapEngine major version
 * @return int value
*/
#define KAPENGINE_VERSION_MAJOR 1
/**
 * @brief KapEngine minor version
 * @return int value
*/
#define KAPENGINE_VERSION_MINOR 2
/**
 * @brief KapEngine version
 * @return string value
 */
#define KAPENGINE_VERSION "1.2.12"

#endif
