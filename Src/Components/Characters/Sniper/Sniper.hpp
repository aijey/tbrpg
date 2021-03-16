//
// Created by romaniy on 14.03.2021.
//

#ifndef TBRPG_SNIPER_HPP
#define TBRPG_SNIPER_HPP

#include "../Character.hpp"
#include "../../Ability/Ability.hpp"
#include <memory>

class Sniper : Character {
public:
    Sniper(std::string x) : Character(x, Weapon("AWP", "sniperRifle", 40, 10, 80)) {
        classType = "Sniper";
        armor = 20;
        hp = 100;
        mp = 130;
        level = 0;
        experience = 0;
        abilities.push_back(std::make_shared<Ability>("Become invisible", "Invisibility", 30,1));
        abilities.push_back(std::make_shared<Ability>("Throw a smoke screen", "Smoke", 40, 2));
        abilities.push_back(std::make_shared<Ability>("Shooting an enemy", "Shot", 20, 3));
    }
};


#endif //TBRPG_SNIPER_HPP
