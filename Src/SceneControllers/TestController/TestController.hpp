//
// Created by romaniy on 16.03.2021.
//

#ifndef TBRPG_TESTCONTROLLER_HPP
#define TBRPG_TESTCONTROLLER_HPP

#include <utility>

#include "../../Core/Scene/SceneController/SceneController.hpp"

class TestController : public SceneController {
public:
    struct InputParams : public SceneControllerInputParams {
        std::shared_ptr<SceneObject> circle;
        explicit InputParams(std::shared_ptr<SceneObject> circle) : circle(std::move(circle)) {}
    };
    class UpdateListener : public Scene::UpdateEvent::Subscriber {
    public:
        TestController* testController = nullptr;
        explicit UpdateListener(TestController* testController) : testController(testController) {};
        UpdateListener() = default;
        void onNotified(const Scene::UpdateEvent::Args& args) const override;
    };
    class KeyPressedListener : public Scene::KeyEvent::Subscriber {
    public:
        TestController* testController = nullptr;
        explicit KeyPressedListener(TestController* testController) : testController(testController) {};
        KeyPressedListener() = default;
        void onNotified(const Scene::KeyEvent::Args& args) const override;
    };
    class KeyReleasedListener : public Scene::KeyEvent::Subscriber {
    public:
        TestController* testController = nullptr;
        explicit KeyReleasedListener(TestController* testController) : testController(testController) {};
        KeyReleasedListener() = default;
        void onNotified(const Scene::KeyEvent::Args& args) const override;
    };
    class DelayedEventListener: public Scene::DelayedEvent::Subscriber {
    public:
        TestController* testController = nullptr;
        explicit DelayedEventListener(TestController* testController, double notifyAt)
            :Scene::DelayedEvent::Subscriber(notifyAt), testController(testController) {};
        DelayedEventListener() = default;
        void onNotified(const Scene::DelayedEvent::Args& args) const override;
    };
    struct UpdateCaptures {
        TestController* testController = nullptr;
        UpdateCaptures() = default;
        static void onUpdate(UpdateCaptures captures, const Scene::UpdateEvent::Args& args);
    };

    InputParams params;
    UpdateListener updateListener;
    Scene::UpdateEvent::SubscriberAdv<UpdateCaptures, UpdateCaptures::onUpdate> updateListener2;
    KeyPressedListener keyPressedListener;
    KeyReleasedListener keyReleasedListener;
    DelayedEventListener delayedEventListener;
    void (*onUpdate)(const Observer::BaseArgs& args) = nullptr;
    int someInt = 123;
    std::vector<std::shared_ptr<SceneObject>> sceneObjects;
    bool isSPressed = false;
    TestController(Scene& sc, SceneResources& sceneResources, InputParams params) : SceneController(sc, sceneResources), params(std::move(params)) {

    }
    void run() override;
};


#endif //TBRPG_TESTCONTROLLER_HPP
