//
// Created by Arturan on 14.03.2021.
//

#include "TestController.hpp"

TestController::TestController(Scene &scene, SceneResources &resources) : SceneController(scene, resources){}

void TestController::run() {
        auto cameraSc = scene.createSceneObject("Camera");
        cameraSc->createCameraComponent(sceneResources.renderWindow);

        auto circleSc = scene.createSceneObject("CircleObject1");
        circleSc->transform.setPosition(sf::Vector2f(150, 150));
        auto circle = std::make_shared<sf::CircleShape>(50);
        circle->setFillColor(sf::Color::Green);
        circleSc->createVisualComponent(circle);

        auto sceneObject2 = scene.createSceneObject("SquareObject1");
        sceneObject2->transform.setPosition(sf::Vector2f(50, 50));
        sceneObject2->transform.setRotation(45);
        auto square = std::make_shared<sf::RectangleShape>(sf::Vector2f(20, 20));
        square->setFillColor(sf::Color::Yellow);
        sceneObject2->createVisualComponent(square);
}


