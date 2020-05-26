#include "Texture.hpp"
#include <iostream>

Texture::Texture(std::string filePath)
{
    this->filePath = filePath;
    data = nullptr;
    width = 0;
    height = 0;
}

Texture::~Texture()
{
    SOIL_free_image_data(data);
    glDeleteTextures(1, &textureName);
}

void Texture::loadTexture()
{
    data = SOIL_load_image(filePath.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    std::cout << filePath << ": " << SOIL_last_result() << "\n";

    glGenTextures(1, &textureName);
    glBindTexture(GL_TEXTURE_2D, textureName);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
}

unsigned char *Texture::getData() { return data; }

int Texture::getWidth() { return width; }

int Texture::getHeight() { return height; }