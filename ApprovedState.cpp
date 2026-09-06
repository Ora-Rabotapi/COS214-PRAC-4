#include<iostream>
#include<string>
#include"ApprovedState.h"
#include"Ticket.h"


void ApprovedState::merge(Ticket* ticket){
    std::cout << ticket->getName() << ": Approved -> Merged (flag set)" << std::endl;
    ticket->markMerged();
}

std::string ApprovedState::getName() const{ 
    return "Approved"; 
}