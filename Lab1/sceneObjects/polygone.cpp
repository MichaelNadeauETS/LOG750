#include "polygon.h"

polygon::polygon() {
}

void polygon::addVertex(vector2Glf vector) {
    this->vertices->append(vector);
}

void polygon::render() {
    super::render();

    glBegin(GL_POLYGON); {
        vector2Glf v;

        for(int i = 0; i < this->vertices->count(); i++) {
            v = this->vertices->at(i);
            glVertex3f(v.x, v.y, 0);
        }
    }
    glEnd();
}
