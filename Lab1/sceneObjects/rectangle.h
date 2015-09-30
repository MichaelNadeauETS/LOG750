#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "sceneObjects/sceneShape.h"

class rectangle : public sceneShape
{
    public:
        rectangle();

        void setCorner1(vector2Glf corner);
        void setCorner2(vector2Glf corner);

        void accept(sceneVisitor* visitor);

    protected:
        vector2Glf corner1;
        vector2Glf corner2;
};

#endif // RECTANGLE_H
