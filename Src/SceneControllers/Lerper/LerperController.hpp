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
    void run() override;
private:
    std::multiset<std::shared_ptr<LerpedObject>> lerpedObjects;
class UpdateListener: public Observer::Subscriber {
        LerperController* lerperController = nullptr;
        void onNotified(const Observer::BaseArgs &eventArgs) const override;

    public:
        UpdateListener() = default;
        explicit UpdateListener(LerperController *lerperController): lerperController(lerperController){}
    };
    UpdateListener updateListener;
};



#endif //TBRPG_LERPERCONTROLLER_HPP
