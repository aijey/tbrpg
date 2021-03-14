//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_SCENERESOURCES_HPP
#define TBRPG_SCENERESOURCES_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class SceneResources {
public:
    explicit SceneResources(std::shared_ptr<sf::RenderWindow> renderWindow);
    std::shared_ptr<sf::RenderWindow> renderWindow;
};


#endif //TBRPG_SCENERESOURCES_HPP
