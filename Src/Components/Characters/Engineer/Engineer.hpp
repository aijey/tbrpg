//
// Created by romaniy on 14.03.2021.
//

#ifndef TBRPG_ENGINEER_HPP
#define TBRPG_ENGINEER_HPP

#include "../Character.hpp"
#include "../../Ability/Ability.hpp"
#include "../../Weapon/Weapon.hpp"
#include <memory>

class Engineer : Character {
public:
    Engineer(std::string x) : Character(x, Weapon("AK-47", "assaultRifle", 120, 30, 30)){
        classType = "Engineer";
        armor = 30;
        hp = 125;
        mp = 160;
        level = 0;
        experience = 0;
        abilities.push_back(std::make_shared<Ability>("Drops a bag of ammo", "Ammo", 30,1));
        abilities.push_back(std::make_shared<Ability>("Place a turret", "Turret", 40, 2));
        abilities.push_back(std::make_shared<Ability>("Shooting an enemy", "Shot", 20, 3));
    }
};


#endif //TBRPG_ENGINEER_HPP
