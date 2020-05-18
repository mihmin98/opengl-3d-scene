#ifndef _PARALLELEPIPED_HPP_
#define _PARALLELEPIPED_HPP_

#include "Object.hpp"

class Parallelepiped : public Object
{
    float length, width, height;

  public:
    Parallelepiped(float length = 1, float width = 1, float height = 1);
    void drawObject();
    void update(float deltaTime);
};

#endif