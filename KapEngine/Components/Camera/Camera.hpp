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
                PROFILER_FUNC_START();
                _bgColor = bgColor;
                PROFILER_FUNC_END();
            }

            /**
             * @brief Get the Background Color
             * 
             * @return KapEngine::Tools::Color 
             */
            Tools::Color getBackgroundColor() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _bgColor;
            }

        protected:
        private:
            Tools::Color _bgColor;
    
    };

}

#endif /* !CAMERA_HPP_ */
