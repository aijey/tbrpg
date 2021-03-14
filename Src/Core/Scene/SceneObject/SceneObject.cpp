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

void SceneObject::createCameraComponent(std::shared_ptr<sf::RenderWindow> renderWindow) {
    auto cameraComponent = std::make_shared<CameraComponent>(renderWindow, this);
    scene.cameraComponents.push_back(cameraComponent);
    cameraComponents.push_back(cameraComponent);
}
