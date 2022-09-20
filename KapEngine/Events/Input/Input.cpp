/*
** EPITECH PROJECT, 2022
** cpp_sfmlV2
** File description:
** Input
*/

#include "Input.hpp"

KapEngine::Events::Input::Input(EventManager &manager) : _manager(manager) {}

void KapEngine::Events::Input::__update() {
    if (!_manager.getEngine().isGraphicalLibExists(_manager.getEngine().getCurrentGraphicalLibIndex()))
        return;
    _inputs = _manager.getEngine().getCurrentGraphicalLib()->getLatsKey();
    _justInputs = _manager.getEngine().getCurrentGraphicalLib()->getKeysPressed();
    _outInputs = _manager.getEngine().getCurrentGraphicalLib()->getKeysReleased();
}

bool KapEngine::Events::Input::getKey(Key::EKey key) {
    if (key == Events::Key::UNKNOWN)
        return false;
    for (std::size_t i = 0; i < _inputs.size(); i++) {
        if (_inputs.at(i) == key)
            return true;
    }
    for (std::size_t i = 0; i < _justInputs.size(); i++) {
        if (_justInputs.at(i) == key)
            return true;
    }
    return false;
}

bool KapEngine::Events::Input::getKeyDown(Key::EKey key) {
    if (key == Events::Key::UNKNOWN)
        return false;
    for (std::size_t i = 0; i < _justInputs.size(); i++) {
        if (_justInputs.at(i) == key)
            return true;
    }
    return false;
}

bool KapEngine::Events::Input::getKeyUp(Key::EKey key) {
    if (key == Events::Key::UNKNOWN)
        return false;
    for (std::size_t i = 0; i < _outInputs.size(); i++) {
        if (_outInputs.at(i) == key)
            return true;
    }
    return false;
}

bool KapEngine::Events::Input::getKey(Key key) {
    if (key == Events::Key::UNKNOWN)
        return false;
    if (getKeyDown(key))
        return true;
    for (std::size_t i = 0; i < _inputs.size(); i++) {
        if (_inputs.at(i) == key)
            return true;
    }
    return false;
}

bool KapEngine::Events::Input::getKeyDown(Key key) {
    return getKeyDown(key.get());
}

bool KapEngine::Events::Input::getKeyUp(Key key) {
    return getKeyUp(key.get());
}

float KapEngine::Events::Input::getAxis(std::string name) {
    float res = 0.0f;
    for (std::size_t i = 0; i < _axises.size(); i++) {
        if (_axises.at(i).name == name) {
            Axis axis = _axises.at(i);

            if (axis.detectMode == AxisDetectMode::GET && (getKey(axis.positiveButton) || getKey(axis.altPositiveButton))) {
                res += 1.0f;
            } else if (axis.detectMode == AxisDetectMode::DOWN && (getKeyDown(axis.positiveButton) || getKeyDown(axis.altPositiveButton))) {
                res += 1.0f;
            } else if (axis.detectMode == AxisDetectMode::UP && (getKeyUp(axis.positiveButton) || getKeyUp(axis.altPositiveButton))) {
                res += 1.0f;
            }

            if (axis.detectMode == AxisDetectMode::GET && (getKey(axis.negativeButton) || getKey(axis.altNegativeButton))) {
                res -= 1.0f;
            } else if (axis.detectMode == AxisDetectMode::DOWN && (getKeyDown(axis.negativeButton) || getKeyDown(axis.altNegativeButton))) {
                res -= 1.0f;
            } else if (axis.detectMode == AxisDetectMode::UP && (getKeyUp(axis.negativeButton) || getKeyUp(axis.altNegativeButton))) {
                res -= 1.0f;
            }

            if (res == 0.0f && axis.joystickId >= 0) {
                if (axis.gamepadId >= 0) {
                    res = _manager.getEngine().getCurrentGraphicalLib()->getJoystikValue(axis.gamepadId, axis.joystickId);
                } else {
                    res = _manager.getEngine().getCurrentGraphicalLib()->getJoystikValue(0, axis.joystickId);
                    if (res == 0.0f)
                        res = _manager.getEngine().getCurrentGraphicalLib()->getJoystikValue(1, axis.joystickId);
                }
            }

            if (axis.invert)
                res *= -1.f;
            break;
        }
    }
    return res;
}
