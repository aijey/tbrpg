//
// Created by Arturan on 14.03.2021.
//

#include <iostream>
#include <utility>
#include "CameraComponent.hpp"
#include "../../SceneObject/SceneObject.hpp"
CameraComponent::CameraComponent(std::shared_ptr<sf::RenderWindow> renderWindow, SceneObject* sceneObject)
    : BaseComponent(sceneObject), renderWindow(std::move(renderWindow))
{
}

void CameraComponent::renderVisuals(const std::vector<std::shared_ptr<VisualComponent>> &visuals) {
    for (auto& i: visuals){
        i->prepareForRender(getSceneObject()->transform, getCameraSize());
        renderWindow->draw(*(i->drawable));
    }
}

sf::Vector2u CameraComponent::getCameraSize() {
    return renderWindow->getSize();
}
