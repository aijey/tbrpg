//
// Created by Arturan on 15.03.2021.
//

#include <iostream>
#include "LerpedObject.hpp"

LerpedObject::LerpedObject(std::string &name, double fromValue, double toValue, double fromTime, double toTime,
                           std::shared_ptr<LerperFunctions> lerperFunctions)
    : name(name), fromValue(fromValue), toValue(toValue), fromTime(fromTime), toTime(toTime),
    lerperFunctions(lerperFunctions){

}

bool LerpedObject::update(double time) {
    double mult = (time - fromTime) / (toTime - fromTime);
    if (mult >= 1.0){
        lerperFunctions->setValue(toValue);
        lerperFunctions->onFinish();
        return true;
    } else {
        double value = mult * (toValue - fromValue) + fromValue;
        lerperFunctions->setValue(value);
        return false;
    }
}
