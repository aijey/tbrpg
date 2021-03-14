//
// Created by Arturan on 13.03.2021.
//

#include "VisualComponent.hpp"
#include "../../SceneObject/SceneObject.hpp"
#include <iostream>
VisualComponent::VisualComponent(std::shared_ptr<sf::Drawable> drawable)
    : BaseComponent(), drawable(drawable) {

}
