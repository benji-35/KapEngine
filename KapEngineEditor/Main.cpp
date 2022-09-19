/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Main
*/

#include <iostream>
#include "KapEngine.hpp"

int main(int ac, char **av) {

    std::string gameName = "\e[33m\n\n██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗    ███████╗██████╗ ██╗████████╗ ██████╗ ██████╗ \n";
                gameName += "██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝    ██╔════╝██╔══██╗██║╚══██╔══╝██╔═══██╗██╔══██╗\n";
                gameName += "█████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗      █████╗  ██║  ██║██║   ██║   ██║   ██║██████╔╝\n";
                gameName += "██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝      ██╔══╝  ██║  ██║██║   ██║   ██║   ██║██╔══██╗\n";
                gameName += "██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗    ███████╗██████╔╝██║   ██║   ╚██████╔╝██║  ██║\n";
                gameName += "╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝    ╚══════╝╚═════╝ ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝\n\e[0m";

    KapEngine::KapEngine engine(true, gameName, "0.0.1", "Benjamin DELVERT");

    engine.run();
}
