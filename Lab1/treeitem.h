#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>

class treeItem
{
    public:
        treeItem();

    protected:
        void addChild(treeItem* item);
        void setParent(treeItem* item);

        treeItem* getParent();
        QList<treeItem>* getChildren();

    private:
        treeItem* parent = 0;
        QList<treeItem>* children = new QList<treeItem>();

};

#endif // TREEITEM_H
