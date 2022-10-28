#include "StackElement.hpp"

KapEngine::Profiler::StackElement::StackElement(std::string &_raw) {
    this->raw = _raw;
    parseMethodName(_raw);
    parseClassName(_raw);
}

void KapEngine::Profiler::StackElement::parseMethodName(std::string &r) {
    size_t colons = r.find("::");
    size_t begin = r.substr(0, colons).rfind(" ") + 1;
    size_t end = r.rfind ("(") - begin;

    method = r.substr(begin, end) + "()";
}

void KapEngine::Profiler::StackElement::parseClassName(std::string &r) {
    size_t colons = r.find("::");

    if (colons == std::string::npos) {
        clazz = "::";
    } else {
        size_t begin = r.substr(0, colons).rfind(" ") + 1;
        size_t end = colons - begin;

        clazz = r.substr(begin, end);
    }
}

KapEngine::Profiler::StackElement::~StackElement() {

}

int KapEngine::Profiler::StackElement::hashCode() {
    return (int) std::hash<std::string>()(this->raw);
}