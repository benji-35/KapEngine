/*
** EPITECH PROJECT, 2022
** engine
** File description:
** ThreadScene
*/

#ifndef THREADSCENE_HPP_
#define THREADSCENE_HPP_

#include <vector>
#include <memory>

#include "GameObject.hpp"

namespace KapEngine {

    class GameObject;
}

namespace KapEngine {
    class ThreadScene {
        public:
            ThreadScene() {}
            ~ThreadScene() {}

            void join();
            void run();

            void addGameObject(std::shared_ptr<GameObject> go);

            static void __threadRunning(ThreadScene *scene);

            std::vector<std::shared_ptr<GameObject>> getGameObjects() {
                return _gos;
            }

        private:
            std::vector<std::shared_ptr<GameObject>> _gos;
            std::shared_ptr<std::thread> _thread;
    };
}

#endif /* !THREADSCENE_HPP_ */
