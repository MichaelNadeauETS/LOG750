#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "treeitem.h"
#include "vectorGLf.h"

class sceneObject : public treeItem<sceneObject>
{
    public:
        sceneObject();

        virtual void render();

};

#endif // SCENEOBJECT_H
