#ifndef BURNDOWNITERATOR_H
#define BURNDOWNITERATOR_H
#include "WorkItemIterator.h"
#include <vector>

//concrete iterator
class WorkItem;

class BurndownIterator:public WorkItemIterator{
    private:
    std::vector<WorkItem*> snapshot;
    unsigned int cursor;

    void collect(WorkItem* node);
    public:
        BurndownIterator(WorkItem* root);
        virtual ~BurndownIterator();
        bool hasNext();
        WorkItem* next();
};

#endif