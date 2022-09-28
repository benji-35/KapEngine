/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** AnimationFadeIn
*/

#ifndef ANIMATIONFADEIN_HPP_
#define ANIMATIONFADEIN_HPP_

#include "Animation.hpp"
#include "UiImage.hpp"

namespace KapEngine {
    class Component;
    class GameObject;
    class Animation;

    namespace UI {
        class Image;
    }
}

namespace KapEngine {

    class AnimationFadeIn : public Animation {
        public:
            AnimationFadeIn(std::shared_ptr<GameObject>);
            ~AnimationFadeIn();

            void onPlay() override;
            void onUpdateAnim() override;
            void onResetAnim() override;

        protected:
        private:
    };

}

#endif /* !ANIMATIONFADEIN_HPP_ */
