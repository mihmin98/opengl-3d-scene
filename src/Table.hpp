#ifndef _TABLE_HPP_
#define _TABLE_HPP_

#pragma once
#include "Object.hpp"
#include "Parallelepiped.hpp"
#include "Vector3.hpp"

class Table : public Object
{
    Vector3 topDimensions, legDimensions;
    Parallelepiped top, leg; // legs are in order: bot-left, bot-right, top-right, top-left
    void generateParallelepipeds();

  public:
    Table(Vector3 topDimensions, Vector3 legDimensions);
    Table(float topLength, float topWidth, float topHeight, float legLength, float legWidth,
          float legHeight);

    void drawObject();
    void update(float deltaTime);
    float getFullHeight();
};

#endif