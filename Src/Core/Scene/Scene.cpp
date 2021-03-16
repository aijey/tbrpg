//
// Created by Arturan on 13.03.2021.
//

#include "Scene.hpp"
#include "../../SceneControllers/MainController/MainController.hpp"

Scene::Scene() = default;


std::shared_ptr<SceneObject> Scene::createSceneObject(const std::string& name){
    auto sceneObject = std::make_shared<SceneObject>(name, *this);
    sceneObjects.push_back(sceneObject);
    return sceneObject;
}

void Scene::loadScene(SceneResources& resources) {
    mainController = std::make_shared<MainController>(*this, resources);
    mainController->run();
}



void Scene::setSceneTime(double time) {
    sceneTime = time;
}

double Scene::getSceneTime() const {
    return sceneTime;
}

Scene::UpdateEvent::Args::Args(double d): deltaTime(d) {

}

Scene::KeyEvent::Args::Args(sf::Keyboard::Key code): code(code) {

}
