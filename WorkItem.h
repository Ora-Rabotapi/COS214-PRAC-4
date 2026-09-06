#ifndef WORKITEM_H
#define WORKITEM_H
#include <string>

//component 
class WorkItemIterator;

class WorkItem{
    public:
        virtual ~WorkItem();
        virtual void add(WorkItem* item);
        virtual void remove(WorkItem* item);

        virtual std::string getName() const=0;
        virtual double getCost() const=0;
        virtual void print(int index=0) const =0;
        virtual WorkItemIterator* createBurndownIterator()=0;
      
};
#endif