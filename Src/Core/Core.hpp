//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_CORE_HPP
#define TBRPG_CORE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Scene/Scene.hpp"

class Core {
private:
    int windowWidth, windowHeight;
    std::shared_ptr<sf::RenderWindow> window;
    Scene scene;
public:

    Core(int windowWidth, int windowHeight): windowWidth(windowWidth), windowHeight(windowHeight){
    };
    void launch(){
        window = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "TurnBasedRPG");
        //window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "TurnBasedRPG")
    }


};


#endif //TBRPG_CORE_HPP
