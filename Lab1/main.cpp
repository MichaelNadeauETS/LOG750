/****************************************************************************

 Copyright (C) 2002-2008 Gilles Debunne. All rights reserved.

 This file is part of the QGLViewer library version 2.3.6.

 http://www.libqglviewer.com - contact@libqglviewer.com

 This file may be used under the terms of the GNU General Public License 
 versions 2.0 or 3.0 as published by the Free Software Foundation and
 appearing in the LICENSE file included in the packaging of this file.
 In addition, as a special exception, Gilles Debunne gives you certain 
 additional rights, described in the file GPL_EXCEPTION in this package.

 libQGLViewer uses dual licensing. Commercial/proprietary software must
 purchase a libQGLViewer Commercial License.

 This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/

#include "simpleViewer.h"
#include "ui_untitled.h"
#include <qapplication.h>
#include <qframe.h>
#include <QBoxLayout>

#include "sceneObjects/text.h"
#include "sceneObjects/rectangle.h"
#include "sceneObjects/polygon.h"
#include "sceneObjects/transformations/translation.h"
#include "sceneObjects/transformations/scaling.h"

#define GLUT_DISABLE_ATEXIT_HACK
#if defined(Q_OS_WIN32) || defined(Q_OS_LINUX)
#include "GL/glut.h"
#endif
#ifdef Q_OS_MAC
#include "GLUT/glut.h"
#endif

int main(int argc, char** argv)
{
  QApplication application(argc,argv);

  glutInit(&argc, argv);

  QMainWindow* mainWindow = new QMainWindow();





  scaling* s = new scaling();
  s->getVector()->x = 1.5;
  s->getVector()->y = 0.5;

  translation* tn = new translation();
  tn->getVector()->x = -20;
  tn->getVector()->y = 15;

  polygon* p = new polygon();
  p->setColor(vector3GLf(0, 1, 1));
  p->addVertex(vector2Glf(0, 0));
  p->addVertex(vector2Glf(-20, 15));
  p->addVertex(vector2Glf(0, 30));
  p->addVertex(vector2Glf(20, 30));
  p->addVertex(vector2Glf(10, 15));

  rectangle* r = new rectangle();
  r->setColor(vector3GLf(0, 0, 1));
  r->setCorner1(vector2Glf(35, 10));
  r->setCorner2(vector2Glf(55, -5));

  text* t = new text();
  t->setColor(vector3GLf(1, 1, 0));
  t->setValue(QString("test"));


  sceneObject* tree = new sceneObject();

  tn->addChild(p);
  s->addChild(tn);
  tree->addChild(s);

  tree->addChild(r);
  tree->addChild(t);







  // **********************************************
  // Instanciates window's components
  // **********************************************
      Ui_MainWindow form1;
      form1.setupUi(mainWindow);

      Viewer* viewer = new Viewer();
      viewer->setSceneModel(tree);

      QLayout* layout = new QHBoxLayout;
      layout->addWidget(viewer);

      form1.frame->setLayout(layout);

  mainWindow->show();

  // Runs application's loop
  return application.exec();
}
