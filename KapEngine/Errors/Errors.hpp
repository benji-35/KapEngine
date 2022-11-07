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
#include "Profiler/KapProfiler.hpp"

namespace KapEngine {

    /**
     * @namespace KapEngine::Errors
     * This namespace regroup all errors for KapEngine
     * @brief All errors
     */
    namespace Errors {

        class Error : public virtual std::exception {
            protected:
                std::string _message;
            public:
                explicit Error(std::string const& msg) {
                    PROFILER_FUNC_START();
                    _message = msg;
                    PROFILER_FUNC_END();
                }

                ~Error() = default;

                const char* what() const noexcept override {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                    return _message.c_str();
                }
        };

        class ComponentError : public Error {
            public: 
                ComponentError(std::string const& msg) : Error(msg) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                ~ComponentError() = default;
        };

        class GameObjectError : public Error {
            public:
                GameObjectError(std::string const& msg) : Error(msg) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                ~GameObjectError() = default;
        };

        class EngineError : public Error {
            public:
                EngineError(std::string const& msg) : Error(msg) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                ~EngineError() = default;
        };

        class SceneError : public Error {
            public:
                SceneError(std::string const& msg) : Error(msg) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                ~SceneError() = default;
        };

        class GameError : public Error {
            public:
                GameError(std::string const& msg) : Error(msg) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                ~GameError() = default;
        };

        class GraphicalSystemError : public Error {
            public:
                GraphicalSystemError(std::string const& msg) : Error(msg) {
                    PROFILER_FUNC_START();
                    PROFILER_FUNC_END();
                }
                ~GraphicalSystemError() = default;
        };

    }

}

#endif /* !ERRORS_HPP_ */
