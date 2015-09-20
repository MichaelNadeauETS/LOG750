#include "sceneObjects/sceneShape.h"

void sceneShape::setColor(vector3GLf color) {
    this->color = color;
}

void sceneShape::render() {
    glColor3f(this->color.x, this->color.y, this->color.z);
}
