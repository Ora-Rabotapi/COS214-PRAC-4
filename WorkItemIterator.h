#ifndef WORKITEMITERATOR_H
#define WORKITEMITERATOR_H

class WorkItem;

class WorkItemIterator{
    public:
        virtual bool hasNext() = 0;
        virtual WorkItem* next() = 0;
        virtual ~WorkItemIterator();
};

#endif