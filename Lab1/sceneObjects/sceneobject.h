#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "treeitem.h"
#include "vectorGLf.h"

class sceneObject : public treeItem
{
    public:
        virtual void render() = 0;

};

#endif // SCENEOBJECT_H
