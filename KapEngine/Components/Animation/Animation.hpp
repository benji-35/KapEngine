/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include "Component.hpp"
#include <functional>
#include "Debug.hpp"
#include "ETime.hpp"

namespace KapEngine {

    class Animation : public Component {
        public:

            struct AnimationLine {
                Component &comp;
                std::size_t curr = 0;
                std::vector<std::function<void (Component &co)>> nodes;
                std::vector<int32_t> nodeTiming;
            };

            Animation(std::shared_ptr<GameObject> go);
            ~Animation();

            virtual void __onPlay() {}

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
                    __onPlay();
                }
            }

            void setTiming(int64_t const& time) {
                // _timing = time;
            }
            void setTiming(Time::ETime const& time) {
                _timing = time;
            }

            virtual void __updateAnim();
            virtual void __resetAnim();

            virtual Animation &operator=(Animation const& anim) {

                _startAnim = anim._startAnim;
                _loop = anim._loop;
                _end = anim._end;
                _timing = anim._timing;
                _currTime = anim._currTime;

                return *this;
            }

            void addAnimationLine(AnimationLine nd) {
                if (nd.nodes.size() != nd.nodeTiming.size()) {
                    Debug::error("[ANIMATION] : the node that adding does not contains same number of keys timing that nodes functions.");
                    return;
                }
                _nodes.push_back(nd);
            }

        protected:

            bool _startAnim = false;
            bool _loop = false;
            bool _end = false;
            Time::ETime _timing;
            int64_t _currTime = 0;

            std::vector<AnimationLine> _nodes;
        private:
    };

}

#endif /* !ANIMATION_HPP_ */
