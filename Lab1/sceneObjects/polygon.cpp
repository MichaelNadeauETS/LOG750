#include "polygon.h"

polygon::polygon() {
}

void polygon::addVertex(vector2Glf vector) {
    this->vertices->append(vector);
}

void text::accept(sceneVisitor* visitor) {
    visitor->visit(this);
}
