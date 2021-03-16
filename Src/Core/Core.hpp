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
#include <chrono>
class Core {
public:

    Core(int windowWidth, int windowHeight):
        windowWidth(windowWidth), windowHeight(windowHeight), scene(), renderer(scene), sceneResources(window){
    };
    void launch(){
        window = std::make_shared<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeight), "TurnBasedRPG");
        sceneResources.renderWindow = window;
        //window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "TurnBasedRPG"

        scene.loadScene(sceneResources);
        auto prevUpdateTime = std::chrono::high_resolution_clock::now();
        auto sceneStartTime = prevUpdateTime;
        auto prevLateUpdateTime = std::chrono::high_resolution_clock::now();
        scene.setSceneTime(0.0);
        while (window->isOpen()){

            auto updateTime = std::chrono::high_resolution_clock::now();
            auto timePassed = std::chrono::duration_cast<std::chrono::microseconds>(updateTime - prevUpdateTime).count();
            auto timePassedFromStart = std::chrono::duration_cast<std::chrono::microseconds>(updateTime - sceneStartTime).count();
            scene.setSceneTime(static_cast<double>(timePassedFromStart) / 1000000);
            prevUpdateTime = updateTime;
            scene.updateEvent.notifyAll(Scene::UpdateEvent::Args(((double)timePassed / 1000000.0)));

            window->clear(sf::Color::Magenta);
            renderer.render();
            window->display();
            sf::Event event;
            while (window->pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window->close();
                }
                if (event.type == sf::Event::KeyPressed){
                    scene.keyPressedEvent.notifyAll(Scene::KeyEvent::Args(event.key.code));
                }
                if (event.type == sf::Event::KeyReleased){
                    scene.keyReleasedEvent.notifyAll(Scene::KeyEvent::Args(event.key.code));
                }
            }
            auto lateUpdateTime = std::chrono::high_resolution_clock::now();
            timePassed = std::chrono::duration_cast<std::chrono::microseconds>(lateUpdateTime - prevLateUpdateTime).count();
            prevLateUpdateTime = lateUpdateTime;
            scene.lateUpdateEvent.notifyAll(Scene::UpdateEvent::Args(((double)timePassed / 1000000.0)));
        }
    }
private:
    int windowWidth, windowHeight;
    std::shared_ptr<sf::RenderWindow> window;
    Scene scene;
    SceneResources sceneResources;
    Renderer renderer;

};


#endif //TBRPG_CORE_HPP
