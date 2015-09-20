#include "rectangle.h"

rectangle::rectangle() {
}

void rectangle::setCorner1(vector2Glf corner) {
    this->corner1 = corner;
}

void rectangle::setCorner2(vector2Glf corner) {
    this->corner2 = corner;
}

void rectangle::render() {
     super::render();

    glBegin(GL_POLYGON); {
        glVertex3d(this->corner1.x, this->corner1.y, 0);
        glVertex3d(this->corner2.x, this->corner1.y, 0);
        glVertex3d(this->corner2.x, this->corner2.y, 0);
        glVertex3d(this->corner1.x, this->corner2.y, 0);
    }
    glEnd();
}
