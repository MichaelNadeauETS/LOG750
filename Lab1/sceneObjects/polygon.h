#ifndef POLYGONE_H
#define POLYGONE_H

#include "sceneObjects/sceneShape.h"
#include <QList>
#include "vectorGLf.h"

class polygon : public sceneShape
{
    public:
        polygon();

        void addVertex(vector2Glf vertex);

        void accept(sceneVisitor* visitor);

    protected:
        QList<vector2Glf>* vertices = new QList<vector2Glf>();
};

#endif // POLYGONE_H
