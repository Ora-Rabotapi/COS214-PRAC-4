#ifndef WORKITEM_H
#define WORKITEM_H
#include <string>

//component participant in composite
//aggregate participant in iterator
class WorkItemIterator;

class WorkItem{
    public:
        virtual ~WorkItem(){}
        virtual void add(WorkItem* item);
        virtual void remove(WorkItem* item);
        virtual int getChildCount() const;
        virtual WorkItem* getChildAt(int) const;
        virtual std::string getName() const=0;
        virtual double getCost() const=0;
        virtual void print(int index=0) const =0;
        virtual WorkItemIterator* createBurndownIterator()=0;
        virtual bool isBlocked() const;
      
};
#endif