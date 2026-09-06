#ifndef INPROGRESSSTATE_H
#define INPROGRESSSTATE_H
#include"TicketState.h"
#include<string>

class InProgressState : public TicketState{
    public:
        void submitForReview(Ticket* ticket);
        std::string getName() const;
};

#endif