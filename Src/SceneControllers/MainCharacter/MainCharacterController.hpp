//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_MAINCHARACTERCONTROLLER_HPP
#define TBRPG_MAINCHARACTERCONTROLLER_HPP

#include "../../Core/Scene/SceneController/SceneController.hpp"
#include "../Lerper/LerperController.hpp"

class MainCharacterController: public SceneController {
public:
    MainCharacterController(Scene& scene, SceneResources& resources, std::shared_ptr<LerperController> lerperController);
    void run(std::shared_ptr<SceneObject> doctorObject,
             std::shared_ptr<SceneObject> sniperObject,
             std::shared_ptr<SceneObject> engineerObject);

    std::shared_ptr<LerperController> lerperController;
};


#endif //TBRPG_MAINCHARACTERCONTROLLER_HPP
