//
// Created by Arturan on 15.03.2021.
//

#include "LerperController.hpp"

LerperController::LerperController(Scene &scene, SceneResources &sceneResources) : SceneController(scene,
                                                                                                   sceneResources) {

}

std::shared_ptr<LerpedObject> LerperController::addObject(std::string name, double fromValue, double toValue, double time,
                                                          std::shared_ptr<LerperFunctions> lerperFunctions) {
    auto obj =  std::make_shared<LerpedObject>(name, fromValue, toValue, scene.getSceneTime(),
                                          scene.getSceneTime() + time, lerperFunctions);
    lerpedObjects.insert(obj);
    return obj;
}

void LerperController::run() {
    auto subscriber = std::make_shared<LerperUpdate>(this);
    scene.updateEvent.subscribe(subscriber);

}
