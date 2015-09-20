#include "treeItem.h"

treeItem::treeItem() {
}

void treeItem::addChild(treeItem* item) {
    item->setParent(this);
    this->children->append(*item);
}

void treeItem::setParent(treeItem* item) {
    this->parent = item;
}

treeItem* treeItem::getParent() {
    return this->parent;
}

QList<treeItem>* treeItem::getChildren() {
    return this->children;
}
