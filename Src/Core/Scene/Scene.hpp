//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_SCENE_HPP
#define TBRPG_SCENE_HPP


#include "SceneObject/SceneObject.hpp"
#include "SceneResources/SceneResources.hpp"
#include "../../Utils/Observer/Observer.hpp"
#include <vector>
#include <chrono>
#include <SFML/Graphics.hpp>
class MainController;
class SceneController;
class Scene {
    friend class SceneObject;
    friend class Renderer;
    friend class Core;


public:
    class UpdateEvent : public Observer {
    public:
        struct Args: public Observer::BaseArgs{
            explicit Args(double d);
            double deltaTime;
        };
        void notifyAll(const Args& eventArgs) {
            Observer::notifyAll(eventArgs);
        }
    };
    class KeyEvent: public Observer {
    public:
        struct Args: public Observer::BaseArgs{
            explicit Args(sf::Keyboard::Key code);
            sf::Keyboard::Key code;
        };
        void notifyAll(const Args& eventArgs) {
            Observer::notifyAll(eventArgs);
        }
    };
    Scene();
    std::shared_ptr<SceneObject> createSceneObject(const std::string& name);
    std::vector<std::shared_ptr<SceneObject>> sceneObjects;
    std::vector<std::shared_ptr<VisualComponent>> visualComponents;
    std::vector<std::shared_ptr<CameraComponent>> cameraComponents;
    std::shared_ptr<MainController> mainController;
    void loadScene(SceneResources& resources);
    UpdateEvent updateEvent;
    KeyEvent keyPressedEvent;
    UpdateEvent lateUpdateEvent;
    KeyEvent keyReleasedEvent;

    void setSceneTime(double time);
    double getSceneTime() const;

private:
    double sceneTime = 0.0;
};


#endif //TBRPG_SCENE_HPP
