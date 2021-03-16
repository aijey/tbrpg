//
// Created by Arturan on 14.03.2021.
//

#include "MainCharacterController.hpp"



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

void MainCharacterController::KeyEventListener::onNotified(const Observer::BaseArgs &eventArgs) const {
    auto keyEventArgs = static_cast<Scene::KeyEvent::Args*>(const_cast<Observer::BaseArgs*>(&eventArgs));
    controller->pressedKey = keyEventArgs->code;
    std::cout << "new key: " << controller->pressedKey << std::endl;
}

void MainCharacterController::UpdateListener::onNotified(const Observer::BaseArgs &eventArgs) const {
    //auto updateArgsPtr = static_cast<Scene::UpdateEvent::Args*>(const_cast<Observer::BaseArgs*>(&eventArgs));
    std::cout << controller->inputParams.doctorObject->name << std::endl;
}

void MainCharacterController::run() {
    keyEventListener = KeyEventListener(this);
    updateListener = UpdateListener(this);
    scene.updateEvent.subscribe(&updateListener);
    scene.keyPressedEvent.subscribe(&keyEventListener);
}
