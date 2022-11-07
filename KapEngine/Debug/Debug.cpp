/*
** EPITECH PROJECT, 2022
** engine
** File description:
** Debug
*/

#include "Debug.hpp"

#if KAPENGINE_THREAD_ACTIVE
    #if KAPENGINE_BETA_ACTIVE
        std::mutex Debug::logMutex;
    #endif
#endif
