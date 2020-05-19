#ifndef _DRINKING_GLASS_HPP_
#define _DRINKING_GLASS_HPP_

#pragma once
#include "Object.hpp"

class DrinkingGlass : public Object
{
    float topRadius, baseRadius, height;
    GLUquadric *quad;
    unsigned char color[4] = {198, 226, 227, 30};

  public:
    DrinkingGlass(float topRadius, float baseRadius, float height);
    ~DrinkingGlass();
    void drawObject();
    void update(float deltaTime);

    void setTopRadius(float topRadius);
    void setBaseRadius(float baseRadius);
    void setHeight(float height);
    float getTopRadius();
    float getBaseRadius();
    float getHeight();
};

#endif