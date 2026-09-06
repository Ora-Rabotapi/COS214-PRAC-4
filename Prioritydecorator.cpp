#include "PriorityDecorator.h"

PriorityDecorator::PriorityDecorator(WorkItem *wrapped, double priorityCostBump)
    : TicketDecorator(wrapped), priorityCostBump(priorityCostBump) {}

double PriorityDecorator::getCost() const
{
    return wrapped->getCost() + priorityCostBump;
}

std::string PriorityDecorator::getName() const
{
    return "[URGENT] " + wrapped->getName();
}