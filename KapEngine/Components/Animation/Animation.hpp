/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include <functional>

#include "KapEngine.hpp"
#include "KapEngineEvents.hpp"

namespace KapEngine {

    /**
     * \addtogroup Components
     * @{
     * @class Animation
     * @}
     */

    class Animation : public Component {
        public:

            Animation(std::shared_ptr<GameObject> go);
            ~Animation();

            void onFixedUpdate() override;

            /**
             * @fn bool isEnded()
             * @brief is animation ended
             * @retval true if animation ended
             * @retval false if animation not ended
             */
            bool isEnded() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _end;
            }

            /**
             * @fn void loop(bool b)
             * @brief
             *
             * @param b
             */
            void loop(bool b) {
                PROFILER_FUNC_START();
                _loop = b;
                PROFILER_FUNC_END();
            }

            /**
             * @fn void play(bool b)
             * @brief
             *
             * @param b
             */
            void play(bool b) {
                PROFILER_FUNC_START();
                _startAnim = b;
                if (b) {
                    _end = false;
                    _currTime = 0;
                    onPlay();
                }
                PROFILER_FUNC_END();
            }

            /**
             * @brief Set the animation duration
             * 
             * @param time (micro seconds)
             */
            void setTiming(int64_t const& time) {
                PROFILER_FUNC_START();
                _timing = time;
                PROFILER_FUNC_END();
            }

            /**
             * @brief Set the animation duration
             * 
             * @param time (KapEngine::Time::ETime)
             */
            void setTiming(Time::ETime const& time) {
                PROFILER_FUNC_START();
                _timing = time;
                PROFILER_FUNC_END();
            }

            virtual void onPlay() {}
            virtual void onUpdateAnim();
            virtual void onResetAnim();

            virtual Animation &operator=(Animation const& anim) {
                PROFILER_FUNC_START();
                _startAnim = anim._startAnim;
                _loop = anim._loop;
                _end = anim._end;
                _timing = anim._timing;
                _currTime = anim._currTime;
                PROFILER_FUNC_END();

                return *this;
            }

            Events::EventAction &getOnEnd() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _onEnd;
            }

            Events::EventAction &getOnStart() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _onStart;
            }

            Events::EventAction &getOnRestart() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
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
