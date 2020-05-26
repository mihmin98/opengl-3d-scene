#include "Table.hpp"

Table::Table(Vector3 topDimensions, Vector3 legDimensions, Color color, Material material)
    : Object(Transform(), color, material)
{
    this->topDimensions = topDimensions;
    this->legDimensions = legDimensions;
    generateParallelepipeds();
}

Table::Table(float topLength, float topWidth, float topHeight, float legLength, float legWidth,
             float legHeight, Color color, Material material)
    : Object(Transform(), color, material)
{
    this->topDimensions = Vector3(topLength, topHeight, topWidth);
    this->legDimensions = Vector3(legLength, legHeight, legWidth);
    generateParallelepipeds();
}

void Table::generateParallelepipeds()
{
    top = Parallelepiped(topDimensions, color, material);
    leg = Parallelepiped(legDimensions, color, material);
}

void Table::drawObject()
{
    // Draw top
    glPushMatrix();
    glTranslatef(0, legDimensions.y, 0);
    top.drawObject();
    glPopMatrix();

    // Draw Legs
    // Bottom Left
    glPushMatrix();
    leg.drawObject();
    glPopMatrix();

    // Bottom Right
    glPushMatrix();
    glTranslatef(topDimensions.x - legDimensions.x, 0, 0);
    leg.drawObject();
    glPopMatrix();

    // Top Right
    glPushMatrix();
    glTranslatef(topDimensions.x - legDimensions.x, 0, topDimensions.z - legDimensions.z);
    leg.drawObject();
    glPopMatrix();

    // Top Left
    glPushMatrix();
    glTranslatef(0, 0, topDimensions.z - legDimensions.z);
    leg.drawObject();
    glPopMatrix();
}

void Table::update(float deltaTime) {}

void Table::setDrawTexture(bool drawTexture)
{
    drawTexture = drawTexture;
    top.setDrawTexture(drawTexture);
    leg.setDrawTexture(drawTexture);
}

void Table::setTextureName(unsigned int textureName)
{
    this->textureName = textureName;
    top.setTextureName(textureName);
    leg.setTextureName(textureName);
}

float Table::getTopHeight() { return topDimensions.y; }

float Table::getLegHeight() { return legDimensions.y; }

float Table::getFullHeight() { return topDimensions.y + legDimensions.y; }

void Table::getTopSurfaceEcuation(float *planeEcuation)
{
    top.getPlaneEcuation(Parallelepiped::TOP, planeEcuation);
}