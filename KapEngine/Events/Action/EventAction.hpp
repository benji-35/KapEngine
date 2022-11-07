/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** EventAction
*/

#ifndef EVENTACTION_HPP_
#define EVENTACTION_HPP_

#include <functional>
#include <vector>

namespace KapEngine {

    namespace Events {

        class EventAction {
            public:
                EventAction() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                ~EventAction() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }

                /**
                 * @brief register an action to do (lambda)
                 * 
                 * @param func 
                 */
                void registerAction(std::function<void()> func) {
                    PROFILER_FUNC_START();
                    _funcs.push_back(func);
                    PROFILER_FUNC_END();
                }

                /**
                 * @brief call all actions
                 * 
                 */
                void invoke() {
                    PROFILER_FUNC_START();
                    for (std::size_t i = 0; i < _funcs.size(); i++) {
                        _funcs[i]();
                    }
                    PROFILER_FUNC_END();
                }

                /**
                 * @brief clear all actions
                 * 
                 */
                void clear() {
                    PROFILER_FUNC_START();
                    _funcs.clear();
                    PROFILER_FUNC_END();
                }

            protected:
            private:
                std::vector<std::function<void()>> _funcs;
        };

    }

}

#endif /* !EVENTACTION_HPP_ */
