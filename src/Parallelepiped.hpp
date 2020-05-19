#ifndef _PARALLELEPIPED_HPP_
#define _PARALLELEPIPED_HPP_

#pragma once
#include "Object.hpp"
#include "Vector3.hpp"

class Parallelepiped : public Object
{
    // x = length, y = height, z = width
    Vector3 dimensions;

  public:
    Parallelepiped(Vector3 dimensions);
    Parallelepiped(float length = 1, float width = 1, float height = 1);
    void drawObject();
    void update(float deltaTime);
};

#endif