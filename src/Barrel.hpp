#ifndef _BARREL_HPP_
#define _BARREL_HPP_

#pragma once
#include "Object.hpp"

class Barrel : public Object
{
    float headRadius, bellyRadius, height;
    int slices = 30, stacks = 30;
    GLUquadric *quad;

  public:
    Barrel(float headRadius, float bellyRadius, float height);
    ~Barrel();
    // Barrel origin is in the center
    void drawObject();
    void update(float deltaTime);
};

#endif