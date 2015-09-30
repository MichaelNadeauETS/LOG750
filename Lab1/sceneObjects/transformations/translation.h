#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "sceneObjects/transformations/sceneTransformation.h"

class translation : public sceneTransformation
{
    public:
        translation();

        vector2Glf* getVector();

    protected:
        vector2Glf* vector = new vector2Glf(0, 0);
};

#endif // TRANSLATION_H
