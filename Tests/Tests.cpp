/*
** EPITECH PROJECT, 2022
** engine
** File description:
** Tests
*/

#include "KapEngine.hpp"
#include <gtest/gtest.h>

TEST(GameObject, Test1) {
    KapEngine::KapEngine engine;

    auto go = engine.getSceneManager()->getScene(1).createGameObject("Toto");

    EXPECT_NE(go.use_count(), 0);
}

int main(int ac, char **av) {
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}
