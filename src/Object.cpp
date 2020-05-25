#include "Object.hpp"

Object::Object(Transform transform, Color color, Material material)
{
    this->transform = transform;
    this->color = color;
    this->material = material;
}

void Object::draw(bool skipColor)
{
    glPushMatrix();
    // Translate object to its current position
    glTranslatef(this->transform.position.x, this->transform.position.y,
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
        glScalef(this->transform.scale.x, this->transform.scale.y, this->transform.scale.z);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    if (!skipColor)
        glColor4ubv(color.getColorArray());

    this->material.applyMaterial();

    this->drawObject();
    glPopMatrix();
}

void Object::drawShadows()
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    for (std::vector<Shadow>::iterator it = shadowList.begin(); it != shadowList.end();
         std::advance(it, 1)) {

        Vector3 pos = it->getPosition();
        glColor3f(0.1, 0.1, 0.1);
        glPushMatrix();
        glTranslatef(pos.x, pos.y, pos.z);
        glMultMatrixf(it->getShadowMatrix());
        draw(true);
        glPopMatrix();
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}

void Object::addShadow(Shadow shadow) { shadowList.push_back(shadow); }