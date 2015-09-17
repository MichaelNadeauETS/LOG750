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

#include <qgl.h>
#define GLUT_DISABLE_ATEXIT_HACK
#if defined(Q_OS_WIN32) || defined(Q_OS_LINUX)
#include "GL/glut.h"
#endif
#ifdef Q_OS_MAC
#include "GLUT/glut.h"
#endif

using namespace std;

void Viewer::draw()
{
  // Color of the object in RGB
  glColor3f(0, 0, 1);

  // Draws a pentagonal-like shape.
  glBegin(GL_POLYGON);
  {
    glVertex2f( 0,  4);
    glVertex2f(-4,  2);
    glVertex2f(-2, -4);
    glVertex2f( 2, -4);
    glVertex2f( 4,  2);
  }
  glEnd();

  // Draw the letter 'E'
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  {
    // Where to put the text (4,4)
    glTranslatef(4, 4, 0);
    
    // The letters by default are around 100 units wide. Need to scale that
    // down by a factor of 100:1 (the grid is 10x10 units).
    glScaled(0.01, 0.01, 0.01);
    
    // Color of the text in RGB
    glColor3f(0.9, 0.3, 0.1);

    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'E');
  }
  glPopMatrix();
}

void Viewer::drawWithNames()
{
  cout << "Viewer::drawWithNames()" << endl;
  // Should draw with names here...
}

void Viewer::postSelection(const QPoint& /* point */)
{
  cout << "Viewer::postSelection(const QPoint& point)" << endl;
  // Should query for the selected object
  // If an object should be moved, set a flag.
  movingObject = true;
}

void Viewer::mouseMoveEvent(QMouseEvent* e) {
  cout << "Viewer::mouseMoveEvent(QMouseEvent* e)" << endl;
  if (movingObject) {
    // We move the object.
  }

  // Normal QGLViewer behavior.
  QGLViewer::mouseMoveEvent(e);
}

void Viewer::mouseReleaseEvent(QMouseEvent* e) {
  cout << "Viewer::mouseReleaseEvent(QMouseEvent* e)" << endl;
  if (movingObject) {
    movingObject = false;
  }
  QGLViewer::mouseReleaseEvent(e);
}

void Viewer::init()
{
  movingObject = false;

  // We want to restrict ourselves to a 2D viewer.
  camera()->setType(qglviewer::Camera::ORTHOGRAPHIC);
  setMouseBinding(Qt::NoModifier, Qt::LeftButton, CAMERA, SCREEN_ROTATE);
  setMouseBinding(Qt::AltModifier, Qt::LeftButton, CAMERA, NO_MOUSE_ACTION);
  setMouseBinding(Qt::NoModifier, Qt::MouseButton(Qt::LeftButton + Qt::MidButton), CAMERA, NO_MOUSE_ACTION);
  setMouseBinding(Qt::ControlModifier, Qt::MouseButton(Qt::LeftButton + Qt::MidButton), CAMERA, NO_MOUSE_ACTION);

  // Our scene will be from -5 to 5 in X and Y (the grid will be 10x10).
  setSceneRadius(5);
  showEntireScene();

  setAxisIsDrawn(true);
  setGridIsDrawn(true);

  // Disable shading of the objects to directly get the color specified by
  // glColor.
  glDisable(GL_LIGHTING);
  
  // Opens help window
  help();
}

QString Viewer::helpString() const
{
  QString text("<h2>SimpleViewer - Lab 1</h2>");
  text += "Use the mouse to move the camera around the object. ";
  text += "You can respectively revolve around, zoom and translate with the three mouse buttons. ";
  text += "Left and middle buttons pressed together rotate around the camera view direction axis<br><br>";
  text += "Pressing <b>Alt</b> and one of the function keys (<b>F1</b>..<b>F12</b>) defines a camera keyFrame. ";
  text += "Simply press the function key again to restore it. Several keyFrames define a ";
  text += "camera path. Paths are saved when you quit the application and restored at next start.<br><br>";
  text += "Press <b>F</b> to display the frame rate, <b>A</b> for the world axis, ";
  text += "<b>Alt+Return</b> for full screen mode and <b>Control+S</b> to save a snapshot. ";
  text += "See the <b>Keyboard</b> tab in this window for a complete shortcut list.<br><br>";
  text += "Double clicks automates single click actions: A left button double click aligns the closer axis with the camera (if close enough). ";
  text += "A middle button double click fits the zoom of the camera and the right button re-centers the scene.<br><br>";
  text += "A left button double click while holding right button pressed defines the camera <i>Revolve Around Point</i>. ";
  text += "See the <b>Mouse</b> tab and the documentation web pages for details.<br><br>";
  text += "Press <b>Escape</b> to exit the viewer.";
  return text;
}
