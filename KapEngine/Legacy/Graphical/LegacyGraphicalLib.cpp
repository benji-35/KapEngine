/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** LegacyGraphicalLib
*/

#include "LegacyGraphicalLib.hpp"
#include "KapEngine.hpp"
#include <iostream>

KapEngine::Graphical::LegacyGraphicalLib::LegacyGraphicalLib(GraphicalLibManager &manager) : GraphicalLib("Legacy", manager) {
    PROFILER_FUNC_START();
    registerCommand("exit", [this](){
        this->manager.getEngine().stop();
    });
    registerCommand("next", [this](){
        DEBUG_LOG("next Graphical Library");
    });
    registerCommand("previous", [this](){
        DEBUG_LOG("previous Graphical Library");
    });
    registerCommand("dump", [this](){
        DEBUG_LOG("Dump scene");
    });
    registerCommand("intel", [this](){
        DEBUG_LOG("Game intel:");
        DEBUG_LOG("Game name: " + this->manager.getEngine().getGameName());
        DEBUG_LOG("Version: " + this->manager.getEngine().getGameVersion());
        DEBUG_LOG("Company: " + this->manager.getEngine().getGameCompany());
    });
    registerCommand("help", [this](){
        DEBUG_LOG("Helper");
    });
    PROFILER_FUNC_END();
}

KapEngine::Graphical::LegacyGraphicalLib::~LegacyGraphicalLib() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::Graphical::LegacyGraphicalLib::display() {
    PROFILER_FUNC_START();
    std::cout << "> ";
    std::string _cmd;
    try {
        if (std::getline(std::cin, _cmd)) {
            executeCommand(_cmd);
        } else {
            exit(0);
        }
        PROFILER_FUNC_END();
    } catch (Errors::EngineError e) {
        DEBUG_WARNING(e.what());
        PROFILER_FUNC_END();
    }
}

void KapEngine::Graphical::LegacyGraphicalLib::executeCommand(std::string const& cmd) {
    PROFILER_FUNC_START();
    if (cmd == "") {
        PROFILER_FUNC_END();
        return;
    }
    if (commandExists(cmd)) {
        _commands.at(cmd)();
        PROFILER_FUNC_END();
        return;
    }
    PROFILER_FUNC_END();
    throw Errors::EngineError("Command \"" + cmd + "\" not found");
}

bool KapEngine::Graphical::LegacyGraphicalLib::commandExists(std::string const& cmd) {
    PROFILER_FUNC_START();
    try {
        std::map<std::string, std::function<void()>>::iterator it;
        it = this->_commands.find(cmd);
        if (it != this->_commands.end()) {
            PROFILER_FUNC_END();
            return true;
        } else {
            PROFILER_FUNC_END();
            return false;
        }
    } catch (...) {
        PROFILER_FUNC_END();
        return false;
    }
}

void KapEngine::Graphical::LegacyGraphicalLib::registerCommand(std::string const& cmd, std::function<void()> func) {
    PROFILER_FUNC_START();
    if (commandExists(cmd)) {
        PROFILER_FUNC_END();
        throw Errors::EngineError("Already registered command");
        return;
    }
    _commands.insert( std::pair<std::string, std::function<void()>>(cmd, func));
    PROFILER_FUNC_END();
}
