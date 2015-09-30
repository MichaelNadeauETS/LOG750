#include "rectangle.h"

rectangle::rectangle() {
}

void rectangle::setCorner1(vector2Glf corner) {
    this->corner1 = corner;
}

void rectangle::setCorner2(vector2Glf corner) {
    this->corner2 = corner;
}

void rectangle::accept(sceneVisitor* visitor) {
    visitor->visit(this);
}
