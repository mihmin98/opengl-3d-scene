#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#ifndef DEG2RAD
#define DEG2RAD 3.14159 / 180.0
#endif

#pragma once
#include "Color.hpp"
#include "GL/freeglut.h"
#include "Material.hpp"
#include "Shadow.hpp"
#include "Transform.hpp"
#include <vector>

class Object
{
  public:
    Transform transform;
    Color color;
    Material material;
    std::vector<Shadow> shadowList;
    bool drawTexture;

    Object(Transform transform = Transform(), Color color = Color(),
           Material material = Material());

    void draw(bool skipColor = false);
    void drawShadows();
    // Pure virtual function that says how the object is drawn (ex. shapes, etc)
    virtual void drawObject() = 0;
    virtual void update(float deltaTime) = 0;

    void addShadow(Shadow shadow);
    virtual void setDrawTexture(bool drawTexture);
};

#endif