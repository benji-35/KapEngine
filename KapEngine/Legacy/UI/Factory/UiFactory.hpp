/*
** EPITECH PROJECT, 2022
** gameEngine2
** File description:
** Factory
*/

#ifndef UI_FACTORY_HPP_
#define UI_FACTORY_HPP_

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

    /**
     * @namespace KapEngine::UI
     * This namespace regroup all UI things
     * @brief All UI things
     */
    namespace UI {

        class UiFactory {
            public:

            //create canvas
            static std::shared_ptr<GameObject> createCanvas(SceneManagement::Scene &scene, std::string const& name = "Canvas") {
                PROFILER_FUNC_START();
                auto result = Factory::createEmptyGameObject(scene, name);
            
                auto canvasComp = std::make_shared<Canvas>(result);
                result->addComponent(canvasComp);

                PROFILER_FUNC_END();
                return result;
            }

            //create image
            static std::shared_ptr<GameObject> createImage(SceneManagement::Scene &scene, std::string const& name = "Image", std::string const& pathImage = "", Tools::Rectangle const& rect = {0, 0, 0, 0}) {
                PROFILER_FUNC_START();
                auto result = Factory::createEmptyGameObject(scene, name);
                std::shared_ptr<Image> imgComponent = std::make_shared<Image>(result);
                result->addComponent(imgComponent);

                imgComponent->setPathSprite(pathImage);
                imgComponent->setRectangle(rect);

                PROFILER_FUNC_END();
                return result;
            }

            //create text
            static std::shared_ptr<GameObject> createText(SceneManagement::Scene &scene, std::string const& name = "Text") {
                PROFILER_FUNC_START();
                auto result = Factory::createEmptyGameObject(scene, name);
                std::shared_ptr<Text> txtComponent = std::make_shared<Text>(result);
                result->addComponent(txtComponent);

                PROFILER_FUNC_END();
                return result;
            }

        };

    }

}

#endif /* !UI_FACTORY_HPP_ */
