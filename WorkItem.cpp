#include "WorkItem.h"

void WorkItem::add(WorkItem*) {}
void WorkItem::remove(WorkItem*){}


int WorkItem::getChildCount() const {
    return 0;
}

WorkItem* WorkItem::getChildAt(int) const {
    return nullptr;
}