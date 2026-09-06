#ifndef BLOCKEDTICKETITERATOR_H
#define BLOCKEDTICKETITERATOR_H
#include"WorkItemIterator.h"
#include<vector>

class WorkItem;

class BlockedTicketIterator : public WorkItemIterator{
    private:
        void collect(WorkItem* node, std::vector<WorkItem*>& out) const;
        std::vector<WorkItem*> snapshot;
        int cursor;
        
    public:
        BlockedTicketIterator(WorkItem* root);
        bool hasNext();
        WorkItem* next();
};