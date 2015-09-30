TEMPLATE = app
TARGET   = simpleViewer

# Add your .ui file here
FORMS += untitled.ui

HEADERS = simpleViewer.h \
    treeItem.h \
    sceneObjects/rectangle.h \
    sceneObjects/text.h \
    vectorGLf.h \
    sceneObjects/sceneShape.h \
    sceneObjects/sceneObject.h \
    sceneObjects/polygon.h \
    sceneObjects/transformations/translation.h \
    sceneObjects/transformations/scaling.h \
    sceneObjects/transformations/sceneTransformation.h \
    sceneTools/sceneVisitors/sceneVistor.h \
    sceneTools/sceneVisitors/renderer.h
SOURCES = main.cpp \
    simpleViewer.cpp \
    sceneObjects/rectangle.cpp \
    sceneObjects/text.cpp \
    sceneObjects/sceneShape.cpp \
    sceneObjects/transformations/translation.cpp \
    sceneObjects/transformations/scaling.cpp \
    sceneObjects/sceneObject.cpp \
    sceneTools/sceneVisitors/renderer.cpp \
    sceneObjects/polygon.cpp

QT *= xml opengl

# Might have to edit this to reflect the platform dependant name.
win32: LIBS += -lglut32
unix {
  macx {
    LIBS += -framework GLUT
  }
  else
  {
    LIBS += -lglut
  }
}

#CONFIG -= debug debug_and_release
CONFIG += debug_and_release qt opengl warn_on thread rtti console embed_manifest_exe

# If necessary, uncomment and change these paths according to your configuration
#INCLUDEPATH *= /PATH/TO/libQGLViewer-2.6.3
#LIB_DIR = /PATH/TO/libQGLViewer-2.6.3/QGLViewer
LIB_FILE = QGLViewer
win32 {
  CONFIG(debug, debug|release) {
    LIB_FILE = $$join(LIB_FILE,,,d)
  }
  LIB_FILE = $$join(LIB_FILE,,,2)
  LIBS += -l$${LIB_FILE}

  contains ( QT_MAJOR_VERSION, 5 ) {
    contains ( QT_MINOR_VERSION, 5) {
      LIBS *= -lopengl32 -lglu32
    }
  }
}
unix {
  macx {
    LIBS += -framework QGLViewer
  }
  else {
    LIBS += -L$${LIB_DIR} -l$${LIB_FILE}
  }
}

DISTFILES +=
