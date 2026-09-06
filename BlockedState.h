#ifndef BLOCKEDSTATE_H
#define BLOCKEDSTATE_H
#include"TicketState.h"
#include<string>

class BlockedState : public TicketState{
    public:
        // Loops back to InProgress once the blocker is resolved.
        void start(Ticket* ticket);
        std::string getName() const;
};

#endif