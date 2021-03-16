//
// Created by romaniy on 16.03.2021.
//

#ifndef TBRPG_DOCTORCONTROLLER_HPP
#define TBRPG_DOCTORCONTROLLER_HPP
#include "../../Components/Characters/Doctor/Doctor.hpp"
#include "../MainCharacter/MainCharacterController.hpp"
#include "../MainController/MainController.hpp"


class DoctorController : public SceneController {
    DoctorController(Scene& sc, SceneResources& scRes) : SceneController(sc, scRes) {}
    void run() override {
        Doctor newDoc("EZ-DOC");

    }
};


#endif //TBRPG_DOCTORCONTROLLER_HPP
