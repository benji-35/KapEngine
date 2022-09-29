/*
** EPITECH PROJECT, 2022
** engine
** File description:
** MouseDetector
*/

#ifndef MOUSEDETECTOR_HPP_
#define MOUSEDETECTOR_HPP_

#include "Component.hpp"

namespace KapEngine {
    class Component;
}

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

        protected:
            void __callMouses(HoverType const& type);
        private:
            Tools::Rectangle _square;
            bool _inSquare = false;
            bool _setted = false;
    };

}

#endif /* !MOUSEDETECTOR_HPP_ */
