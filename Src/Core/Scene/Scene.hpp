//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_SCENE_HPP
#define TBRPG_SCENE_HPP


#include "SceneObject/SceneObject.hpp"

class Scene {
public:
    Scene() = default;
    std::shared_ptr<SceneObject> createSceneObject(const std::string& name){
        sceneObjects.push_back(std::make_shared<SceneObject>(name));
    }
private:
    std::vector<std::shared_ptr<SceneObject>> sceneObjects;
};


#endif //TBRPG_SCENE_HPP
