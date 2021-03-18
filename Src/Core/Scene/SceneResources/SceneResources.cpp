//
// Created by Arturan on 14.03.2021.
//

#include "SceneResources.hpp"

#include <utility>

SceneResources::SceneResources(std::shared_ptr<sf::RenderWindow> renderWindow): renderWindow(std::move(renderWindow)) {

}

sf::Texture* SceneResources::loadTexture(const std::string &filename) {
    auto texture = std::make_shared<sf::Texture>();
    auto status = texture->loadFromFile(filename);
    if (status){
        textures[filename] = texture;
        return texture.get();
    }
    return nullptr;
}

void SceneResources::unloadTexture(const std::string &filename){
    textures.erase(filename);
}
