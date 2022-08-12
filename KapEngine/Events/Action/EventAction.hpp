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
                EventAction() {}
                ~EventAction() {}

                void registerAction(std::function<void()> func) {
                    _funcs.push_back(func);
                }

                void invoke() {
                    for (std::size_t i = 0; i < _funcs.size(); i++) {
                        _funcs[i]();
                    }
                }

                void clear() {
                    _funcs.clear();
                }

            protected:
            private:
                std::vector<std::function<void()>> _funcs;
        };

    }

}

#endif /* !EVENTACTION_HPP_ */
