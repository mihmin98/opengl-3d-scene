#include "Barrel.hpp"
#include "DrinkingGlass.hpp"
#include "Light.hpp"
#include "Parallelepiped.hpp"
#include "Shadow.hpp"
#include "Table.hpp"
#include "TextureManager.hpp"
#include <GL/freeglut.h>
#include <SOIL/SOIL.h>
#include <cmath>
#include <iostream>

const int windowWidth = 800;
const int windowHeight = 600;

// Camera vars
float angle = 0;
float lx = 0, lz = -1;
float x = 0, z = 0;

// Objects
TextureManager textureManager;
float plane[4];
Parallelepiped ground = Parallelepiped(Vector3(10, 1, 10), Color(180, 180, 180)),
               ceiling = Parallelepiped(Vector3(10, 1, 10), Color(180, 180, 180)),
               frontWall = Parallelepiped(Vector3(10, 4, 1), Color(180, 180, 180)),
               backWall = Parallelepiped(Vector3(10, 4, 1), Color(180, 180, 180)),
               leftWall = Parallelepiped(Vector3(1, 4, 10), Color(180, 180, 180)),
               rightWall = Parallelepiped(Vector3(1, 4, 10), Color(180, 180, 180));

Table table = Table(Vector3(2, 0.15, 1), Vector3(0.1, 0.5, 0.1));
Barrel barrel = Barrel(0.25, 0.275, 0.75), barrel2 = Barrel(0.25, 0.3, 0.75), barrel3 = barrel,
       barrel4 = barrel;
DrinkingGlass drinkingGlass = DrinkingGlass(0.15, 0.1, 0.4), drinkingGlass2 = drinkingGlass,
              drinkingGlass3 = drinkingGlass;
Light light = Light(GL_LIGHT0, Color(255, 244, 180), Vector3(0.5, 2.5, 0));
GLUquadric *quad = gluNewQuadric();

void init()
{
    // Load textures
    textureManager.addTexture("wood", "textures/wood.png");
    textureManager.addTexture("barrel", "textures/barrel.png");
    textureManager.addTexture("stone", "textures/stone.png");

    // Set wall positions
    ground.transform.position = Vector3(-5, -1, -5);
    ceiling.transform.position = Vector3(-5, 4, -5);
    frontWall.transform.position = Vector3(-5, 0, -5);
    backWall.transform.position = Vector3(-5, 0, 5);
    leftWall.transform.position = Vector3(-5, 0, -5);
    rightWall.transform.position = Vector3(4, 0, -5);

    // Set wall textures
    ground.setTextureName(textureManager.getTexture("stone")->getTextureName());
    ceiling.setTextureName(textureManager.getTexture("stone")->getTextureName());
    frontWall.setTextureName(textureManager.getTexture("stone")->getTextureName());
    backWall.setTextureName(textureManager.getTexture("stone")->getTextureName());
    leftWall.setTextureName(textureManager.getTexture("stone")->getTextureName());
    rightWall.setTextureName(textureManager.getTexture("stone")->getTextureName());

    // Set table properties
    table.transform.position = Vector3(-1, 0, -2);
    table.material.setShininess(0.25);
    table.setTextureName(textureManager.getTexture("wood")->getTextureName());

    // Set barrel properties
    barrel.transform.position = Vector3(0, barrel.getHeight() / 2, -3);
    barrel.setBarrelTextureName(textureManager.getTexture("barrel")->getTextureName());
    barrel.setWoodTextureName(textureManager.getTexture("wood")->getTextureName());

    barrel2.transform.position = Vector3(-1, barrel2.getHeight() - 0.4, -3);
    barrel2.transform.rotation = Vector3(0, 0, 90);
    barrel2.setBarrelTextureName(textureManager.getTexture("barrel")->getTextureName());
    barrel2.setWoodTextureName(textureManager.getTexture("wood")->getTextureName());

    barrel3.transform.position = Vector3(0.65, barrel.getHeight() / 2 + 0.1, -3);
    barrel3.transform.rotation = Vector3(0, 0, 30);
    barrel3.setBarrelTextureName(textureManager.getTexture("barrel")->getTextureName());
    barrel3.setWoodTextureName(textureManager.getTexture("wood")->getTextureName());

    barrel4.transform.position = Vector3(1.5, barrel.getHeight() / 2, 1);
    barrel4.setBarrelTextureName(textureManager.getTexture("barrel")->getTextureName());
    barrel4.setWoodTextureName(textureManager.getTexture("wood")->getTextureName());

    // Set drinking glass properties
    drinkingGlass.transform.position = Vector3(-0.25, table.getFullHeight(), -1.5);
    drinkingGlass2.transform.position = Vector3(0.25, table.getFullHeight(), -1.5);
    drinkingGlass3.transform.position = Vector3(0.65, table.getFullHeight() + .1, -1.2);
    drinkingGlass3.transform.rotation = Vector3(0, 0, 75);

    GLfloat fogColor[4] = {0.6, 0.6, 0.5, 1};
    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_DENSITY, .15);
    glHint(GL_FOG_HINT, GL_DONT_CARE);
    glFogf(GL_FOG_START, 2.0);
    glFogf(GL_FOG_END, 10.0);
}

