//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_SCENECONTROLLER_HPP
#define TBRPG_SCENECONTROLLER_HPP


#include "../Scene.hpp"
#include "../SceneResources/SceneResources.hpp"

class SceneController {
public:
    explicit SceneController(Scene& scene, SceneResources& sceneResources);
protected:
    Scene& scene;
    SceneResources& sceneResources;
};


#endif //TBRPG_SCENECONTROLLER_HPP
