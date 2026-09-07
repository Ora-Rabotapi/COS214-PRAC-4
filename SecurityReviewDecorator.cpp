#include "SecurityReviewDecorator.h"

SecurityReviewDecorator::SecurityReviewDecorator(WorkItem *wrapped, double reviewOverhead)
    : TicketDecorator(wrapped), reviewOverhead(reviewOverhead) {}

double SecurityReviewDecorator::getCost() const
{
    return wrapped->getCost() + reviewOverhead;
}

std::string SecurityReviewDecorator::getName() const
{
    return wrapped->getName() + " [security-reviewed]";
}