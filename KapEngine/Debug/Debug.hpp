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
#include <mutex>

namespace KapEngine {
    class Debug {
        public:

            /**
            * @fn log(std::string _msg)
            * afficher dans la console (horrodaté) un message sous le format log
            * @brief afficher un log
            */
            static void log(std::string _msg) {
                std::lock_guard<std::recursive_mutex> lk(KapEngine::debugMutex);
                std::cout << "[" << __getCDate() << "]\e[1;37m log: \e[0m" << _msg << "\e[0m" << std::endl;
                KapEngine::debugMutex.unlock();
            }

            /**
            * @fn warning(std::string _msg)
            * afficher dans la console (horrodaté) un message sous le format warning
            * @brief afficher un warning
            */
            static void warning(std::string _msg) {
                std::lock_guard<std::recursive_mutex> lk(KapEngine::debugMutex);
                std::cout << "[" << __getCDate() << "]\e[1;33m warning: \e[0m" << _msg << "\e[0m" << std::endl;
                KapEngine::debugMutex.unlock();
            }

            /**
            * @fn error(std::string _msg)
            * afficher dans la console (horrodaté) un message sous le format error
            * @brief afficher une erreur
            */
            static void error(std::string _msg) {
                std::lock_guard<std::recursive_mutex> lk(KapEngine::debugMutex);
                std::cout << "[" << __getCDate() << "]\e[1;31m Error: \e[0m" << _msg << "\e[0m" << std::endl;
                KapEngine::debugMutex.unlock();
            }

        protected:
        private:
            static std::string __getCDate() {
                // current date/time based on current system
                time_t now = std::time(0);
                
                // convert now to string form
                char* dt = std::ctime(&now);
                std::string _str(dt);
                _str.pop_back();
                return _str;
            }
    };
}

#endif /* !DEBUG_HPP_ */
