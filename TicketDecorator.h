#ifndef TICKETDECORATOR_H
#define TICKETDECORATOR_H

#include "WorkItem.h"
#include <string>
class TicketDecorator : public WorkItem {
public:
    explicit TicketDecorator(WorkItem* wrapped);
    virtual ~TicketDecorator() override;

    void add(WorkItem* child) override;
    void remove(WorkItem* child) override;
    int getChildCount() const override;
    WorkItem* getChildAt(int index) const override;
    WorkItemIterator* createBurndownIterator() override;
    void print(int indent = 0) const override;
    double getCost() const override;
    std::string getName() const override;
    bool isBlocked() const override;

protected:
    WorkItem* wrapped;
};

#endif