#ifndef RTYPE_STACKELEMENT_HPP
#define RTYPE_STACKELEMENT_HPP

#include <string>

namespace KapEngine {

    namespace Profiler {

        class StackElement {

        private:
            std::string raw;
            std::string method;
            std::string clazz;

            void parseMethodName(std::string &);
            void parseClassName(std::string &);

        public:
            StackElement(std::string &);
            ~StackElement();

            int hashCode();

        };
    }
}

#endif //RTYPE_STACKELEMENT_HPP
