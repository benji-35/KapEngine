/*
** EPITECH PROJECT, 2022
** engine
** File description:
** KapEngineEvents
*/

#ifndef INCLUDES_KAPENGINEEVENTS_HPP_
#define INCLUDES_KAPENGINEEVENTS_HPP_

namespace KapEngine {
    namespace Events {
        class Mouse;
        class Input;
        class Key;
        class EventManager;
    }
}

#ifndef EVENTACTION_HPP_
    #include "Events/Action/EventAction.hpp"
#endif

#ifndef INPUT_HPP_
    #include "Events/Input/Input.hpp"
#endif

#ifndef KEY_HPP_
    #include "Events/Input/Key.hpp"
#endif

#ifndef EVENTMANAGER_HPP_
    #include "Events/Manager/EventManager.hpp"
#endif

#ifndef MOUSE_HPP_
    #include "Events/Mouse/Mouse.hpp"
#endif

#endif /* !INCLUDES_KAPENGINEEVENTS_HPP_ */
