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
                return "\\e[0m";
            }

            static std::string colorRed() {
                return "\\e[31m";
            }

            static std::string colorYellow() {
                return "\\e[33m";
            }

            static std::string colorWhite() {
                return "\\e[97m";
            }

            static std::string colorBlue() {
                return "\\e[34m";
            }

            static std::string colorBlack() {
                return "\\e[30m";
            }

            static std::string colorGreen() {
                return "\\e[32m";
            }

            static std::string colorMagenta() {
                return "\\e[35m";
            }

            static std::string colorCyan() {
                return "\\e[36m";
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
