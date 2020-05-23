#ifndef _DRINKING_GLASS_HPP_
#define _DRINKING_GLASS_HPP_

#pragma once
#include "Object.hpp"

class DrinkingGlass : public Object
{
    float topRadius, baseRadius, height;
    GLUquadric *quad;

  public:
    DrinkingGlass(float topRadius, float baseRadius, float height, Color color = Color(198, 226, 227, 30));
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