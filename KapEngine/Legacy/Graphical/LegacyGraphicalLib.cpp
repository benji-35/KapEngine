/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** LegacyGraphicalLib
*/

#include "LegacyGraphicalLib.hpp"
#include "Debug.hpp"
#include <iostream>

KapEngine::Graphical::LegacyGraphicalLib::LegacyGraphicalLib(GraphicalLibManager &manager) : GraphicalLib("Legacy", manager) {
    registerCommand("exit", [this](){
        this->manager.getEngine().stop();
    });
    registerCommand("next", [this](){
        Debug::log("next Graphical Library");
    });
    registerCommand("previous", [this](){
        Debug::log("previous Graphical Library");
    });
    registerCommand("dump", [this](){
        Debug::log("Dump scene");
    });
    registerCommand("intel", [this](){
        Debug::log("Game intel:");
        Debug::log("Game name: " + this->manager.getEngine().getGameName());
        Debug::log("Version: " + this->manager.getEngine().getGameVersion());
        Debug::log("Company: " + this->manager.getEngine().getGameCompany());
    });
    registerCommand("help", [this](){
        Debug::log("Helper");
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
        Debug::warning(e.what());
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
