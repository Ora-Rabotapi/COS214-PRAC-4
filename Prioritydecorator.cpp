#include "PriorityDecorator.h"

PriorityDecorator::PriorityDecorator(WorkItem *wrapped, double priorityCostBump)
    : TicketDecorator(wrapped), priorityCostBump_(priorityCostBump) {}

double PriorityDecorator::getCost() const
{
    return wrapped_->getCost() + priorityCostBump_;
}

std::string PriorityDecorator::getName() const
{
    return "[URGENT] " + wrapped_->getName();
}