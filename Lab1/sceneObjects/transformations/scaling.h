#ifndef SCALING_H
#define SCALING_H

#include "sceneObjects/transformations/sceneTransformation.h"

class scaling : public sceneTransformation
{
    public:
        scaling();

        vector2Glf* getVector();

        virtual void render();

    protected:
        vector2Glf* vector = new vector2Glf(1, 1);
};

#endif // SCALING_H
