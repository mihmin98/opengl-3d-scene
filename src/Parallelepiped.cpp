#include "Parallelepiped.hpp"

Parallelepiped::Parallelepiped(float length, float width, float height)
{
    this->length = length;
    this->width = width;
    this->height = height;
}

void Parallelepiped::drawObject()
{
    // Origin is the bottom left corner
    // Vertices are in CCW order
    glBegin(GL_QUADS);

    // Bottom Face
    glVertex3f(0, 0, 0);
    glVertex3f(length, 0, 0);
    glVertex3f(length, 0, width);
    glVertex3f(0, 0, width);

    // Top Face
    glVertex3f(0, height, 0);
    glVertex3f(length, height, 0);
    glVertex3f(length, height, width);
    glVertex3f(0, height, width);

    // Front Face
    glVertex3f(0, 0, 0);
    glVertex3f(length, 0, 0);
    glVertex3f(length, height, 0);
    glVertex3f(0, height, 0);

    // Back Face
    glVertex3f(0, 0, width);
    glVertex3f(length, 0, width);
    glVertex3f(length, height, width);
    glVertex3f(0, height, width);

    // Left Face
    glVertex3f(0, 0, 0);
    glVertex3f(0, height, 0);
    glVertex3f(0, height, width);
    glVertex3f(0, 0, width);

    // Right Face
    glVertex3f(length, 0, 0);
    glVertex3f(length, height, 0);
    glVertex3f(length, height, width);
    glVertex3f(length, 0, width);

    glEnd();
}

void Parallelepiped::update(float deltaTime) {}