/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Dictionary
*/

#ifndef DICTIONARY_HPP_
#define DICTIONARY_HPP_

#include "Profiler/KapProfiler.hpp"
#include <map>

namespace KapEngine {
    template <typename TKey, typename TValue>
    class Dictionary {
        private:
        std::map<TKey, TValue> map;

        public:
        Dictionary() = default;

        ~Dictionary() {
            PROFILER_FUNC_START();
            map.clear();
            PROFILER_FUNC_END();
        };

        TValue& operator[](TKey key) {
            PROFILER_FUNC_START();
            PROFILER_FUNC_END();
            return map[key];
        }

        bool tryGetValue(TKey key, TValue& value) {
            PROFILER_FUNC_START();
            auto it = map.find(key);
            if (it == map.end()) {
                PROFILER_FUNC_END();
                return false;
            }
            value = it->second;
            PROFILER_FUNC_END();
            return true;
        }

        bool containsKey(TKey key) {
            PROFILER_FUNC_START();
            auto it = map.find(key);
            PROFILER_FUNC_END();
            return it != map.end();
        }

        bool remove(TKey key) {
            PROFILER_FUNC_START();
            auto it = map.find(key);
            if (it == map.end()) {
                PROFILER_FUNC_END();
                return false;
            }
            map.erase(it);
            PROFILER_FUNC_END();
            return true;
        }

        void clear() {
            PROFILER_FUNC_START();
            map.clear();
            PROFILER_FUNC_END();
        }

        int size() const {
            PROFILER_FUNC_START();
            PROFILER_FUNC_END();
            return map.size();
        }

        class Iterator {
            private:
            typename std::map<TKey, TValue>::iterator it;

            public:
            Iterator(typename std::map<TKey, TValue>::iterator _it) : it(_it) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
            }

            Iterator& operator++() {
                PROFILER_FUNC_START();
                ++it;
                PROFILER_FUNC_END();
                return *this;
            }

            bool operator!=(const Iterator& other) const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return it != other.it;
            }

            std::pair<TKey, TValue> operator*() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return *it;
            }
        };

        Iterator begin() {
            PROFILER_FUNC_START();
            PROFILER_FUNC_END();
            return Iterator(map.begin());
        }

        Iterator end() {
            PROFILER_FUNC_START();
            PROFILER_FUNC_END();
            return Iterator(map.end());
        }

        class ConstIterator {
            private:
            typename std::map<TKey, TValue>::const_iterator it;

            public:
            ConstIterator(typename std::map<TKey, TValue>::const_iterator _it) : it(_it) {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
            }

            ConstIterator& operator++() {
                PROFILER_FUNC_START();
                ++it;
                PROFILER_FUNC_END();
                return *this;
            }

            bool operator!=(const ConstIterator& other) const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return it != other.it;
            }

            std::pair<TKey, TValue> operator*() const {
                PROFILER_FUNC_START();
                PROFILER_FUNC_END();
                return *it;
            }
        };

        ConstIterator begin() const {
            PROFILER_FUNC_START();
            PROFILER_FUNC_END();
            return ConstIterator(map.begin());
        }

        ConstIterator end() const {
            PROFILER_FUNC_START();
            PROFILER_FUNC_END();
            return ConstIterator(map.end());
        }
    };
}

#endif
