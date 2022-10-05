/*
** EPITECH PROJECT, 2022
** engine
** File description:
** Collider
*/

#ifndef COLLIDER_HPP_
#define COLLIDER_HPP_

#include "KapEngine.hpp"
#include "KapEngineDebug.hpp"

namespace KapEngine {

    class Collider : public Component {
        public:
            Collider(std::shared_ptr<GameObject> go);
            ~Collider();

        protected:
        private:
    };

}

#endif /* !COLLIDER_HPP_ */
