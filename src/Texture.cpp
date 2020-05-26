#include "Texture.hpp"

Texture::Texture(std::string filePath)
{
    this->filePath = filePath;
    data = nullptr;
}

void Texture::loadTexture()
{
    data = SOIL_load_image(filePath.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
}

unsigned char *Texture::getData() { return data; }

int Texture::getWidth() { return width; }

int Texture::getHeight() { return height; }