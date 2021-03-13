//
// Created by Arturan on 13.03.2021.
//

#include "SceneObject.hpp"

void SceneObject::addVisualComponent(std::shared_ptr<VisualComponent> visualComponent) {
    visualComponents.push_back(visualComponent);
}