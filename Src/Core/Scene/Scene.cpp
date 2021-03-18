//
// Created by Arturan on 13.03.2021.
//

#include <iostream>
#include "Scene.hpp"
#include "../../SceneControllers/MainController/MainController.hpp"

Scene::Scene(): delayedEvent(this) {
};


std::shared_ptr<SceneObject> Scene::createSceneObject(const std::string& name){
    auto sceneObject = std::make_shared<SceneObject>(name, *this);
    sceneObjects.push_back(sceneObject);
    return sceneObject;
}

void Scene::loadScene(SceneResources& resources) {
    mainController = std::make_shared<MainController>(*this, resources);
    mainController->run();
}

void Scene::removeSceneObject(const std::shared_ptr<SceneObject> &sceneObject) {
    auto it = std::find(sceneObjects.begin(), sceneObjects.end(), sceneObject);
    sceneObjects.erase(it);
    removeAllSceneObjectComponents(sceneObject);
}

void Scene::removeAllSceneObjectComponents(const std::shared_ptr<SceneObject> &sceneObject) {
    removeComponents(visualComponents, sceneObject->visualComponents);
    removeComponents(cameraComponents, sceneObject->cameraComponents);
}

template<class T>
void Scene::removeComponents(std::vector<std::shared_ptr<T>>& from, std::vector<std::shared_ptr<T>>& components) {
    for (auto& component: components){
        removeComponent(from, component);
    }
}

template<class T>
void Scene::removeComponent(std::vector<std::shared_ptr<T>>& from, std::shared_ptr<T>& component) {
    auto it = std::find(from.begin(), from.end(), component);
    from.erase(it);
}

void Scene::setSceneTime(double time) {
    sceneTime = time;
}

double Scene::getSceneTime() const {
    return sceneTime;
}

Scene::UpdateEvent::Args::Args(double d): deltaTime(d) {

}

Scene::KeyEvent::Args::Args(sf::Keyboard::Key code): code(code) {

}

void Scene::UpdateEvent::Subscriber::onNotified(const Observer::BaseArgs &eventArgs) const {
    const Args& updateEventArgs = *static_cast<Args*>(const_cast<Observer::BaseArgs*>(&eventArgs));
    onNotified(updateEventArgs);
}

void Scene::KeyEvent::Subscriber::onNotified(const Observer::BaseArgs &eventArgs) const {
    const Args& keyEventArgs = *static_cast<Args*>(const_cast<Observer::BaseArgs*>(&eventArgs));
    onNotified(keyEventArgs);
}

void Scene::DelayedEvent::Subscriber::onNotified(const Observer::BaseArgs &eventArgs) const {
    const Args& keyEventArgs = *static_cast<Args*>(const_cast<Observer::BaseArgs*>(&eventArgs));
    onNotified(keyEventArgs);
}

Scene::DelayedEvent::Subscriber::Subscriber(double notifyAt): notifyAt(notifyAt) {

}

void Scene::DelayedEvent::UpdateListener::onNotified(const Scene::UpdateEvent::Args &args) const {
    auto curTime = delayedEvent->scene->getSceneTime();
    std::vector<Observer::Subscriber*> toRemove;

    for (auto i: delayedEvent->subscribers){
        auto sub = static_cast<DelayedEvent::Subscriber *>(i);
        if (curTime >= sub->notifyAt){
            sub->notify({});
            toRemove.push_back(sub);
        }
    }
    for (auto& i: toRemove) {
        delayedEvent->subscribers.erase(i);
    }

}

Scene::DelayedEvent::UpdateListener::UpdateListener(DelayedEvent *delayedEvent): delayedEvent(delayedEvent) {
}

Scene::DelayedEvent::DelayedEvent(Scene *scene): scene(scene) {
    updateListener = UpdateListener(this);
    scene->updateEvent.subscribe(&updateListener);
}
