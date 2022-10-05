/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** GraphicalLib
*/

#include "GraphicalLib.hpp"

KapEngine::Graphical::GraphicalLib::GraphicalLib(std::string const& name, GraphicalLibManager &manager) : manager(manager)
{
    _name = name;
}

KapEngine::Graphical::GraphicalLib::~GraphicalLib()
{
}

void KapEngine::Graphical::GraphicalLib::clear() {

}

void KapEngine::Graphical::GraphicalLib::getEvents() {

}

void KapEngine::Graphical::GraphicalLib::display() {

}

KapEngine::Tools::Vector2 KapEngine::Graphical::GraphicalLib::getScreenSize() {
    return manager.getEngine().getScreenSize();
}
