/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Engine
*/

#ifndef KENGINE_HPP_
#define KENGINE_HPP_

#include "Errors.hpp"
#include "SceneManager.hpp"
#include "PrefabManager.hpp"
#include "GraphicalLibManager.hpp"
#include "SplashScreen.hpp"
#include "EClock.hpp"

#include "KapEngineSettings.hpp"

#if KAPENGINE_THREAD_ACTIVE
    #include <thread>
    #include <mutex>
#endif

namespace KapEngine {
    namespace SceneManagement {
        class SceneManager;
        class SplashScreen;
    }

    namespace Prefabs {
        class PrefabManager;
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
     * @class KEngine
     */
    class KEngine {
        public:
            #if !KAPENGINE_BETA_ACTIVE
                /**
                 * @brief Construct a new KapEngine Engine
                 * @param debug enable/disable debug mode
                 * @param gameName name of your game
                 * @param version version of your game
                 * @param company company name that developpe the game
                 */
                KEngine(bool debug = false, std::string const& gameName = "Game", std::string const& version = "1.0.0", std::string const& company = "Default Company");
            #else
                /**
                 * @brief Construct a new KapEngine Engine
                 * @param gameName name of your game
                 * @param version version of your game
                 * @param company company name that developpe the game
                 */
                KEngine(std::string const& gameName = "Game", std::string const& version = "1.0.0", std::string const& company = "Default Company");
            #endif
            ~KEngine();

            /**
             * @brief Fix max fps of game
             * @param fps fps amount
             */
            void setMaxFps(int fps) {
                PROFILER_FUNC_START();
                _fpsLock = fps;
                PROFILER_FUNC_END();
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
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _run;
            }
            #if !KAPENGINE_BETA_ACTIVE
                /**
                 * @brief check debug mode
                 *
                 * @retval true if debug mode is enable
                 * @retval false if debug mode is disable
                 */
                bool debugMode() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _debug;
                }
                /**
                 * @brief Set the debug mode
                 * @param b
                 */
                void setDebugMod(bool b) {
                    PROFILER_FUNC_START();
                    _debug = b;
                    PROFILER_FUNC_END();
                }
            #endif

            /**
             * @brief Get the Current Graphical Lib
             *
             * @return std::shared_ptr<KapEngine::Graphical::GraphicalLib>
             */
            std::shared_ptr<Graphical::GraphicalLib> getCurrentGraphicalLib();

            /**
             * @brief Check if lib exists from it's id in engine
             *
             * @param index
             * @return true if lib exists
             * @return false if lib does not exist
             */
            bool isGraphicalLibExists(std::size_t const& index) const;

            /**
             * @brief Check graphical lib exists from it's name in engine
             *
             * @param name
             * @return true if lib exists
             * @return false if lib does not exist
             */
            bool isGraphicalLibExists(std::string const& name) const;

            /**
             * @brief Get the Current Graphical Lib Index
             *
             * @return std::size_t
             */
            std::size_t getCurrentGraphicalLibIndex() const;

            /**
             * @brief Get the Game Name
             * @return std::string
             */
            std::string getGameName() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _gameName;
            }

