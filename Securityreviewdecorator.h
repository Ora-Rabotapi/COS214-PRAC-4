#ifndef SECURITYREVIEWDECORATOR_H
#define SECURITYREVIEWDECORATOR_H

#include "TicketDecorator.h"

class SecurityReviewDecorator : public TicketDecorator {
public:
    explicit SecurityReviewDecorator(WorkItem* wrapped, double reviewOverhead = 2.0);

    double getCost() const override;
    std::string getName() const override;

private:
    double reviewOverhead_;
};

#endif