/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <string>

namespace KapEngine {

    class Entity {
        public:
            Entity(std::size_t __id = 0) : _id(__id) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
            }
            ~Entity() {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
            }

            /**
             * @brief set entity id
             * @param id 
             */
            void __setId(std::size_t id) {
                PROFILER_FUNC_START();
                if (_id != 0) {
                    PROFILER_FUNC_END();
                    return;
                }
                _id = id;
                PROFILER_FUNC_END();
            }

            /**
             * @brief Get the entity id
             * @return std::size_t 
             */
            std::size_t getId() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return _id;
            }

            virtual Entity &operator=(Entity const& en) {
                PROFILER_FUNC_START();
                _id = en._id;
                PROFILER_FUNC_END();
                return *this;
            }

            virtual bool operator==(Entity const& en) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return en._id == _id;
            }

            virtual bool operator!=(Entity const& en) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return !(*this == en);
            }

        protected:
            std::size_t _id = 0;
        private:
    };

}

#endif /* !ENTITY_HPP_ */
