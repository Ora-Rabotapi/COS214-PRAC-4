#include<iostream>
#include<string>
#include"InReviewState.h"
#include"BlockedState.h"
#include"ApprovedState.h"
#include"Ticket.h"

void InReviewState::block(Ticket* ticket){
    std::cout << ticket->getName() << ": InReview -> Blocked" <<std::endl;
    ticket->setState(new BlockedState());
}

void InReviewState::approve(Ticket* ticket){
    std::cout << ticket->getName() << ": InReview -> Approved" << std::endl;
    ticket->setState(new ApprovedState());
}

std::string InReviewState::getName() const{ 
    return "InReview"; 
}