#include "scaling.h"

scaling::scaling() {
}

vector2Glf* scaling::getVector() {
    return this->vector;
}

void scaling::accept(sceneVisitor* visitor) {
    visitor->visit(this);
}
