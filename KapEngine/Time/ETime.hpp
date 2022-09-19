/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Time
*/

#ifndef TIME_HPP_
#define TIME_HPP_

#include <cstdint>

namespace KapEngine {
    namespace Time {

        /**
         * @class ETime
         * @brief Engine Time is internal time system of engine
         */
        class ETime {
            public:
                ETime() {
                    _micro_s = 0;
                }
                ETime(int64_t _val) {
                    _micro_s = _val;
                }
                ETime(ETime const& _val) {
                    *this = _val;
                }
                ~ETime() {}

                /**
                 * @fn virtual float asSecond() const
                 * @brief avoir le temps en secondes
                 * @return float 
                 */
                virtual float asSecond() const {
                    return (asMilliSecond() / 1000);
                }
                /**
                 * @fn virtual int32_t asMilliSecond() const
                 * @brief avoir le temps en millisecondes
                 * @return int32_t 
                 */
                virtual int32_t asMilliSecond() const {
                    return (_micro_s / 100);
                }
                /**
                 * @fn virtual int64_t asMicroSecond() const
                 * @brief avoir le temps en microsecondes
                 * @return int64_t 
                 */
                virtual int64_t asMicroSecond() const {
                    return _micro_s;
                }

                virtual ETime &operator=(ETime const& _time) {
                    this->_micro_s = _time._micro_s;
                    return *this;
                }
                virtual ETime &operator=(ETime const* _time) {
                    *this = *_time;
                    return *this;
                }
                virtual ETime &operator=(int64_t const& _val) {
                    this->_micro_s = _val;
                    return *this;
                }

                virtual bool operator<(ETime const& _time) {
                    return (this->_micro_s < _time._micro_s);
                }
                virtual bool operator<(int64_t const& _time) {
                    return (this->_micro_s < _time);
                }

                virtual bool operator<=(ETime const& _time) {
                    return (this->_micro_s <= _time._micro_s);
                }
                virtual bool operator<=(int64_t const& _time) {
                    return (this->_micro_s <= _time);
                }

                virtual bool operator>(ETime const& _time) {
                    return (this->_micro_s > _time._micro_s);
                }
                virtual bool operator>(int64_t const& _time) {
                    return (this->_micro_s > _time);
                }

                virtual bool operator>=(ETime const& _time) {
                    return (this->_micro_s >= _time._micro_s);
                }
                virtual bool operator>=(int64_t const& _time) {
                    return (this->_micro_s >= _time);
                }

                virtual ETime &operator+=(ETime const& _time) {
                    this->_micro_s += _time._micro_s;
                    return *this;
                }

                /**
                 * @brief Set the Seconds of time
                 * @param s seconds
                 */
                void setSeconds(float s) {
                    _micro_s = (int64_t)(s * 1000000.0f);
                }

                /**
                 * @brief Set the Milliseconds of time
                 * @param ms milliseconds
                 */
                void setMilliseconds(int64_t ms) {
                    _micro_s = ms * 100;
                }

                /**
                 * @brief Set the Microseconds of time
                 * 
                 * @param mc microseconds
                 */
                void setMicroseconds(int64_t mc) {
                    _micro_s = mc;
                }

                protected:
                    int64_t _micro_s;

                private:
        };

    }
}

#endif /* !TIME_HPP_ */
