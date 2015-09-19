#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "treeitem.h"
#include "vectorGLf.h"

class sceneObject : public treeItem
{
    public:
        sceneObject();

        void setColor(vector3GLf color);

        virtual void render();

    protected:
        typedef sceneObject super;

        vector3GLf color;

};

#endif // SCENEOBJECT_H
