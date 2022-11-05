#ifndef RTYPE_STACKSUMMARY_HPP
#define RTYPE_STACKSUMMARY_HPP

#include <string>
#include <algorithm>
#include <fstream>

namespace KapEngine {

    namespace Profiler {

        class StackSummary {
        private:
            std::string _raw;
            long long _callCount;
            long long _totalTime;
            float _callPerSecond;
            float _meanCallPerSecond;
            long long _start;
            long long _time;
            long long _totTimeAllCalls;
            double _percentageTime;

            void compute() {
                long long onel = 1;
                _callPerSecond = (_callCount / (std::max(_time - _start, onel))) / 1000000000;
                long long totTime = (_totalTime / 1000000);
                _meanCallPerSecond = (long) (totTime / std::max(_callCount, onel));
                _percentageTime = ((double) totTime / (double) std::max(_totTimeAllCalls, onel)) * 100.0;
            }

        public:
            StackSummary(std::string &raw, long long callCount, long long totalTime,
                         long long start, long long time, long long totTimeAllCalls) {
                _raw = raw;
                _callCount = callCount;
                _totalTime = totalTime;
                _start = start;
                _time = time;
                _totTimeAllCalls = totTimeAllCalls;
                compute();
            }

            std::string &getRaw() {
                return _raw;
            }

            long long getCallCount() const {
                return _callCount;
            }

            long long getTotalTime() const {
                return _totalTime;
            }

            long long getStartTime() const {
                return _start;
            }

            long long getTime() const {
                return _time;
            }

            long long getTotTimeAllCalls() const {
                return _totTimeAllCalls;
            }

            void serialize(std::ostream& stream) {
                stream << _raw << _callCount << _totalTime << _start << _time << _totTimeAllCalls;
            }

            void deserialize(std::istream& stream) {
                stream >> _raw >> _callCount >> _totalTime >> _start >> _time >> _totTimeAllCalls;
            }

        };

    };


}

#endif //RTYPE_STACKSUMMARY_HPP
