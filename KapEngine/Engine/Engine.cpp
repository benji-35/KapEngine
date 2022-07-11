/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Engine
*/

#include "Engine.hpp"

KapEngine::KapEngine::KapEngine(bool debug, std::string const& gameName, std::string const& version, std::string const& company) {
    _debug = debug;
    _gameName = gameName;
    _gameVersion = version;
    _gameCompany = company;

    _sceneManager = std::make_shared<SceneManagement::SceneManager>(*this);
}

KapEngine::KapEngine::~KapEngine()
{
}

void KapEngine::KapEngine::run() {
    _run = true;

    while (_run) {

    }
}

void KapEngine::KapEngine::stop() {
    _run = false;
}
