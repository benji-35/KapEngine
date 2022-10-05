/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Dictionary
*/

#ifndef DICTIONARY_HPP_
#define DICTIONARY_HPP_

#include <map>

namespace KapEngine {
    template <typename TKey, typename TValue>
    class Dictionary {
        private:
        std::map<TKey, TValue> map;

        public:
        Dictionary() = default;

        ~Dictionary() {
            map.clear();
        };

        TValue& operator[](TKey key) {
            return map[key];
        }

        bool tryGetValue(TKey key, TValue& value) {
            auto it = map.find(key);
            if (it == map.end()) {
                return false;
            }
            value = it->second;
            return true;
        }

        bool containsKey(TKey key) {
            auto it = map.find(key);
            return it != map.end();
        }

        bool remove(TKey key) {
            auto it = map.find(key);
            if (it == map.end()) {
                return false;
            }
            map.erase(it);
            return true;
        }

        void clear() {
            map.clear();
        }

        int size() const {
            return map.size();
        }

        class Iterator {
            private:
            typename std::map<TKey, TValue>::iterator it;

            public:
            Iterator(typename std::map<TKey, TValue>::iterator _it) : it(_it) {}

            Iterator& operator++() {
                ++it;
                return *this;
            }

            bool operator!=(const Iterator& other) const {
                return it != other.it;
            }

            std::pair<TKey, TValue> operator*() const {
                return *it;
            }
        };

        Iterator begin() {
            return Iterator(map.begin());
        }

        Iterator end() {
            return Iterator(map.end());
        }

        class ConstIterator {
            private:
            typename std::map<TKey, TValue>::const_iterator it;

            public:
            ConstIterator(typename std::map<TKey, TValue>::const_iterator _it) : it(_it) {}

            ConstIterator& operator++() {
                ++it;
                return *this;
            }

            bool operator!=(const ConstIterator& other) const {
                return it != other.it;
            }

            std::pair<TKey, TValue> operator*() const {
                return *it;
            }
        };

        ConstIterator begin() const {
            return ConstIterator(map.begin());
        }

        ConstIterator end() const {
            return ConstIterator(map.end());
        }
    };
}

#endif
