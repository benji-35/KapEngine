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
            PROFILER_FUNC_START();
            PROFILER_FUNC_END();
            return std::hash<std::string>()(typeid(T).name());
        }

        template<typename T>
        inline static std::size_t getHashCode(T& obj) {
            PROFILER_FUNC_START();
            PROFILER_FUNC_END();
            return std::hash<std::string>()(typeid(obj).name());
        }
    };
}

#endif
