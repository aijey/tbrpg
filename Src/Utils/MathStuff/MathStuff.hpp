//
// Created by Arturan on 18.03.2021.
//

#ifndef TBRPG_MATHSTUFF_HPP
#define TBRPG_MATHSTUFF_HPP

#include <cmath>

namespace MathStuff {
    const double PI = std::acos(-1);
    template<class T>
    T rotate2DVectorDegrees(const T& vector, const double& degrees){
        double angle = degrees * PI / 180.0;
        auto res = vector;
        res.x = vector.x * std::cos(angle) - vector.y * std::sin(angle);
        res.y = vector.x * std::sin(angle) + vector.y * std::cos(angle);
        return res;
    }
};


#endif //TBRPG_MATHSTUFF_HPP
