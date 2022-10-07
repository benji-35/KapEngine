/*
** EPITECH PROJECT, 2022
** engine
** File description:
** MouseDetector
*/

#ifndef MOUSEDETECTOR_HPP_
#define MOUSEDETECTOR_HPP_

#include "KapEngine.hpp"

namespace KapEngine {

    class MouseDetector : public Component {
        public:
            enum HoverType {
                NONE,
                JUSTE_HOVER,
                STAY_HOVER,
                LEAVE_HOVER
            };

            MouseDetector(std::shared_ptr<GameObject> go);
            ~MouseDetector();

            void onUpdate() override;

            void setCheckZone(Tools::Rectangle zone) {
                _square = zone;
                _setted = true;
            }

            /**
             * @brief set if check mouse is in canvas or not
             * if mouse is in canvas, it gonna try to get canvas parent and make calculations in reference of canvas render type
             * @param b 
             */
            void detectMouseInCanvas(bool b) {
                _inCanvas = b;
            }

        private:
            void __callMouses(HoverType const& type);
            bool __checkNoCanvas(Tools::Vector2 const& pos);
            bool __checkCanvas(Tools::Vector2 const& pos);

            Tools::Vector2 crossProductScreen(Tools::Vector2 value);
        private:
            bool _inCanvas;
            Tools::Rectangle _square;
            bool _inSquare = false;
            bool _setted = false;
    };

}

#endif /* !MOUSEDETECTOR_HPP_ */
