//
// Created by Arturan on 14.03.2021.
//

#include <iostream>
#include "Renderer.hpp"
#include "../Scene/Component/VisualComponent/VisualComponent.hpp"
#include "../Scene/Component/CameraComponent/CameraComponent.hpp"
#include "../Scene/Scene.hpp"
Renderer::Renderer(Scene &scene): scene(scene) {
}

void Renderer::render() {
    auto& cameras = scene.cameraComponents;
    for (auto& i: cameras){
        i->renderVisuals(scene.visualComponents);
    }
}
