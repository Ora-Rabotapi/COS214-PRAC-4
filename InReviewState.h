#ifndef INREVIEWSTATE_H
#define INREVIEWSTATE_H
#include"TicketState.h"
#include<string>
 
class InReviewState : public TicketState{
    public:
        void block(Ticket* ticket);
        void approve(Ticket* ticket);
        std::string getName() const;
};
 
#endif
 