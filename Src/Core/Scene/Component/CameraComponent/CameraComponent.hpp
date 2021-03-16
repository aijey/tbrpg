//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_CAMERACOMPONENT_HPP
#define TBRPG_CAMERACOMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "../BaseComponent.hpp"
#include "../VisualComponent/VisualComponent.hpp"
#include <memory>
class CameraComponent: public BaseComponent {
public:
    explicit CameraComponent(std::shared_ptr<sf::RenderWindow> renderWindow, SceneObject* sceneObject);
    void renderVisuals(const std::vector<std::shared_ptr<VisualComponent>>& visuals);
    sf::Vector2u getCameraSize();
    std::shared_ptr<CameraComponent> copy();
private:
    std::shared_ptr<sf::RenderWindow> renderWindow;

};


#endif //TBRPG_CAMERACOMPONENT_HPP
