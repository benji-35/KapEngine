/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GraphicalLib
*/

#include "GraphicalLib.hpp"

KapEngine::Graphical::GraphicalLib::GraphicalLib(std::string const& name, GraphicalLibManager &manager) : manager(manager)
{
    PROFILER_FUNC_START();
    _name = name;
    PROFILER_FUNC_END();
}

KapEngine::Graphical::GraphicalLib::~GraphicalLib()
{
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::Graphical::GraphicalLib::clear() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::Graphical::GraphicalLib::getEvents() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
}

void KapEngine::Graphical::GraphicalLib::display() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();

}

KapEngine::Tools::Vector2 KapEngine::Graphical::GraphicalLib::getScreenSize() {
    PROFILER_FUNC_START();
    PROFILER_FUNC_END();
    return manager.getEngine().getScreenSize();
}
