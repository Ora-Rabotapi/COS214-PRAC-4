#ifndef TICKETDECORATOR_H
#define TICKETDECORATOR_H

#include "WorkItem.h"

class TicketDecorator : public WorkItem {
public:
    explicit TicketDecorator(WorkItem* wrapped);
    ~TicketDecorator() override;

    void add(WorkItem* child) override;
    void remove(WorkItem* child) override;
    bool isComposite() const override;
    WorkItemIterator* createIterator() const override;

    double getCost() const override = 0;
    std::string getName() const override = 0;

protected:
    WorkItem* wrapped_;
};

#endif