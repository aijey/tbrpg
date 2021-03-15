//
// Created by Arturan on 15.03.2021.
//

#ifndef TBRPG_LERPERCONTROLLER_HPP
#define TBRPG_LERPERCONTROLLER_HPP

#include <string>
#include <set>

#include "../../Core/Scene/SceneController/SceneController.hpp"
#include "LerperFunctions.hpp"
#include "LerpedObject.hpp"
class LerperController: public SceneController {
public:
    LerperController(Scene& scene, SceneResources& sceneResources);
    std::shared_ptr<LerpedObject> addObject(std::string name, double fromValue, double toValue, double time,
                                            std::shared_ptr<LerperFunctions> lerperFunctions);
    void run();
private:
    std::multiset<std::shared_ptr<LerpedObject>> lerpedObjects;
    class LerperUpdate: public ObserverSubscriber<UpdateEventArgs> {
        LerperController* lerperController;
        void onNotified(const UpdateEventArgs &eventArgs) override {
            std::vector<std::shared_ptr<LerpedObject>> toRemove;
            for (auto &i: lerperController->lerpedObjects){
                auto time = lerperController->scene.getSceneTime();
                bool result = i->update(time);
                if (result){
                    toRemove.push_back(i);
                }
            }

            for (auto &i: toRemove){
                lerperController->lerpedObjects.erase(i);
            }

        }

    public:
        explicit LerperUpdate(LerperController *lerperController): lerperController(lerperController){}
    };
};



#endif //TBRPG_LERPERCONTROLLER_HPP
