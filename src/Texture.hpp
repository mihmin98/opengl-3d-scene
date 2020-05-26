#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#pragma once
#include <cstdlib>
#include <string>
#include <SOIL/SOIL.h>

class Texture
{
    int width, height;
    unsigned char *data;
    std::string filePath;

  public:
    Texture(std::string filePath);
    ~Texture();
    void loadTexture();
    unsigned char *getData();
    int getWidth();
    int getHeight();
};

#endif