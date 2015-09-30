#ifndef RENDERER_H
#define RENDERER_H

#include "sceneTools/sceneVisitors/sceneVistor.h"

class renderer : public sceneVisitor
{
    public :
        renderer();

        void visit(polygon* p);
        void visit(rectangle* r);
        void visit(text* t);

        void visit(scaling* s);
        void visit(translation* t);
};

#endif // RENDERER_H
