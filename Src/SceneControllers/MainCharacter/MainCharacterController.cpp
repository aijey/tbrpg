//
// Created by Arturan on 14.03.2021.
//

#include "MainCharacterController.hpp"
#include "../Lerper/LerperFunctions.hpp"


MainCharacterController::MainCharacterController(Scene &scene, SceneResources &resources,
                                                 std::shared_ptr<LerperController> lerperController)
                                                 : SceneController(scene, resources), lerperController(lerperController) {

}

void MainCharacterController::run(std::shared_ptr<SceneObject> doctorObject, std::shared_ptr<SceneObject> sniperObject,
                                  std::shared_ptr<SceneObject> engineerObject) {
    class TestLerperFunctions: public LerperFunctions {
    public:
        MainCharacterController* mainCharacterController;
        explicit TestLerperFunctions(MainCharacterController* mainCharacterController): mainCharacterController(mainCharacterController){}
        void setValue(double value) override {
            std::cout << mainCharacterController->scene.getSceneTime() << " -> " << value << std::endl;
        }
        void onFinish() override {

        }
    };

    lerperController->run();
    auto functions = std::make_shared<TestLerperFunctions>(this);
    auto obj = lerperController->addObject("TestObj", -10, 10, 20, functions);
}




