#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "sceneObjects/sceneObject.h"

class rectangle : public sceneObject
{
    public:
        rectangle();

        void setCorner1(vector2Glf corner);
        void setCorner2(vector2Glf corner);

        virtual void render();

    protected:
        vector2Glf corner1;
        vector2Glf corner2;
};

#endif // RECTANGLE_H
