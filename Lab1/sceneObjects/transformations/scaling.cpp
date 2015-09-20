#include "scaling.h"

scaling::scaling() {
}

vector2Glf* scaling::getVector() {
    return this->vector;
}

void scaling::render() {
    glScalef(this->vector->x, this->vector->y, 1);
}
