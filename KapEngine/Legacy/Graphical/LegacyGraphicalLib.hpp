/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** LegacyGraphical
*/

#ifndef LEGACYGRAPHICAL_HPP_
#define LEGACYGRAPHICAL_HPP_

#include <functional>
#include <map>

#include "GraphicalLib.hpp"

namespace KapEngine {

    class KapEngine;

    namespace Graphical {
        class GraphicalLib;
        class GraphicalLibManager;
    }
}

namespace KapEngine {
    namespace Graphical {

        class LegacyGraphicalLib : public GraphicalLib {
            
            public:
                LegacyGraphicalLib(GraphicalLibManager &manager);
                ~LegacyGraphicalLib();

                void display() override;

            private:
                std::map<std::string, std::function<void()>> _commands;

                void registerCommand(std::string const& cmd, std::function<void()>);
                void executeCommand(std::string const& cmd);
                bool commandExists(std::string const& cmd);

        };

    }
}

#endif /* !LEGACYGRAPHICAL_HPP_ */
