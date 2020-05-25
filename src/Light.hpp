#ifndef _LIGHT_HPP_
#define _LIGHT_HPP_

#pragma once
#include "Color.hpp"
#include "Vector3.hpp"
#include <GL/freeglut.h>

class Light
{
    GLenum lightNumber;
    Vector3 position;
    float ambient[4], diffuse[4], specular[4], positionv[4];

  public:
    Light(GLenum lightNumber, Color ambient = Color(), Color diffuse = Color(),
          Color specular = Color(), Vector3 position = Vector3());
    Light(GLenum lightNumber, Color lightColor, Vector3 position = Vector3());
    Light(GLenum lightNumber, float ambient[4], float diffuse[4], float specular[4],
          Vector3 position = Vector3());

    void applyLight();

    void setPosition(Vector3 position);
    Vector3 getPosition();
    float *getPositionv();
};

#endif