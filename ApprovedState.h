#ifndef APPROVEDSTATE_H
#define APPROVEDSTATE_H
#include"TicketState.h"
#include<string>

class ApprovedState : public TicketState{
    public:
        void merge(Ticket* ticket);
        std::string getName() const;
};

#endif