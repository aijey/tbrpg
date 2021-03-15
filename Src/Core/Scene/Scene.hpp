//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_SCENE_HPP
#define TBRPG_SCENE_HPP


#include "SceneObject/SceneObject.hpp"
#include "SceneResources/SceneResources.hpp"
#include "SceneEventArgs/KeyEventArgs/KeyEventArgs.hpp"
#include "SceneEventArgs/UpdateEventArgs/UpdateEventArgs.hpp"
#include "../../Utils/Observer/Observer.hpp"
#include <vector>
#include <chrono>
class SceneController;
class Scene {
    friend class SceneObject;
    friend class Renderer;
public:
    Scene() = default;
    std::shared_ptr<SceneObject> createSceneObject(const std::string& name);
    void addController(std::shared_ptr<SceneController> sceneController);
    std::vector<std::shared_ptr<SceneObject>> sceneObjects;
    std::vector<std::shared_ptr<VisualComponent>> visualComponents;
    std::vector<std::shared_ptr<CameraComponent>> cameraComponents;
    std::vector<std::shared_ptr<SceneController>> sceneControllers;
    void loadScene(SceneResources& resources);
    Observer<UpdateEventArgs> updateEvent;
    Observer<KeyEventArgs> keyPressedEvent;
    Observer<UpdateEventArgs> lateUpdateEvent;
    Observer<KeyEventArgs> keyReleasedEvent;

    void setSceneTime(double time);
    double getSceneTime() const;

private:
    double sceneTime;
};


#endif //TBRPG_SCENE_HPP
