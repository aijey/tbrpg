//
// Created by romaniy on 13.03.2021.
//

#ifndef TBRPG_DOCTOR_HPP
#define TBRPG_DOCTOR_HPP

#include "../Character.hpp"
#include "../../Ability/Ability.hpp"
#include <memory>

class Doctor : public Character {
public:
    Doctor(std::string x) : Character(x, Weapon("XM1014", "Shotgun", 40, 8, 60)) {
        classType = "Doctor";
        armor = 40;
        hp = 150;
        mp = 200;
        level = 0;
        experience = 0;
        abilities.push_back(std::make_shared<Ability>("Heal yourself or an ally", "Heal", 30, 1));
        abilities.push_back(std::make_shared<Ability>("Revive an ally", "Revive", 40, 2));
        abilities.push_back(std::make_shared<Ability>("Shooting an enemy", "Shot", 20, 3));
    }
};



#endif //TBRPG_DOCTOR_HPP
