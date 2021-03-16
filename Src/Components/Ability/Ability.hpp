//
// Created by romaniy on 13.03.2021.
//

#ifndef TBRPG_ABILITY_HPP
#define TBRPG_ABILITY_HPP


#include <string>
#include <vector>
#include <iostream>
#include <memory>



class Ability {
public:
    std::string name, action;
    int number, cost;

    Ability(std::string action, std::string name, int cost, int number) : action(action), name(name), cost(cost), number(number) {}

    static void useAbility() {
        std::cout << "Ya usanuv abilku" << std::endl;
    }
    std::string getAbilityAction() const {
        return action;
    }
};


#endif //TBRPG_ABILITY_HPP
