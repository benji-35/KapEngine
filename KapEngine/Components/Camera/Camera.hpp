/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_


#include "Component.hpp"
#include "Vectors.hpp"
#include "Colors.hpp"

namespace KapEngine {
    class Component;
}

namespace KapEngine {

    class Camera : public Component {
        public:
            Camera(std::shared_ptr<GameObject> go);
            ~Camera();

            void setBackgroundColor(Tools::Color const& bgColor) {
                _bgColor = bgColor;
            }

            Tools::Color getBackgroundColor() const {
                return _bgColor;
            }

        protected:
        private:
            Tools::Color _bgColor;
    
    };

}

#endif /* !CAMERA_HPP_ */
