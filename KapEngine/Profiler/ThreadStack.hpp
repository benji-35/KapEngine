#ifndef RTYPE_THREADSTACK_HPP
#define RTYPE_THREADSTACK_HPP

#include <chrono>
#include <map>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <fstream>
#include <iostream>

#include "FixedQueue.hpp"
#include "StackElement.hpp"
#include "StackSummary.hpp"

namespace KapEngine {

    namespace Profiler {

        class ThreadStack {

            bool _running;
            std::thread _monitorThread;
            std::mutex _queueMutex;
            std::mutex mtx;
            std::condition_variable needCallerInsertion;
            std::thread::id _id;
            long long _start;
            long long _lastDebug;

            std::queue<std::tuple<std::string, int, long long>> callersToInsert;

            std::map<size_t, std::string> _hashMapping;
            std::map<size_t, long long> _callCounts;
            std::map<size_t, long long> _hashTiming;
            std::map<size_t, long long> _callTime;
            FixedQueue<StackElement, 10> _rollingStack;

            long long now() {
                return std::chrono::high_resolution_clock::now().time_since_epoch().count();
            }

            bool canProcess() {
                return now() - _lastDebug > 1000000000;
            }

            long getTotalTimeAllCalls() {
                long long totTimeAllCalls = 0;

                for (auto &_callTime : _callTime) {
                    totTimeAllCalls += _callTime.second / 1000000;
                }
                return totTimeAllCalls;
            }

            std::string getThreadAsString() {
                std::ostringstream threadString;
                threadString << std::this_thread::get_id();

                return threadString.str();
            }

            std::string getKprofFileName() {
                return getThreadAsString() + ".kprof";
            }

            std::vector<StackSummary> getStackSummaries() {
                std::vector<StackSummary> stackSummaries;
                long long totalAllTimeCalls = getTotalTimeAllCalls();
                long long n = now();

                for (auto &_callCount : _callCounts) {
                    size_t stackHash = _callCount.first;
                    std::string s = _hashMapping[stackHash];
                    long long totTime = (_callTime[stackHash] / 1000000);
                    StackSummary summary(s, _callCount.second, totTime, _start, n, totalAllTimeCalls);

                    stackSummaries.push_back(summary);
                }
                return stackSummaries;
            }

            void saveKProf() {
                std::ofstream file(getKprofFileName(), std::ios::trunc);
                std::stringstream output;

                std::vector<StackSummary> stackSummaries = getStackSummaries();
                output << stackSummaries.size() << '\n';
                for (auto &summary : stackSummaries) {
                    summary.serialize(output);
                    output << '\n';
                }
                output << '\\';
                if (file.good() && file.is_open()) {
                    file << output.str();
                    file.close();
                }
            }

            void process() {
                saveKProf();
                _lastDebug = now();
            }

            void checkProcess() {
                if (canProcess()) {
                    process();
                }
            }

            void _run() {
                while (_running) {
                    _queueMutex.lock();
                    while (!callersToInsert.empty()) {
                        std::tuple<std::string, int, long long> tuple = callersToInsert.front();
                        _insertCaller(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple));
                        callersToInsert.pop();
                    }
                    _queueMutex.unlock();
                    checkProcess();
                }
            }

        public:
            ThreadStack(std::thread::id &id) {
                _running = true;
                _id = id;
                _start = now();
                _monitorThread = std::thread([this]{ _run(); });
            }


            void enqueueCaller(std::string &_caller, int state, long long time) {
                _queueMutex.lock();
                // Limit in case of slow profiling
                if (callersToInsert.size() >= 100) {
                    _queueMutex.unlock();
                    return;
                }
                callersToInsert.push(std::make_tuple(_caller, state, time));
                _queueMutex.unlock();
            }

            void _insertCaller(std::string &_caller, int state, long long time) {
                //std::cout << _caller << std::endl;
                StackElement element(_caller);
                size_t longHash = element.hashCode();

                if (_hashMapping.count(longHash) == 0) {
                    _hashMapping[longHash] = element.toString();
                }
                if (state == 1) {
                    if (_hashTiming.count(longHash) == 1) {
                        long long elapsed = time - _hashTiming[longHash];

                        if (_callCounts.count(longHash) == 1) {
                            _callCounts[longHash] += 1;
                        }else{
                            _callCounts[longHash] = 1;
                        }
                        if (_callTime[longHash] == 0) {
                            _callTime[longHash] = elapsed;
                        }else{
                            _callTime[longHash] += elapsed;
                        }
                    }
                }else{
                    _hashTiming[longHash] = time;
                    _rollingStack.push(element);
                }
            }

        };

    }

}

#endif //RTYPE_THREADSTACK_HPP
