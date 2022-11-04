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
                    PROFILER_FUNC_START();
                    __setNow();
                    PROFILER_FUNC_END();
                }
                EClock(EClock const& _clk) {
                    PROFILER_FUNC_START();
                    *this = _clk;
                    PROFILER_FUNC_END();
                }
                ~EClock() {}

                /**
                 * @fn virtual ETime restart()
                 * redémare la clock et donne également le temps écoulé depuis le dernier redémarrage de celle ci
                 * @brief Redémarer la clock
                 * @return ETime temps écoulé depuis le dernier redémarrage
                 */
                virtual ETime restart() {
                    PROFILER_FUNC_START();
                    ETime _got = __getElapse();
                    __setNow();
                    PROFILER_FUNC_END();
                    return _got;
                }

                /**
                 * @fn virtual ETime getElapseTime()
                 * avoir le temps écouler depuis le dernier redémarrage de la clock sans l'arrêter
                 * @brief avoir le temps
                 * @return ETime temps écoulé depuis le dernier redémarrage
                 */
                virtual ETime getElapseTime() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return ETime(__getElapse());
                }

                EClock &operator=(EClock const& _clk) {
                    PROFILER_FUNC_START();
                    this->_start = _clk._start;
                    PROFILER_FUNC_END();
                    return *this;
                }

            protected:
                int64_t _start = 0;
            private:
                int64_t __getElapse() {
                    PROFILER_FUNC_START();
                    std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds >(
                        std::chrono::high_resolution_clock::now().time_since_epoch()
                    );
                    int64_t _nVal = ms.count();
                    PROFILER_FUNC_END();
                    return (_nVal - _start);
                }

                void __setNow() {
                    PROFILER_FUNC_START();
                    std::chrono::microseconds ms = std::chrono::duration_cast<std::chrono::microseconds >(
                        std::chrono::high_resolution_clock::now().time_since_epoch()
                    );
                    PROFILER_FUNC_END();
                    _start = ms.count();
                }
        };
    }
}

#endif /* !ECLOCK_HPP_ */
