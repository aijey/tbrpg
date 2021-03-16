//
// Created by Arturan on 14.03.2021.
//

#include "MainController.hpp"
#include "../MainCharacter/MainCharacterController.hpp"
#include "../Lerper/LerperController.hpp"
#include "../../Components/Characters/Doctor/Doctor.hpp"


MainController::MainController(Scene &scene, SceneResources &resources)
    : SceneController(scene, resources) {

}
void MainController::run() {
        auto cameraSc = scene.createSceneObject("Camera");
        cameraSc->createCameraComponent(sceneResources.renderWindow);

        auto circleSc = scene.createSceneObject("CircleObject1");
        circleSc->transform.setPosition(sf::Vector2f(150, 150));
        auto circle = std::make_shared<sf::CircleShape>(50);
        circle->setFillColor(sf::Color::Green);
        circleSc->createVisualComponent(circle);

        // krutitisya
        auto scene0 = scene.createSceneObject("MySceneObject");
        auto newCircle = std:: make_shared<sf::CircleShape>(20);
        newCircle->setFillColor(sf::Color::Black);
        scene0->createVisualComponent(newCircle, { 20, 20 });

        auto sceneObject2 = scene.createSceneObject("SquareObject1");
        sceneObject2->transform.setPosition(sf::Vector2f(50, 50));
        sceneObject2->transform.setRotation(45);
        auto square = std::make_shared<sf::RectangleShape>(sf::Vector2f(20, 20));
        square->setFillColor(sf::Color::Yellow);
        sceneObject2->createVisualComponent(square);

        // DOCTOR OBJECT
        auto doctorObject = scene.createSceneObject("Doc");
        auto doctorCircle = std::make_shared<sf::CircleShape>(20);
        doctorCircle->setFillColor(sf::Color::Green);
        doctorObject->createVisualComponent(doctorCircle, {20, 20});

        // ENGINEER OBJECT
        auto engineerObject = scene.createSceneObject("EngineerObject");
        auto engineerCircle = std::make_shared<sf::CircleShape>(20);
        engineerCircle->setFillColor(sf::Color::Blue);
        engineerObject->createVisualComponent(engineerCircle, {20, 20});

        // SNIPER OBJECT
        auto sniperObject = scene.createSceneObject("SniperObject");
        auto sniperCircle = std::make_shared<sf::CircleShape>(20);
        sniperCircle->setFillColor(sf::Color(163, 73, 164)); // Purple
        sniperObject->createVisualComponent(sniperCircle, {20, 20});

        // LerperController
        lerperController = std::make_shared<LerperController>(scene, sceneResources);
        lerperController->run();

        // MainCharacterController
        mainCharacterController =
                std::make_unique<MainCharacterController>(scene, sceneResources,
                                                          MainCharacterController::InputParams(doctorObject,
                                                                                               sniperObject,
                                                                                               engineerObject,
                                                                                               lerperController));
        mainCharacterController->run();

        //TestController
        testController = std::make_shared<TestController>(scene, sceneResources, TestController::InputParams(scene0));
        testController->run();
}



