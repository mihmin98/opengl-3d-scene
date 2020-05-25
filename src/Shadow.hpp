#ifndef _SHADOW_HPP_
#define _SHADOW_HPP_

#pragma once
#include "Color.hpp"
#include "Light.hpp"
#include "Transform.hpp"

class Shadow
{
    float planeEcuation[4], lightPosition[4];
    float shadowMatrix[4][4];
    Color color;
    Transform transform;

  public:
    Shadow(float *planeEcuation, float *lightPosition, Color color = Color(100, 100, 100, 255), Transform Transform = Transform());
    Shadow(float *planeEcuation, Light light, Color color = Color(100, 100, 100, 255), Transform Transform = Transform());

    void generateShadowMatrix();

    float *getShadowMatrix();

    void setPosition(Vector3 position);
    void setRotation(Vector3 rotation);

    Transform getTransform();
    Vector3 getPosition();
};

#endif