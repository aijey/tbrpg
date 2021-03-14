//
// Created by Arturan on 13.03.2021.
//

#include <iostream>
#include "SceneObject.hpp"
#include "../Scene.hpp"

SceneObject::SceneObject(const std::string& name, Scene& scene): name(name), scene(scene){
    std::cout << "Printing sceneObjects" << std::endl;
    for (auto& i: scene.sceneObjects){
        std::cout << i->name << std::endl;
    }
};

void SceneObject::createVisualComponent(std::shared_ptr<sf::Drawable> drawable) {
    auto visualComponent = std::make_shared<VisualComponent>(drawable);
    std::cout << "Printing sceneObjects 2" << std::endl;
    for (auto& i: scene.sceneObjects){
        std::cout << i->name << std::endl;
    }
    scene.visualComponents.push_back(visualComponent);
    visualComponents.push_back(visualComponent);
}