/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <functional>

#include "Component.hpp"
#include "Debug.hpp"
#include "ETime.hpp"

#include "EventAction.hpp"

namespace KapEngine {

    class Animation : public Component {
        public:

            Animation(std::shared_ptr<GameObject> go);
            ~Animation();

            void onFixedUpdate() override;

            /**
             * @fn bool isEnded()
             * @brief animation terminée ?
             * @retval true si l'animation est terminée
             * @retval false si l'animation n'est pas terminée
             */
            bool isEnded() {
                return _end;
            }

            /**
             * @fn void loop(bool b)
             * @brief
             *
             * @param b
             */
            void loop(bool b) {
                _loop = b;
            }

            /**
             * @fn void play(bool b)
             * @brief
             *
             * @param b
             */
            void play(bool b) {
                _startAnim = b;
                if (b) {
                    _end = false;
                    _currTime = 0;
                    onPlay();
                }
            }

            void setTiming(int64_t const& time) {
                _timing = time;
            }
            void setTiming(Time::ETime const& time) {
                _timing = time;
            }

            virtual void onPlay() {}
            virtual void onUpdateAnim();
            virtual void onResetAnim();

            virtual Animation &operator=(Animation const& anim) {

                _startAnim = anim._startAnim;
                _loop = anim._loop;
                _end = anim._end;
                _timing = anim._timing;
                _currTime = anim._currTime;

                return *this;
            }

            Events::EventAction &getOnEnd() {
                return _onEnd;
            }
            Events::EventAction &getOnStart() {
                return _onStart;
            }
            Events::EventAction &getOnRestart() {
                return _onRestart;
            }

        protected:

            bool _startAnim = false;
            bool _loop = false;
            bool _end = false;
            Time::ETime _timing;
            int64_t _currTime = 0;

            Events::EventAction _onEnd;
            Events::EventAction _onRestart;
            Events::EventAction _onStart;
        private:
            bool _reseted = false;
    };

}

#endif /* !ANIMATION_HPP_ */
