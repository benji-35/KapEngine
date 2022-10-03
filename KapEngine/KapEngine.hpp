/*
** EPITECH PROJECT, 2022
** engine
** File description:
** KapEngine
*/

#ifndef INCLUDES_KAPENGINE_HPP_
#define INCLUDES_KAPENGINE_HPP_

namespace KapEngine {
    class KapEngine;

    class IComponent;
    class Component;
    class Entity;
    class GameObject;

    class Factory;

    class Debug;
    class PlayerPrefs;

    //components created
    class Camera;
    class Transform;
    class MouseDetector;
    class Animator;
    class Animation;

    namespace Errors {
        class Error;
    }
}

//include basics includes
#ifndef ENGINE_HPP_
    #include "Engine/Engine.hpp"
#endif

#ifndef GAMEOBJECT_HPP_
    #include "GameObject/GameObject.hpp"
#endif

#ifndef COMPONENT_HPP_
    #include "Component/Component.hpp"
#endif

#ifndef ICOMPONENT_HPP_
    #include "Component/IComponent.hpp"
#endif

#ifndef ENTITY_HPP_
    #include "Entity/Entity.hpp"
#endif

#ifndef FACTORY_HPP_
    #include "Engine/Factory.hpp"
#endif

//include statics
#ifndef ERRORS_HPP_
    #include "Errors/Errors.hpp"
#endif

#ifndef DEBUG_HPP_
    #include "Debug/Debug.hpp"
#endif

#ifndef PLAYERPREFS_HPP_
    #include "PlayerPrefs/PlayerPrefs.hpp"
#endif

#ifndef CAMERA_HPP_
    #include "Camera.hpp"
#endif

#ifndef TRANSFORM_HPP_
    #include "Transform.hpp"
#endif

#ifndef MOUSEDETECTOR_HPP_
    #include "MouseDetector.hpp"
#endif

#ifndef ANIMATOR_HPP_
    #include "Animator.hpp"
#endif

#ifndef ANIMATION_HPP_
    #include "Animation.hpp"
#endif

#endif /* !INCLUDES_KAPENGINE_HPP_ */
