//
// Created by Arturan on 13.03.2021.
//

#ifndef TBRPG_VISUALCOMPONENT_HPP
#define TBRPG_VISUALCOMPONENT_HPP
#include "../BaseComponent.hpp"
#include <memory>
class VisualComponent: public BaseComponent {
public:
    VisualComponent(std::shared_ptr<SceneObject> sceneObject);
private:
    std::shared_ptr<SceneObject> sceneObject;
    virtual void attachToSceneObject();
};


#endif //TBRPG_VISUALCOMPONENT_HPP
