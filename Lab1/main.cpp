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

#define GLUT_DISABLE_ATEXIT_HACK
#if defined(Q_OS_WIN32) || defined(Q_OS_LINUX)
#include "GL/glut.h"
#endif
#ifdef Q_OS_MAC
#include "GLUT/glut.h"
#endif

int main(int argc, char** argv)
{
  // Read command lines arguments.
  QApplication application(argc,argv);

  glutInit(&argc, argv);

  QMainWindow* mainWindow = new QMainWindow;
  Ui_MainWindow form1;
  form1.setupUi(mainWindow);

  // Instantiate and layout the viewer.
  Viewer *v = new Viewer();
  QLayout *layout = new QHBoxLayout;
  layout->addWidget(v);
  form1.frame->setLayout(layout);

  mainWindow->show();

  // Run main loop.
  return application.exec();
}
