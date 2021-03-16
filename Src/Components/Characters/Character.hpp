//
// Created by romaniy on 13.03.2021.
//

#ifndef TBRPG_CHARACTER_HPP
#define TBRPG_CHARACTER_HPP

#include "../Ability/Ability.hpp"
#include "../Weapon/Weapon.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <utility>

class Character {
public:
    std::string name, classType;
    int level, armor, hp, mp, experience;
    std::vector<std::shared_ptr<Ability>> abilities;
    Weapon weapon;

    Character(std::string name, Weapon weapon) : name(name), weapon(weapon) {}

    void addExperience(int x) {
        experience += x;
        if (experience >= 100) {
            level++;
            experience -= 100;
        }
    }

    void changeHp(int x) {
        hp += x;
    }

    void changeMp(int x) {
        mp += x;
    }

    void getAbilities() {
        for (int i = 0; i < abilities.size(); i++) {

            std::cout << abilities[i]->action << std::endl;
        }
    }
};


#endif //TBRPG_CHARACTER_HPP
