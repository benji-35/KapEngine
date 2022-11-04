/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Colors
*/

#ifndef COLORS_HPP_
#define COLORS_HPP_

#include <iostream>

namespace KapEngine {

    /**
     * @namespace KapEngine::Tools
     * This namespace regroup all Tools things
     * @brief All Tools things
     */
    namespace Tools {

        class Color {
            public:
                Color() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) {
                    PROFILER_FUNC_START();
                    _r = r;
                    _g = g;
                    _b = b;
                    _a = a;
                    PROFILER_FUNC_END();
                }
                ~Color() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }

                unsigned char getR() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _r;
                }
                unsigned char getG() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _g;
                }
                unsigned char getB() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _b;
                }
                unsigned char getA() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _a;
                }
            
                void setR(unsigned char r) {
                    PROFILER_FUNC_START();
                    _r = r;
                    PROFILER_FUNC_END();
                }

                void setG(unsigned char g) {
                    PROFILER_FUNC_START();
                    _g = g;
                    PROFILER_FUNC_END();
                }

                void setB(unsigned char b) {
                    PROFILER_FUNC_START();
                    _b = b;
                    PROFILER_FUNC_END();
                }

                void setA(unsigned char a) {
                    PROFILER_FUNC_START();
                    _a = a;
                    PROFILER_FUNC_END();
                }

                bool operator==(Color const& col) const {
                    PROFILER_FUNC_START();
                    if (_r != col.getR()) {
                        PROFILER_FUNC_END();
                        return false;
                    }
                    if (_g != col.getG()) {
                        PROFILER_FUNC_END();
                        return false;
                    }
                    if (_b != col.getB()) {
                        PROFILER_FUNC_END();
                        return false;
                    }
                    if (_a != col.getA()) {
                        PROFILER_FUNC_END();
                        return false;
                    }
                    PROFILER_FUNC_END();
                    return true;
                }

                bool operator!=(Color const& col) const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return !(*this==col);
                }

                Color &operator=(Color const& col) {
                    PROFILER_FUNC_START();
                    _r = col.getR();
                    _g = col.getG();
                    _b = col.getB();
                    _a = col.getA();
                    PROFILER_FUNC_END();
                    return *this;
                }

                static Color white() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Color();
                }

                static Color black() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Color(0, 0, 0, 255);
                }

                static Color transparent() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Color(255, 255, 255, 0);
                }

                static Color yellow() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Color(255, 255, 0, 255);
                }

                static Color orange() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Color(255, 165, 0, 255);
                }

                static Color blue() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Color(0, 0, 255, 255);
                }

                static Color pink() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Color(238, 130, 238, 255);
                }

                static Color grey() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Color(120, 120, 120, 255);
                }

                static Color green() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Color(0, 255, 0, 255);
                }

                static Color red() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return Color(255, 0, 0, 255);
                }

            protected:
            private:
                unsigned char _r = 255;
                unsigned char _g = 255;
                unsigned char _b = 255;
                unsigned char _a = 255;
        };

    }

}

#endif /* !COLORS_HPP_ */
