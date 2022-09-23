/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Factory
*/

#ifndef FACTORY_HP_
#define FACTORY_HPP_

#include "Factory.hpp"
#include "GameObject.hpp"
#include "UiImage.hpp"
#include "UiText.hpp"
#include "UiCanvas.hpp"

namespace KapEngine {
    class Factory;
    class GameObject;

    namespace UI {
        class Image;
        class Text;
        class Canvas;
    }

}

namespace KapEngine {

    namespace UI {

        class UiFactory {
            public:

            //create canvas
            static std::shared_ptr<GameObject> createCanvas(SceneManagement::Scene &scene, std::string const& name = "Canvas") {
                auto result = Factory::createEmptyGameObject(scene, name);
            
                auto canvasComp = std::make_shared<Canvas>(result);
                result->addComponent(canvasComp);

                return result;
            }

            //create image
            static std::shared_ptr<GameObject> createImage(SceneManagement::Scene &scene, std::string const& name = "Image", std::string const& pathImage = "") {
                auto result = Factory::createEmptyGameObject(scene, name);
                std::shared_ptr<Image> imgComponent = std::make_shared<Image>(result);
                result->addComponent(imgComponent);

                imgComponent->setPathSprite(pathImage);

                return result;
            }

            //create text
            static std::shared_ptr<GameObject> createText(SceneManagement::Scene &scene, std::string const& name = "Text") {
                auto result = Factory::createEmptyGameObject(scene, name);
                std::shared_ptr<Text> txtComponent = std::make_shared<Text>(result);
                result->addComponent(txtComponent);

                return result;
            }

        };

    }

}

#endif /* !FACTORY_HPP_ */
