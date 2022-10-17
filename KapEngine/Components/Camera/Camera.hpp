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

    /**
     * \addtogroup Components
     * @{
     * @class Camera
     * @}
     */

    class Camera : public Component {
        public:
            Camera(std::shared_ptr<GameObject> go);
            ~Camera();

            /**
             * @brief Set the Background Color of windows game
             * 
             * @param bgColor 
             */
            void setBackgroundColor(Tools::Color const& bgColor) {
                _bgColor = bgColor;
            }

            /**
             * @brief Get the Background Color
             * 
             * @return KapEngine::Tools::Color 
             */
            Tools::Color getBackgroundColor() const {
                return _bgColor;
            }

        protected:
        private:
            Tools::Color _bgColor;
    
    };

}

#endif /* !CAMERA_HPP_ */
