#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#ifndef DEG2RAD
#define DEG2RAD 3.14159 / 180.0
#endif

#pragma once
#include "Transform.hpp"
#include "GL/freeglut.h"

class Object
{
public:
    Transform transform;

    Object(Transform transform = Transform());

    void draw();
    virtual void drawObject() = 0; // Pure virtual function that says how the object is drawn (ex. shapes, etc)
    virtual void update(float deltaTime) = 0;
};

#endif