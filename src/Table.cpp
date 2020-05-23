#include "Table.hpp"

Table::Table(Vector3 topDimensions, Vector3 legDimensions, Color color)
{
    this->topDimensions = topDimensions;
    this->legDimensions = legDimensions;
    this->color = color;
    generateParallelepipeds();
}

Table::Table(float topLength, float topWidth, float topHeight, float legLength, float legWidth,
             float legHeight, Color color)
{
    this->topDimensions = Vector3(topLength, topHeight, topWidth);
    this->legDimensions = Vector3(legLength, legHeight, legWidth);
    this->color = color;
    generateParallelepipeds();
}

void Table::generateParallelepipeds()
{
    top = Parallelepiped(topDimensions, color);
    leg = Parallelepiped(legDimensions, color);
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

float Table::getFullHeight() { return topDimensions.y + legDimensions.y; }