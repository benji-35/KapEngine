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

    namespace Tools {
        class Vector2;
        class Vector3;
        class Color;
        class Rectangle;
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

#ifndef INCLUDES_KAPENGINE_DEBUG_HPP_
    #include "KapEngineDebug.hpp"
#endif

#ifndef PLAYERPREFS_HPP_
    #include "PlayerPrefs/PlayerPrefs.hpp"
#endif

#ifndef CAMERA_HPP_
    #include "Components/Camera/Camera.hpp"
#endif

#ifndef TRANSFORM_HPP_
    #include "Components/Transform/Transform.hpp"
#endif

#ifndef MOUSEDETECTOR_HPP_
    #include "Components/MouseDetector/MouseDetector.hpp"
#endif

#ifndef ANIMATOR_HPP_
    #include "Components/Animator/Animator.hpp"
#endif

#ifndef ANIMATION_HPP_
    #include "Components/Animation/Animation.hpp"
#endif

#ifndef COLORS_HPP_
    #include "Tools/Colors.hpp"
#endif

#ifndef RECTANGLE_HPP_
    #include "Tools/Rectangle.hpp"
#endif

#ifndef VECTORS_HPP_
    #include "Tools/Vectors.hpp"
#endif

#endif /* !INCLUDES_KAPENGINE_HPP_ */
