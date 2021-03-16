//
// Created by romaniy on 16.03.2021.
//

#include "TestController.hpp"
#include <cmath>

void TestController::UpdateListener::onNotified(const Scene::UpdateEvent::Args &args) const {
    auto currentPosition = testController->params.circle->transform.getPosition();
    currentPosition.x = std::cos(testController->scene.getSceneTime())*200;
    currentPosition.y = std::sin(testController->scene.getSceneTime())*200;
    testController->params.circle->transform.setPosition(currentPosition);
    int h = 0;
    for (auto& i: testController->sceneObjects) {
        auto oldPosition = i->transform.getPosition();
        if (h%2 == 0) {
            oldPosition += sf::Vector2f(10 * args.deltaTime,10 * args.deltaTime);
        } else {
            oldPosition += sf::Vector2f(-10 * args.deltaTime,-10 * args.deltaTime);
        }
        h++;
        i->transform.setPosition(oldPosition);
    }
}

void TestController::run() {
    updateListener = UpdateListener(this);
    keyPressedListener = KeyPressedListener(this);
    scene.updateEvent.subscribe(&updateListener);
    scene.keyPressedEvent.subscribe(&keyPressedListener);
}

void TestController::KeyPressedListener::onNotified(const Scene::KeyEvent::Args &args) const {
    if (args.code == sf::Keyboard::Space) {
        auto currentPosition = testController->params.circle->transform.getPosition();
        auto newCircle = std:: make_shared<sf::CircleShape>(10);
        newCircle->setFillColor(sf::Color::Red);
        auto newSceneObject = testController->scene.createSceneObject("NewObject");
        newSceneObject->createVisualComponent(newCircle, { 10, 10 });
        newSceneObject->transform.setPosition(currentPosition);
        testController->sceneObjects.push_back(newSceneObject);
    }
}
