/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Debug
*/

#ifndef DEBUG_HPP_
#define DEBUG_HPP_

#include <string>
#include <ctime>
#include <iostream>

#if KAPENGINE_THREAD_ACTIVE
    #if KAPENGINE_BETA_ACTIVE
        #include <mutex>
    #endif
#endif

#include "KapEngineSettings.hpp"
#include "Profiler/KapProfiler.hpp"

namespace KapEngine {
    class Debug {
        public:

            /**
            * @brief display a simple message
            */
            static void log(std::string _msg, std::string prefix = "") {
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

            static void log(char const* _msg, std::string prefix = "") {
                PROFILER_FUNC_START();
                log(std::string(_msg), prefix);
                PROFILER_FUNC_END();
            }

            static void log(const char *_msg, const char *fileName, int const line) {
                PROFILER_FUNC_START();
                log(std::string(_msg), fileName, line);
                PROFILER_FUNC_END();
            }

            static void log(std::string const& _msg, const char *fileName, int const line) {
                PROFILER_FUNC_START();
                log(std::string(_msg), "[" + colorGreen() + std::string(fileName) + colorNone() + " " + colorBlue() + "l. " + std::to_string(line) + colorNone() + "]");
                PROFILER_FUNC_END();
            }

            /**
            * @brief display a warning message
            */
            static void warning(std::string _msg, std::string prefix = "") {
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

            static void warning(char const* _msg, std::string prefix = "") {
                PROFILER_FUNC_START();
                warning(std::string(_msg), prefix);
                PROFILER_FUNC_END();
            }

            static void warning(const char *_msg, const char *fileName, int const line) {
                PROFILER_FUNC_START();
                warning(std::string(_msg), fileName, line);
                PROFILER_FUNC_END();
            }

            static void warning(std::string const& _msg, const char *fileName, int const line) {
                PROFILER_FUNC_START();
                warning(std::string(_msg), "[" + colorYellow() + std::string(fileName) + colorNone() + " " + colorBlue() + "l. " + std::to_string(line) + colorNone() + "]");
                PROFILER_FUNC_END();
            }
            /**
            * @brief display an error message
            */
            static void error(std::string _msg, std::string prefix = "") {
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

            static void error(char const* _msg, std::string prefix = "") {
                PROFILER_FUNC_START();
                error(std::string(_msg), prefix);
                PROFILER_FUNC_END();
            }

            static void error(const char *_msg, const char *fileName, int const line) {
                PROFILER_FUNC_START();
                error(std::string(_msg), fileName, line);
                PROFILER_FUNC_END();
            }

            static void error(std::string const& _msg, const char *fileName, int const line) {
                PROFILER_FUNC_START();
                error(std::string(_msg), "[" + colorRed() + std::string(fileName) + colorNone() + " " + colorBlue() + "l. " + std::to_string(line) + colorNone() + "]");
                PROFILER_FUNC_END();
            }

            static std::string colorNone() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[0m";
                #endif
            }

            static std::string colorRed() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[31m";
                #endif
            }

            static std::string colorYellow() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[33m";
                #endif
            }

            static std::string colorWhite() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[97m";
                #endif
            }

            static std::string colorBlue() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[34m";
                #endif
            }

            static std::string colorBlack() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[30m";
                #endif
            }

            static std::string colorGreen() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[32m";
                #endif
            }

            static std::string colorMagenta() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[35m";
                #endif
            }

            static std::string colorCyan() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[36m";
                #endif
            }
        
            static std::string colorBackgroundDefault() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[49m";
                #endif
            }

            static std::string colorBackgroundRed() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[101m";
                #endif
            }

            static std::string colorBackgroundYellow() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[103m";
                #endif
            }

            static std::string colorBackgroundWhite() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[107m";
                #endif
            }

            static std::string colorBackgroundBlue() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[104m";
                #endif
            }

            static std::string colorBackgroundBlack() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[40m";
                #endif
            }

            static std::string colorBackgroundGreen() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[102m";
                #endif
            }

            static std::string colorBackgroundMagenta() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[105m";
                #endif
            }

            static std::string colorBackgroundCyan() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[106m";
                #endif
            }

            static std::string boldStyle() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[1m";
                #endif
            }
        
            #if KAPENGINE_THREAD_ACTIVE
                #if KAPENGINE_BETA_ACTIVE
                    static std::mutex logMutex;
                #endif
            #endif

        protected:
        private:

            static std::string __getCDate() {
                PROFILER_FUNC_START();
                // current date/time based on current system
                time_t now = std::time(0);
                
                // convert now to string form
                char* dt = std::ctime(&now);
                std::string _str(dt);
                _str.pop_back();
                PROFILER_FUNC_END();
                return _str;
            }
    };
}

#endif /* !DEBUG_HPP_ */
