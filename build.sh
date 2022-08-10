#!/bin/sh
## ██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
## ██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
## █████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗  
## ██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝  
## ██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
## ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
##
## by Benjamin DELVERT
## Do not touch this file

BUILD_EDITOR=0
BUILD_GAME=0

clear

echo -e "\e[33m"
echo -e " ██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗"
echo -e " ██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝"
echo -e " █████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗  "
echo -e " ██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝  "
echo -e " ██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗"
echo -e " ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝"
echo -e "\e[0m"
echo -e "\e[32mby Benjamin DELVERT\e[0m"
echo -e ""

read -p "[KAP ENGINE] Re build Engine ? (Y/N) ? " confirm

#Build Engine
if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
then
    echo -e "[KAP ENGINE]\e[0mBuilding engine...\e[0m"
    make re -C KapEngine
    if [ $? -eq 0 ]
    then
        echo -e "\e[92m[KAP ENGINE]\e[0m Engine built !"
    else
        echo -e "\e[1;5;91m[KAP ENGINE]\e[0mFailled to build\e[0m"
        exit 1
    fi
else
    read -p "[KAP ENGINE] Keep current version ? (Y/N) " confirm
    if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
    then
        read -p "[KAP ENGINE] Clear engine built ? (Y/N) " confirm
        if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
        then
            make fclean -C KapEngine
            if [ $? -eq 0 ]
            then
                echo -e "\e[92m[KAP ENGINE]\e[0m Engine built clear !"
                echo -e "[KAP ENGINE] stop build script."
                exit 0
            else
                echo -e "\e[1;5;91m[KAP ENGINE]\e[0mFailled to clear build\e[0m"
                exit 1
            fi
            
        fi
        echo -e "\e[31m[KAP ENGINE]\e[0m skip engine step"
    else
        echo -e "[KAP ENGINE]\e[0mBuilding engine...\e[0m"
        make -C KapEngine
        if [ $? -eq 0 ]
        then
            echo -e "\e[92m[KAP ENGINE]\e[0m Engine built !"
        else
            echo -e "\e[1;5;91m[KAP ENGINE]\e[0mFailled to build\e[0m"
            exit 1
        fi
    fi
fi

#Build editor
read -p "[KAP ENGINE] Build UI Editor ? (Y/N) ? " confirm
if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
    then
        echo -e "\e[92m[KAP ENGINE]\e[0m let's build the editor...\e[0m"
    else
        echo -e "\e[31m[KAP ENGINE]\e[0m Skip editor build\e[0m"
fi

#Build game
read -p "[KAP ENGINE] Build Game ? (Y/N) ? " confirm
if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
    then
        make -C KapEngineGame
        if [ $? -eq 0 ]
        then
            echo -e "\e[92m[KAP ENGINE]\e[0m Game built !"
        else
            echo -e "\e[1;5;91m[KAP ENGINE]\e[0mFailled to build\e[0m"
            exit 1
        fi
    else
        echo -e "\e[31m[KAP ENGINE]\e[0m Skip game build\e[0m"
fi

echo -e "All done."
