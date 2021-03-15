//
// Created by Arturan on 13.03.2021.
//

#include "Scene.hpp"
#include "../../SceneControllers/MainController/MainController.hpp"

std::shared_ptr<SceneObject> Scene::createSceneObject(const std::string& name){
    auto sceneObject = std::make_shared<SceneObject>(name, *this);
    sceneObjects.push_back(sceneObject);
    return sceneObject;
}

void Scene::loadScene(SceneResources& resources) {
    auto testController = std::make_shared<MainController>(*this, resources);
    addController(testController);
    testController->run();

}

void Scene::addController(std::shared_ptr<SceneController> sceneController) {
    sceneControllers.push_back(sceneController);
}

void Scene::setSceneTime(double time) {
    sceneTime = time;
}

double Scene::getSceneTime() const {
    return sceneTime;
}
