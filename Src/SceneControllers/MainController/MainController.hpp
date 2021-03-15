//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_MAINCONTROLLER_HPP
#define TBRPG_MAINCONTROLLER_HPP

#include "../../Core/Scene/SceneController/SceneController.hpp"
#include "MainController.hpp"
class MainController: public SceneController{
public:
    MainController(Scene& scene, SceneResources& resources);
    void run();
};


#endif //TBRPG_MAINCONTROLLER_HPP
