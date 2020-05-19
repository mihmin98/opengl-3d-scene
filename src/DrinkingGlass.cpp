#include "DrinkingGlass.hpp"

DrinkingGlass::DrinkingGlass(float topRadius, float baseRadius, float height)
{
    this->topRadius = topRadius;
    this->baseRadius = baseRadius;
    this->height = height;
    quad = gluNewQuadric();
}

DrinkingGlass::~DrinkingGlass() { gluDeleteQuadric(quad); }

void DrinkingGlass::drawObject()
{

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ubv(color);
    // Draw the cylinder
    glPushMatrix();
    glRotatef(270, 1, 0, 0);
    gluCylinder(quad, baseRadius, topRadius, height, 20, 20);
    glPopMatrix();

    // Draw the base disk
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluDisk(quad, 0, baseRadius, 20, 1);
    glPopMatrix();
    glDisable(GL_BLEND);
}

void DrinkingGlass::update(float deltaTime) {}

void DrinkingGlass::setTopRadius(float topRadius) { this->topRadius = topRadius; }
void DrinkingGlass::setBaseRadius(float baseRadius) { this->baseRadius = baseRadius; }
void DrinkingGlass::setHeight(float height) { this->height = height; }
float DrinkingGlass::getTopRadius() { return topRadius; }
float DrinkingGlass::getBaseRadius() { return topRadius; }
float DrinkingGlass::getHeight() { return height; }