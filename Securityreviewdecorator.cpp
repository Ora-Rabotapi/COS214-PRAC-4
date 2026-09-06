#include "SecurityReviewDecorator.h"

SecurityReviewDecorator::SecurityReviewDecorator(WorkItem *wrapped, double reviewOverhead)
    : TicketDecorator(wrapped), reviewOverhead_(reviewOverhead) {}

double SecurityReviewDecorator::getCost() const
{
    return wrapped_->getCost() + reviewOverhead_;
}

std::string SecurityReviewDecorator::getName() const
{
    return wrapped_->getName() + " [security-reviewed]";
}