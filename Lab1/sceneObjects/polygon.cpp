#include "polygon.h"

polygon::polygon() {
}

void polygon::addVertex(vector2Glf vector) {
    this->vertices->append(vector);
}

void polygon::accept(sceneVisitor* visitor) {
    visitor->visit(this);
}
