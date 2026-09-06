#include "TicketDecorator.h"

TicketDecorator::TicketDecorator(WorkItem* wrapped) : wrapped_(wrapped) {}

TicketDecorator::~TicketDecorator() {
    delete wrapped_;
}

void TicketDecorator::add(WorkItem* child) {
    wrapped_->add(child);
}

void TicketDecorator::remove(WorkItem* child) {
    wrapped_->remove(child);
}

bool TicketDecorator::isComposite() const {
    return wrapped_->isComposite();
}

WorkItemIterator* TicketDecorator::createIterator() const {
    return wrapped_->createIterator();
}