#ifndef BACKLOGSTATE_H
#define BACKLOGSTATE_H
#include"TicketState.h"
#include<string>

class BacklogState : public TicketState{
    public:
        void start(Ticket* ticket);
        std::string getName() const;
};
 
#endif
 