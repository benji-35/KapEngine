```
██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
█████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗  
██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝  
██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
                                                                        
par Benjamin DELVERT
```

# Créer ton composant

Sur cette page tu vas apprendre qu'est ce qu'un KapEngine::Component, pourquoi il existse et comment en créer un.

## Table des matières
| Titre                     | Lien                           | Statut         |
|---------------------------|--------------------------------|----------------|
| Qu'est ce qu'un composant | [GO](#Quest-ce-quun-composant) | :green_circle: |
| Créer le sien             | [GO](#Créer-le-sien)           | :large_orange_diamond:   |
| Démarrage Rapide          | [GO](#Démarrage-rapide)        | :green_circle: |

## Qu'est ce qu'un composant

Un composant est un script rattaché à un objet de jeu (KapEngine::GameObject). Il a pour but de donner une logique ou une action à votre objet.

Certaines fonctions seront automatiquement appelées par KapEngine ce qui permet une autonomisation du fonctionnement de votre jeu une fois lancé.


:warning: le KapEngine est un engine multi thread. Ce qui signifie que le jeu utilisera plusieurs coeur de votre ordinateur pour effectuer des calculs plus rapides. Les composants sont appelés sur les thread suivant : 2, 3, 4. Lors de la création de vos composants, vous pouvez définir sur quel thread votre composant tournera. Si vous définissez un autre "threadID" que ceux indiqué juste avant, votre composant ne sera jamais lu.

Cette méthode de calcul vous permet d'avoir un jeu plus performant. Cependant il se peut que vous ayez des réécriute de valeur. Ce sera à vous d'y faire attention.

## Créer le sien

Créer un composant est très simple. Vous devez créer un nouveau fichier .hpp. Ce fichier contiendra la classe de votre composant : [exemple](#Démarrage-rapide). Une fois que vous aurez créé ce composant, il fous suffira de l'ajouter sur un objet.

Exemple:
```C++

int main() {
    /*
        On suppose que vous aurez déjà initilisé l'engine et certaines scene.
    
        La variable scene ici contiendra une scène déjà initialisée
    */

    //sur cette ligne vous demandez à l'engine de créer un objet de votre scene
    std::shared_ptr<GameObject> monObjet = KapEngine::Factory::createEmptyGameObject(scene, "Le nom de mon objet");

    //sur cette ligne vous demandez de la mémoire pour votre nouveau composant
    std::make_shared<MonComposant> monComposant = std::make_shared<MonComposant>(monObjet);
    
    //sur cette ligne vous ajouté le composant à l'objet
    monObjet->addComponent(monComposant);
}

```
Ces étapes sont obligatoires pour pouvoir ajouter un composant à un objet.

:warning: Il est primordiale de ne pas mélanger les GameObjects pour le composant. L'objet dans lequel vous ajouté le composant doit être le même objet qui se trouve dans le constructeur du composant comme dans l'exemple.

### Liste des fonctions disponibles

#### onInit
Cette fonction est appelée lors de l'initialisation du composant au runtime.

## Démarrage Rapide 

```C++

//déclaration de ce que l'on a besoin d'inclure

#include "Component"

namespace KapEngine {
    class Component;
}

// définition de ton nouveau composant

namespace KapEngine {

    namespace MonJeu {

        class MonComposant : public Component {
            public:
                //constructeur du composant avec l'id de son thread
                MonComposant(std::shared_ptr<GameObject> go, int threadId);
                //constructuer du composant sans préciser son thread
                MonComposant(std::shared_ptr<GameObject> go);
                ~MonComposant();

                /**
                 * Fonctionnalité de base d'un composant
                */

                //appelé lors de l'initialisation du composant (au runtime)
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

        }

        MonComposant(std::shared_ptr<GameObject> go, int threadId) : Component(go, "Nom du composant", threadId) {
            Debug::log("Suppression du composant au thread " + std::to_string(threadId) + " !");
        }

        MonComposant(std::shared_ptr<GameObject> go) : Component(go, "Nom du composant") {
            Debug::log("Création du composant sans préciser de thread !");
        }

        ~MonComposant() {
            Debug::log("Suppression du composant !");
        }

        void MonComposant::onInit() {
            Debug::log("Mon composant initialisé !");
        }

        void MonComposant::onAwake() {
            Debug::log("Mon composant se lève !");
        }

        void MonComposant::onStart() {
            Debug::log("Mon composant commence !");
        }

        void MonComposant::onUpdate() {
            Debug::log("Mon composant appelle l'update !");
        }

        void MonComposant::onFixedUpdate() {
            Debug::log("Mon composant appelle le fixedUpdate !");
        }

        void MonComposant::onDisplay() {
            Debug::log("Mon composant s'affiche !");
        }

        void MonComposant::onMouseEnter() {
            Debug::log("La souris passe sur mon objet");
        }

        void MonComposant::onMouseStay() {
            Debug::log("La souris reste sur mon objet");
        }

        void MonComposant::onMouseExit() {
            Debug::log("La souris sort de mon objet");
        }

        void MonComposant::onTriggerEnter(std::shared_ptr<GameObject> go) {
            Debug::log("L'objet " + go->getName() + " rentre dans mon objet");
        }

        void MonComposant::onTriggerStay(std::shared_ptr<GameObject> go) {
            Debug::log("L'objet " + go->getName() + " reste dans mon objet");
        }

        void MonComposant::onTriggerExit(std::shared_ptr<GameObject> go) {
            Debug::log("L'objet " + go->getName() + " sort de mon objet");
        }

    }

}

```
