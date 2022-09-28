```
██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
█████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗  
██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝  
██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
                                                                        
par Benjamin DELVERT
```

# <span color="blue">Créer ton composant</span>

Sur cette page tu vas apprendre qu'est ce qu'un KapEngine::Component, pourquoi il existse et comment en créer un.

## <span color="blue">Table des matières</span>
| Titre                     | Lien                           | Statut         |
|---------------------------|--------------------------------|----------------|
| Qu'est ce qu'un composant | [GO](#Quest-ce-quun-composant) | :green_circle: |
| Créer le sien             | [GO](#Créer-le-sien)           | :large_orange_diamond:   |
| Démarrage Rapide          | [GO](#Démarrage-rapide)        | :green_circle: |

## <span color="blue">Qu'est ce qu'un composant</span>

Un composant est un script rattaché à un objet de jeu (KapEngine::GameObject). Il a pour but de donner une logique ou une action à votre objet.

Certaines fonctions seront automatiquement appelées par KapEngine ce qui permet une autonomisation du fonctionnement de votre jeu une fois lancé.


:warning: le KapEngine est un engine multi thread. Ce qui signifie que le jeu utilisera plusieurs coeur de votre ordinateur pour effectuer des calculs plus rapides. Les composants sont appelés sur les thread suivant : 2, 3, 4. Lors de la création de vos composants, vous pouvez définir sur quel thread votre composant tournera. Si vous définissez un autre "threadID" que ceux indiqué juste avant, votre composant ne sera jamais lu.

Cette méthode de calcul vous permet d'avoir un jeu plus performant. Cependant il se peut que vous ayez des réécriute de valeur. Ce sera à vous d'y faire attention.

## <span color="blue">Fonctions utiles</span>

Tous les composants on des fonctions très utiles permettant de connaître certains évenements de votre jeu comme les touches appuyées ou la position de votre souris en jeu.

Pour cela 2 fonctions sont crées : getInput() et getMouse().

- getInput() : vous permet de récupérer les évenements des touches du jeu. [page de input](inputFr.md).
- getMouse() : vous permet de récupérer les informations sur la souris. [page de la souris](mouseFr.md).

pour récupérer l'objet sur lequel votre composant est attaché vous devez utiliser ces commandes :
- getGameObject()
- getGameObjectCont()

#### Vous souhaitez faire fonctionner votre composant que si il est accompagné d'un autre composan sur le même objett ?

Une fonction spécifique a été pensé pour cela.
- addRequireComponent("AutreComposant")

Cette fonction prend en argument le nom de l'autre composant voulue pour faire fonctionner le votre. Si jamais le composant donné n'est pas sur l'objet rattaché à votre composant, votre composant sera comme désactivé (sans l'être).

Vous souhaitez ajouter des conditions qui permettent de faire focntionner ou non votre composant ?
Lisez les explications de la foncton :
- bool checkComponentValidity()

## <span color="blue">Créer le sien</span>

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
Important : Les focntions proposés ne sont pas toutes à réécrire. Vous pouvez réécrire uniquement celle que vous souhaitez utiliser. Cela peut également rendre votre code plus beau et épuré.

#### onInit [DEPRECATED]
Cette fonction n'est plus utilisée. Elle sera prochainement supprimé

#### onAwake
Cette fonction est lancé sur tous les composants actif ou non de la scène 1 seule fois (lorsque le GameObject appaprait dans la scène au runtime). Elle permet en règle général d'initialiser les valeurs qui ne sont toujours pas initialisées.

#### onStart
Cette fonction ressemble énormément à onAwake. Elle ne se lance qu'une seule fois (lorsque le GameObject appaprait dans la scène au runtime ET qu'il est activé et utilisable).
En effet la seule différence c'est que le composant doit être activé et utilisable pour entrer dans cette fonction.

#### onUpdate
Cette fonction comme son nom l'indique vous permettra d'update votre composant. Cette fonction sera appelé à chaque frame de votre jeu.
Cela peut devenir un peu énergivore et temps ivore sur vos calculs (réfléchissez bien si il ne faut pas utiliser le [onFixedUpdate](####onFixedUpdate)).

#### onFixedUpdate
Cette fonction permet tout comme la onUpdate de mettre à jour vos informations. Mais elle n'est appelé que sur un temps donné. Votre engine contient cette valeur de temps, qui est modifiable. Cette valeur est également général à tout votre jeu. Ce qui veut dire que tous les composants appellent le onFixedUpdate en même temps.

#### onDisplay
Cette fonction est appelée après toutes les fonctions énoncées précédement. Elle vous permet comme son nom l'indique, intéragir avec les lib graphiques si vous le souhaitez (c'est pour cela que cette fonction à été faite ;) ).

#### onDestroy [EVENT]
Cette fonction est appelée lorsque le KapEngine::GameObject sur lequel votre composant est rattaché, va être détruit.
Cella permet de faire une dernière action avant la destruction définitive de votre objet.
Attention : cette fonction ne suit pas un ordre logique d'appel. Elle peut être appelé avant ou après les updates. Prenez ça en compte dans vos codes

#### onGameQuit [EVENT]
Cette fonction est appelée lorsque votre jeu va être sur le point de se quitter. Cela vous permet de faire une dernière action avant que le jeu s'éteigne.
Attention : cette fonction ne suit pas un ordre logique d'appel. Elle peut être appelé avant ou après les updates. Prenez ça en compte dans vos codes

#### onDisable [EVENT]
Cette fonction est appelée lorsque votre composant se désactive.
Attention : cette fonction ne suit pas un ordre logique d'appel. Elle peut être appelé avant ou après les updates. Prenez ça en compte dans vos codes

#### onEnable [EVENT]
Cette fonction est appelée lorsque votre composant s'active.
Attention : cette fonction ne suit pas un ordre logique d'appel. Elle peut être appelé avant ou après les updates. Prenez ça en compte dans vos codes


#### onMouseEnter [BESOIN D'UN COMPOSANT]
Composant: "Mouse Detector"
--------------------------
Cette fonction vous permet de détecter quand la souris rentre dans une zone que vous avez prédéfinie.
Attention : cette fonction ne suit pas un ordre logique d'appel. Elle peut être appelé avant ou après les updates. Prenez ça en compte dans vos codes

#### onMouseStay [BESOIN D'UN COMPOSANT]
Composant: "Mouse Detector"
--------------------------
Cette fonction vous permet de détecter quand la souris reste dans une zone que vous avez prédéfinie.
Attention : cette fonction ne suit pas un ordre logique d'appel. Elle peut être appelé avant ou après les updates. Prenez ça en compte dans vos codes

#### onMouseExit [BESOIN D'UN COMPOSANT]
Composant: "Mouse Detector"
--------------------------
Cette fonction vous permet de détecter quand la souris sort dans une zone que vous avez prédéfinie.
Attention : cette fonction ne suit pas un ordre logique d'appel. Elle peut être appelé avant ou après les updates. Prenez ça en compte dans vos codes

## <span color="blue">Démarrage Rapide</span>

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

        bool MonComposant::checkComponentValidity() {
            if (...) {
                //mon composant ne doit pas se lancer
                return false;
            }
            //mon composant peut se lancer
            return true;
        }

        void MonComposant::onDestroy() {
            Debug::log("L'objet " + go->getName() + " est détruit");
        }

        void MonComposant::onGameQuit() {
            Debug::log("Le jeu s'arrête");
        }

        void MonComposant::onDisable() {
            Debug::log("L'object " + go->getName() + " s'est désactivé");
        }

        void MonComposant::onEnable() {
            Debug::log("L'object " + go->getName() + " s'est activé");
        }

    }

}

```
