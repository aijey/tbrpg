//
// Created by Arturan on 13.03.2021.
//

#include "VisualComponent.hpp"
#include "../../SceneObject/SceneObject.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <utility>
VisualComponent::VisualComponent(std::shared_ptr<sf::Drawable> drawable, SceneObject* sceneObject)
    : BaseComponent(sceneObject), drawable(std::move(drawable))  {
}

VisualComponent::VisualComponent(std::shared_ptr<sf::Drawable> drawable, const sf::Vector2f& pivot, SceneObject* sceneObject)
    : BaseComponent(sceneObject), drawable(std::move(drawable)), pivot(pivot){

}

void VisualComponent::prepareForRender(const Transform& cameraTransform, const sf::Vector2u& cameraSize) {
    auto transformable = dynamic_cast<sf::Transformable*>(drawable.get());
    if (transformable){
        int addX = (int)cameraSize.x / 2;
        int addY = (int)cameraSize.y / 2;
        auto position = getSceneObject()->transform.position - cameraTransform.position;
        position.x += (float)addX;
        position.y += (float)addY;
        auto rotation = getSceneObject()->transform.rotation - cameraTransform.rotation;
        transformable->setPosition(position - pivot);
        transformable->setRotation(rotation);
    }

}


