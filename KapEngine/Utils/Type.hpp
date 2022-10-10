/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Type
*/

#ifndef TYPE_HPP_
#define TYPE_HPP_

#include <memory>

namespace KapEngine {
    class Type {
        public:
        template<typename T>
        inline static std::size_t getHashCode() {
            std::size_t type = typeid(T).hash_code();
            return type;
        }

        template<typename T>
        inline static std::size_t getHashCode(T& obj) {
            std::size_t type = typeid(obj).hash_code();
            return type;
        }
    };
}

#endif
