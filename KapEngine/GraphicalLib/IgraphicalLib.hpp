/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** IgraphicalLib
*/

#ifndef IGRAPHICALLIB_HPP_
#define IGRAPHICALLIB_HPP_

#include "Vectors.hpp"
#include "Colors.hpp"

namespace KapEngine {

    namespace Graphical {

        class IgraphicalLib {
            public:
                virtual ~IgraphicalLib() {}

                // internall functions
                virtual void setFps(int fps) = 0;

                //graphical functions

                virtual void updateCamera(Tools::Vector3 const& pos, Tools::Vector3 const& rot, Tools::Color const& bgColor) = 0;

                //

            protected:
            private:
        };

    }

}

#endif /* !IGRAPHICALLIB_HPP_ */
