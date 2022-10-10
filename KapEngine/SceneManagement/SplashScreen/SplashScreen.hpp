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
#include <memory>

#include "Vectors.hpp"
#include "Rectangle.hpp"
#include "Engine.hpp"

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
                SplashScreen(KEngine &engine);
                ~SplashScreen();

                void addSplashScreen(std::shared_ptr<SplashScreenNode> splash) {
                    _splahes.push_back(splash);
                }

                void setDisplayKapEngineLogo(bool b) {
                    _displayKapEngineLogo = b;
                }

                void __init();

            protected:
            private:
                KEngine &_engine;
                std::vector<std::shared_ptr<SplashScreenNode>> _splahes;
                bool _displayKapEngineLogo = true;
                std::size_t _sceneId = 0;
        };

    }

}

#endif /* !SPLASHSCREEN_HPP_ */
