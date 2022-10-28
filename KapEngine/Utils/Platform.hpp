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

//check platform
#ifndef ON_WINDOWS
    #ifdef __WINDOWS__
        #define ON_WINDOWS true
    #else
        #define ON_WINDOWS false
    #endif
#endif

#ifndef ON_LINUX
    #ifdef __LINUX__
        #define ON_LINUX true
    #else
        #define ON_LINUX false
    #endif
#endif

#ifndef ON_MACOS
    #ifdef __MACOS__
        #define ON_MACOS true
    #else
        #define ON_MACOS false
    #endif
#endif

#ifndef ON_ANDROID
    #ifdef __ANDROID__
        #define ON_ANDROID true
    #else
        #define ON_ANDROID false
    #endif
#endif

#ifndef ON_IPHONE
    #define ON_IPHONE false
#endif

#ifndef ON_XBOX
    #define ON_XBOX false
#endif

#ifndef ON_PLAYSTATION
    #define ON_PLAYSTATION false
#endif

#ifndef ON_NINTENDO
    #define ON_NINTENDO false
#endif

#ifndef ON_CLANG
    #ifndef __clang__
        #define ON_CLANG false
    #else
        #define ON_CLANG true
    #endif
#endif

#ifndef ON_GCC
    #ifndef __GNUC__
        #define ON_GCC false
    #else
        #define ON_GCC true
    #endif
#endif

#endif
