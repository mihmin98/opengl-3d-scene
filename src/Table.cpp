#include "Table.hpp"

Table::Table(Vector3 topDimensions, Vector3 legDimensions)
{
    this->topDimensions = topDimensions;
    this->legDimensions = legDimensions;
    generateParallelepipeds();
}

Table::Table(float topLength, float topWidth, float topHeight, float legLength, float legWidth,
             float legHeight)
{
    this->topDimensions = Vector3(topLength, topHeight, topWidth);
    this->legDimensions = Vector3(legLength, legHeight, legWidth);
    generateParallelepipeds();
}

void Table::generateParallelepipeds()
{
    top = Parallelepiped(topDimensions);
    leg = Parallelepiped(legDimensions);
}

void Table::drawObject()
{
    // TODO: Maybe change the drawObject() to draw() by setting the parallelepiped Object members
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
    glTranslatef(top.getDimensions().x - leg.getDimensions().x, 0, 0);
    leg.drawObject();
    glPopMatrix();

    // Top Right
    glPushMatrix();
    glTranslatef(top.getDimensions().x - leg.getDimensions().x, 0, top.getDimensions().z - leg.getDimensions().z);
    leg.drawObject();
    glPopMatrix();

    // Top Left
    glPushMatrix();
    glTranslatef(0, 0, top.getDimensions().z - leg.getDimensions().z);
    leg.drawObject();
    glPopMatrix();
}

void Table::update(float deltaTime) {}