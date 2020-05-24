#include "Material.hpp"

Material::Material(Color specular, Color emission)
{
    this->specular[0] = specular.getRed() / 255.0;
    this->specular[1] = specular.getGreen() / 255.0;
    this->specular[2] = specular.getBlue() / 255.0;
    this->specular[3] = specular.getAlpha() / 255.0;

    this->emission[0] = emission.getRed() / 255.0;
    this->emission[1] = emission.getGreen() / 255.0;
    this->emission[2] = emission.getBlue() / 255.0;
    this->emission[3] = emission.getAlpha() / 255.0;
}

Material::Material(float *specular, float *emission)
{
    this->specular[0] = specular[0];
    this->specular[1] = specular[1];
    this->specular[2] = specular[2];
    this->specular[3] = specular[3];

    this->emission[0] = emission[0];
    this->emission[1] = emission[1];
    this->emission[2] = emission[2];
    this->emission[3] = emission[3];
}

void Material::applyMaterial()
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
}

void Material::setSpecular(float *specular)
{
    this->specular[0] = specular[0];
    this->specular[1] = specular[1];
    this->specular[2] = specular[2];
    this->specular[3] = specular[3];
}

void Material::setSpecular(Color specular)
{
    this->specular[0] = specular.getRed() / 255.0;
    this->specular[1] = specular.getGreen() / 255.0;
    this->specular[2] = specular.getBlue() / 255.0;
    this->specular[3] = specular.getAlpha() / 255.0;
}

void Material::setEmission(float *emission)
{
    this->emission[0] = emission[0];
    this->emission[1] = emission[1];
    this->emission[2] = emission[2];
    this->emission[3] = emission[3];
}

void Material::setEmission(Color emission)
{
    this->emission[0] = emission.getRed() / 255.0;
    this->emission[1] = emission.getGreen() / 255.0;
    this->emission[2] = emission.getBlue() / 255.0;
    this->emission[3] = emission.getAlpha() / 255.0;
}

float *Material::getSpecular() { return specular; }

float *Material::getEmission() { return emission; }
