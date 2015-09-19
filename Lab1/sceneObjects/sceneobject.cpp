#include "sceneObjects/sceneObject.h"

sceneObject::sceneObject() {
}

void sceneObject::setColor(vector3GLf color) {
    this->color = color;
}

void sceneObject::render() {
    glColor3f(this->color.x, this->color.y, this->color.z);
}
