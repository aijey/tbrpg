//
// Created by Arturan on 14.03.2021.
//

#include <iostream>
#include "CameraComponent.hpp"
#include "../../SceneObject/SceneObject.hpp"
CameraComponent::CameraComponent(std::shared_ptr<sf::RenderWindow> renderWindow, SceneObject* sceneObject)
    : renderWindow(renderWindow), BaseComponent(sceneObject)
{

}

void CameraComponent::renderVisuals(const std::vector<std::shared_ptr<VisualComponent>> &visuals) {
    for (auto& i: visuals){
        i->prepareForRender(getSceneObject()->transform);
        renderWindow->draw(*(i->drawable));
    }
}
