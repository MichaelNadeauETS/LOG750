#ifndef SCENESHAPE_H
#define SCENESHAPE_H

#include "sceneObjects/sceneobject.h"

class sceneShape : public sceneObject
{
    public:
        void setColor(vector3GLf color);

        virtual void render();

    protected:
        typedef sceneShape super;

        vector3GLf color;

};

#endif // SCENESHAPE_H
