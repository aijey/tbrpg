//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_BASECOMPONENT_HPP
#define TBRPG_BASECOMPONENT_HPP




#include <memory>
#include <iostream>

class SceneObject;
class BaseComponent {
public:
    explicit BaseComponent(SceneObject* sceneObject);
    ~BaseComponent();
    SceneObject* getSceneObject();
private:
    SceneObject* sceneObject;
};


#endif //TBRPG_BASECOMPONENT_HPP
