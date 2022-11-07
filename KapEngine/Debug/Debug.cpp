/*
** EPITECH PROJECT, 2022
** KapEngine
** File description:
** Debug
*/

#include "Debug.hpp"

#if KAPENGINE_THREAD_ACTIVE
    #if KAPENGINE_BETA_ACTIVE
        std::mutex KapEngine::Debug::logMutex;
    #endif
#endif

void KapEngine::Debug::log(std::string _msg, std::string prefix) {
    PROFILER_FUNC_START();
    #if KAPENGINE_THREAD_ACTIVE
        #if KAPENGINE_BETA_ACTIVE
            if (!logMutex.try_lock())
                return;
            std::cout << "[" << __getCDate() << "] " << prefix << boldStyle() << " log: " << colorNone() << _msg << colorNone() << std::endl;
            logMutex.unlock();
        #endif
    #else
        std::cout << "[" << __getCDate() << "] " << prefix << boldStyle() << " log: " << colorNone() << _msg << colorNone() << std::endl;
    #endif
    PROFILER_FUNC_END();
}

void KapEngine::Debug::warning(std::string _msg, std::string prefix) {
    PROFILER_FUNC_START();
    #if KAPENGINE_THREAD_ACTIVE
        #if KAPENGINE_BETA_ACTIVE
            logMutex.lock();
            std::cout << "[" << __getCDate() << "] " << prefix << boldStyle() << colorYellow() << " warning: " << colorNone() << _msg << colorNone() << std::endl;
            logMutex.unlock();
        #endif
    #else
        std::cout << "[" << __getCDate() << "] " << prefix << boldStyle() << colorYellow() << " warning: " << colorNone() << _msg << colorNone() << std::endl;
    #endif
    PROFILER_FUNC_END();
}

void KapEngine::Debug::error(std::string _msg, std::string prefix) {
    PROFILER_FUNC_START();
    #if KAPENGINE_THREAD_ACTIVE
        #if KAPENGINE_BETA_ACTIVE
            logMutex.lock();
            std::cout << "[" << __getCDate() << "] " << prefix << colorRed() << " error: " << colorNone() << _msg << colorNone() << std::endl;
            logMutex.unlock();
        #endif
    #else
        std::cout << "[" << __getCDate() << "] " << prefix << colorRed() << " error: " << colorNone() << _msg << colorNone() << std::endl;
    #endif
    PROFILER_FUNC_END();
}
