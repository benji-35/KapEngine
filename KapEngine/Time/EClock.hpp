/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** EClock
*/

#ifndef ECLOCK_HPP_
#define ECLOCK_HPP_

#include <chrono>
#include "ETime.hpp"

namespace KapEngine {
    namespace Time {
        class ETime;
    }
}

namespace KapEngine {
    namespace Time {
        class EClock {
            public:
                EClock() {
                    __setNow();
                }
                EClock(EClock const& _clk) {
                    *this = _clk;
                }
                ~EClock() {}

                /**
                 * @fn virtual ETime restart()
                 * redémare la clock et donne également le temps écoulé depuis le dernier redémarrage de celle ci
                 * @brief Redémarer la clock
                 * @return ETime temps écoulé depuis le dernier redémarrage
                 */
                virtual ETime restart() {
                    ETime _got = __getElapse();
                    __setNow();
                    return _got;
                }

                /**
                 * @fn virtual ETime getElapseTime()
                 * avoir le temps écouler depuis le dernier redémarrage de la clock sans l'arrêter
                 * @brief avoir le temps
                 * @return ETime temps écoulé depuis le dernier redémarrage
                 */
                virtual ETime getElapseTime() {
                    return ETime(__getElapse());
                }

                EClock &operator=(EClock const& _clk) {
                    this->_start = _clk._start;
                    return *this;
                }

            protected:
                int64_t _start = 0;
            private:
                int64_t __getElapse() {
                    std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds >(
                        std::chrono::high_resolution_clock::now().time_since_epoch()
                    );
                    int64_t _nVal = ms.count();
                    return (_nVal - _start);
                }

                void __setNow() {
                    std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds >(
                        std::chrono::high_resolution_clock::now().time_since_epoch()
                    );
                    _start = ms.count();
                }
        };
    }
}

#endif /* !ECLOCK_HPP_ */
