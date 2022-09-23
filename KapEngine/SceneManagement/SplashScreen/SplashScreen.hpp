/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** SplashScreen
*/

#ifndef SPLASHSCREEN_HPP_
#define SPLASHSCREEN_HPP_

#include <string>
#include <vector>
#include "Vectors.hpp"
#include "Rectangle.hpp"

namespace KapEngine {

    namespace SceneManagement {

        class SplashScreen {
            public:
                struct SplashScreenNode {
                    std::string pathImage;
                    int timing;
                    Tools::Vector2 pos;
                    Tools::Vector2 size;
                    Tools::Rectangle rect;

                    SplashScreenNode(std::string path, int dur = 2) {
                        timing = dur;
                        size.setX(1.f);
                        size.setX(1.f);
                        pathImage = path;
                    }
                };
            public:
                SplashScreen();
                ~SplashScreen();

            protected:
            private:
                std::vector<SplashScreen::SplashScreenNode> _splahes;
        };

    }

}

#endif /* !SPLASHSCREEN_HPP_ */
