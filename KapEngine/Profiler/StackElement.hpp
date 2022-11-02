#ifndef RTYPE_STACKELEMENT_HPP
#define RTYPE_STACKELEMENT_HPP

#include <string>
#include <sstream>

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

            size_t hashCode() const;

            [[nodiscard]] std::string getMethod() const {
                return method;
            }

            [[nodiscard]] std::string getClass() const {
                return clazz;
            }

            [[nodiscard]] std::string toString() const {
                return raw;
            }

        };

    }
}

#endif //RTYPE_STACKELEMENT_HPP
