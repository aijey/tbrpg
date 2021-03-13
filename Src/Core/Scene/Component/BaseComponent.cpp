//
// Created by Arturan on 13.03.2021.
//

#include "BaseComponent.hpp"

BaseComponent::BaseComponent(std::shared_ptr<SceneObject> sceneObject): sceneObject(sceneObject){

}

std::shared_ptr<SceneObject> BaseComponent::getSceneObject() {
    return sceneObject;
}