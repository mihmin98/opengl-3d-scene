#include "Light.hpp"

Light::Light(GLenum lightNumber, Color ambient, Color diffuse, Color specular, Vector3 position)
{
    this->lightNumber = lightNumber;

    this->ambient[0] = ambient.getRed() / 255.0;
    this->ambient[1] = ambient.getGreen() / 255.0;
    this->ambient[2] = ambient.getBlue() / 255.0;
    this->ambient[3] = ambient.getAlpha() / 255.0;

    this->diffuse[0] = diffuse.getRed() / 255.0;
    this->diffuse[1] = diffuse.getGreen() / 255.0;
    this->diffuse[2] = diffuse.getBlue() / 255.0;
    this->diffuse[3] = diffuse.getAlpha() / 255.0;

    this->specular[0] = specular.getRed() / 255.0;
    this->specular[1] = specular.getGreen() / 255.0;
    this->specular[2] = specular.getBlue() / 255.0;
    this->specular[3] = specular.getAlpha() / 255.0;

    this->position = position;
    positionv[0] = position.x;
    positionv[1] = position.y;
    positionv[2] = position.z;
    positionv[3] = 1;
}

Light::Light(GLenum lightNumber, Color lightColor, Vector3 position)
{
    this->lightNumber = lightNumber;

    this->ambient[0] = lightColor.getRed() / 255.0;
    this->ambient[1] = lightColor.getGreen() / 255.0;
    this->ambient[2] = lightColor.getBlue() / 255.0;
    this->ambient[3] = lightColor.getAlpha() / 255.0;

    this->diffuse[0] = lightColor.getRed() / 255.0 * 0.2;
    this->diffuse[1] = lightColor.getGreen() / 255.0 * 0.2;
    this->diffuse[2] = lightColor.getBlue() / 255.0 * 0.2;
    this->diffuse[3] = lightColor.getAlpha() / 255.0 * 0.2;

    this->specular[0] = lightColor.getRed() / 255.0 * 0.2;
    this->specular[1] = lightColor.getGreen() / 255.0 * 0.2;
    this->specular[2] = lightColor.getBlue() / 255.0 * 0.2;
    this->specular[3] = lightColor.getAlpha() / 255.0 * 0.2;

    this->position = position;
    positionv[0] = position.x;
    positionv[1] = position.y;
    positionv[2] = position.z;
    positionv[3] = 1;
}

Light::Light(GLenum lightNumber, float ambient[4], float diffuse[4], float specular[4],
             Vector3 position)
{
    this->lightNumber = lightNumber;

    this->ambient[0] = ambient[0];
    this->ambient[1] = ambient[1];
    this->ambient[2] = ambient[2];
    this->ambient[3] = ambient[3];

    this->diffuse[0] = diffuse[0];
    this->diffuse[1] = diffuse[1];
    this->diffuse[2] = diffuse[2];
    this->diffuse[3] = diffuse[3];

    this->specular[0] = specular[0];
    this->specular[1] = specular[1];
    this->specular[2] = specular[2];
    this->specular[3] = specular[3];

    this->position = position;
    positionv[0] = position.x;
    positionv[1] = position.y;
    positionv[2] = position.z;
    positionv[3] = 1;
}

void Light::applyLight()
{
    glLightfv(lightNumber, GL_AMBIENT, ambient);
    glLightfv(lightNumber, GL_DIFFUSE, diffuse);
    glLightfv(lightNumber, GL_SPECULAR, specular);
    glLightfv(lightNumber, GL_POSITION, positionv);

    glEnable(GL_LIGHTING);
    glEnable(lightNumber);
}
