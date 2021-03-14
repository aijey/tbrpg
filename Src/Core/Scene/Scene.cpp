//
// Created by Arturan on 13.03.2021.
//

#include "Scene.hpp"

std::shared_ptr<SceneObject> Scene::createSceneObject(const std::string& name){
    auto sceneObject = std::make_shared<SceneObject>(name, *this);
    sceneObjects.push_back(sceneObject);
    return sceneObject;
}