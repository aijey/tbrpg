//
// Created by Arturan on 14.03.2021.
//

#include <iostream>
#include "Renderer.hpp"
#include "../Scene/Component/VisualComponent/VisualComponent.hpp"
#include "../Scene/Scene.hpp"
Renderer::Renderer(Scene &scene): scene(scene) {
}

void Renderer::render(std::shared_ptr<sf::RenderWindow> target) {
    for (auto& i: scene.visualComponents){
        std::cout << "Iteration" << std::endl;
        target->draw(*(i->drawable));
    }
}