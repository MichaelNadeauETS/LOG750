#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>

template <class treeItemType>
class treeItem
{
    public:
        void addChild(treeItemType* item){
            if (!this->hasChildren())
                this->children = new QList<treeItemType*>();

            this->children->append(item);
        }

        bool hasChildren() {
            if (this->children == 0)
                return false;

            return this->children->count() > 0;
        }

        QList<treeItemType*>* getChildren() {
            return this->children;
        }

    private:
        QList<treeItemType*>* children = 0;

};

#endif // TREEITEM_H
