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
    enum Face { BOTTOM, TOP, FRONT, BACK, LEFT, RIGHT };
    unsigned int textureName;

    Parallelepiped(Vector3 dimensions, Color color = Color(), Material material = Material());
    Parallelepiped(float length = 1, float width = 1, float height = 1, Color color = Color(),
                   Material material = Material());
    void getPlaneEcuation(Face face, float *planeEcuation);
    void drawObject();
    void update(float deltaTime);

    void setDimensions(Vector3 dimensions);
    void setDimensions(float length, float height, float width);
    void setTextureName(unsigned int textureName);
    Vector3 getDimensions();
};

#endif