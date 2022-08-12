/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <string>

namespace KapEngine {

    namespace Errors {

        class Error : public virtual std::exception {
            protected:
                std::string _message;
            public:
                explicit Error(std::string const& msg) {
                    _message = msg;
                }
                ~Error() = default;
                const char* what() const noexcept override {
                    return _message.c_str();
                }
        };

        class ComponentError : public Error {
            public: 
                ComponentError(std::string const& msg) : Error(msg) {}
                ~ComponentError() = default;
        };

        class GameObjectError : public Error {
            public:
                GameObjectError(std::string const& msg) : Error(msg) {}
                ~GameObjectError() = default;
        };

        class EngineError : public Error {
            public:
                EngineError(std::string const& msg) : Error(msg) {}
                ~EngineError() = default;
        };

        class SceneError : public Error {
            public:
                SceneError(std::string const& msg) : Error(msg) {}
                ~SceneError() = default;
        };

        class GameError : public Error {
            public:
                GameError(std::string const& msg) : Error(msg) {}
                ~GameError() = default;
        };

        class GraphicalSystemError : public Error {
            public:
                GraphicalSystemError(std::string const& msg) : Error(msg) {}
                ~GraphicalSystemError() = default;
        };

    }

}

#endif /* !ERRORS_HPP_ */
