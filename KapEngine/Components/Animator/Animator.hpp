/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Animator
*/

#ifndef ANIMATOR_HPP_
#define ANIMATOR_HPP_

#include "Component.hpp"
#include "Animation.hpp"

namespace KapEngine {
    
    /**
     * \addtogroup composants
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
             * @fn void addAnim(Animation *anim, std::string name)
             * add animation in animator and set unused name
             * @brief add animation
             * @param anim animation
             * @param name name
             */
            void addAnim(std::shared_ptr<Animation> anim, std::string name);
            /**
             * @fn void addLink(std::string animName, std::string outAnim, std::string trigger = "")
             * permet de lier la fin d'une animation avec une autre animation dans l'animator
             * @brief ajouter un lien entre 2 animations
             * @param animName nom de l'animation actuelle
             * @param outAnim nom de l'animation suivante
             * @param trigger nom du trigger pour passer à l'autre animation. Si trigger est vide dans ce cas là, l'animator attendra la fin de la première animation pour passer à la suivante
             */
            void addLink(std::string animName, std::string outAnim, std::string trigger = "");
            /**
             * @fn void addLink(std::string animName, std::string outAnim, std::vector<std::string> triggers)
             * permet de lier la fin d'une animation avec une autre animation dans l'animator
             * @brief ajouter un lien entre 2 animations
             * @param animName nom de l'animation actuelle
             * @param outAnim nom de l'animation suivante
             * @param triggers nom des triggers pour passer à l'autre animation. Si la liste des triggers est vide dans ce cas là, l'animator attendra la fin de la première animation pour passer à la suivante
             */
            void addLink(std::string animName, std::string outAnim, std::vector<std::string> triggers);

            /**
             * @fn void setTrigger(std::string name)
             * @brief appel le trigger
             * @param name nom du trigger
             */
            void setTrigger(std::string name);

            /**
             * @fn NodeAnim *getAnimNode(std::string name)
             * @brief prendre une node de l'animator contenant une animation
             * @param name nom de l'animation
             * @return NodeAnim* 
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
