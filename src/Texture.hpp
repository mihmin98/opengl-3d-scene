#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#pragma once
#include <cstdlib>
#include <string>
#include <SOIL/SOIL.h>
#include <GL/freeglut.h>

class Texture
{
    int width, height;
    unsigned char *data;
    unsigned int textureName;
    std::string filePath;

  public:
    Texture(std::string filePath);
    ~Texture();
    void loadTexture();
    unsigned char *getData();
    unsigned int getTextureName();
    int getWidth();
    int getHeight();
};

#endif