#include "Parallelepiped.hpp"

Parallelepiped::Parallelepiped(Vector3 dimensions, Color color, Material material)
    : Object(Transform(), color, material)
{
    this->dimensions = dimensions;
}

Parallelepiped::Parallelepiped(float length, float width, float height, Color color,
                               Material material)
    : Object(Transform(), color, material)
{
    dimensions = Vector3(length, height, width);
}

void Parallelepiped::drawObject()
{
    // Origin is the bottom left corner
    // Vertices are in CCW order
    glBegin(GL_QUADS);

    // Bottom Face
    glVertex3f(0, 0, 0);
    glVertex3f(dimensions.x, 0, 0);
    glVertex3f(dimensions.x, 0, dimensions.z);
    glVertex3f(0, 0, dimensions.z);

    // Top Face
    glVertex3f(0, dimensions.y, 0);
    glVertex3f(dimensions.x, dimensions.y, 0);
    glVertex3f(dimensions.x, dimensions.y, dimensions.z);
    glVertex3f(0, dimensions.y, dimensions.z);

    // Front Face
    glVertex3f(0, 0, 0);
    glVertex3f(dimensions.x, 0, 0);
    glVertex3f(dimensions.x, dimensions.y, 0);
    glVertex3f(0, dimensions.y, 0);

    // Back Face
    glVertex3f(0, 0, dimensions.z);
    glVertex3f(dimensions.x, 0, dimensions.z);
    glVertex3f(dimensions.x, dimensions.y, dimensions.z);
    glVertex3f(0, dimensions.y, dimensions.z);

    // Left Face
    glVertex3f(0, 0, 0);
    glVertex3f(0, dimensions.y, 0);
    glVertex3f(0, dimensions.y, dimensions.z);
    glVertex3f(0, 0, dimensions.z);

    // Right Face
    glVertex3f(dimensions.x, 0, 0);
    glVertex3f(dimensions.x, dimensions.y, 0);
    glVertex3f(dimensions.x, dimensions.y, dimensions.z);
    glVertex3f(dimensions.x, 0, dimensions.z);

    glEnd();
}

void Parallelepiped::update(float deltaTime) {}

void Parallelepiped::setDimensions(Vector3 dimensions) { this->dimensions = dimensions; }

void Parallelepiped::setDimensions(float length, float height, float width)
{
    dimensions = Vector3(length, height, width);
}

Vector3 Parallelepiped::getDimensions() { return dimensions; }