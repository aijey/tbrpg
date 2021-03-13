//
// Created by Arturan on 13.03.2021.
//

#include "VisualComponent.hpp"
#include "../../SceneObject/SceneObject.hpp"
VisualComponent::VisualComponent(std::shared_ptr<SceneObject> sceneObject): BaseComponent::BaseComponent(sceneObject) {
    attachToSceneObject();
}

void VisualComponent::attachToSceneObject() {
    sceneObject->addVisualComponent(std::shared_ptr<VisualComponent>(this));
}