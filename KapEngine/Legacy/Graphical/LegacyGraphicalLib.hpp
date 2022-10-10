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
#include "KapEngineDebug.hpp"

namespace KapEngine {

    class KEngine;

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

                void startDisplay() override {
                    DEBUG_LOG("Use " + getName());
                }

            private:
                std::map<std::string, std::function<void()>> _commands;

                void registerCommand(std::string const& cmd, std::function<void()>);
                void executeCommand(std::string const& cmd);
                bool commandExists(std::string const& cmd);

        };

    }
}

#endif /* !LEGACYGRAPHICAL_HPP_ */
