#ifndef SCENEVISTOR
#define SCENEVISTOR

#include "sceneObjects/polygon.h"
#include "sceneObjects/rectangle.h"
#include "sceneObjects/text.h"

#include "sceneObjects/transformations/scaling.h"
#include "sceneObjects/transformations/translation.h"

class polygon;
class rectangle;
class text;

class scaling;
class translation;

class sceneVisitor {
    public:
        virtual void visit(polygon* p) = 0;
        virtual void visit(rectangle* r) = 0;
        virtual void visit(text* t) = 0;

        virtual void visit(scaling* s) = 0;
        virtual void visit(translation* t) = 0;
};

#endif // SCENEVISTOR
