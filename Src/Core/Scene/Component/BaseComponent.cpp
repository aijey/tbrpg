//
// Created by Arturan on 13.03.2021.
//

#include "BaseComponent.hpp"
#include "../SceneObject/SceneObject.hpp"





BaseComponent::BaseComponent(SceneObject *sceneObject): sceneObject(sceneObject)  {

}

SceneObject* BaseComponent::getSceneObject() {
    return sceneObject;
}

BaseComponent::~BaseComponent() {
}
