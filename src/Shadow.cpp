#include "Shadow.hpp"
#include <iostream>

Shadow::Shadow(float *planeEcuation, float *lightPosition, Color color, Transform transform)
{
    this->planeEcuation[0] = planeEcuation[0];
    this->planeEcuation[1] = planeEcuation[1];
    this->planeEcuation[2] = planeEcuation[2];
    this->planeEcuation[3] = planeEcuation[3];

    this->lightPosition[0] = lightPosition[0];
    this->lightPosition[1] = lightPosition[1];
    this->lightPosition[2] = lightPosition[2];
    this->lightPosition[3] = lightPosition[3];

    this->color = color;
    this->transform = transform;

    generateShadowMatrix();
}

Shadow::Shadow(float *planeEcuation, Light light, Color color, Transform transform)
{
    this->planeEcuation[0] = planeEcuation[0];
    this->planeEcuation[1] = planeEcuation[1];
    this->planeEcuation[2] = planeEcuation[2];
    this->planeEcuation[3] = planeEcuation[3];

    float *lightPosition = light.getPositionv();
    this->lightPosition[0] = lightPosition[0];
    this->lightPosition[1] = lightPosition[1];
    this->lightPosition[2] = lightPosition[2];
    this->lightPosition[3] = lightPosition[3];

    this->color = color;
    this->transform = transform;

    generateShadowMatrix();
}

void Shadow::generateShadowMatrix()
{
    float dot = planeEcuation[0] * lightPosition[0] + planeEcuation[1] * lightPosition[1] +
                planeEcuation[2] * lightPosition[2] + planeEcuation[3] * lightPosition[3];

    shadowMatrix[0][0] = dot - lightPosition[0] * planeEcuation[0];
    shadowMatrix[1][0] = 0.0 - lightPosition[0] * planeEcuation[1];
    shadowMatrix[2][0] = 0.0 - lightPosition[0] * planeEcuation[2];
    shadowMatrix[3][0] = 0.0 - lightPosition[0] * planeEcuation[3];

    shadowMatrix[0][1] = 0.0 - lightPosition[1] * planeEcuation[0];
    shadowMatrix[1][1] = dot - lightPosition[1] * planeEcuation[1];
    shadowMatrix[2][1] = 0.0 - lightPosition[1] * planeEcuation[2];
    shadowMatrix[3][1] = 0.0 - lightPosition[1] * planeEcuation[3];

    shadowMatrix[0][2] = 0.0 - lightPosition[2] * planeEcuation[0];
    shadowMatrix[1][2] = 0.0 - lightPosition[2] * planeEcuation[1];
    shadowMatrix[2][2] = dot - lightPosition[2] * planeEcuation[2];
    shadowMatrix[3][2] = 0.0 - lightPosition[2] * planeEcuation[3];

    shadowMatrix[0][3] = 0.0 - lightPosition[3] * planeEcuation[0];
    shadowMatrix[1][3] = 0.0 - lightPosition[3] * planeEcuation[1];
    shadowMatrix[2][3] = 0.0 - lightPosition[3] * planeEcuation[2];
    shadowMatrix[3][3] = dot - lightPosition[3] * planeEcuation[3];
}

float *Shadow::getShadowMatrix() { return (float *)shadowMatrix; }

void Shadow::setPosition(Vector3 position) { transform.position = position; }

void Shadow::setRotation(Vector3 rotation) { transform.rotation = rotation; }

Transform Shadow::getTransform() { return transform; }

Vector3 Shadow::getPosition() { return transform.position; }
