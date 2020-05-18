#include "ObjectManager.hpp"

ObjectManager *ObjectManager::instance = nullptr;

ObjectManager::ObjectManager()
{
    objects = std::vector<Object *>();
}

ObjectManager *ObjectManager::getInstance()
{
    if (instance == nullptr || instance == 0)
        instance = new ObjectManager();
    return instance;
}

void ObjectManager::addObject(Object *obj)
{
    objects.push_back(obj);
}

void ObjectManager::update(float deltaTime)
{
    for (std::vector<Object *>::iterator it = objects.begin(); it < objects.end(); std::advance(it, 1))
        (*it)->update(deltaTime);
}

void ObjectManager::draw()
{
    for (std::vector<Object *>::iterator it = objects.begin(); it < objects.end(); std::advance(it, 1))
        (*it)->draw();
}