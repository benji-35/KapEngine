/*
** EPITECH PROJECT, 2022
** engine
** File description:
** KapEngineSettings
*/

#ifndef KAPENGINESETTINGS_HPP_
#define KAPENGINESETTINGS_HPP_

#ifndef KAPENGINEVERSION_HPP_
    #include "KapEngineVersion.hpp"
#endif

#ifndef KAPENGINE_PLATFORM_HPP
    #include "Utils/Platform.hpp"
#endif

#ifndef KAPENGINE_BETA_ACTIVE
    #define KAPENGINE_BETA_ACTIVE false
#endif

#ifndef KAPENGINE_PROFILER_ACTIVE
    #define KAPENGINE_PROFILER_ACTIVE false
#endif

#ifndef KAPENGINE_THREAD_ACTIVE
    #define KAPENGINE_THREAD_ACTIVE false
#endif

#ifndef KAPENGINE_DEBUG_ACTIVE
    #define KAPENGINE_DEBUG_ACTIVE false
#endif

#ifndef KAPENGINE_EDITOR_ACTIVE
    #define KAPENGINE_EDITOR_ACTIVE false
#endif

#ifndef WINDOWS_ASSET_PATH_CHANGED
    #define WINDOWS_ASSET_PATH_CHANGED true
#endif

#ifndef LINUX_ASSET_PATH_CHANGED
    #define LINUX_ASSET_PATH_CHANGED false
#endif

#ifndef MACOS_ASSET_PATH_CHANGED
    #define MACOS_ASSET_PATH_CHANGED false
#endif

#ifndef KAPENGINE_PREFIX_ASSETS_PATH
    #if ON_WINDOWS
        #if WINDOWS_ASSET_PATH_CHANGED
            #define KAPENGINE_PREFIX_ASSETS_PATH "../../../"
        #else
            #define KAPENGINE_PREFIX_ASSETS_PATH ""
        #endif
    #elif ON_LINUX
        #if LINUX_ASSET_PATH_CHANGED
            #define KAPENGINE_PREFIX_ASSETS_PATH "../"
        #else
            #define KAPENGINE_PREFIX_ASSETS_PATH ""
        #endif
    #elif ON_MACOS
        #if MACOS_ASSET_PATH_CHANGED
            #define KAPENGINE_PREFIX_ASSETS_PATH "../"
        #else
            #define KAPENGINE_PREFIX_ASSETS_PATH ""
        #endif
    #else
        #define KAPENGINE_PREFIX_ASSETS_PATH ""
    #endif
#endif

#endif /* !KAPENGINESETTINGS_HPP_ */
