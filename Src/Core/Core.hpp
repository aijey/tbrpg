//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_CORE_HPP
#define TBRPG_CORE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include "Scene/Scene.hpp"
#include "Renderer/Renderer.hpp"
#include "Scene/Component/VisualComponent/VisualComponent.hpp"
class Core {
public:

    Core(int windowWidth, int windowHeight):
        windowWidth(windowWidth), windowHeight(windowHeight), scene(), renderer(scene){
    };
    void launch(){
        loadScene();
        window = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "TurnBasedRPG");
        //window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "TurnBasedRPG"
        while (window->isOpen()){
            window->clear(sf::Color::Magenta);
            renderer.render(window);
            window->display();
            sf::Event event;

            while (window->pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window->close();
                }
            }

        }
    }
private:
    int windowWidth, windowHeight;
    std::shared_ptr<sf::RenderWindow> window;
    Scene scene;
    Renderer renderer;
    void loadScene(){
        auto sceneObject1 = scene.createSceneObject("Object1");
        auto circle = std::make_shared<sf::CircleShape>(100);
        circle->setFillColor(sf::Color::Green);
        sceneObject1->createVisualComponent(circle);
    }

};


#endif //TBRPG_CORE_HPP
