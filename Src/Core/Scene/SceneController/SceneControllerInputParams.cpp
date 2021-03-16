//
// Created by Arturan on 15.03.2021.
//

#include <iostream>
#include "SceneControllerInputParams.hpp"

SceneControllerInputParams::SceneControllerInputParams(SceneControllerInputParams &&other) noexcept {
    std::cout << "Move called" << std::endl;
}
