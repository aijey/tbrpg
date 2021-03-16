//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_MAINCONTROLLER_HPP
#define TBRPG_MAINCONTROLLER_HPP

#include "../../Core/Scene/SceneController/SceneController.hpp"
#include "../Lerper/LerperController.hpp"
#include "../MainCharacter/MainCharacterController.hpp"

class MainController: public SceneController {
public:
    MainController(Scene& scene, SceneResources& resources);
    void run() override;
    std::shared_ptr<LerperController> lerperController;
    std::shared_ptr<MainCharacterController> mainCharacterController;
};


#endif //TBRPG_MAINCONTROLLER_HPP
