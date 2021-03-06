#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "treeitem.h"
#include "sceneTools/sceneVisitors/sceneVistor.h"

class sceneObject : public treeItem<sceneObject>
{
    public:
        sceneObject();

        virtual void accept(sceneVisitor* visitor);

};

#endif // SCENEOBJECT_H
