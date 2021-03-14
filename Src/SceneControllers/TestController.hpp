//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_TESTCONTROLLER_HPP
#define TBRPG_TESTCONTROLLER_HPP

#include "../Core/Scene/SceneController/SceneController.hpp"
class TestController: public SceneController{
public:
    TestController(Scene& scene, SceneResources& resources);
    void run() override;
};


#endif //TBRPG_TESTCONTROLLER_HPP
