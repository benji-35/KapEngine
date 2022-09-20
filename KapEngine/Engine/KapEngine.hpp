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
#include "EClock.hpp"

#include <mutex>

namespace KapEngine {
    namespace SceneManagement {
        class SceneManager;
    }

    namespace Graphical {
        class GraphicalLibManager;
        class GraphicalLib;
    }

    namespace Time {
        class ETime;
        class EClock;
    }

    namespace Events {
        class EventManager;
    }
}

/**
 * @brief main namespace
 * @namespace KapEngine
 */
namespace KapEngine {

    /**
     * @brief Class of engine
     * @class KapEngine
     */
    class KapEngine {
        public:
            /**
             * @brief Construct a new KapEngine
             * @param debug enable/disable debug mode
             * @param gameName name of your game
             * @param version version of your game
             * @param company company name that developpe the game
             */
            KapEngine(bool debug = false, std::string const& gameName = "Game", std::string const& version = "1.0.0", std::string const& company = "Default Company");
            ~KapEngine();

            /**
             * @brief Fix max fps of game
             * @param fps fps amount
             */
            void setMaxFps(int fps) {
                _fpsLock = fps;
            }

            /**
             * @brief run your game
             */
            void run();
            /**
             * @brief stop your game (can be call by component)
             */
            void stop();
            /**
             * @brief Check if game is running
             * @retval true if game is running
             * @retval false if game is not running
             */
            bool isRunning() const {
                return _run;
            }
            /**
             * @brief check debug mode
             * 
             * @retval true if debug mode is enable
             * @retval false if debug mode is disable
             */
            bool debugMod() const {
                return _debug;
            }
            /**
             * @brief Set the debug mode
             * @param b 
             */
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

            std::shared_ptr<SceneManagement::SceneManager> getSceneManager() const {
                return _sceneManager;
            }

            static void __threadRun(KapEngine *engine, int threadId);

            /**
             * @brief Mutex for threading
             */
            static std::recursive_mutex debugMutex;

            Time::ETime getElapsedTime() {
                float f = _elapsed.asMilliSecond() * deltaTime;
                Time::ETime res;

                res.setMilliseconds(f);
                return res;
            }

            Events::EventManager &getEventManager();

        protected:
        private:
            bool _run = false;
            bool _debug = false;

            int _fpsLock = 60;

            float deltaTime = 1.0f;

            Time::EClock _internalClock;
            Time::ETime _elapsed;

            //all game intels
            std::string _gameName;
            std::string _gameVersion;
            std::string _gameCompany;
    
            //scene manager
            std::shared_ptr<SceneManagement::SceneManager> _sceneManager;

            //graphical libs
            std::shared_ptr<Graphical::GraphicalLibManager> _libManager;

            std::shared_ptr<Events::EventManager> _eventManager;

            //functions
            void __init();
    };

}

#endif /* !ENGINE_HPP_ */
