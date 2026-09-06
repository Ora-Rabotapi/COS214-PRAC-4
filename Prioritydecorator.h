#ifndef PRIORITYDECORATOR_H
#define PRIORITYDECORATOR_H

#include "TicketDecorator.h"

class PriorityDecorator : public TicketDecorator
{
public:
    explicit PriorityDecorator(WorkItem *wrapped, double priorityCostBump = 0.5);

    double getCost() const override;
    std::string getName() const override;

private:
    double priorityCostBump_;
};

#endif