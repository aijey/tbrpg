//
// Created by Arturan on 13.03.2021.
//

#include <iostream>
#include "SceneObject.hpp"
#include "../Scene.hpp"

SceneObject::SceneObject(const std::string& name, Scene& scene): name(name), scene(scene){

};

void SceneObject::createVisualComponent(std::shared_ptr<sf::Drawable> drawable) {
    auto visualComponent = std::make_shared<VisualComponent>(drawable, this);
    scene.visualComponents.push_back(visualComponent);
    visualComponents.push_back(visualComponent);
}

void SceneObject::createVisualComponent(std::shared_ptr<sf::Drawable> drawable, const sf::Vector2f& pivot) {
    auto visualComponent = std::make_shared<VisualComponent>(drawable, pivot, this);
    scene.visualComponents.push_back(visualComponent);
    visualComponents.push_back(visualComponent);
}

void SceneObject::copyVisualComponent(const std::shared_ptr<VisualComponent> &visualComponent) {
    auto newVisualComponent = visualComponent->copy();
    scene.visualComponents.push_back(newVisualComponent);
    visualComponents.push_back(newVisualComponent);
}

void SceneObject::createCameraComponent(std::shared_ptr<sf::RenderWindow> renderWindow) {
    auto cameraComponent = std::make_shared<CameraComponent>(renderWindow, this);
    scene.cameraComponents.push_back(cameraComponent);
    cameraComponents.push_back(cameraComponent);
}

void SceneObject::copyCameraComponent(const std::shared_ptr<CameraComponent> &cameraComponent) {
    auto newCameraComponent = cameraComponent->copy();
    scene.cameraComponents.push_back(newCameraComponent);
    cameraComponents.push_back(newCameraComponent);
}

std::shared_ptr<SceneObject> SceneObject::copy() const {
    auto newSceneObject = scene.createSceneObject(name);
    newSceneObject->transform = transform;
    // COPY COMPONENTS
    for(auto &i: visualComponents){
        newSceneObject->copyVisualComponent(i);
    }
    for(auto &i: cameraComponents){
        newSceneObject->copyCameraComponent(i);
    }
    return newSceneObject;
}


