//
// Created by Arturan on 13.03.2021.
//

#include "VisualComponent.hpp"
#include "../../SceneObject/SceneObject.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
VisualComponent::VisualComponent(std::shared_ptr<sf::Drawable> drawable, SceneObject* sceneObject)
    : drawable(drawable), BaseComponent(sceneObject) {
}

void VisualComponent::prepareForRender(const Transform& cameraTransform) {
    auto transformable = dynamic_cast<sf::Transformable*>(drawable.get());
    if (transformable){
        auto position = getSceneObject()->transform.position - cameraTransform.position;
        auto rotation = getSceneObject()->transform.rotation - cameraTransform.rotation;
        transformable->setPosition(position);
        transformable->setRotation(rotation);
    }

}