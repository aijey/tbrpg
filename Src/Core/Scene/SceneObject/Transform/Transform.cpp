//
// Created by Arturan on 13.03.2021.
//

#include "Transform.hpp"

sf::Vector2f Transform::getPosition() const {
    return position;
}

void Transform::setPosition(const sf::Vector2<float>& newPosition) {
    position = newPosition;
}

void Transform::setRotation(const float& rotation) {
    this->rotation = rotation;
}

void Transform::setPosition(int x, int y) {
    position = sf::Vector2f(x, y);
}

float Transform::getRotation() const {
    return rotation;
}

void Transform::setScale(const sf::Vector2<float> &scale) {
    this->scale = scale;
}

sf::Vector2f Transform::getScale() {
    return scale;
}
