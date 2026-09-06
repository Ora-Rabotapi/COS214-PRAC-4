#include "Ticket.h"
#include "TicketState.h"
#include "BacklogState.h"
#include "BurndownIterator.h"
#include <iostream>

Ticket::Ticket(const std::string& name, double cost) 
    : name(name), cost(cost), state(new BacklogState()), merged(false) {}

Ticket::~Ticket() {
    delete state;
}

double Ticket::getCost() const { 
    return cost; 
}

std::string Ticket::getName() const { 
    return name; 
}

void Ticket::start() { 
    state->start(this); 
}

void Ticket::submitForReview() { 
    state->submitForReview(this); 
}

void Ticket::block() { 
    state->block(this); 
}

void Ticket::approve() { 
    state->approve(this); 
}

void Ticket::merge() { 
    state->merge(this); 
}

void Ticket::setState(TicketState* newState) {
    delete state;
    state = newState;
}

TicketState* Ticket::getState() const {
    return state;
}

std::string Ticket::getStateName() const { 
    return state->getName(); 
}

bool Ticket::isBlocked() const { 
    return state->getName() == "Blocked"; 
}

bool Ticket::isMerged() const { 
    return merged; 
}

void Ticket::markMerged() { 
    merged = true; 
}

void Ticket::print(int indent) const {
    for (int i = 0; i < indent; ++i) {
        std::cout << "  ";
    }
    std::cout << "- [Ticket] " << name << " ($" << cost << ")" << std::endl;
}

WorkItemIterator* Ticket::createBurndownIterator() {
    return new BurndownIterator(this);
}