#include<iostream>
#include<string>
#include"BacklogState.h"
#include"InProgressState.h"
#include"Ticket.h"

void BacklogState::start(Ticket* ticket){
    std::cout << ticket->getName() << ": Backlog -> InProgress" << std::endl;
    ticket->setState(new InProgressState());
}

std::string BacklogState::getName() const{
    return "Backlog";
}