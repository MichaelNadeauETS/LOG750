#include "sceneObjects/text.h"

text::text() {
}

void text::setValue(QString value) {
    this->value = value;
}

void text::accept(sceneVisitor* visitor) {
    visitor->visit(this);
}
