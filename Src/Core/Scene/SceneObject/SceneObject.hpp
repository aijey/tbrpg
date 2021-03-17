//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_SCENEOBJECT_HPP
#define TBRPG_SCENEOBJECT_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "Transform/Transform.hpp"

class VisualComponent;
class CameraComponent;
class Scene;
class SceneObject {
    friend class Scene;
public:
    Transform transform;
    std::string name;
    explicit SceneObject(const std::string& name, Scene& scene);
    SceneObject(const SceneObject& sceneObject) = delete;

    void createVisualComponent(const std::shared_ptr<sf::Drawable>& drawable);
    void createVisualComponent(const std::shared_ptr<sf::Drawable>& drawable, const sf::Vector2f& pivot);
    void removeVisualComponent(std::shared_ptr<VisualComponent>& visualComponent);

    void createCameraComponent(std::shared_ptr<sf::RenderWindow>& renderWindow);
    void removeCameraComponent(std::shared_ptr<CameraComponent>& cameraComponent);

    std::shared_ptr<SceneObject> copy() const;
protected:
    Scene& scene;
    std::vector<std::shared_ptr<VisualComponent>> visualComponents;
    std::vector<std::shared_ptr<CameraComponent>> cameraComponents;
    void copyCameraComponent(const std::shared_ptr<CameraComponent>& cameraComponent);
    void copyVisualComponent(const std::shared_ptr<VisualComponent>& visualComponent);
    template<class T>
    void removeComponent(std::vector<std::shared_ptr<T>>& from, std::shared_ptr<T>& component);
};




#endif //TBRPG_SCENEOBJECT_HPP
