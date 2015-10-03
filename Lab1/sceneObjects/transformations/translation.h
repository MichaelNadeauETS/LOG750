#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "sceneObjects/transformations/sceneTransformation.h"

class translation : public sceneTransformation
{
    public:
        translation();

        vector2Glf* vector = new vector2Glf(0, 0);

        vector2Glf* getVector();

        void accept(sceneVisitor *visitor);

};

#endif // TRANSLATION_H
