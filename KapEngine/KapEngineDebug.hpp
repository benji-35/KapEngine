/*
** EPITECH PROJECT, 2022
** engine
** File description:
** KapDebug
*/

#ifndef INCLUDES_KAPENGINE_DEBUG_HPP_
#define INCLUDES_KAPENGINE_DEBUG_HPP_

#ifndef DEBUG_HPP_
    #include "Debug/Debug.hpp"
#endif

#include "Platform.hpp"

#ifndef KAPENGINE_DEBUGS_MACROS
#define KAPENGINE_DEBUGS_MACROS
    #ifndef KAP_DEBUG_LOG
        #define KAP_DEBUG_LOG(__expr) (KapEngine::Debug::log(__expr, __PRETTY_FUNCTION__, __LINE__))
    #endif
    #ifndef DEBUG_LOG
        #define DEBUG_LOG(__expr) (Debug::log(__expr, __PRETTY_FUNCTION__, __LINE__))
    #endif

    #ifndef KAP_DEBUG_WARNING
        #define KAP_DEBUG_WARNING(__expr) (KapEngine::Debug::warning(__expr, __PRETTY_FUNCTION__, __LINE__))
    #endif
    #ifndef DEBUG_WARNING
        #define DEBUG_WARNING(__expr) (Debug::warning(__expr, __PRETTY_FUNCTION__, __LINE__))
    #endif

    #ifndef KAP_DEBUG_ERROR
        #define KAP_DEBUG_ERROR(__expr) (KapEngine::Debug::error(__expr, __PRETTY_FUNCTION__, __LINE__))
    #endif
    #ifndef DEBUG_ERROR
        #define DEBUG_ERROR(__expr) (Debug::error(__expr, __PRETTY_FUNCTION__, __LINE__))
    #endif
#endif

#endif /* !INCLUDES_KAPENGINE_DEBUG_HPP_ */
