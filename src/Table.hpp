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
    unsigned int textureName;
    void generateParallelepipeds();

  public:
    Table(Vector3 topDimensions, Vector3 legDimensions, Color color = Color(150, 111, 51, 255),
          Material material = Material());
    Table(float topLength, float topWidth, float topHeight, float legLength, float legWidth,
          float legHeight, Color color = Color(150, 111, 51, 255), Material material = Material());

    void drawObject();
    void update(float deltaTime);
    void setDrawTexture(bool drawTexture);
    void setTextureName(unsigned int textureName);
    float getTopHeight();
    float getLegHeight();
    float getFullHeight();
    void getTopSurfaceEcuation(float *planeEcuation);
};

#endif