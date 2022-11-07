#include "StackElement.hpp"

KapEngine::Profiler::StackElement::StackElement(std::string &_raw) {
    this->raw = _raw;
    parseMethodName(_raw);
    parseClassName(_raw);
}

void KapEngine::Profiler::StackElement::parseMethodName(std::string &r) {
    size_t parenthesis_last = r.find_last_of("(");

    if (parenthesis_last == -1) {
        method = r;
        return;
    }
    size_t colons = r.substr(0, parenthesis_last - 1).find_last_of("::");
    if (colons == -1) {
        method = r;
        return;
    }
    method = r.substr(colons + 1);
    size_t parenthesis_lc = method.find_first_of("(");
    if (parenthesis_last > 0) {
        method = method.substr(0, parenthesis_lc);
    }
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

size_t KapEngine::Profiler::StackElement::hashCode() const {
    return std::hash<std::string>()(this->raw);
}