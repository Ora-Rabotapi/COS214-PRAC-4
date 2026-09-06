#include "BurndownIterator.h"
#include "Group.h"
#include "WorkItem.h"

BurndownIterator::BurndownIterator(WorkItem* root):cursor(0) {
    if (root!=nullptr) {
        collect(root);
    }
}

BurndownIterator::~BurndownIterator() {
    snapshot.clear();
}

void BurndownIterator::collect(WorkItem* node) {
    if (node==nullptr){
        return;
    }
    snapshot.push_back(node);

    const Group* group=dynamic_cast<const Group*>(node);
    if (group != nullptr) {
        const std::vector<WorkItem*>& children = group->getChildren();
        for (std::vector<WorkItem*>::const_iterator it = children.begin(); it != children.end(); ++it) {
            collect(*it);
        }
    }
}

bool BurndownIterator::hasNext() {
    return cursor<snapshot.size();
}

WorkItem* BurndownIterator::next() {
    if (hasNext()) {
        WorkItem* current=snapshot[cursor];
        cursor++;
        return current;
    }
    return nullptr;
}