# Create new one

### Prototype

.hpp

```cpp
#include "KapEngine.hpp"

namespace KapEngine {
    namespace MyGame {
        
        class MyComponent : public Component {
            public:
                //constructuer du composant sans préciser son thread
                MyComponent(std::shared_ptr<GameObject> go);
                ~MyComponent();

                /**
                 * Fonctionnalité de base d'un composant
                */

                //appelé lors de l'initialisation du composant (au runtime) deprecated
                void onInit() override;
                //appelé lors du premier chargement de la scène OU quand on charge la scène après qu'une autre scène ai été chargé
                void onAwake() override;
                //appelé à chaque chargement / rechargement de la scène
                void onStart() override;
                //appelé à chaque frame
                void onUpdate() override;
                //appelé à chaque X ms. (X étant le nombre définie par vous dans l'engine. De base X = 25)
                void onFixedUpdate() override;
                //appelé après toutes les fonctions de mise à jour
                void onDisplay() override;

                /**
                 * Fonctionnalité lorsque votre GameObject (objet de jeu) à un composant collider sur lui
                 * 
                 * Attnetion !
                 * Les fonctions suivantes, ne seront pas appelé lors des fonctions mise à jour (au dessus)
                 * ces fonctions peuvent être appelé plus tard ou avant
                */

                //appelé lors du passage de la souris sur l'objet
                void onMouseEnter() override;
                //appelé lorsque la souris reste sur l'objet
                void onMouseStay() override;
                //appelé lors de la sortie de la souris sur l'objet
                void onMouseExit() override;

                //appelé lorsqu'un objet rentre dans l'objet rattaché
                void onTriggerEnter(std::shared_ptr<GameObject> go) override;
                //appelé lorsqu'un objet reste dans l'objet rattaché
                void onTriggerStay(std::shared_ptr<GameObject> go) override;
                //appelé lorsqu'un objet sort dans l'objet rattaché
                void onTriggerExit(std::shared_ptr<GameObject> go) override;
                //ajoutez des conditions au lancement de votre composant
                bool checkComponentValidity() override;
                //appelé lorsque votre objet est détruit
                void onDestroy() override;
                //appelé lorsque le jeu se quitte
                void onGameQuit() override;
                //appelé lorsque le GameObject se désactive
                void onDisable() override;
                //appelé lorsque le GameObject s'active
                void onEnable() override;

        }
        
    }
}
```

.cpp

```cpp
#include "MyComponent.hpp"

KapEngine::MyGame::MyComponent(std::shared_ptr<GameObject> go) : Component(go, "MyComponent") {
    Debug::log("Creating component...");
}

KapEngine::MyGame::~MyComponent() {
    Debug::log("Deleting component...");
}

void KapEngine::MyGame::MyComponent::onAwake() {
    Debug::log("My component awake !");
}

void KapEngine::MyGame::MyComponent::onStart() {
    Debug::log("Starting component !");
}

void KapEngine::MyGame::MyComponent::onUpdate() {
    Debug::log("Update component !");
}

void KapEngine::MyGame::MyComponent::onFixedUpdate() {
    Debug::log("Fixed Update component !");
}

void KapEngine::MyGame::MyComponent::onDisplay() {
    Debug::log("Display component !");
}

void MonComposant::onMouseEnter() {
    Debug::log("Mouse entered in object");
}

void MonComposant::onMouseStay() {
    Debug::log("Mouse stay in object");
}

void KapEngine::MyGame::MyComponent::onMouseExit() {
    Debug::log("Mouse exit object");
}

void KapEngine::MyGame::MyComponent::onTriggerEnter(std::shared_ptr<GameObject> go) {
    Debug::log("The object: " + go->getName() + " entered in my object");
}

void KapEngine::MyGame::MyComponent::onTriggerStay(std::shared_ptr<GameObject> go) {
    Debug::log("The object: " + go->getName() + " stays in my object");
}

void KapEngine::MyGame::MyComponent::onTriggerExit(std::shared_ptr<GameObject> go) {
    Debug::log("The object: " + go->getName() + " comes out of my object");
}

bool KapEngine::MyGame::MyComponent::checkComponentValidity() {
    if (...) {
        //my component should not start
        return false;
    }
    //my component can start
    return true;
}

void KapEngine::MyGame::MyComponent::onDestroy() {
    Debug::log("The object " + getGameObject().getName() + " is destroy");
}

void KapEngine::MyGame::MyComponent::onGameQuit() {
    Debug::log("Game is stopping");
}

void KapEngine::MyGame::MyComponent::onDisable() {
    Debug::log("The object " + getGameObject().getName() + " is now disable");
}

void KapEngine::MyGame::MyComponent::onEnable() {
    Debug::log("The object " + getGameObject().getName() + " is now enable");
}


```
