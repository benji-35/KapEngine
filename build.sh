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

#definitions

BUILD_EXISTS = 0

libKapExists() {
    BUILD_EXISTS=0
    if [ -f "libKapEngine.so" ]
    then
        BUILD_EXISTS=1
    fi
}

buildEngine() {
    libKapExists
    if [ $BUILD_EXISTS -eq 0 ]
    then
        read -p "[KAP ENGINE] Do you want to build KapEngine (engine) ? (Y/N) ? " confirm
        if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
        then
            echo -e "[KAP ENGINE]\e[0m Building engine...\e[0m"
            make -C KapEngine
            if [ $? -eq 0 ]
            then
                echo -e "\e[92m[KAP ENGINE]\e[0m Engine built !"
            else
                echo -e "\e[1;5;91m[KAP ENGINE]\e[0m Failled to build\e[0m"
                exit 1
            fi
        else
            return
        fi
    else
        read -p "[KAP ENGINE] Do you want to rebuild KapEngine (engine) ? (Y/N) ? " confirm
        if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
        then
            echo -e "[KAP ENGINE]\e[0m Rebuilding engine...\e[0m"
            make re -C KapEngine
            if [ $? -eq 0 ]
            then
            BUILD_EXISTS = 0
                echo -e "\e[92m[KAP ENGINE]\e[0m Engine rebuilt !"
            else
                echo -e "\e[1;5;91m[KAP ENGINE]\e[0m Failled to rebuild\e[0m"
                exit 1
            fi
        else
            read -p "[KAP ENGINE] Do you want to delete KapEngine (engine) ? (Y/N) ? " confirm
            if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
            then
                make fclean -C KapEngine
                return
            fi
        fi
    fi
    if [ $BUILD_EXISTS -eq 0 ]
    then
        buildEditor
    fi
    buildGame
}

buildEditor() {
    read -p "[KAP ENGINE] Build UI Editor ? (Y/N) ? " confirm
    if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
        then
            echo -e "\e[92m[KAP ENGINE]\e[0m let's build the editor...\e[0m"
    fi
}

buildGame() {
    read -p "[KAP ENGINE] Delete Game ? (Y/N) " confirm
    if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
    then
        make fclean -C KapEngineGame
    fi
    read -p "[KAP ENGINE] Build Game ? (Y/N) " confirm
    if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
        then
            make -C KapEngineGame
            if [ $? -eq 0 ]
            then
                echo -e "\e[92m[KAP ENGINE]\e[0m Game built !"
            else
                echo -e "\e[1;5;91m[KAP ENGINE]\e[0m Failled to build\e[0m"
                exit 1
            fi
    fi
}

#actions

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
buildEngine
echo -e "All done."
