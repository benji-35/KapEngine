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

namespace KapEngine {
    namespace SceneManagement {
        class SceneManager;
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

        protected:
        private:

            bool _run = false;
            bool _debug = false;

            int _fpsLock = 60;

            //all game intels
            std::string _gameName;
            std::string _gameVersion;
            std::string _gameCompany;
    
            std::shared_ptr<SceneManagement::SceneManager> _sceneManager;
    };

}

#endif /* !ENGINE_HPP_ */
