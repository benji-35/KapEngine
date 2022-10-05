/*
** EPITECH PROJECT, 2022
** engine
** File description:
** GameObjectTests
*/

#include "KapEngine.hpp"
#include <gtest/gtest.h>

TEST(GameObject, Test1) {
    KapEngine::KapEngine engine;

    auto go = engine.getSceneManager()->getScene(1).createGameObject("Toto");

    ASSERT_NE((int)go.use_count(), 0);
}
