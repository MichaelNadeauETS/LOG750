#ifndef SCENETEXT_H
#define SCENETEXT_H

#include "sceneObjects/sceneShape.h"
#include <QString>

#if defined(Q_OS_WIN32) || defined(Q_OS_LINUX)
#include "GL/glut.h"
#endif
#ifdef Q_OS_MAC
#include "GLUT/glut.h"
#endif

class text : public sceneShape
{
    public:
        text();

        QString value;

        void setValue(QString value);

        void accept(sceneVisitor *visitor);

};

#endif // SCENETEXT_H
