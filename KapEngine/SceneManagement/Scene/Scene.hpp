/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "Engine.hpp"
#include "GameObject.hpp"

#include <functional>

namespace KapEngine {
    class KEngine;
    class GameObject;
    class Component;
    class Entity;

    namespace SceneManagement {
        class SceneManager;
    }
}

#include <string>
#include <memory>
#include <vector>

namespace KapEngine {

    namespace SceneManagement {

        class Scene {
            public:
                Scene(SceneManager &manager, std::string const& sceneName);
                ~Scene();

                void addGameObject(std::shared_ptr<GameObject> go);
                void destroyGameObject(std::shared_ptr<GameObject> const go);
                void destroyGameObject(GameObject const& go);
                void destroyGameObject(std::size_t id);

                bool setId(std::size_t id) {
                    if (_id != 0)
                        return false;
                    _id = id;
                    return true;
                }
                std::size_t getId() const {
                    return _id;
                }

                std::string getName() const {
                    return _name;
                }

                bool operator==(Scene const& scene) {
                    if (_id == scene.getId())
                        return true;
                    return false;
                }
                bool operator==(std::shared_ptr<Scene> scene) {
                    return *this == *scene;
                }

                bool operator!=(Scene const& scene) {
                    if (_id != scene.getId())
                        return true;
                    return false;
                }
                bool operator!=(std::shared_ptr<Scene> scene) {
                    return *this != *scene;
                }

                Component &getActiveCamera() const;

                /**
                 * @brief Get the Game Object object
                 * 
                 * @param id 
                 * @return std::shared_ptr<GameObject>& 
                 */
                std::shared_ptr<GameObject> &getGameObject(std::size_t id);
                /**
                 * @brief Get GameObject object
                 * 
                 * @param id 
                 * @return std::shared_ptr<GameObject>&
                 * @deprecated please use getGameObject
                 */
                std::shared_ptr<GameObject> &getObject(std::size_t id) {
                    return getGameObject(id);
                }
                std::shared_ptr<GameObject> getGameObjectConst(std::size_t id) const;
                /**
                 * @brief Get the Object Const object
                 * 
                 * @param id 
                 * @return std::shared_ptr<GameObject>
                 * @deprecated 
                 */
                std::shared_ptr<GameObject> getObjectConst(std::size_t id) const {
                    return getGameObjectConst(id);
                }
                std::vector<std::shared_ptr<GameObject>> getAllGameObjects();
                /**
                 * @brief Get the All Objects object
                 * 
                 * @return std::vector<std::shared_ptr<GameObject>> 
                 * @deprecated
                 */
                std::vector<std::shared_ptr<GameObject>> getAllObjects() {
                    return getAllGameObjects();
                }
                std::shared_ptr<GameObject> &getGameObject(Entity const& en);
                /**
                 * @brief Get the Object object
                 * 
                 * @param en 
                 * @return std::shared_ptr<GameObject>&
                 * @deprecated 
                 */
                std::shared_ptr<GameObject> &getObject(Entity const& en) {
                    return getGameObject(en);
                }
                
                std::vector<std::shared_ptr<GameObject>> getGameObjects(std::string const& name);

                std::vector<std::shared_ptr<GameObject>> getGameObjectByTag(std::string const& tag);

                KEngine &getEngine();

                /**
                 * @warning Do not call or modifie this function
                 */
                void __update();
                /**
                 * @warning Do not call or modifie this function
                 */
                void __changingScene();
                /**
                 * @warning Do not call or modifie this function
                 */
                void __engineStop(bool currentScene = false);
                /**
                 * @warning Do not call or modifie this function
                 */
                void __init();
                /**
                 * @warning Do not call or modifie this function
                 */
                void __finit();

                /**
                 * @brief Display all objects in scene
                 * 
                 * @param showComponents if you want to display components attached to your objects
                 */
                void dump(bool showComponents = false);

                std::shared_ptr<GameObject> createGameObject(std::string const& name);

                /**
                 * @brief get first GameObject with it's name
                 * 
                 * @param name 
                 * @return std::shared_ptr<GameObject> 
                 */
                std::shared_ptr<GameObject> findFirstGameObject(std::string const& name);

                /**
                 * @brief update scene by thread
                 * 
                 * @param scene 
                 * @param go
                 */
                static void __threadSceneUpdate(std::vector<std::shared_ptr<GameObject>> gos, bool physics);

                /**
                 * @brief add temporary action when scene updated
                 * 
                 * @param action
                 */
                void registerTmpActionAfterUpdate(std::function<void(Scene &scene)> action) {
                    _tmpActionsAfterUpdate.push_back(action);
                }

            protected:
            private:
                std::size_t _id = 0;
                std::string _name;
                std::size_t _idObjectMax = 0;
                SceneManager &manager;
                std::vector<std::shared_ptr<GameObject>> _gameObjects;
                std::vector<std::shared_ptr<GameObject>> _gameObjectsRun;
                std::vector<std::size_t> _gameObjectsToDestroy;

                void __checkDestroy();
                void __checkThread();
                std::size_t __nbGameObjectNoParent();
                std::vector<std::shared_ptr<GameObject>> __getGameObjectsNoParent();
                void __updateGameObjects(std::vector<std::shared_ptr<GameObject>> objs);
                std::vector<std::function<void(Scene &scene)>> _tmpActionsAfterUpdate;
        };

    }

}

#endif /* !SCENE_HPP_ */
