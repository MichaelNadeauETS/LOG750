#include "translation.h"

translation::translation() {
}

vector2Glf* translation::getVector() {
    return this->vector;
}

void translation::accept(sceneVisitor* visitor) {
    visitor->visit(this);
}
