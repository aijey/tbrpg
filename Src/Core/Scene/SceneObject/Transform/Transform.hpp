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

    void setPosition(const sf::Vector2<float>& newPosition);
    void setPosition(int x, int y);
    sf::Vector2f getPosition() const;
    void setRotation(float rotation);
};


#endif //TBRPG_TRANSFORM_HPP
