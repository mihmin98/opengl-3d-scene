#include "Parallelepiped.hpp"
#include <iostream>

Parallelepiped::Parallelepiped(Vector3 dimensions, Color color, Material material)
    : Object(Transform(), color, material)
{
    this->dimensions = dimensions;
    textureName = 0;
}

Parallelepiped::Parallelepiped(float length, float width, float height, Color color,
                               Material material)
    : Object(Transform(), color, material)
{
    dimensions = Vector3(length, height, width);
    textureName = 0;
}

void Parallelepiped::getPlaneEcuation(Face face, float *planeEcuation)
{
    // Points Must be in ClockWise order
    float x = dimensions.x;
    float y = dimensions.y;
    float z = dimensions.z;

    Vector3 p1, p2, p3;
    switch (face) {
    case BOTTOM:
        p1 = Vector3(0, 0, 0);
        p2 = Vector3(x, 0, 0);
        p3 = Vector3(x, 0, z);
        break;
    case TOP:
        p1 = Vector3(0, y, 0);
        p2 = Vector3(x, y, z);
        p3 = Vector3(x, y, 0);
        break;
    // TODO: Fix the order of vertices for those below
    case FRONT:
        p1 = Vector3(0, 0, 0);
        p2 = Vector3(x, 0, 0);
        p3 = Vector3(x, y, 0);
        break;
    case BACK:
        p1 = Vector3(0, 0, z);
        p2 = Vector3(x, 0, z);
        p3 = Vector3(x, y, z);
        break;
    case LEFT:
        p1 = Vector3(0, 0, 0);
        p2 = Vector3(0, y, 0);
        p3 = Vector3(0, y, z);
        break;
    case RIGHT:
        p1 = Vector3(x, 0, 0);
        p2 = Vector3(x, y, 0);
        p3 = Vector3(x, y, z);
        break;
    }

    Vector3::PlaneEcuation(planeEcuation, p1, p2, p3);
}

void Parallelepiped::drawObject()
{
    if (drawTexture && textureName != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureName);
    }

    // Origin is the bottom left corner
    // Vertices are in CCW order
    glBegin(GL_QUADS);

    // Bottom Face
    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 0);
    glVertex3f(0, 0, 0);
    
    glTexCoord2f(1, 0);
    glVertex3f(dimensions.x, 0, 0);
    
    glTexCoord2f(1, 1);
    glVertex3f(dimensions.x, 0, dimensions.z);
    
    glTexCoord2f(0, 1);
    glVertex3f(0, 0, dimensions.z);

    // Top Face
    glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0);
    glVertex3f(0, dimensions.y, 0);
    
    glTexCoord2f(1, 0);
    glVertex3f(dimensions.x, dimensions.y, 0);
    
    glTexCoord2f(1, 1);
    glVertex3f(dimensions.x, dimensions.y, dimensions.z);
    
    glTexCoord2f(0, 1);
    glVertex3f(0, dimensions.y, dimensions.z);

    // Front Face
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(0, 0, 0);
    
    glTexCoord2f(1, 0);
    glVertex3f(dimensions.x, 0, 0);
    
    glTexCoord2f(1, 1);
    glVertex3f(dimensions.x, dimensions.y, 0);
    
    glTexCoord2f(0, 1);
    glVertex3f(0, dimensions.y, 0);

    // Back Face
    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 0);
    glVertex3f(0, 0, dimensions.z);
    
    glTexCoord2f(1, 0);
    glVertex3f(dimensions.x, 0, dimensions.z);
    
    glTexCoord2f(1, 1);
    glVertex3f(dimensions.x, dimensions.y, dimensions.z);
    
    glTexCoord2f(0, 1);
    glVertex3f(0, dimensions.y, dimensions.z);

    // Left Face
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(0, 0, 0);
    
    glTexCoord2f(0, 1);
    glVertex3f(0, dimensions.y, 0);
    
    glTexCoord2f(1, 1);
    glVertex3f(0, dimensions.y, dimensions.z);
    
    glTexCoord2f(1, 0);
    glVertex3f(0, 0, dimensions.z);

    // Right Face
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(dimensions.x, 0, 0);
    
    glTexCoord2f(0, 1);
    glVertex3f(dimensions.x, dimensions.y, 0);
    
    glTexCoord2f(1, 1);
    glVertex3f(dimensions.x, dimensions.y, dimensions.z);
    
    glTexCoord2f(1, 0);
    glVertex3f(dimensions.x, 0, dimensions.z);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Parallelepiped::update(float deltaTime) {}

void Parallelepiped::setDimensions(Vector3 dimensions) { this->dimensions = dimensions; }

void Parallelepiped::setDimensions(float length, float height, float width)
{
    dimensions = Vector3(length, height, width);
}

void Parallelepiped::setTextureName(unsigned int textureName) { this->textureName = textureName; }

Vector3 Parallelepiped::getDimensions() { return dimensions; }