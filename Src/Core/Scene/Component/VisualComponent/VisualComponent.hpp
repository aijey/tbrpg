//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_VISUALCOMPONENT_HPP
#define TBRPG_VISUALCOMPONENT_HPP
#include "../BaseComponent.hpp"
#include <memory>
#include <SFML/Graphics.hpp>
#include "../../SceneObject/Transform/Transform.hpp"

class VisualComponent: public BaseComponent {
public:
    VisualComponent(std::shared_ptr<sf::Drawable> drawable, SceneObject* sceneObject);
    std::shared_ptr<sf::Drawable> drawable;
    void prepareForRender(const Transform& cameraTransform);
    VisualComponent(const VisualComponent& other) = delete;
};


#endif //TBRPG_VISUALCOMPONENT_HPP
