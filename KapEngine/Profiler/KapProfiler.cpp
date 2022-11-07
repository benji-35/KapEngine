#include "KapProfiler.hpp"

using namespace KapEngine::Profiler;

KapProfiler *KapProfiler::instance = nullptr;

KapProfiler::KapProfiler() {

}

KapProfiler::~KapProfiler() {

}

void KapProfiler::_insertCaller(const char *_caller, int state, long time) {
    std::thread::id id = std::this_thread::get_id();
    std::shared_ptr<ThreadStack> stack;

    if (_threads.count(id) == 0) {
        stack = std::make_shared<ThreadStack>(id);
        _threads[id] = stack;
    }else{
        stack = _threads[id];
    }
    if (stack == nullptr) {
        return;
    }
    std::string sCaller(_caller);
    stack->enqueueCaller(sCaller, state, time);
}
