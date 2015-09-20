#include "translation.h"

translation::translation() {
}

vector2Glf* translation::getVector() {
    return this->vector;
}

void translation::render() {
    glTranslatef(this->vector->x, this->vector->y, 0);
}
