/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GraphicalLibManager
*/

#ifndef GRAPHICALLIBMANAGER_HPP_
#define GRAPHICALLIBMANAGER_HPP_

#include "Engine.hpp"
#include "GraphicalLib.hpp"
#include <thread>

namespace KapEngine {
    namespace Graphical {
        class GraphicalLib;
        class LegacyGraphicalLib;
    }
}

namespace KapEngine {

    /**
     * @namespace KapEngine::Graphical
     * This namespace regroup all graphical things
     * @brief All graphical things
     */
    namespace Graphical {

        class GraphicalLibManager {
            public:
                GraphicalLibManager(KEngine &engine);
                ~GraphicalLibManager();

                void addLib(std::shared_ptr<GraphicalLib> lib);

                void removeLib(std::size_t const& index);
                void removeLib(std::string const& name);

                bool isLibExists(std::size_t const& index);
                bool isLibExists(std::string const& name);

                std::size_t getLibIndexFromName(std::string const& name);
                std::string getLibNameFromIndex(std::size_t const& index);
                std::shared_ptr<GraphicalLib> getLib(std::size_t index);

                void __update();

                std::size_t getCurrLib() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return currLib;
                }

                std::shared_ptr<GraphicalLib> getCurrentLib() const;

                KEngine &getEngine() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _engine;
                }

                void changeLib(std::size_t const& libId);
                void changeLib(std::string const& libName);

            protected:
            private:
                std::size_t currLib = 0;
                std::size_t _maxLib = 0;

                std::vector<std::shared_ptr<GraphicalLib>> _libs;
                KEngine &_engine;
        };

    }
}

#endif /* !GRAPHICALLIBMANAGER_HPP_ */
