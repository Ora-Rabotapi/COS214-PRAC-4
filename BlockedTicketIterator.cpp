#include<iostream>
#include<vector>
#include"BlockedTicketIterator.h"
#include"WorkItem.h"
#include"Ticket.h"

BlockedTicketIterator::BlockedTicketIterator(WorkItem* root) : cursor(0){
    collect(root, snapshot);
}

void BlockedTicketIterator::collect(WorkItem* node, std::vector<WorkItem*>& out) const{
    if(node == nullptr){
        return;
    }

    Ticket* asTicket = dynamic_cast<Ticket*>(node);

    if(asTicket != nullptr){
        if(asTicket->isBlocked()){
            out.push_back(node);
        }
        return; // a Ticket leaf has no children
    }

    for(int i = 0; i < node->getChildCount(); ++i){
        collect(node->getChildAt(i), out);
    }
}

bool BlockedTicketIterator::hasNext(){
    return cursor < static_cast<int>(snapshot.size());
}

WorkItem* BlockedTicketIterator::next(){
    return snapshot[cursor++];
}