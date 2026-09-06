#include<iostream>
#include<string>
#include"InProgressState.h"
#include"InReviewState.h"
#include"Ticket.h"

 
void InProgressState::submitForReview(Ticket* ticket){
    std::cout << ticket->getName() << ": InProgress -> InReview" << std::endl;
    ticket->setState(new InReviewState());
}

std::string InProgressState::getName() const{ 
    return "InProgress"; 
}