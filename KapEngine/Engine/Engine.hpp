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

#include <mutex>

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
            /**
             * @brief Construct a new KapEngine Engine
             * @param debug enable/disable debug mode
             * @param gameName name of your game
             * @param version version of your game
             * @param company company name that developpe the game
             */
            KEngine(bool debug = false, std::string const& gameName = "Game", std::string const& version = "1.0.0", std::string const& company = "Default Company");
            ~KEngine();

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
            bool debugMode() const {
                return _debug;
            }
            /**
             * @brief Set the debug mode
             * @param b
             */
            void setDebugMod(bool b) {
                _debug = b;
            }

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
                return _gameName;
            }

            /**
             * @brief Get the Game Version
             * @return std::string
             */
            std::string getGameVersion() const {
                return _gameVersion;
            }

            /**
             * @brief Get the Game Company name
             * @return std::string
             */
            std::string getGameCompany() const {
                return _gameCompany;
            }

            /**
             * @brief Get the Scene Manager of game
             *
             * @return std::shared_ptr<KapEngine::SceneManagement::SceneManager>
             */
            std::shared_ptr<SceneManagement::SceneManager> getSceneManager() const {
                return _sceneManager;
            }

            /**
             * @brief Get the Prefab Manager of game
             *
             * @return std::shared_ptr<KapEngine::Prefabs::PrefabManager>
             */
            std::shared_ptr<Prefabs::PrefabManager> getPrefabManager() const {
                return _prefabManager;
            }

            /**
             * @brief Get the Elapsed Time since last internal clock restart
             * @return KapEngine::Time::ETime
             */
            Time::ETime getElapsedTime() {
                float f = _elapsed.asMilliSecond() * deltaTime;
                Time::ETime res;

                res.setMilliseconds(f);
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
                deltaTime = dTime;
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
                return screenSize;
            }

            /**
             * @brief Get the Max Fps of game
             * 
             * @return float 
             */
            float getMaxFps() const {
                return _fpsLock;
            }

            /**
             * @brief return if onFixedUpdate can be call
             * 
             * @return true 
             * @return false 
             */
            bool __canRunFixed() const {
                return _runFixed;
            }

            /**
             * @brief Get the Splash Screen manager
             * 
             * @return std::shared_ptr<KapEngine::SceneManagement::SplashScreen> 
             */
            std::shared_ptr<SceneManagement::SplashScreen> getSplashScreen() const {
                return _splashsScreen;
            }

            /**
             * @brief Set the Fixed Time of engine
             * fixed time is used to call onFixedUpdate() function of component -> this your internal clock
             * 
             * @param time 
             */
            void setFixedTime(Time::ETime time) {
                _fixedTime = time;
            }

            /**
             * @brief Set the Icon path of your Game
             * 
             * @param iconPath 
             */
            void setIconGame(std::string const& iconPath) {
                _icon = iconPath;
            }

            /**
             * @brief Get the Icon Path of your game
             * 
             * @return std::string 
             */
            std::string getIconPath() const {
                return _icon;
            }

            /**
             * @brief Set if engine have to use threads
             * 
             * @param b 
             */
            void setEngineThread(bool b) {
                _threaded = b;
            }

            /**
             * @brief return if engine is threaded
             * 
             * @return true 
             * @return false 
             */
            bool isEngineThreaded() const {
                return _threaded;
            }

            /**
             * @brief Set the Title of game windows
             * 
             * @param title 
             */
            void setTitle(std::string const& title) {
                _gameName = title;
            }

            /**
             * @brief set if you want to show fps in game
             * @param b 
             */
            void displayFPS(bool b) {
                _displayFps = b;
            }

            /**
             * @brief return if fps is displayed
             * 
             * @return true 
             * @return false 
             */
            bool isDisplayFPS() const {
                return _displayFps;
            }

            /**
             * @warning this function is not for user. Do not use it
             */
            static void __threadRun(KEngine *engine, int threadId);

            /**
             * @warning this function is not for user. Do not use it
             */
            bool __canRunUpdate();

            void __setCompUpdated(bool b) {
                _updateComp = b;
            }

            bool __isCompUpdated() const {
                return _updateComp;
            }

            void __setPhysicsUpdated(bool b) {
                _updatePhys = b;
            }

            bool __isPhysicsUpdated() const {
                return _updatePhys;
            }

        protected:
        private:
            bool _run = false;
            bool _debug = false;
            bool _runFixed = false;
            bool _threaded = false;
            bool _displayFps = false;

            bool _updateComp = false;
            bool _updatePhys = false;

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

    };

}

#endif /* !ENGINE_HPP_ */
