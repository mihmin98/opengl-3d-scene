#ifndef _MATERIAL_HPP_
#define _MATERIAL_HPP_

#pragma once
#include "Color.hpp"
#include <GL/freeglut.h>

class Material
{
    float specular[4];
    float emission[4];

  public:
    Material(Color specular = Color(255, 255, 255, 255), Color emission = Color(0, 0, 0, 255));
    Material(float *specular, float *emission);
    void applyMaterial();

    void setSpecular(float *specular);
    void setSpecular(Color specular);
    void setEmission(float *emission);
    void setEmission(Color emission);

    float *getSpecular();
    float *getEmission();
};

#endif