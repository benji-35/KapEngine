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

#include "Utils/Platform.hpp"

namespace KapEngine {
    class Debug {
        public:

            /**
            * @fn log(std::string _msg)
            * afficher dans la console (horrodaté) un message sous le format log
            * @brief afficher un log
            */
            static void log(std::string _msg, std::string prefix = "") {
                std::cout << "[" << __getCDate() << "] " + prefix + "\\e[1;37m log: \\e[0m" << _msg << "\\e[0m" << std::endl;
            }

            static void log(char const* _msg, std::string prefix = "") {
                log(std::string(_msg), prefix);
            }

            static void log(const char *_msg, const char *fileName, int const line) {
                log(std::string(_msg), fileName, line);
            }

            static void log(std::string const& _msg, const char *fileName, int const line) {
                log(std::string(_msg), "[" + colorGreen() + std::string(fileName) + colorNone() + " " + colorBlue() + "l. " + std::to_string(line) + colorNone() + "]");
            }

            /**
            * @fn warning(std::string _msg)
            * afficher dans la console (horrodaté) un message sous le format warning
            * @brief afficher un warning
            */
            static void warning(std::string _msg, std::string prefix = "") {
                std::cout << "[" << __getCDate() << "] " + prefix + "\\e[1;33m warning: \\e[0m" << _msg << "\\e[0m" << std::endl;
            }

            static void warning(char const* _msg, std::string prefix = "") {
                warning(std::string(_msg), prefix);
            }

            static void warning(const char *_msg, const char *fileName, int const line) {
                warning(std::string(_msg), fileName, line);
            }

            static void warning(std::string const& _msg, const char *fileName, int const line) {
                warning(std::string(_msg), "[" + colorYellow() + std::string(fileName) + colorNone() + " " + colorBlue() + "l. " + std::to_string(line) + colorNone() + "]");
            }
            /**
            * @fn error(std::string _msg)
            * afficher dans la console (horrodaté) un message sous le format error
            * @brief afficher une erreur
            */
            static void error(std::string _msg, std::string prefix = "") {
                std::cout << "[" << __getCDate() << "] " + prefix + "\\e[1;31m error: \\e[0m" << _msg << "\\e[0m" << std::endl;
            }

            static void error(char const* _msg, std::string prefix = "") {
                error(std::string(_msg), prefix);
            }

            static void error(const char *_msg, const char *fileName, int const line) {
                error(std::string(_msg), fileName, line);
            }

            static void error(std::string const& _msg, const char *fileName, int const line) {
                error(std::string(_msg), "[" + colorRed() + std::string(fileName) + colorNone() + " " + colorBlue() + "l. " + std::to_string(line) + colorNone() + "]");
            }

            static std::string colorNone() {
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[0m";
                #endif
            }

            static std::string colorRed() {
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[31m";
                #endif
            }

            static std::string colorYellow() {
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[33m";
                #endif
            }

            static std::string colorWhite() {
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[97m";
                #endif
            }

            static std::string colorBlue() {
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[34m";
                #endif
            }

            static std::string colorBlack() {
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[30m";
                #endif
            }

            static std::string colorGreen() {
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[32m";
                #endif
            }

            static std::string colorMagenta() {
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[35m";
                #endif
            }

            static std::string colorCyan() {
                #ifdef __WINDOWS__
                    return "";
                #else
                    return "\e[36m";
                #endif
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
