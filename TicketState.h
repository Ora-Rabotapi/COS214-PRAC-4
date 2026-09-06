#ifndef TICKETSTATE_H
#define TICKETSTATE_H
#include<string>

class Ticket;

class TicketState{
    protected:
        void logInvalid(const std::string& action) const;

    public:
        virtual ~TicketState();
        virtual void start(Ticket* ticket);
        virtual void submitForReview(Ticket* ticket);
        virtual void block(Ticket* ticket);
        virtual void approve(Ticket* ticket);
        virtual void merge(Ticket* ticket);
        virtual std::string getName() const = 0; 
};


#endif