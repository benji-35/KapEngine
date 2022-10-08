/*
** EPITECH PROJECT, 2022
** engine
** File description:
** PlayerPrefs
*/

#ifndef PLAYERPREFS_HPP_
#define PLAYERPREFS_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "KapEngineDebug.hpp"

namespace KapEngine {

    /**
     * @class PlayerPref
     * Le playerPref permet de sauvegarder dans un fichier des informations au runtime rapidement.
     * @brief sauvegarde d'infos
     */
    class PlayerPrefs {
        public:
            struct PlayerPrefIntel {
                std::string key;
                std::string content;
            };
            

            /**
             * @fn static void setBool(std::string name, bool val)
             * Enregistrer un préférence du joueur sous forme booléenne
             * @brief Enregistrer une bool
             * @param name nom de la préférence
             * @param val valeur de la préférence (bool)
             */
            static void setBool(std::string const& name, bool const& val) {
                if (val) {
                    setString(name, "true");
                } else {
                    setString(name, "false");
                }
            }

            /**
             * @fn static void setInt(std::string name, int val)
             * Enregistrer un préférence du joueur sous forme int
             * @brief Enregistrer une int
             * @param name nom de la préférence
             * @param val valeur de la préférence (int)
             */
            static void setInt(std::string const& name, int const& val) {
                setString(name, std::to_string(val));
            }
            
            /**
             * @fn static void setString(std::string name, std::string val)
             * Enregistrer un préférence du joueur sous forme std::string
             * @brief Enregistrer une std::string
             * @param name nom de la préférence
             * @param val valeur de la préférence (std::string)
             */
            static void setString(std::string const& name, std::string const& val) {
                std::vector<PlayerPrefIntel> intels = readPlayerPref();
                bool newVal = true;

                for (std::size_t i = 0; i < intels.size(); i++) {
                    if (intels.at(i).key == name) {
                        intels.at(i).content = val;
                        newVal = false;
                        break;
                    }
                }
                if (!newVal) {
                    writePlayerPrefs(intels);
                    return;
                }
                PlayerPrefIntel nIntel;
                nIntel.content = val;
                nIntel.key = name;
                intels.push_back(nIntel);
                writePlayerPrefs(intels);
            }

            /**
             * @fn static std::string getString(std::string const& name)
             * récupérer la valeur de name depuis les préférences sous le format string
             * @brief avoir la valeur string
             * 
             * @param name nom de la préférence
             * @return std::string 
             */
            static std::string getString(std::string const& name) {
                std::vector<PlayerPrefIntel> intels = readPlayerPref();

                for (std::size_t i = 0; i < intels.size(); i++) {
                    if (name == intels.at(i).key)
                        return intels.at(i).content;
                }
                DEBUG_ERROR("no content with key: " + name);
                return "";
            }

            /**
             * @fn static int getInt(std::string const& name)
             * récupérer la valeur de name depuis les préférences sous le format int
             * @brief avoir la valeur int
             * 
             * @param name nom de la préférence
             * @return int 
             */
            static int getInt(std::string const& name) {
                std::stringstream sstr;
                std::string str = getString(name);
                int res = 0;

                sstr << str;
                sstr >> res;

                return res;

            }

            /**
             * @fn static bool getBool(std::string const& name)
             * récupérer la valeur de name depuis les préférences sous le format bool
             * @brief avoir la valeur bool
             * 
             * @param name nom de la préférence
             * @return bool 
             */
            static bool getBool(std::string const& name) {
                std::string strVal = getString(name);

                if (strVal == "true" || strVal == "1")
                    return true;
                return false;
            }

        protected:
        private:

            inline static const std::string filePlayerPrefName = "playerPrefs.keDat";
            
            static std::vector<PlayerPrefIntel> readPlayerPref() {
                std::string line;
                std::ifstream myfile (filePlayerPrefName);
                std::vector<std::string> lines;
                std::vector<PlayerPrefIntel> res;
                if (myfile.is_open())
                {
                    while ( getline (myfile,line) ) {
                        lines.push_back(line);
                    }
                    myfile.close();
                } else {
                    DEBUG_ERROR("PlayerPref file does not exists. Please save something with PlayerPref to create this file");
                    return res;
                }

                for (std::size_t i = 0; i < lines.size(); i++) {
                    std::size_t posEqu = lines.at(i).find(":");
                    PlayerPrefIntel nIntel;

                    nIntel.key = lines.at(i).substr(0, posEqu);
                    nIntel.content = lines.at(i).substr(posEqu + 1, lines.at(i).size());
                    res.push_back(nIntel);
                }
                return res;
            }

            static void writePlayerPrefs(std::vector<PlayerPrefIntel> const& list) {
                std::ofstream myfile;
                std::string content = "";

                for (std::size_t i = 0; i < list.size(); i++) {
                    std::string lineCont;

                    lineCont = list.at(i).key + ":" + list.at(i).content;
                    if (i < list.size() - 1) {
                        lineCont += "\n";
                    }
                    content += lineCont;
                }

                myfile.open (filePlayerPrefName);
                if (!myfile.is_open()) {
                    DEBUG_ERROR("PlayerPrefs can't save anything. File does not open");
                    return;
                }
                myfile << content;
                myfile.close();
            }
    };

}

#endif /* !PLAYERPREFS_HPP_ */
