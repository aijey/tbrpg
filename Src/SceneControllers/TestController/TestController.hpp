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
    InputParams params;
    UpdateListener updateListener;
    KeyPressedListener keyPressedListener;
    std::vector<std::shared_ptr<SceneObject>> sceneObjects;
    TestController(Scene& sc, SceneResources& sceneResources, InputParams params) : SceneController(sc, sceneResources), params(std::move(params)) {

    }
    void run() override;
};


#endif //TBRPG_TESTCONTROLLER_HPP
