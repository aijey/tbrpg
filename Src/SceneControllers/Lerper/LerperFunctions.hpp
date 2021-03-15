//
// Created by Arturan on 15.03.2021.
//

#ifndef TBRPG_LERPERFUNCTIONS_HPP
#define TBRPG_LERPERFUNCTIONS_HPP


class LerperFunctions {
public:
    LerperFunctions() = default;
    virtual void setValue(double x) = 0;
    virtual void onFinish() = 0;
};


#endif //TBRPG_LERPERFUNCTIONS_HPP
