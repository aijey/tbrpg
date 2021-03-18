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
    VisualComponent(const std::shared_ptr<sf::Drawable>& drawable, SceneObject* sceneObject);
    VisualComponent(const std::shared_ptr<sf::Drawable>& drawable, const sf::Vector2f& pivot, SceneObject* sceneObject);
    VisualComponent(const VisualComponent& other) = delete;
    ~VisualComponent() = default;

    void prepareForRender(const Transform& cameraTransform, const sf::Vector2u& cameraSize);
    std::shared_ptr<VisualComponent> copy();


    std::shared_ptr<sf::Drawable> drawable;
private:
    sf::Vector2f pivot;
};


#endif //TBRPG_VISUALCOMPONENT_HPP
