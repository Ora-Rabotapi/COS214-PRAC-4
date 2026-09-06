#ifndef TICKET_H
#define TICKET_H
#include "WorkItem.h"
#include <string>

class TicketState;
//Leaf participant
//concrete aggregate participant
class Ticket:public WorkItem{
    private:
    std::string name;
    double baseCost;
    TicketState* currentState;

    public:
    Ticket(const std::string& ticketName, double cost=0.0);
    virtual ~Ticket();

    std::string getName() const override;
    double getCost() const override;
    void print(int indent=0) const override;
    WorkItemIterator* createBurndownIterator() override;
    void setState(TicketState* newState);
    TicketState* getState() const;
};
#endif 