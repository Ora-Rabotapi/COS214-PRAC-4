#include "TicketDecorator.h"

TicketDecorator::TicketDecorator(WorkItem* wrapped) : wrapped(wrapped) {}

TicketDecorator::~TicketDecorator() {
    delete wrapped;
}

void TicketDecorator::add(WorkItem* child) {
    wrapped->add(child);
}

void TicketDecorator::remove(WorkItem* child) {
    wrapped->remove(child);
}

bool TicketDecorator::isComposite() const {
    return wrapped->isComposite();
}

WorkItemIterator* TicketDecorator::createIterator() const {
    return wrapped->createIterator();
}