#ifndef RTYPE_KAPPROFILER_HPP
#define RTYPE_KAPPROFILER_HPP

#include <chrono>
#include <map>
#include <thread>
#include "ThreadStack.hpp"

namespace KapEngine::Profiler {

        class KapProfiler {
            static KapProfiler *instance;

            private:
                std::map<std::thread::id, std::shared_ptr<ThreadStack>> _threads;

        public:
            KapProfiler();
            ~KapProfiler();

            void _insertCaller(const char *_caller, int state, long time);

            static KapProfiler *getInstance() {
                if (instance == nullptr) {
                    instance = new KapProfiler();
                }
                return instance;
            }

        };

}


using namespace KapEngine::Profiler;

static void profiler_func(const char *_caller, int state) {
    #if KAPENGINE_PROFILER_ACTIVE
        std::string caller = std::string(_caller);
        std::chrono::time_point time = std::chrono::high_resolution_clock::now();

        if (KapProfiler::getInstance() == nullptr) {
            return;
        }
        KapProfiler::getInstance()->_insertCaller(_caller, state, time.time_since_epoch().count());
    #endif
}

#define PROFILER_FUNC_START() profiler_func(__PRETTY_FUNCTION__, 0);
#define PROFILER_FUNC_END() profiler_func(__PRETTY_FUNCTION__, 1);

#endif //RTYPE_KAPPROFILER_HPP
