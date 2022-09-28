```
██╗  ██╗ █████╗ ██████╗ ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
█████╔╝ ███████║██████╔╝█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗  
██╔═██╗ ██╔══██║██╔═══╝ ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝  
██║  ██╗██║  ██║██║     ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
                                                                        
par Benjamin DELVERT
```

# Qu'est ce qu'une scène ?

Une scène...

# Qu'est ce qu'un UI ?

Un ui ...

# Pourquoi cet exemple ?

Cet exemple vous permet d'avoir plusieurs informations importants sur KapEngine comme par exemple le système de création de scènes ou le système de création de UI.

Ces 2 points sont très important pour une meilleur compréhension du moteur de jeu et des ses subtilités.

# Code source

```C++

//KapEngine UI includes
#include "UiImage.hpp"
#include "UiText.hpp"
#include "UiFactory.hpp"
#include "UiCanvas.hpp"

//KapEngine includes
#include "Debug.hpp"
#include "Factory.hpp"
#include "KapEngine.hpp"

void createUI(KapEngine::SceneManagement::Scene &scene) {

        /*
            On créé l'objet Canvas qui va contenir tous les élément du UI souhaité. Si cette étape n'est pas faite,
            vos éléments de UI ne s'afficheront pas
        */
        auto canvasObject = KapEngine::UI::UiFactory::createCanvas(scene, "Canvas");

        //créer une image
        auto image = KapEngine::UI::UiFactory::createImage(scene, "Image Object", "Path/Image.png");

        //créer un texte
        auto text = KapEngine::UI::UiFactory::createText(scene, "Text Object", "Text content");

        //try to set parents of image and text
        try {
            auto &trImg = (Transform &)image->getTransform();
            auto &trTxt = (Transform &)text->getTransform();

            trImg.setParent(canvasObject->getId());
            trTxt.setParent(canvasObject->getId());
        } catch(...) {
            KapEngine::Debug::Error("Failled to set parent of image and text");
        }

        //changer la position et la taille de l'image
        try {

            auto &trImg = (Transform &)image->getTransform();

            trImg.setPosition(KapEngine::Tools::Vector3(250, 150, 0));
            trImg.setScale(KapEngine::Tools::Vector3(150, 50, 0));

        } catch(...) {
            KapEngine::Debug::Error("Failled to set size and scale of image");
        }

}

int main() {
    KapEngine::KapEngine engine(true, "Mon Jeu", "Version", "Ma Compagnie");

    //on définie la taille de l'écran
    engine.setScreenSize(KapEngine::Tools::Vector2(720, 480));
    
    //on créé une nouvelle scène
    auto uiScene = KapEngine::Factory::createScene(engine.getSceneManager(), "Nom de ma scène");

    //on charge cette nouvelle scène pour qu'elle soit affichée en première
    engine.getSceneManager()->loadScene("Nom de ma scène");

    createUI(*uiScene);

    //on lance le jeu
    engine.run();
}

```
