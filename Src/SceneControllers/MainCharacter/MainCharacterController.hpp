//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_MAINCHARACTERCONTROLLER_HPP
#define TBRPG_MAINCHARACTERCONTROLLER_HPP

#include "../../Core/Scene/SceneController/SceneController.hpp"
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
    struct KeyEventListener: public Observer::Subscriber {
        MainCharacterController* controller = nullptr;
        KeyEventListener() = default;
        explicit KeyEventListener(MainCharacterController* controller): controller(controller){}
        void onNotified(const Observer::BaseArgs& eventArgs) const override;
    };

    struct UpdateListener: public Observer::Subscriber {
        MainCharacterController* controller = nullptr;
        UpdateListener() = default;
        explicit UpdateListener(MainCharacterController* controller): controller(controller){}
        void onNotified(const Observer::BaseArgs& eventArgs) const override;
    };
    std::shared_ptr<LerperController> lerperController;
    sf::Keyboard::Key pressedKey = sf::Keyboard::Unknown;
    UpdateListener updateListener;
    KeyEventListener keyEventListener;

};



#endif //TBRPG_MAINCHARACTERCONTROLLER_HPP
