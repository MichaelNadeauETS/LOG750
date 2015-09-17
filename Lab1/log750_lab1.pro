TEMPLATE = app
TARGET   = simpleViewer

# Add your .ui file here
FORMS += untitled.ui

HEADERS  = simpleViewer.h
SOURCES  = simpleViewer.cpp main.cpp

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
