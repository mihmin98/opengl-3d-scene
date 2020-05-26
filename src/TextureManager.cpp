#include "TextureManager.hpp"

TextureManager::TextureManager() {}

TextureManager::~TextureManager() {}

void TextureManager::addTexture(std::string key, std::string filePath)
{
    Texture *texture = new Texture(filePath);
    texture->loadTexture();
    textureDictionary.insert(std::pair<std::string, Texture *>(key, texture));
}

void TextureManager::addTexture(std::string key, Texture *texture)
{
    textureDictionary.insert(std::pair<std::string, Texture *>(key, texture));
}

Texture *TextureManager::getTexture(std::string key) { return textureDictionary.at(key); }