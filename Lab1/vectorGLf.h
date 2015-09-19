#ifndef VECTORGLF
#define VECTORGLF

#include <GL/gl.h>

struct vector2Glf {

    GLfloat x;
    GLfloat y;

    vector2Glf() {
        this->x = 0;
        this->y = 0;
    }

    vector2Glf(GLfloat x, GLfloat y) {
        this->x = x;
        this->y = y;
    }
};

struct vector3GLf {

    GLfloat x;
    GLfloat y;
    GLfloat z;

    vector3GLf() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    vector3GLf(GLfloat x, GLfloat y, GLfloat z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

#endif // VECTORGLF
