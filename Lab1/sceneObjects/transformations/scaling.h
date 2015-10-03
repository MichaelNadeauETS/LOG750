#ifndef SCALING_H
#define SCALING_H

#include "sceneObjects/transformations/sceneTransformation.h"

class scaling : public sceneTransformation
{
    public:
        scaling();

        vector2Glf* vector = new vector2Glf(1, 1);

        vector2Glf* getVector();

        void accept(sceneVisitor *visitor);

};

#endif // SCALING_H
