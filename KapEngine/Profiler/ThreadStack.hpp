#ifndef RTYPE_THREADSTACK_HPP
#define RTYPE_THREADSTACK_HPP

#include <chrono>
#include <map>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "KapEngineDebug.hpp"
#include "FixedQueue.hpp"
#include "StackElement.hpp"

namespace KapEngine {

    namespace Profiler {

        class ThreadStack {

            bool _running;
            std::thread _monitorThread;
            std::mutex mtx;
            std::condition_variable needCallerInsertion;
            std::thread::id _id;
            long long _start;

            std::queue<std::string> callersToInsert;

            std::map<size_t, long long> _callCounts;
            std::map<int, long long> _hashTiming;
            FixedQueue<std::shared_ptr<StackElement>, 10> _rollingStack;

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
                    while (!callersToInsert.empty()) {
                        std::string &o = callersToInsert.front();
                        std::cout << o << std::endl;
                        //std::tuple<std::string, int, long long> tuple = callersToInsert.front();
                        //_insertCaller(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple));
                        callersToInsert.pop();
                    }
                    //std::unique_lock<std::mutex> lock(mtx);
                    //needCallerInsertion.wait(lock, [this]{ return !callersToInsert.empty(); });
                }
            }

            void enqueueCaller(std::string &_caller, int state, long long time) {
                //_insertCaller(_caller, state, time);
                /*{
                    std::lock_guard<std::mutex> lk (mtx);
                    callersToInsert.push(_caller);
                    //callersToInsert.push(std::make_tuple(_caller, state, time));
                }
                needCallerInsertion.notify_all();*/
            }

            void _insertCaller(std::string &_caller, int state, long long time) {
                std::shared_ptr<StackElement> element = std::make_shared<StackElement>(_caller);
                int hash = element->hashCode();

                if (state == 1) {
                    if (_hashTiming.count(hash) == 1) {
                        long long elapsed = time - _hashTiming[hash];
                        size_t longHash = std::hash<std::string>()(_caller);

                        if (_callCounts.count(longHash) == 1) {
                            _callCounts[longHash] += 1;
                        }else{
                            _callCounts[longHash] = 1;
                        }
                    }
                }else{
                    _hashTiming[hash] = time;
                    _rollingStack.push(element);
                }
            }

        };

    }

}

#endif //RTYPE_THREADSTACK_HPP
