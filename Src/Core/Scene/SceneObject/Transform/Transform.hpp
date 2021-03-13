//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_TRANSFORM_HPP
#define TBRPG_TRANSFORM_HPP

#include <SFML/Graphics.hpp>

class Transform {
public:
    sf::Vector2<float> position;
    float angle;
    Transform() = default;
    Transform(sf::Vector2<float> position, float angle): position(position), angle(angle){};
};


#endif //TBRPG_TRANSFORM_HPP
