//
// Created by Arturan on 15.03.2021.
//

#ifndef TBRPG_LERPEDOBJECT_HPP
#define TBRPG_LERPEDOBJECT_HPP


#include <string>
#include <memory>
#include "LerperFunctions.hpp"

class LerpedObject {
public:
    std::string name;
    double fromValue;
    double toValue;
    double fromTime;
    double toTime;
    std::shared_ptr<LerperFunctions> lerperFunctions;
    LerpedObject(std::string& name,
                 double fromValue,
                 double toValue,
                 double fromTime,
                 double toTime,
                 std::shared_ptr<LerperFunctions> lerperFunctions);
    bool update(double time);
};


#endif //TBRPG_LERPEDOBJECT_HPP
