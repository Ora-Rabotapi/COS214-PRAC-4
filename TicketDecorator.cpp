#include "TicketDecorator.h"

TicketDecorator::TicketDecorator(WorkItem* wrapped) : wrapped(wrapped) {}

TicketDecorator::~TicketDecorator() {
    delete wrapped;
}

void TicketDecorator::add(WorkItem* child) {
    if(wrapped!=nullptr){
        wrapped->add(child);
    }
    
}


void TicketDecorator::remove(WorkItem* child) {
    if(wrapped!=nullptr){
        wrapped->remove(child);
    }
    
}
int TicketDecorator::getChildCount() const {
    return wrapped!=nullptr?wrapped->getChildCount():0;
}

WorkItem* TicketDecorator::getChildAt(int index) const {
    return wrapped!= nullptr?wrapped->getChildAt(index):nullptr;
}

void TicketDecorator::print(int indent) const {
    if (wrapped!=nullptr) {
        wrapped->print(indent);
    }
}


WorkItemIterator* TicketDecorator::createBurndownIterator() {
    return wrapped != nullptr ? wrapped->createBurndownIterator():nullptr;
}

std::string TicketDecorator::getName() const {
    return wrapped != nullptr ? wrapped->getName() : "";
}

double TicketDecorator::getCost() const {
    return wrapped != nullptr ? wrapped->getCost() : 0.0;
}

bool TicketDecorator::isBlocked() const {
    return wrapped != nullptr ? wrapped->isBlocked() : false;
}