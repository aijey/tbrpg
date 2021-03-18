//
// Created by Arturan on 14.03.2021.
//

#include "MainCharacterController.hpp"
#include <iostream>


MainCharacterController::MainCharacterController(Scene &scene, SceneResources &resources,
                                                 InputParams inputParams)
                                                 : SceneController(scene, resources),
                                                 inputParams(std::move(inputParams)),
                                                 lerperController(inputParams.lerperController){

}


MainCharacterController::InputParams::InputParams(std::shared_ptr<SceneObject> doctorObject,
                                                  std::shared_ptr<SceneObject> sniperObject,
                                                  std::shared_ptr<SceneObject> engineerObject,
                                                  std::shared_ptr<LerperController> lerperController)
                                                  : doctorObject(std::move(doctorObject)),
                                                  sniperObject(std::move(sniperObject)),
                                                  engineerObject(std::move(engineerObject)),
                                                  lerperController(std::move(lerperController)) {

}

void MainCharacterController::KeyPressedEventListener::onNotified(const Scene::KeyEvent::Args &eventArgs) const {
    controller->pressedKey = eventArgs.code;
    std::cout << "new key: " << controller->pressedKey << std::endl;
}


void MainCharacterController::KeyReleasedEventListener::onNotified(const Scene::KeyEvent::Args &eventArgs) const {
    controller->pressedKey = sf::Keyboard::Unknown;
}

void MainCharacterController::UpdateListener::onNotified(const Scene::UpdateEvent::Args &eventArgs) const {
    if (controller->pressedKey == sf::Keyboard::A){
        auto oldPos = controller->inputParams.doctorObject->transform.getPosition();
        controller->inputParams.doctorObject->transform.setPosition(oldPos + sf::Vector2f(-1, 0));
    }
    if (controller->pressedKey == sf::Keyboard::D){
        auto oldPos = controller->inputParams.doctorObject->transform.getPosition();
        controller->inputParams.doctorObject->transform.setPosition(oldPos + sf::Vector2f(1, 0));
    }
}


void MainCharacterController::run() {
    keyPressedEventListener = KeyPressedEventListener(this);
    keyReleasedEventListener = KeyReleasedEventListener(this);
    updateListener = UpdateListener(this);
    scene.updateEvent.subscribe(&updateListener);
    scene.keyPressedEvent.subscribe(&keyPressedEventListener);
    scene.keyReleasedEvent.subscribe(&keyReleasedEventListener);
}
