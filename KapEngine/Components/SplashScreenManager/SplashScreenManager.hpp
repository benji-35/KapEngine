/*
** EPITECH PROJECT, 2022
** gameEngine
** File description:
** SplashScreenManager
*/

#ifndef SPLASHSCREENMANAGER_HPP_
#define SPLASHSCREENMANAGER_HPP_

#include "Component.hpp"
#include "ETime.hpp"
#include <vector>
#include <memory>

namespace KapEngine {
    class Component;
    class GameObject;
}

namespace KapEngine {
    namespace SceneManagement {

        class SplashScreenManager : public Component {
            public:
                SplashScreenManager(std::shared_ptr<GameObject> go, bool b = false);
                ~SplashScreenManager();

                void setTime(Time::ETime time) {
                    _time = time;
                }

                void setNextSplash(std::shared_ptr<SplashScreenManager> next) {
                    nextSplash = next;
                }

                void setNextScene(std::string name) {
                    sceneName = name;
                }

                void update();
                void fixedUpdate();

                void setStart(bool b);

            protected:
            private:
                std::shared_ptr<SplashScreenManager> nextSplash;
                Time::ETime _time;
                Time::ETime currTime;
                std::string sceneName;
                bool isFirst = false;
                bool _start = false;
                float lastAlpha;
        };

    }
}

#endif /* !SPLASHSCREENMANAGER_HPP_ */
