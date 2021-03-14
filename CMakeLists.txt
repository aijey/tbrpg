cmake_minimum_required(VERSION 3.17)
project(tbrpg)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR SFML-2.5.1/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES true)
find_package(SFML COMPONENTS graphics audio REQUIRED)
add_executable(tbrpg Src/main.cpp Src/Utils/Observer/Observer.cpp Src/Utils/Observer/Observer.hpp Src/Utils/Observer/ObserverSubscriber.cpp Src/Utils/Observer/ObserverSubscriber.hpp Src/UpdateListener.cpp Src/UpdateListener.hpp Src/Core/Core.cpp Src/Core/Core.hpp Src/Core/Scene/Scene.cpp Src/Core/Scene/Scene.hpp Src/Core/Scene/SceneObject/SceneObject.cpp Src/Core/Scene/SceneObject/SceneObject.hpp Src/Core/Scene/Component/BaseComponent.cpp Src/Core/Scene/Component/BaseComponent.hpp Src/Core/Scene/Component/VisualComponent/VisualComponent.cpp Src/Core/Scene/Component/VisualComponent/VisualComponent.hpp Src/Core/Scene/SceneObject/Transform/Transform.cpp Src/Core/Scene/SceneObject/Transform/Transform.hpp Src/Core/Renderer/Renderer.cpp Src/Core/Renderer/Renderer.hpp Src/Core/Scene/Component/CameraComponent/CameraComponent.cpp Src/Core/Scene/Component/CameraComponent/CameraComponent.hpp Src/Core/Scene/SceneController/SceneController.cpp Src/Core/Scene/SceneController/SceneController.hpp Src/SceneControllers/TestController.cpp Src/SceneControllers/TestController.hpp Src/Core/Scene/SceneResources/SceneResources.cpp Src/Core/Scene/SceneResources/SceneResources.hpp)

target_link_libraries(tbrpg sfml-graphics sfml-audio)
