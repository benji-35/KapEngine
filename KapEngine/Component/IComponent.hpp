/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <memory>

namespace KapEngine {
    class GameObject;
}

namespace KapEngine {

    class IComponent {
        public:
            ~IComponent() {}

            //function to update object
            /**
             * @fn virtual void onInit()
             * will be called during the component creation process. Be advised that some engine features cannot be used in this function.
             * @brief call on component init
             * @deprecated
             */
            virtual void onInit() = 0;
            /**
             * @fn virtual void onAwake()
             * will be called at runtime when the scene is first loaded or when another scene has been loaded before.
             * @brief call  component awake
             */
            virtual void onAwake() = 0;
            /**
             * @fn virtual void onStart()
             * will be called when the scene is loaded or when its KapEngine::GameObject is active after it is disabled
             * @brief call component start
             */
            virtual void onStart() = 0;
            /**
             * @fn virtual void onUpdate()
             * 
             * @brief call each frame
             */
            virtual void onUpdate() = 0;
            /**
             * @brief call eachv x ms
             * 
             * 
             * 
             */
            virtual void onFixedUpdate() = 0;

            /**
             * @brief use to display some things
             * this function is call after all updates fucntion
             */
            virtual void onDisplay() = 0;

            /**
             * @brief something enter in object
             * 
             */
            virtual void onTriggerEnter(std::shared_ptr<GameObject> go) = 0;
            
            /**
             * @brief something stay in object
             * 
             */
            virtual void onTriggerStay(std::shared_ptr<GameObject> go) = 0;
            
            /**
             * @brief something out of object
             * 
             */
            virtual void onTriggerExit(std::shared_ptr<GameObject> go) = 0;

            /**
             * @brief called when mouse enter object
             * 
             */
            virtual void onMouseEnter() = 0;

            /**
             * @brief called when mouse stay on object
             * 
             */
            virtual void onMouseStay() = 0;

            /**
             * @brief called when mouse leave object
             * 
             */
            virtual void onMouseExit() = 0;

            /**
             * @brief Check you component is runnable
             * With this function you can add some conditions to make your component runnable or not
             * @return true if your component is runnable
             * @return false if your component is not runnable
             */
            virtual bool checkComponentValidity() = 0;

            /**
             * @brief call when component destroyed
             * 
             */
            virtual void onDestroy() = 0;

            /**
             * @brief call when game is turn off
             * 
             */
            virtual void onGameQuit() = 0;

            /**
             * @brief call when GameObject is disable after being enable
             * 
             */
            virtual void onDisable() = 0;

            /**
             * @brief call when GameObject is enable after being disable
             * 
             */
            virtual void onEnable() = 0;

            /**
             * @brief call when scene is updated (not threaded)
             * 
             */
            virtual void onSceneUpdated() = 0;

            /**
             * @brief call when scene will update (not threaded)
             * 
             */
            virtual void onSceneGonnaUpdated() = 0;

            /**
             * @brief call when scene is changed
             * 
             */
            virtual void onSceneChanged() = 0;

        protected:
        private:
    };

}

#endif /* !ICOMPONENT_HPP_ */
