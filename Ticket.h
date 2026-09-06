#ifndef TICKET_H
#define TICKET_H

#include "WorkItem.h"
#include <string>

class TicketState;
class WorkItemIterator;

class Ticket : public WorkItem {
private:
    std::string name;
    double cost;
    TicketState* state;
    bool merged;

public:
    Ticket(const std::string& name, double cost = 0.0);
    virtual ~Ticket();
    std::string getName() const override;
    double getCost() const override;
    void print(int indent = 0) const override;
    WorkItemIterator* createBurndownIterator() override;
    void start();
    void submitForReview();
    void block();
    void approve();
    void merge();
    void setState(TicketState* newState);
    TicketState* getState() const;
    std::string getStateName() const;
    bool isBlocked() const;
    bool isMerged() const;
    void markMerged();
};

#endif