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
    VisualComponent(std::shared_ptr<sf::Drawable> drawable, const sf::Vector2f& pivot, SceneObject* sceneObject);
    void prepareForRender(const Transform& cameraTransform, const sf::Vector2u& cameraSize);
    VisualComponent(const VisualComponent& other) = delete;
    std::shared_ptr<VisualComponent> copy();


    std::shared_ptr<sf::Drawable> drawable;
private:
    sf::Vector2f pivot;
};


#endif //TBRPG_VISUALCOMPONENT_HPP
