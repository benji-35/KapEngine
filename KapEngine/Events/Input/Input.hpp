/*
** EPITECH PROJECT, 2022
** cpp_sfmlV2
** File description:
** Input
*/

/**
* @file Input.hpp
* fichier contenant les fonctions permettant la prise d'information sur les inputs
* @author Benjamin Delvert
* @date 2022
* @version 1.0
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <vector>
#include "Key.hpp"
#include "EventManager.hpp"

namespace KapEngine {
    namespace Events {
        class Key;
        class EventManager;
    }
}

namespace KapEngine {
    namespace Events
    {
        /**
         * @class Input
         * Input permet de connaître les actions des touches pendant le run du jeu
         * @brief Ations des touches
         */
        class Input {
            public:

                /**
                 * @brief donne le mode de detection dun axe
                 * 
                 */
                enum AxisDetectMode {
                    UNKNOWN,
                    GET,
                    DOWN,
                    UP
                };

                /**
                 * @struct Axis
                 * un Axe permet d'avoir un combiné de touches assignées pour une même action résultant une valeur comprise entre -1 et 1
                 * @brief 
                 * @param name nom de l'axe
                 * @param positiveButton input permettant d'obtenir la valeur 1
                 * @param altPositiveButton input alternatif permettant d'obtenir la valeur 1
                 * @param negativeButton input permettant d'obtenir la valeur -1
                 * @param altNegativeButton input alternatif permettant d'obtenir la valeur -1
                 * @param joystickId index du joystick d'un gamepad (si celui ci reste sur -1, aucun joystick ne sera assigné)
                 * @param gamepadId index du gamepad. Si un joystick est définit mais que le gamepad reste à -1, alors l'axe vérifiera tous les gamepads (les 2 gamepads)
                 * @param invert permet d'inverser le résultat (-1 -> 1, 1 -> -1)
                 */
                struct Axis {
                    std::string name;
                    Key positiveButton;
                    Key negativeButton;
                    Key altPositiveButton;
                    Key altNegativeButton;

                    AxisDetectMode detectMode;

                    int joystickId;
                    int gamepadId;

                    bool invert;

                    Axis(std::string _name) {
                        gamepadId = -1;
                        joystickId = -1;
                        positiveButton = Key::UNKNOWN;
                        negativeButton = Key::UNKNOWN;
                        altPositiveButton = Key::UNKNOWN;
                        altNegativeButton = Key::UNKNOWN;
                        invert = false;
                        name = _name;
                        detectMode = AxisDetectMode::GET;
                    }
                };

                Input(EventManager &manager);
                ~Input() {}

                /**
                 * @fn void __update()
                 * @brief mettre à jour les touches
                 * @warning ne pas utiliser. Seul l'engine doit l'utiliser
                 */
                void __update();

                /**
                 * @fn bool getKey(Key::EKey key)
                 * savoir si une action a été faite sur la touche demandée
                 * @brief action sur une touche
                 * @param key Key::Ekey (enum) touche
                 * @retval true si une action a été faite sur la touche
                 * @retval false si aucune action n'a été faite sur la touche
                 */
                bool getKey(Key::EKey key);
                /**
                 * @fn bool getKeyDown(Key::EKey key)
                 * savoir si la touche a été appuyée
                 * @brief appuie sur la touche
                 * @param key Key::Ekey (enum) touche
                 * @retval true si la touche a été appuyée
                 * @retval false si la touche n'a pas été appuyée
                 */
                bool getKeyDown(Key::EKey key);
                /**
                 * @fn bool getKeyUp(Key::EKey key)
                 * savoir si la touche a été relachée
                 * @brief relachement de la touche
                 * @param key Key::Ekey (enum) touche
                 * @retval true si la touche a été relachée
                 * @retval false si la touche n'a pas été relachée
                 */
                bool getKeyUp(Key::EKey key);

                /**
                 * @fn bool getKey(Key key)
                 * savoir si une action a été faite sur la touche demandée
                 * @brief action sur une touche
                 * @param key Key (calss) touche
                 * @retval true si une action a été faite sur la touche
                 * @retval false si aucune action n'a été faite sur la touche
                 */
                bool getKey(Key key);
                /**
                 * @fn bool getKeyDown(Key key)
                 * savoir si la touche a été appuyée
                 * @brief appuie sur la touche
                 * @param key Key (class) touche
                 * @retval true si la touche a été appuyée
                 * @retval false si la touche n'a pas été appuyée
                 */
                bool getKeyDown(Key key);
                /**
                 * @fn bool getKeyUp(Key key)
                 * savoir si la touche a été relachée
                 * @brief relachement de la touche
                 * @param key Key (class) touche
                 * @retval true si la touche a été relachée
                 * @retval false si la touche n'a pas été relachée
                 */
                bool getKeyUp(Key key);
                /**
                 * @fn float getAxis(std::string name)
                 * cette fonction permet d'avoir un système plus avancé de touche permettant d'avoir une valeur (float entre -1 et 1) selon les touches appuyées
                 * @brief avoir la valeur de l'axe
                 * 
                 * @param name nom de l'axe souhaité
                 * @return float (entre 1 et -1)
                 */
                float getAxis(std::string name);

                /**
                 * @fn void addAxis(std::string name)
                 * ajoute un nouvel axe vide
                 * @brief ajouter un nouvel axe
                 * @param name name de l'axe
                 */
                void addAxis(std::string name) {
                    _axises.push_back(Axis(name));
                }

                /**
                 * @fn void addAxis(Axis const& axis)
                 * ajoute un nouvel axe que vous aurez défini
                 * @brief ajouter un nouvel axe
                 * @param axis axe prédéfini
                 */
                void addAxis(Axis const& axis) {
                    _axises.push_back(axis);
                }

                Axis &getAxisSettings(std::string const& name) {
                    for (std::size_t i = 0; i < _axises.size(); i++) {
                        if (_axises[i].name == name)
                            return _axises[i];
                    }
                    throw Errors::EngineError("Axis \"" + name + "\" not found");
                }

            protected:
            private:
                bool _pressed = false;
                bool _realesed = false;
                EventManager &_manager;

                std::vector<Key> _justInputs;
                std::vector<Key> _inputs;
                std::vector<Key> _outInputs;

                std::vector<Axis> _axises;
        };
    }
}

#endif /* !INPUT_HPP_ */
