#include<iostream>
#include<string>
#include"TicketState.h"
#include"Ticket.h"


TicketState::~TicketState(){

}

void TicketState::start(Ticket*){ 
    logInvalid("start"); 
}

void TicketState::submitForReview(Ticket*){ 
    logInvalid("submitForReview"); 
}

void TicketState::block(Ticket*){ 
    logInvalid("block"); 
}
void TicketState::approve(Ticket*){ 
    logInvalid("approve"); 
}

void TicketState::merge(Ticket*){ 
    logInvalid("merge"); 
}

void TicketState::logInvalid(const std::string& action) const{
    std::cout << "[Invalid transition] " << action << "' is not allowed from state '" << getName() << std::endl;
}