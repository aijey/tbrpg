//
// Created by Arturan on 14.03.2021.
//

#include "TestControllerUpdateListener.hpp"

TestControllerUpdateListener::TestControllerUpdateListener(SceneObject &sceneObject): sceneObject(sceneObject) {

}

void TestControllerUpdateListener::onNotified(const UpdateEventArgs &eventArgs) {
    sceneObject.transform.position.x += 0.05;
}


