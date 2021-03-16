//
// Created by romaniy on 14.03.2021.
//

#ifndef TBRPG_WEAPON_HPP
#define TBRPG_WEAPON_HPP

#include "../Bullet/Bullet.hpp"
#include <iostream>
#include <vector>
#include <memory>

class Weapon {
public:
    std::string name, type;
    int damage, currentAmmo, spareAmmo, allAmmo, ammoInMagazine;
    std::vector <std::shared_ptr<Bullet>> bullets;


    Weapon(std::string name, std::string type, int allAmmo, int ammoInMagazine, int damage) : name(name), type(type), allAmmo(allAmmo), ammoInMagazine(ammoInMagazine), damage(damage) {
        currentAmmo = ammoInMagazine;
        spareAmmo = allAmmo - ammoInMagazine;
    }

    void Fire() {
        currentAmmo--;
        auto bullet = std::make_shared<Bullet>(0,0,1);
        bullets.push_back(bullet);
    }
    void Reload() {
        spareAmmo = spareAmmo + currentAmmo - ammoInMagazine;
        currentAmmo = ammoInMagazine;
    }
};


#endif //TBRPG_WEAPON_HPP
