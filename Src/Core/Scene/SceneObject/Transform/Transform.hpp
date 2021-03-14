//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_TRANSFORM_HPP
#define TBRPG_TRANSFORM_HPP

#include <SFML/Graphics.hpp>

class Transform {
public:
    sf::Vector2<float> position;
    float rotation;
    Transform() = default;
    Transform(sf::Vector2<float> position, float rotation): position(position), rotation(rotation){};

    void setPosition(sf::Vector2<float> newPosition){
        position = newPosition;
    }
    void setRotation(float rotation){
        this->rotation = rotation;
    }
};


#endif //TBRPG_TRANSFORM_HPP
