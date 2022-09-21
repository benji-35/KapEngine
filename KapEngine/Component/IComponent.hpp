/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace KapEngine {

    class IComponent {
        public:
            ~IComponent() {}

            //function to update object
            /**
             * @fn virtual void onInit()
             * will be called during the component creation process. Be advised that some engine features cannot be used in this function.
             * @brief call on component init
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
            virtual void onTriggerEnter() = 0;
            
            /**
             * @brief something stay in object
             * 
             */
            virtual void onTriggerStay() = 0;
            
            /**
             * @brief something out of object
             * 
             */
            virtual void onTriggerExit() = 0;

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

        protected:
        private:
    };

}

#endif /* !ICOMPONENT_HPP_ */
