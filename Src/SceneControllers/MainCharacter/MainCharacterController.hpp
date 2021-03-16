//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_MAINCHARACTERCONTROLLER_HPP
#define TBRPG_MAINCHARACTERCONTROLLER_HPP

#include "../../Core/Scene/SceneController/SceneController.hpp"
#include "../TestController/TestController.hpp"
#include "../Lerper/LerperController.hpp"

class MainCharacterController: public SceneController {
public:
    struct InputParams: public SceneControllerInputParams {
        std::shared_ptr<SceneObject> doctorObject;
        std::shared_ptr<SceneObject> sniperObject;
        std::shared_ptr<SceneObject> engineerObject;
        std::shared_ptr<LerperController> lerperController;
        InputParams(std::shared_ptr<SceneObject> doctorObject, std::shared_ptr<SceneObject> sniperObject,
                    std::shared_ptr<SceneObject> engineerObject, std::shared_ptr<LerperController> lerperController);
    };

    MainCharacterController(Scene& scene, SceneResources& resources, InputParams inputParams);
    void run() override;
    InputParams inputParams;


private:
    struct KeyPressedEventListener: public Scene::KeyEvent::Subscriber {
        MainCharacterController* controller = nullptr;
        KeyPressedEventListener() = default;
        explicit KeyPressedEventListener(MainCharacterController* controller): controller(controller){}
        void onNotified(const Scene::KeyEvent::Args& eventArgs) const override;
    };

    struct KeyReleasedEventListener: public Scene::KeyEvent::Subscriber {
        MainCharacterController* controller = nullptr;
        KeyReleasedEventListener() = default;
        explicit KeyReleasedEventListener(MainCharacterController* controller): controller(controller){}
        void onNotified(const Scene::KeyEvent::Args& eventArgs) const override;
    };

    struct UpdateListener: public Scene::UpdateEvent::Subscriber {
        MainCharacterController* controller = nullptr;
        UpdateListener() = default;
        explicit UpdateListener(MainCharacterController* controller): controller(controller){}
        void onNotified(const Scene::UpdateEvent::Args& eventArgs) const override;
    };
    std::shared_ptr<LerperController> lerperController;
    sf::Keyboard::Key pressedKey = sf::Keyboard::Unknown;
    UpdateListener updateListener;
    KeyPressedEventListener keyPressedEventListener;
    KeyReleasedEventListener keyReleasedEventListener;
};



#endif //TBRPG_MAINCHARACTERCONTROLLER_HPP
