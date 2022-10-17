/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Animator
*/

#ifndef ANIMATOR_HPP_
#define ANIMATOR_HPP_

#include "KapEngine.hpp"

namespace KapEngine {
    
    /**
     * \addtogroup Components
     * @{
     * @class Animator
     * @}
     */
    
    class Animator : public Component {
        public:
            struct NodeAnim;

            struct LinkAnim {
                std::shared_ptr<NodeAnim> target;
                std::vector<std::string> triggers;
                bool mainExit;
            };

            struct NodeAnim {
                std::string _name;
                std::shared_ptr<Animation> _anim;
                std::vector<std::shared_ptr<LinkAnim>> links;

                bool _goAfter;

                NodeAnim(std::shared_ptr<Animation> anim, std::string name) {
                    _anim = anim;
                    _name = name;
                    _goAfter = true;
                }
            
                bool hasMainExit() {
                    for (std::size_t i = 0; i < links.size(); i++) {
                        if (links.at(i).get()->mainExit)
                            return true;
                    }
                    return false;
                }
            };


        public:
            Animator(std::shared_ptr<GameObject> go);
            ~Animator();

            void onStart() override;
            void onFixedUpdate() override;

            /**
             * @fn void addAnim(std::shared_ptr<Animation> anim, std::string name)
             * add animation in animator and set unused name
             * @brief add animation
             * @param anim animation
             * @param name name
             */
            void addAnim(std::shared_ptr<Animation> anim, std::string name);
            /**
             * @fn void addLink(std::string animName, std::string outAnim, std::string trigger = "")
             * allow you to link two animations
             * @brief link two animations
             * @param animName current animation name
             * @param outAnim next animation name
             * @param trigger trigger name two play next animation. If trigger name is empty, next animation gonna play at end of current animation
             */
            void addLink(std::string animName, std::string outAnim, std::string trigger = "");
            /**
             * @fn void addLink(std::string animName, std::string outAnim, std::vector<std::string> triggers)
             * allow you to link two animations
             * @brief link two animations
             * @param animName current animation name
             * @param outAnim next animation name
             * @param triggers triggers names two play next animation. if triggers are empty, next animation gonna play at end of current animation
             */
            void addLink(std::string animName, std::string outAnim, std::vector<std::string> triggers);

            /**
             * @fn void setTrigger(std::string name)
             * @brief call  a trigger
             * @param name nom du trigger
             */
            void setTrigger(std::string name);

            /**
             * @fn std::shared_ptr<NodeAnim> getAnimNode(std::string name)
             * @brief get node animator that contains 1 animations
             * @param name animation name
             * @return std::shared_ptr<NodeAnim>
             */
            std::shared_ptr<NodeAnim> getAnimNode(std::string name);

        protected:
        private:
            size_t _currAnim = 0;
            std::shared_ptr<NodeAnim> _anim;
            std::shared_ptr<NodeAnim> _firstAnim;
            std::vector<std::shared_ptr<NodeAnim>> _anims;
    };

}

#endif /* !ANIMATOR_HPP_ */
