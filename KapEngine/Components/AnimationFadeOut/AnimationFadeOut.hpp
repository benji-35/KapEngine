/*
** EPITECH PROJECT, 2022
** indieStudio
** File description:
** AnimationFadeOut
*/

#ifndef ANIMATIONFADEOUT_HPP_
#define ANIMATIONFADEOUT_HPP_

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

    class AnimationFadeOut : public Animation {
        public:
            AnimationFadeOut(std::shared_ptr<GameObject>);
            ~AnimationFadeOut();

            void onPlay() override;
            void onUpdateAnim() override;
            void onResetAnim() override;

        protected:
        private:
    };

}

#endif /* !ANIMATIONFADEOUT_HPP_ */
