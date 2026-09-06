#include<iostream>
#include<string>
#include"BlockedState.h"
#include"InProgressState.h"
#include"Ticket.h"


void BlockedState::start(Ticket* ticket){
    std::cout << ticket->getName() << ": Blocked -> InProgress (blocker resolved)" << std::endl;
    ticket->setState(new InProgressState());
}

std::string BlockedState::getName() const{ 
    return "Blocked"; 
}