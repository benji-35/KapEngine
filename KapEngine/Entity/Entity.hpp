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
            Entity(std::size_t __id = 0) : _id(__id) {}
            ~Entity() {}

            /**
             * @brief set entity id
             * @param id 
             */
            void __setId(std::size_t id) {
                if (_id != 0)
                    return;
                _id = id;
            }

            /**
             * @brief Get the entity id
             * @return std::size_t 
             */
            std::size_t getId() const {
                return _id;
            }

            virtual void __update(int threadId) = 0;

            virtual Entity &operator=(Entity const& en) {
                _id = en._id;
                return *this;
            }
            virtual bool operator==(Entity const& en) {
                return en._id == _id;
            }
            virtual bool operator!=(Entity const& en) {
                return !(*this == en);
            }

        protected:
            std::size_t _id = 0;
        private:
    };

}

#endif /* !ENTITY_HPP_ */
