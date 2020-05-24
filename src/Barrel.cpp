#include "Barrel.hpp"

Barrel::Barrel(float headRadius, float bellyRadius, float height, Color color, Material material)
{
    this->headRadius = headRadius;
    this->bellyRadius = bellyRadius;
    this->height = height;
    this->color = color;
    this->material = material;

    quad = gluNewQuadric();
}

Barrel::~Barrel() { gluDeleteQuadric(quad); }

void Barrel::drawObject()
{
    // Top half
    glPushMatrix();
    glRotatef(270, 1, 0, 0);
    gluCylinder(quad, bellyRadius, headRadius, height / 2, slices, stacks);
    glPopMatrix();

    // Bottom half
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(quad, bellyRadius, headRadius, height / 2, slices, stacks);
    glPopMatrix();

    // Top lid
    glPushMatrix();
    glTranslatef(0, height / 2, 0);
    glRotatef(270, 1, 0, 0);
    gluDisk(quad, 0, headRadius, slices, 1);
    glPopMatrix();

    // Bottom lid
    glPushMatrix();
    glTranslatef(0, -height / 2, 0);
    glRotatef(90, 1, 0, 0);
    gluDisk(quad, 0, headRadius, slices, 1);
    glPopMatrix();
}

void Barrel::update(float deltaTime) {}

void Barrel::setHeadRadius(float headRadius) { this->headRadius = headRadius; }
void Barrel::setBellyRadius(float bellyRadius) { this->bellyRadius = bellyRadius; }
void Barrel::setHeight(float height) { this->height = height; }
float Barrel::getHeadRadius() { return headRadius; }
float Barrel::getBellyRadius() { return bellyRadius; }
float Barrel::getHeight() { return height; }