//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_SCENEOBJECT_HPP
#define TBRPG_SCENEOBJECT_HPP

#include <memory>
#include "Transform/Transform.hpp"
#include "../Component/VisualComponent/VisualComponent.hpp"
#include "../Component/CameraComponent/CameraComponent.hpp"


class Scene;
class SceneObject {
public:
    Transform transform;
    std::vector<std::shared_ptr<VisualComponent>> visualComponents;
    std::vector<std::shared_ptr<CameraComponent>> cameraComponents;
    std::string name;
    explicit SceneObject(const std::string& name, Scene& scene);
    void createVisualComponent(std::shared_ptr<sf::Drawable> drawable);
    void createVisualComponent(std::shared_ptr<sf::Drawable> drawable, const sf::Vector2f& pivot);
    void copyVisualComponent(const std::shared_ptr<VisualComponent>& visualComponent);
    void createCameraComponent(std::shared_ptr<sf::RenderWindow> renderWindow);
    void copyCameraComponent(const std::shared_ptr<CameraComponent>& cameraComponent);
    SceneObject(const SceneObject& sceneObject) = delete;
    std::shared_ptr<SceneObject> copy() const;

private:
    Scene& scene;
};


#endif //TBRPG_SCENEOBJECT_HPP