void drawScene()
{
    glShadeModel(GL_SMOOTH);

    glCullFace(GL_BACK);

    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_ALWAYS, 1, 0);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glClearColor(.5, .7, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(x, 1.0f, z, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);

    // Draw ground floor
    ground.draw();

    // Draw floor shadows
    Vector3::PlaneEcuation(plane, Vector3(0, 0, 0), Vector3(1, 0, 1), Vector3(1, 0, 0));
    Shadow floorShadow = Shadow(plane, light.getPositionv());

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    barrel.setDrawTexture(false);
    barrel2.setDrawTexture(false);
    barrel3.setDrawTexture(false);
    barrel4.setDrawTexture(false);
    table.setDrawTexture(false);

    glColor4f(0.2f, 0.2f, 0.2f, 0.5); /* shadow color */
    glPushMatrix();
    glMultMatrixf(floorShadow.getShadowMatrix());
    barrel.draw(true);
    barrel2.draw(true);
    barrel3.draw(true);
    barrel4.draw(true);
    table.draw(true);
    glPopMatrix();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    // Draw walls
    ceiling.draw();
    frontWall.draw();
    backWall.draw();
    leftWall.draw();
    rightWall.draw();

    // Draw table
    table.setDrawTexture(true);
    table.draw();

    // Draw barrels
    barrel.setDrawTexture(true);
    barrel.draw();
    barrel2.setDrawTexture(true);
    barrel2.draw();
    barrel3.setDrawTexture(true);
    barrel3.draw();
    barrel4.setDrawTexture(true);
    barrel4.draw();

    // Draw drinking glass
    drinkingGlass.draw();
    drinkingGlass2.draw();
    drinkingGlass3.draw();

    // Draw light
    glPushMatrix();
    glTranslatef(light.getPosition().x, light.getPosition().y, light.getPosition().z);
    glColor4ub(64, 64, 64, 255);
    glPushMatrix();
    glRotatef(270, 1, 0, 0);
    gluCylinder(quad, .025, .025, .5, 20, 20);
    glPopMatrix();
    glColor4ub(255, 244, 140, 255);
    gluSphere(quad, .15, 20, 20);
    glPopMatrix();
    light.applyLight();

    glutSwapBuffers();
}

void changeSize(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;
    float ratio = w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void processSpecialKeys(int key, int xx, int yy)
{

    float fraction = 0.3f;

    switch (key) {
    case GLUT_KEY_LEFT:
        angle -= 0.03f;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case GLUT_KEY_RIGHT:
        angle += 0.03f;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case GLUT_KEY_UP:
        x += lx * fraction;
        z += lz * fraction;
        break;
    case GLUT_KEY_DOWN:
        x -= lx * fraction;
        z -= lz * fraction;
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("opengl-3d");

    init();
    glutDisplayFunc(drawScene);
    glutIdleFunc(drawScene);
    glutReshapeFunc(changeSize);
    glutSpecialFunc(processSpecialKeys);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}