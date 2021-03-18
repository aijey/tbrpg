//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_TRANSFORM_HPP
#define TBRPG_TRANSFORM_HPP

#include <SFML/Graphics.hpp>

class Transform {
public:
    Transform() = default;
    Transform(sf::Vector2<float> position, float rotation): position(position), rotation(rotation){};

    void setPosition(const sf::Vector2<float>& newPosition);
    void setPosition(int x, int y);
    sf::Vector2f getPosition() const;
    void setScale(const sf::Vector2<float>& scale);
    sf::Vector2f getScale();
    float getRotation() const;
    void setRotation(const float &rotation);
private:
    sf::Vector2<float> position = {0, 0};
    sf::Vector2<float> scale = {1.0, 1.0};
    float rotation = 0.0;
};


#endif //TBRPG_TRANSFORM_HPP
