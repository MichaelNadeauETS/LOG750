#ifndef SCENESHAPE_H
#define SCENESHAPE_H

#include "sceneObjects/sceneObject.h"
#include "vectorGLf.h"

class sceneShape : public sceneObject
{
    public:
        void setColor(vector3GLf color);

        void applyColor();

    protected:
        vector3GLf color;

};

#endif // SCENESHAPE_H
