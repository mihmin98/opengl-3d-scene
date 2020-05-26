#ifndef _BARREL_HPP_
#define _BARREL_HPP_

#pragma once
#include "Object.hpp"
#include "Texture.hpp"

class Barrel : public Object
{
    float headRadius, bellyRadius, height;
    int slices = 30, stacks = 30;
    GLUquadric *quad;
    unsigned int barrelTextureName, woodTextureName;

  public:
    Barrel(float headRadius, float bellyRadius, float height,
           Color color = Color(150, 111, 51, 255), Material material = Material());
    ~Barrel();
    // Barrel origin is in the center
    void drawObject();
    void update(float deltaTime);

    void setHeadRadius(float headRadius);
    void setBellyRadius(float bellyRadius);
    void setHeight(float height);
    void setBarrelTextureName(unsigned int barrelTextureName);
    void setWoodTextureName(unsigned int woodTextureName);
    float getHeadRadius();
    float getBellyRadius();
    float getHeight();
};

#endif