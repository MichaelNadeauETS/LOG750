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
#include "sceneObjects/transformations/sceneTransformation.h"
#include "scenetools/sceneVisitors/renderer.h"

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
    render(this->model);
}

void Viewer::setSceneModel(sceneObject* tree) {
    this->model = tree;
}

void Viewer::render(sceneObject* tree) {

    bool isTransformation = dynamic_cast<sceneTransformation*>(tree) != 0;

    if (isTransformation)
        glPushMatrix();

    renderer* r = new renderer();
    tree->accept(r);

    if (!tree->hasChildren())
        return;

    for (int i = 0; i < tree->getChildren()->size(); i++)
        this->render(tree->getChildren()->at(i));

    if (isTransformation)
        glPopMatrix();
}

void Viewer::drawWithNames() {
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

  camera()->setType(qglviewer::Camera::ORTHOGRAPHIC);

  setMouseBinding(Qt::NoModifier, Qt::LeftButton, CAMERA, NO_MOUSE_ACTION);
  setMouseBinding(Qt::AltModifier, Qt::LeftButton, CAMERA, NO_MOUSE_ACTION);
  setMouseBinding(Qt::NoModifier, Qt::MouseButton(Qt::LeftButton + Qt::MidButton), CAMERA, NO_MOUSE_ACTION);
  setMouseBinding(Qt::ControlModifier, Qt::MouseButton(Qt::LeftButton + Qt::MidButton), CAMERA, NO_MOUSE_ACTION);

  setSceneRadius(50);
  showEntireScene();

  setGridIsDrawn(true);

  glDisable(GL_LIGHTING);
}

QString Viewer::helpString() const {
    QString text("<h2>SimpleViewer - Lab 1</h2>");
    return text;
}
