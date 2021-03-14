//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_VISUALCOMPONENT_HPP
#define TBRPG_VISUALCOMPONENT_HPP
#include "../BaseComponent.hpp"
#include <memory>
#include <SFML/Graphics.hpp>
class VisualComponent: public BaseComponent {
public:
    VisualComponent(std::shared_ptr<sf::Drawable> drawable);
    std::shared_ptr<sf::Drawable> drawable;
};


#endif //TBRPG_VISUALCOMPONENT_HPP
