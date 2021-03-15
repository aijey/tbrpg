//
// Created by Arturan on 14.03.2021.
//

#ifndef TBRPG_TESTCONTROLLERUPDATELISTENER_HPP
#define TBRPG_TESTCONTROLLERUPDATELISTENER_HPP


#include "../../Utils/Observer/ObserverSubscriber.hpp"
#include "../../Core/Scene/SceneEventArgs/UpdateEventArgs/UpdateEventArgs.hpp"
#include "../../Core/Scene/SceneObject/SceneObject.hpp"

class TestControllerUpdateListener: public ObserverSubscriber<UpdateEventArgs> {
public:
    explicit TestControllerUpdateListener(SceneObject& sceneObject);
    void onNotified(const UpdateEventArgs &eventArgs) override;
private:
    SceneObject& sceneObject;
};


#endif //TBRPG_TESTCONTROLLERUPDATELISTENER_HPP
