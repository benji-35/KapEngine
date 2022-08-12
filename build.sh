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
BUILD_EXISTS_BIN = 0
BUILD_EXISTS_BIN_SF = 0
LIB_SF_FILE_EXISTS = 0

# functions

libKapExists() {
    BUILD_EXISTS=0
    if [ -f "libKapEngine.so" ]
    then
        BUILD_EXISTS=1
    fi
}

libKapExistsBin() {
    BUILD_EXISTS_BIN=0
    if [ -f "/usr/lib/libKapEngine.so" ]
    then
        BUILD_EXISTS_BIN=1
    fi
}

lib64Exists() {
    LIB_SF_FILE_EXISTS=0
    if [ -d "/usr/lib64" ]
    then
        LIB_SF_FILE_EXISTS=1
    fi
}

libKapExistsBin64() {
    BUILD_EXISTS_BIN_SF=0
    lib64Exists
    if [ $LIB_SF_FILE_EXISTS -eq 0 ]
    then
        return
    fi
    if [ -f "/usr/lib64/libKapEngine.so" ]
    then
        BUILD_EXISTS_BIN_SF=1
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
                copyEngineToBin
            else
                echo -e "\e[1;5;91m[KAP ENGINE]\e[0m Failled to build\e[0m"
                exit 1
            fi
        else
            read -p "[KAP ENGINE] Do you want to delete your Game ? (Y/N) ? " confirm
            if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
            then
                make fclean -C KapEngineGame
            fi
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
            BUILD_EXISTS=0
                echo -e "\e[92m[KAP ENGINE]\e[0m Engine rebuilt !"
                copyEngineToBin
            else
                echo -e "\e[1;5;91m[KAP ENGINE]\e[0m Failled to rebuild\e[0m"
                exit 1
            fi
        else
            read -p "[KAP ENGINE] Do you want to delete KapEngine (engine) ? (Y/N) ? " confirm
            if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
            then
                make fclean -C KapEngine
                read -p "[KAP ENGINE] Do you want to delete your Game ? (Y/N) ? " confirm
                if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
                then
                    make fclean -C KapEngineGame
                fi
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

copyEngineToBin() {
    lib64Exists
    libKapExistsBin

    if [ $LIB_SF_FILE_EXISTS -eq 1 ]
    then
        libKapExistsBin64
        if [ $BUILD_EXISTS_BIN_SF -eq 1 ]
        then
            read -p "[KAP ENGINE] Do you want to delete existing KapEngine in /usr/lib64/ ? (Y/N) " confirm
            if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
            then
                sudo rm /usr/lib64/libKapEngine.so
            else
                return
            fi
        fi
        read -p "[KAP ENGINE] Do you want to copy KapEngine library to your /usr/lib64/ ? (Y/N) ? " confirm
        if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
        then
            sudo cp libKapEngine.so /usr/lib64
        fi
        return
    fi

    if [ $BUILD_EXISTS_BIN -eq 1 ]
    then
        read -p "[KAP ENGINE] Do you want to delete existing KapEngine in /usr/lib/ ? (Y/N) " confirm
        if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
        then
            sudo rm /usr/lib/libKapEngine.so
        else
            return
        fi
    fi
    read -p "[KAP ENGINE] Do you want to copy KapEngine library to your /usr/lib/ ? (Y/N) ? " confirm
    if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]
    then
        sudo cp libKapEngine.so /usr/lib
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
