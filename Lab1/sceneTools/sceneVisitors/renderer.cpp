#include "renderer.h"

#include "sceneObjects/polygon.h"
#include "sceneObjects/rectangle.h"
#include "sceneObjects/text.h"

#include "sceneObjects/transformations/scaling.h"
#include "sceneObjects/transformations/translation.h"

renderer::renderer()
{
}

void renderer::visit(polygon* p) {
    p->applyColor();

    glBegin(GL_POLYGON); {
        vector2Glf v;

        for(int i = 0; i < p->vertices->count(); i++) {
            v = p->vertices->at(i);
            glVertex3f(v.x, v.y, 0);
        }
    }
    glEnd();
}

void renderer::visit(rectangle* r) {
    r->applyColor();

    glBegin(GL_POLYGON); {
        glVertex3d(r->corner1.x, r->corner1.y, 0);
        glVertex3d(r->corner2.x, r->corner1.y, 0);
        glVertex3d(r->corner2.x, r->corner2.y, 0);
        glVertex3d(r->corner1.x, r->corner2.y, 0);
    }
    glEnd();
}

void renderer::visit(text* t) {
    t->applyColor();

    for (int i = 0; i < t->value.count(); i++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, t->value.at(i).unicode());
    }
}

void renderer::visit(scaling* s) {
    glScalef(s->vector->x, s->vector->y, 1);
}

void renderer::visit(translation* t) {
    glTranslatef(t->vector->x, t->vector->y, 0);
}
