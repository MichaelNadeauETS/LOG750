#ifndef SCENETEXT_H
#define SCENETEXT_H

#include "sceneObjects/sceneObject.h"
#include <QString>

#if defined(Q_OS_WIN32) || defined(Q_OS_LINUX)
#include "GL/glut.h"
#endif
#ifdef Q_OS_MAC
#include "GLUT/glut.h"
#endif

class text : public sceneObject
{
    public:
        text();

        void setValue(QString value);

         virtual void render();

    protected:
        QString value;

};

#endif // SCENETEXT_H