            /**
             * @brief Get the Game Version
             * @return std::string
             */
            std::string getGameVersion() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _gameVersion;
            }

            /**
             * @brief Get the Game Company name
             * @return std::string
             */
            std::string getGameCompany() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _gameCompany;
            }

            /**
             * @brief Get the Scene Manager of game
             *
             * @return std::shared_ptr<KapEngine::SceneManagement::SceneManager>
             */
            std::shared_ptr<SceneManagement::SceneManager> getSceneManager() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _sceneManager;
            }

            /**
             * @brief Get the Prefab Manager of game
             *
             * @return std::shared_ptr<KapEngine::Prefabs::PrefabManager>
             */
            std::shared_ptr<Prefabs::PrefabManager> getPrefabManager() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _prefabManager;
            }

            /**
             * @brief Get the Elapsed Time since last internal clock restart
             * @return KapEngine::Time::ETime
             */
            Time::ETime getElapsedTime() {
                PROFILER_FUNC_START();
                float f = _elapsed.asMilliSecond() * deltaTime;
                Time::ETime res;

                res.setMilliseconds(f);
                PROFILER_FUNC_END();
                return res;
            }

            /**
             * @brief Get the Event Manager of game
             * @return KapEngine::Events::EventManager&
             */
            Events::EventManager &getEventManager();

            /**
             * @brief Set the Delta Time of game
             * more delta time increase more the game gonna be fast. more delta decrease, more the game gonna be slow
             * @param dTime
             */
            void setDeltaTime(float dTime) {
                PROFILER_FUNC_START();
                deltaTime = dTime;
                PROFILER_FUNC_END();
            }

            /**
             * @brief Get the Graphical Lib Manager
             * 
             * @return std::shared_ptr<KapEngine::Graphical::GraphicalLibManager> 
             */
            std::shared_ptr<Graphical::GraphicalLibManager> getGraphicalLibManager() const {
                return _libManager;
            }

            /**
             * @brief Set the Screen Size at the game beginning
             * 
             * @param width 
             * @param heigth 
             */
            void setScreenSize(float width, float heigth);

            /**
             * @brief Set the Screen Size at the game beginning
             * 
             * @param size (KapEngine::Tools::Vector2)
             */
            void setScreenSize(Tools::Vector2 size);

            /**
             * @brief Get the Screen Size at the game beginning
             * 
             * @return Tools::Vector2 
             */
            Tools::Vector2 getScreenSize() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return screenSize;
            }

            /**
             * @brief Get the Max Fps of game
             * 
             * @return float 
             */
            float getMaxFps() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _fpsLock;
            }

            /**
             * @brief return if onFixedUpdate can be call
             * 
             * @return true 
             * @return false 
             */
            bool __canRunFixed() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _runFixed;
            }

            /**
             * @brief Get the Splash Screen manager
             * 
             * @return std::shared_ptr<KapEngine::SceneManagement::SplashScreen> 
             */
            std::shared_ptr<SceneManagement::SplashScreen> getSplashScreen() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _splashsScreen;
            }

            /**
             * @brief Set the Fixed Time of engine
             * fixed time is used to call onFixedUpdate() function of component -> this your internal clock
             * 
             * @param time 
             */
            void setFixedTime(Time::ETime time) {
                PROFILER_FUNC_START();
                _fixedTime = time;
                PROFILER_FUNC_END();
            }

            Time::ETime getFixedTime() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _fixedTime;
            }

            /**
             * @brief Set the Icon path of your Game
             * 
             * @param iconPath 
             */
            void setIconGame(std::string const &iconPath) {
                PROFILER_FUNC_START();
                _icon = iconPath;
                PROFILER_FUNC_END();
            }

            /**
             * @brief Get the Icon Path of your game
             * 
             * @return std::string 
             */
            std::string getIconPath() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _icon;
            }

            #if !KAPENGINE_BETA_ACTIVE

                /**
                 * @brief Set if engine have to use threads
                 * 
                 * @param b 
                 */
                void setEngineThread(bool b) {
                    PROFILER_FUNC_START();
                    _threaded = b;
                    PROFILER_FUNC_END();
                }

                /**
                 * @brief return if engine is threaded
                 * 
                 * @return true 
                 * @return false 
                 */
                bool isEngineThreaded() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _threaded;
                }

            #else
                #if KAPENGINE_THREAD_ACTIVE
                    std::mutex &getMutex() {
                        return _mutex;
                    }
                #endif
            #endif

            /**
             * @brief Set the Title of game windows
             * 
             * @param title 
             */
            void setTitle(std::string const& title) {
                PROFILER_FUNC_START();
                #if KAPENGINE_BETA_ACTIVE
                    #if KAPENGINE_THREAD_ACTIVE
                        _mutex.lock();
                    #endif
                #endif
                _gameName = title;
                #if KAPENGINE_BETA_ACTIVE
                    #if KAPENGINE_THREAD_ACTIVE
                        _mutex.unlock();
                    #endif
                #endif
                PROFILER_FUNC_END();
            }

            void displayFPS(bool b) {
                PROFILER_FUNC_START();
                #if KAPENGINE_BETA_ACTIVE
                    #if KAPENGINE_THREAD_ACTIVE
                        _mutex.lock();
                    #endif
                #endif
                _displayFps = b;
                #if KAPENGINE_BETA_ACTIVE
                    #if KAPENGINE_THREAD_ACTIVE
                        _mutex.unlock();
                    #endif
                #endif
                PROFILER_FUNC_END();
            }

            bool isDisplayFPS() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _displayFps;
            }

        protected:
        private:
            bool _run = false;
            #if !KAPENGINE_BETA_ACTIVE
                bool _debug = false;
                bool _threaded = false;
            #else
                std::mutex engineMutex;
            #endif
            bool _runFixed = false;
            bool _displayFps = false;

            int _fpsLock = 60;

            float deltaTime = 1.0f;

            Tools::Vector2 screenSize;

            Time::EClock _internalClock;
            Time::ETime _elapsed;
            Time::ETime _fixedTime;

            //all game intels
            std::string _gameName;
            std::string _gameVersion;
            std::string _gameCompany;
            std::string _icon = "Library/KapEngine/Documentation/images/KapEngineLogo100x100.png";

            //scene manager
            std::shared_ptr<SceneManagement::SceneManager> _sceneManager;

            //prefab manager
            std::shared_ptr<Prefabs::PrefabManager> _prefabManager;

            //graphical libs
            std::shared_ptr<Graphical::GraphicalLibManager> _libManager;

            //input events
            std::shared_ptr<Events::EventManager> _eventManager;

            //splash screens
            std::shared_ptr<SceneManagement::SplashScreen> _splashsScreen;

            //functions
            void __init();

            bool __canRunUpdate();
    };

}

#endif /* !ENGINE_HPP_ */
