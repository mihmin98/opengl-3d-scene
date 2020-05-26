#include "Barrel.hpp"
#include <iostream>

Barrel::Barrel(float headRadius, float bellyRadius, float height, Color color, Material material)
    : Object(Transform(), color, material)
{
    this->headRadius = headRadius;
    this->bellyRadius = bellyRadius;
    this->height = height;
    barrelTextureName = 0;
    woodTextureName = 0;

    quad = gluNewQuadric();
}

Barrel::~Barrel() { gluDeleteQuadric(quad); }

void Barrel::drawObject()
{
    // Top half
    if (barrelTextureName != 0 && drawTexture) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, barrelTextureName);

        gluQuadricDrawStyle(quad, GLU_FILL);
        gluQuadricNormals(quad, GLU_SMOOTH);
        gluQuadricTexture(quad, GL_TRUE);
    }

    glPushMatrix();
    glRotatef(270, 1, 0, 0);
    gluCylinder(quad, bellyRadius, headRadius, height / 2, slices, stacks);
    glPopMatrix();

    // Bottom half
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    gluCylinder(quad, bellyRadius, headRadius, height / 2, slices, stacks);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    gluQuadricTexture(quad, GL_FALSE);

    if (woodTextureName != 0 && drawTexture) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, woodTextureName);

        gluQuadricDrawStyle(quad, GLU_FILL);
        gluQuadricNormals(quad, GLU_SMOOTH);
        gluQuadricTexture(quad, GL_TRUE);
    }

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

    glDisable(GL_TEXTURE_2D);
    gluQuadricTexture(quad, GL_FALSE);
}

void Barrel::update(float deltaTime) {}

void Barrel::setHeadRadius(float headRadius) { this->headRadius = headRadius; }
void Barrel::setBellyRadius(float bellyRadius) { this->bellyRadius = bellyRadius; }
void Barrel::setHeight(float height) { this->height = height; }
void Barrel::setBarrelTextureName(unsigned int barrelTextureName)
{
    this->barrelTextureName = barrelTextureName;
}

void Barrel::setWoodTextureName(unsigned int woodTextureName)
{
    this->woodTextureName = woodTextureName;
}

float Barrel::getHeadRadius() { return headRadius; }
float Barrel::getBellyRadius() { return bellyRadius; }
float Barrel::getHeight() { return height; }