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
    /**
     * @namespace KapEngine::Time
     * This namespace regroup all things about time
     * @brief All things about time
     */
    namespace Time {

        /**
         * @class ETime
         * @brief Engine Time is internal time system of engine
         */
        class ETime {
            public:
                ETime() {
                    PROFILER_FUNC_START();
                    _micro_s = 0;
                    PROFILER_FUNC_END();
                }
                ETime(int64_t _val) {
                    PROFILER_FUNC_START();
                    _micro_s = _val;
                    PROFILER_FUNC_END();
                }
                ETime(ETime const& _val) {
                    PROFILER_FUNC_START();
                    *this = _val;
                    PROFILER_FUNC_END();
                }
                ~ETime() {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }

                /**
                 * @fn virtual double asSecond() const
                 * @brief avoir le temps en secondes
                 * @return double 
                 */
                virtual double asSecond() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return ((double)asMilliSecond() / 1000.0);
                }
                /**
                 * @fn virtual int32_t asMilliSecond() const
                 * @brief avoir le temps en millisecondes
                 * @return int32_t 
                 */
                virtual int32_t asMilliSecond() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return (_micro_s / 100);
                }
                /**
                 * @fn virtual int64_t asMicroSecond() const
                 * @brief avoir le temps en microsecondes
                 * @return int64_t 
                 */
                virtual int64_t asMicroSecond() const {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _micro_s;
                }

                virtual ETime &operator=(ETime const& _time) {
                    PROFILER_FUNC_START();
                    this->_micro_s = _time._micro_s;
                    PROFILER_FUNC_END();
                    return *this;
                }
                virtual ETime &operator=(ETime const* _time) {
                    PROFILER_FUNC_START();
                    *this = *_time;
                    PROFILER_FUNC_END();
                    return *this;
                }
                virtual ETime &operator=(int64_t const& _val) {
                    PROFILER_FUNC_START();
                    this->_micro_s = _val;
                    PROFILER_FUNC_END();
                    return *this;
                }

                virtual bool operator<(ETime const& _time) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return (this->_micro_s < _time._micro_s);
                }
                virtual bool operator<(int64_t const& _time) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return (this->_micro_s < _time);
                }

                virtual bool operator<=(ETime const& _time) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return (this->_micro_s <= _time._micro_s);
                }
                virtual bool operator<=(int64_t const& _time) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return (this->_micro_s <= _time);
                }

                virtual bool operator>(ETime const& _time) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return (this->_micro_s > _time._micro_s);
                }
                virtual bool operator>(int64_t const& _time) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return (this->_micro_s > _time);
                }

                virtual bool operator>=(ETime const& _time) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return (this->_micro_s >= _time._micro_s);
                }
                virtual bool operator>=(int64_t const& _time) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return (this->_micro_s >= _time);
                }

                virtual ETime &operator+=(ETime const& _time) {
                    PROFILER_FUNC_START();
                    this->_micro_s += _time._micro_s;
                    PROFILER_FUNC_END();
                    return *this;
                }

                /**
                 * @brief Set the Seconds of time
                 * @param s seconds
                 */
                void setSeconds(float s) {
                    PROFILER_FUNC_START();
                    _micro_s = (int64_t)(s * 1000000.0f);
                    PROFILER_FUNC_END();
                }

                /**
                 * @brief Set the Milliseconds of time
                 * @param ms milliseconds
                 */
                void setMilliseconds(int64_t ms) {
                    PROFILER_FUNC_START();
                    _micro_s = ms * 100;
                    PROFILER_FUNC_END();
                }

                /**
                 * @brief Set the Microseconds of time
                 * 
                 * @param mc microseconds
                 */
                void setMicroseconds(int64_t mc) {
                    PROFILER_FUNC_START();
                    _micro_s = mc;
                    PROFILER_FUNC_END();
                }

                protected:
                    int64_t _micro_s;

                private:
        };

    }
}

#endif /* !TIME_HPP_ */
