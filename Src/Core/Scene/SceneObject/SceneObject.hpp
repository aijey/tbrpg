//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_SCENEOBJECT_HPP
#define TBRPG_SCENEOBJECT_HPP

#include <memory>
#include "Transform/Transform.hpp"
#include "../Component/VisualComponent/VisualComponent.hpp"

class SceneObject {
public:
    Transform transform;
    std::vector<std::shared_ptr<VisualComponent>> visualComponents;
    std::string name;
    explicit SceneObject(const std::string& name): name(name){};
    void addVisualComponent(std::shared_ptr<VisualComponent> visualComponent);
};


#endif //TBRPG_SCENEOBJECT_HPP
