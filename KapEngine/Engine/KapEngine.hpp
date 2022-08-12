/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "Errors.hpp"
#include "SceneManager.hpp"
#include "GraphicalLibManager.hpp"

namespace KapEngine {
    namespace SceneManagement {
        class SceneManager;
    }

    namespace Graphical {
        class GraphicalLibManager;
        class GraphicalLib;
    }
}

namespace KapEngine {

    class KapEngine {
        public:
            KapEngine(bool debug = false, std::string const& gameName = "Game", std::string const& version = "1.0.0", std::string const& company = "Default Company");
            ~KapEngine();

            void setMaxFps(int fps) {
                _fpsLock = fps;
            }

            void run();
            void stop();
            bool isRunning() const {
                return _run;
            }

            bool debugMod() const {
                return _debug;
            }
            void setDebugMod(bool b) {
                _debug = b;
            }

            //action with graphical lib
            std::shared_ptr<Graphical::GraphicalLib> getCurrentGraphicalLib();
            bool isGraphicalLibExists(std::size_t const& index) const;
            bool isGraphicalLibExists(std::string const& name) const;
            std::size_t getCurrentGraphicalLibIndex() const;

            //getter intels
            std::string getGameName() const {
                return _gameName;
            }

            std::string getGameVersion() const {
                return _gameVersion;
            }

            std::string getGameCompany() const {
                return _gameCompany;
            }

        protected:
        private:

            bool _run = false;
            bool _debug = false;

            int _fpsLock = 60;

            //all game intels
            std::string _gameName;
            std::string _gameVersion;
            std::string _gameCompany;
    
            //scene manager
            std::shared_ptr<SceneManagement::SceneManager> _sceneManager;

            //graphical libs
            std::shared_ptr<Graphical::GraphicalLibManager> _libManager;

            //functions
            void __init();
    };

}

#endif /* !ENGINE_HPP_ */
