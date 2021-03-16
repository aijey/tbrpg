//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_SCENECONTROLLER_HPP
#define TBRPG_SCENECONTROLLER_HPP



#include "../SceneResources/SceneResources.hpp"
#include "SceneControllerInputParams.hpp"
class Scene;
#include "../Scene.hpp"
class SceneController {
public:
    SceneController(Scene& scene, SceneResources& sceneResources);
    virtual void run() = 0;
protected:
    Scene& scene;
    SceneResources& sceneResources;
};



#endif //TBRPG_SCENECONTROLLER_HPP
