/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "Factory.hpp"
#include "GameObject.hpp"
#include "UiImage.hpp"
#include "UiText.hpp"

namespace KapEngine {
    class Factory;
    class GameObject;

    namespace UI {
        class Image;
        class Text;
    }

}

namespace KapEngine {

    namespace UI {

        class UiFactory {

            static std::shared_ptr<GameObject> createImage(SceneManagement::Scene &scene, std::string const& name = "Image") {
                std::shared_ptr<GameObject> result = Factory::createEmptyGameObject(scene, name);
                std::shared_ptr<Image> imgComponent = std::make_shared<Image>(result);
                result->addComponent(imgComponent);

                return result;
            }

            static std::shared_ptr<GameObject> createText(SceneManagement::Scene &scene, std::string const& name = "Text") {
                std::shared_ptr<GameObject> result = Factory::createEmptyGameObject(scene, name);
                std::shared_ptr<Text> txtComponent = std::make_shared<Text>(result);
                result->addComponent(txtComponent);

                return result;
            }

        };

    }

}

#endif /* !FACTORY_HPP_ */
