/*
** EPITECH PROJECT, 2022
** engine
** File description:
** GameObjectTests
*/

#include "KapEngine.hpp"
#include "criterion/criterion.h"

Test(GameObject, GameObject_Creation1) {
    KapEngine::KEngine engine;
    auto &scene = engine.getSceneManager()->getScene(1);

    auto go = std::make_shared<KapEngine::GameObject>(scene, "TestObject");

    auto found = scene.getObject(go->getId());
    cr_assert((found.use_count() > 0));
}

Test(GameObject, GameObject_Creation2) {
    KapEngine::KEngine engine;
    auto &scene = engine.getSceneManager()->getScene(1);

    auto go = scene.createGameObject("TestObject");

    auto found = scene.getObject(go->getId());
    cr_assert((found.use_count() > 0));
}
