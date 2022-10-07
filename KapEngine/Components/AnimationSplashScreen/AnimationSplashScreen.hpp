/*
** EPITECH PROJECT, 2022
** engine
** File description:
** AnimationSplashScreen
*/

#ifndef ANIMATIONSPLASHSCREEN_HPP_
#define ANIMATIONSPLASHSCREEN_HPP_

#include "KapEngine.hpp"
#include "KapEngineUi.hpp"

namespace KapEngine {

    class AnimationSplashScreen : public Animation {
        public:
            AnimationSplashScreen(std::shared_ptr<GameObject>);
            ~AnimationSplashScreen();

            void onPlay() override;
            void onUpdateAnim() override;
            void onResetAnim() override;

        protected:
        private:
            void __fadeIn(float val);
            void __fadeOut(float val);
    };

}

#endif /* !ANIMATIONSPLASHSCREEN_HPP_ */
