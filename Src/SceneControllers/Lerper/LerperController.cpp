//
// Created by Arturan on 15.03.2021.
//

#include "LerperController.hpp"

LerperController::LerperController(Scene &scene, SceneResources &sceneResources) : SceneController(scene, sceneResources) {

}

std::shared_ptr<LerpedObject> LerperController::addObject(std::string name, double fromValue, double toValue, double time,
                                                          std::shared_ptr<LerperFunctions> lerperFunctions) {
    auto obj =  std::make_shared<LerpedObject>(name, fromValue, toValue, scene.getSceneTime(),
                                          scene.getSceneTime() + time, lerperFunctions);
    lerpedObjects.insert(obj);
    return obj;
}

void LerperController::run() {
    updateListener = UpdateListener(this);
    scene.updateEvent.subscribe(&updateListener);
}

void LerperController::UpdateListener::onNotified(const Observer::BaseArgs &eventArgs) const {

    auto updateArgsPtr = static_cast<Scene::UpdateEvent::Args*>(const_cast<Observer::BaseArgs*>(&eventArgs));

    std::vector<std::shared_ptr<LerpedObject>> toRemove;
    for (auto &i: lerperController->lerpedObjects) {
        auto time = lerperController->scene.getSceneTime();
        bool result = i->update(time);
        if (result) {
            toRemove.push_back(i);
        }
    }

    for (auto &i: toRemove) {
        lerperController->lerpedObjects.erase(i);
    }


}
