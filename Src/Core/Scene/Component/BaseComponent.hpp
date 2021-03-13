//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_BASECOMPONENT_HPP
#define TBRPG_BASECOMPONENT_HPP



#include <memory>
class SceneObject;
class BaseComponent {
private:
    std::shared_ptr<SceneObject> sceneObject;
public:
    explicit BaseComponent(std::shared_ptr<SceneObject> sceneObject);
    std::shared_ptr<SceneObject> getSceneObject();
};


#endif //TBRPG_BASECOMPONENT_HPP
