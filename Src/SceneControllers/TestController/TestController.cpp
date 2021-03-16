//
// Created by romaniy on 16.03.2021.
//

#include "TestController.hpp"
#include <cmath>

void TestController::UpdateListener::onNotified(const Scene::UpdateEvent::Args &args) const {
    auto currentPosition = testController->params.circle->transform.getPosition();
    if (!testController->isSPressed) {
        currentPosition.x = std::cos(testController->scene.getSceneTime()) * 200;
        currentPosition.y = std::sin(testController->scene.getSceneTime()) * 200;
        testController->params.circle->transform.setPosition(currentPosition);
    }
    int h = 0;
    for (auto& i: testController->sceneObjects) {
        auto curObjPos = i->transform.getPosition();
        sf::Vector2<float> posDif = currentPosition - curObjPos;
        auto toAdd = sf::Vector2f(posDif.x * 0.001, posDif.y * 0.001);
        i->transform.setPosition(curObjPos + toAdd);
    }
}

void TestController::run() {
    updateListener = UpdateListener(this);
    keyPressedListener = KeyPressedListener(this);
    keyReleasedListener = KeyReleasedListener(this);
    scene.updateEvent.subscribe(&updateListener);
    scene.keyPressedEvent.subscribe(&keyPressedListener);
    scene.keyReleasedEvent.subscribe(&keyReleasedListener);
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
    if (args.code == sf::Keyboard::S){
        testController->isSPressed = true;
    }
}

void TestController::KeyReleasedListener::onNotified(const Scene::KeyEvent::Args &args) const {
    if (args.code == sf::Keyboard::S){
        testController->isSPressed = false;
    }
}
