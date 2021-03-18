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
        class Subscriber: public Observer::Subscriber {
            void onNotified(const BaseArgs &eventArgs) const override;
            virtual void onNotified(const Args& args) const = 0;
        };
        template<class CaptureType, void(*Callback)(CaptureType& , const Args&)>
        class SubscriberOnCb: public Observer::Subscriber{
        public:
            mutable CaptureType captures;
            SubscriberOnCb() = default;
            explicit SubscriberOnCb(CaptureType captures);
            void onNotified(const BaseArgs &eventArgs) const override;
        };
    };
    class KeyEvent: public Observer {
    public:
        struct Args: public Observer::BaseArgs{
            explicit Args(sf::Keyboard::Key code);
            sf::Keyboard::Key code;
        };
        class Subscriber: public Observer::Subscriber {
            void onNotified(const BaseArgs &eventArgs) const override;
            virtual void onNotified(const Args& args) const = 0;
        };
    };
    class DelayedEvent: public Observer {
    public:
        struct Args: public Observer::BaseArgs{

        };
        class Subscriber: public Observer::Subscriber {
        public:
            explicit Subscriber(double notifyAt);
            Subscriber() = default;
            void onNotified(const BaseArgs &eventArgs) const override;
            virtual void onNotified(const Args& args) const = 0;
            double notifyAt;
        };

        explicit DelayedEvent(Scene* scene);
    private:
        class UpdateListener: public UpdateEvent::Subscriber {
        public:
            DelayedEvent* delayedEvent = nullptr;
            explicit UpdateListener(DelayedEvent* delayedEvent);
            UpdateListener() = default;
            void onNotified(const Scene::UpdateEvent::Args &args) const override;
        };

        UpdateListener updateListener;
        Scene* scene;
    };

    Scene();
    std::shared_ptr<SceneObject> createSceneObject(const std::string& name);
    void removeSceneObject(const std::shared_ptr<SceneObject>& sceneObject);
    std::vector<std::shared_ptr<SceneObject>> sceneObjects;
    double getSceneTime() const;
    UpdateEvent updateEvent;
    KeyEvent keyPressedEvent;
    UpdateEvent lateUpdateEvent;
    KeyEvent keyReleasedEvent;
    DelayedEvent delayedEvent;
private:
    void loadScene(SceneResources& resources);
    std::shared_ptr<MainController> mainController;
    std::vector<std::shared_ptr<VisualComponent>> visualComponents;
    std::vector<std::shared_ptr<CameraComponent>> cameraComponents;
    template<class T>
    void removeComponents(std::vector<std::shared_ptr<T>>& from, std::vector<std::shared_ptr<T>>& components);
    template<class T>
    void removeComponent(std::vector<std::shared_ptr<T>>& from, std::shared_ptr<T>& component);
    void removeAllSceneObjectComponents(const std::shared_ptr<SceneObject> &sceneObject);
    void setSceneTime(double time);
    double sceneTime = 0.0;
};

template<class CaptureType, void (*Callback)(CaptureType& , const Scene::UpdateEvent::Args&)>
void Scene::UpdateEvent::SubscriberOnCb<CaptureType, Callback>::onNotified(const Observer::BaseArgs& eventArgs) const {
    const Scene::UpdateEvent::Args& updateEventArgs =
            *static_cast<Scene::UpdateEvent::Args*>(const_cast<Observer::BaseArgs*>(&eventArgs));
    Callback(captures, updateEventArgs);
}

template<class CaptureType, void (*Callback)(CaptureType& , const Scene::UpdateEvent::Args &)>
Scene::UpdateEvent::SubscriberOnCb<CaptureType, Callback>::SubscriberOnCb(CaptureType captures): captures(std::move(captures)) {

}


#endif //TBRPG_SCENE_HPP
