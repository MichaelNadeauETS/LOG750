#include "sceneObjects/text.h"

text::text() {
}

void text::setValue(QString value) {
    this->value = value;
}

void text::render() {
    super::render();

    for (int i = 0; i < this->value.count(); i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, this->value.at(i).unicode());
}
