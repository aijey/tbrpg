//
// Created by Arturan on 15.03.2021.
//

#ifndef TBRPG_SCENECONTROLLERINPUTPARAMS_HPP
#define TBRPG_SCENECONTROLLERINPUTPARAMS_HPP


class SceneControllerInputParams {
public:
    SceneControllerInputParams() = default;
    SceneControllerInputParams(SceneControllerInputParams& other) = delete;
    SceneControllerInputParams(SceneControllerInputParams&& other) noexcept;
};


#endif //TBRPG_SCENECONTROLLERINPUTPARAMS_HPP
