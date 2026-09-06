#ifndef BURNDOWNITERATOR_H
#define BURNDOWNITERATOR_H
#include "WorkItemIterator.h"
#include <vector>

class WorkItem;

class BurndownIterator:public WorkItemIterator{
    private:
    std::vector<WorkItem*> snapshot;
    int cursor;

    void collect(WorkItem* node);
    public:
        BurndownIterator(WorkItem* root);
        virtual ~BurndownIterator();
        bool hasNext();
        WorkItem* next();
};

#endif