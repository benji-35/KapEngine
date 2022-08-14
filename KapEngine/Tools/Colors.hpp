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

    namespace Tools {

        class Color {
            public:
                Color() {}
                Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) {
                    _r = r;
                    _g = g;
                    _b = b;
                    _a = a;
                }
                ~Color() {}

                unsigned char getR() const {
                    return _r;
                }
                unsigned char getG() const {
                    return _g;
                }
                unsigned char getB() const {
                    return _b;
                }
                unsigned char getA() const {
                    return _a;
                }
            
                void setR(unsigned char r) {
                    _r = r;
                }
                void setG(unsigned char g) {
                    _g = g;
                }
                void setB(unsigned char b) {
                    _b = b;
                }
                void setA(unsigned char a) {
                    _a = a;
                }

                bool operator==(Color const& col) const {
                    if (_r != col.getR())
                        return false;
                    if (_g != col.getG())
                        return false;
                    if (_b != col.getB())
                        return false;
                    if (_a != col.getA())
                        return false;
                    return true;
                }

                bool operator!=(Color const& col) const {
                    return !(*this==col);
                }

                Color &operator=(Color const& col) {
                    _r = col.getR();
                    _g = col.getG();
                    _b = col.getB();
                    _a = col.getA();
                    return *this;
                }

                static Color white() {
                    return Color();
                }

                static Color black() {
                    return Color(0, 0, 0, 255);
                }

                static Color transparent() {
                    return Color(255, 255, 255, 0);
                }

                static Color yellow() {
                    return Color(255, 255, 0, 255);
                }

                static Color orange() {
                    return Color(255, 165, 0, 255);
                }

                static Color blue() {
                    return Color(0, 0, 255, 255);
                }

                static Color pink() {
                    return Color(238, 130, 238, 255);
                }

                static Color grey() {
                    return Color(120, 120, 120, 255);
                }

                static Color green() {
                    return Color(0, 255, 0, 255);
                }

                static Color red() {
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
