#ifndef _TEXTURE_MANAGER_HPP_
#define _TEXTURE_MANAGER_HPP_

#pragma once
#include "Texture.hpp"
#include <map>
#include <string>

class TextureManager
{
    std::map<std::string, Texture *> textureDictionary;

  public:
    TextureManager();
    ~TextureManager();
    void addTexture(std::string key, std::string filePath);
    void addTexture(std::string key, Texture *texture);
    Texture *getTexture(std::string key);
};

#endif