#include "Ticket.h"
#include "BurndownIterator.h"
#include <iostream>

Ticket::Ticket(const std::string& ticketName, double cost)
    : name(ticketName), baseCost(cost), currentState(nullptr) {}

Ticket::~Ticket() {
 
}

std::string Ticket::getName() const {
    return name;
}

double Ticket::getCost() const {
    return baseCost;
}

void Ticket::print(int indent) const {
    for (int i = 0; i < indent; ++i) {
        std::cout << "  ";
    }
    std::cout << "- [Ticket] " << name << " ($" << baseCost << ")" << std::endl;
}

WorkItemIterator* Ticket::createBurndownIterator() {
    return new BurndownIterator(this);
}

void Ticket::setState(TicketState* newState) {
    currentState = newState;
}

TicketState* Ticket::getState() const {
    return currentState;
}