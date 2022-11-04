#ifndef RTYPE_THREADSTACK_HPP
#define RTYPE_THREADSTACK_HPP

#include <chrono>
#include <map>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "FixedQueue.hpp"
#include "StackElement.hpp"

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

        public:
            ThreadStack(std::thread::id &id) {
                _running = true;
                _id = id;
                _start = now();
                _monitorThread = std::thread([this]{ _run(); });
            }

            void _run() {
                while (_running) {
                    std::lock_guard<std::mutex> lock(_queueMutex);
                    while (!callersToInsert.empty()) {
                        std::tuple<std::string, int, long long> tuple = callersToInsert.front();
                        _insertCaller(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple));
                        callersToInsert.pop();
                    }
                    //std::unique_lock<std::mutex> lock(mtx);
                    //needCallerInsertion.wait(lock, [this]{ return !callersToInsert.empty(); });
                    long long now = std::chrono::high_resolution_clock::now().time_since_epoch().count();
                    if (now - _lastDebug > 1000000000) {
                        //KapEngine::Debug::log("---------------------------------");
                        std::ostringstream s2;
                        s2 << std::this_thread::get_id();
                        std::string idstr = s2.str();
                        //KapEngine::Debug::log("Thread #" + s2.str());

                        long long totTimeAllCalls = 0;
                        for (auto &_callTime : _callTime) {
                            totTimeAllCalls += _callTime.second / 1000000;
                        }
                        long long onel = 1;
                        for (auto &_callCount : _callCounts) {
                            size_t stackHash = _callCount.first;
                            std::string s = _hashMapping[stackHash];
                            StackElement elem(s);
                            float callSec = (_callCount.second / (std::max(now - _start, onel))) / 1000000000;
                            long long totTime = (_callTime[stackHash] / 1000000);
                            float mean = (long) (totTime / std::max(_callCount.second, onel));
                            double timePercentage = ((double) totTime / (double) std::max(totTimeAllCalls, onel)) * 100.0;

                            /*KapEngine::Debug::log(elem.getClass() + " " + elem.getMethod() + " Count[" + std::to_string(_callCount.second)
                                + "] Call/s[" + std::to_string(callSec) + "] "
                                + "Mean[" + std::to_string(mean) + " ms] "
                                + "Total[" + std::to_string(totTime) + " ms] "
                                + std::to_string(timePercentage) + " % [" + std::to_string(totTimeAllCalls) + "]");*/
                        }
                        //KapEngine::Debug::log("---------------------------------");
                        _lastDebug = now;
                    }
                }
            }

            void enqueueCaller(std::string &_caller, int state, long long time) {
                //_insertCaller(_caller, state, time);
                std::lock_guard<std::mutex> lock(_queueMutex);
                // Limit in case of slow profiling
                if (callersToInsert.size() >= 100) {
                    return;
                }
                callersToInsert.push(std::make_tuple(_caller, state, time));
                //needCallerInsertion.notify_all();
            }

            void _insertCaller(std::string &_caller, int state, long long time) {
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
