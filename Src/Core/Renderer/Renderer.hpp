//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_RENDERER_HPP
#define TBRPG_RENDERER_HPP

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
class Scene;
class VisualComponent;
class CameraComponent;
class Renderer {
public:

    Renderer(Scene& scene);
    void render();
    Scene& scene;
private:
};


#endif //TBRPG_RENDERER_HPP
