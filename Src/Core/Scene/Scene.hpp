//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_SCENE_HPP
#define TBRPG_SCENE_HPP


#include "SceneObject/SceneObject.hpp"
#include "SceneResources/SceneResources.hpp"
#include <vector>

class Scene {
    friend class SceneObject;
    friend class Renderer;
public:
    Scene() = default;
    std::shared_ptr<SceneObject> createSceneObject(const std::string& name);
    std::vector<std::shared_ptr<SceneObject>> sceneObjects;
    std::vector<std::shared_ptr<VisualComponent>> visualComponents;
    std::vector<std::shared_ptr<CameraComponent>> cameraComponents;
    void loadScene(SceneResources& resources);
};


#endif //TBRPG_SCENE_HPP
