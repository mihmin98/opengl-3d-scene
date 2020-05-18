#include "Object.hpp"

Object::Object(Transform transform)
{
    this->transform = transform;
}

void Object::draw()
{
    glPushMatrix();
    // Translate object to its current position
    glTranslatef(this->transform.position.x,
                 this->transform.position.y,
                 this->transform.position.z);

    // Rotate object
    // X Axis
    if (this->transform.rotation.x != 0)
        glRotatef(this->transform.rotation.x, 1, 0, 0);
    
    // Y Axis
    if (this->transform.rotation.y != 0)
        glRotatef(this->transform.rotation.y, 0, 1, 0);

    // Z Axis
    if (this->transform.rotation.z != 0)
        glRotatef(this->transform.rotation.z, 0, 0, 1);

    // Scale object
    if (this->transform.scale != Vector3(1, 1, 1))
        glScalef(this->transform.scale.x,
                 this->transform.scale.y,
                 this->transform.scale.z);

    this->drawObject();
    glPopMatrix();
}