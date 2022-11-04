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
}

KapEngine::Graphical::LegacyGraphicalLib::~LegacyGraphicalLib() {}

void KapEngine::Graphical::LegacyGraphicalLib::display() {
    std::cout << "> ";
    std::string _cmd;
    try {
        if (std::getline(std::cin, _cmd)) {
            executeCommand(_cmd);
        } else {
            exit(0);
        }
    } catch (Errors::EngineError e) {
        DEBUG_WARNING(e.what());
    }
}

void KapEngine::Graphical::LegacyGraphicalLib::executeCommand(std::string const& cmd) {
    if (cmd == "")
        return;
    if (commandExists(cmd)) {
        _commands.at(cmd)();
        return;
    }
    throw Errors::EngineError("Command \"" + cmd + "\" not found");
}

bool KapEngine::Graphical::LegacyGraphicalLib::commandExists(std::string const& cmd) {
    try {
        std::map<std::string, std::function<void()>>::iterator it;
        it = this->_commands.find(cmd);
        if (it != this->_commands.end()) {
            return true;
        } else {
            return false;
        }
    } catch (...) {
        return false;
    }
}

void KapEngine::Graphical::LegacyGraphicalLib::registerCommand(std::string const& cmd, std::function<void()> func) {
    if (commandExists(cmd)) {
        throw Errors::EngineError("Already registered command");
        return;
    }
    _commands.insert( std::pair<std::string, std::function<void()>>(cmd, func));
}
