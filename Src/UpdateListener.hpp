//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_UPDATELISTENER_HPP
#define TBRPG_UPDATELISTENER_HPP

#include "Utils/Observer/ObserverSubscriber.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class UpdateListener: public ObserverSubscriber {
    sf::CircleShape& circle;
public:
    explicit UpdateListener(sf::CircleShape& circle) : circle(circle) {}
    void onNotified() override {
        auto oldPos = circle.getPosition();
        auto newPos = sf::Vector2<float>(oldPos.x + 0.1, oldPos.y);
        circle.setPosition(newPos);
        std::cout << newPos.x << " " << newPos.y << std::endl;
    }
};


#endif //TBRPG_UPDATELISTENER_HPP
