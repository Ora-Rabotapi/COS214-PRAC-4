#ifndef TICKET_H
#define TICKET_H
#include"WorkItem.h"
#include<string>

class TicketState;

// Ticket is both the Leaf in the Composite hierarchy AND the Context in
// the State pattern: it holds a pointer to its current TicketState and forwards every lifecycle call to it.

class Ticket : public WorkItem{
    private:
        std::string name;
        double cost;
        TicketState* state;
        bool merged;

    public:
        explicit Ticket(const std::string& name, double cost = 0.0);
        ~Ticket();
        double getCost() const;
        std::string getName() const;
        void start();
        void submitForReview();
        void block();
        void approve();
        void merge();
        void setState(TicketState* newState);
        std::string getStateName() const;
        bool isBlocked() const;
        bool isMerged() const;
        void markMerged();

};

#endif 