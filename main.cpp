#include <iostream>
#include "Group.h"
#include "Ticket.h"
#include "BurndownIterator.h"
#include "BlockedTicketIterator.h"
#include "PriorityDecorator.h"
#include "SecurityReviewDecorator.h"

int main() {
    
    std::cout << "        TASKFORGE: HIERARCHICAL WORK PROCESSING SYSTEM        \n\n";
    

    
    // SCENARIO 1: SPRINT PLANNING & FULL BURNDOWN HIERARCHY

    std::cout << ">>> SCENARIO 1: Building Software Delivery Pipeline Hierarchy\n\n";

    // Root Level (Level 0)
    Group* release = new Group("Release 4.2");

    // Level 1: Epics
    Group* authEpic = new Group("Authentication Overhaul Epic");
    Group* billingEpic = new Group("Billing Pipeline Epic");

    // Level 2: Features
    Group* loginFeature = new Group("OAuth Login Feature");
    Group* sessionFeature = new Group("JWT Session Feature");
    Group* stripeFeature = new Group("Stripe Gateway Feature");

    // Level 3: Individual Work Items (Tickets)
    Ticket* t1 = new Ticket("Configure OAuth endpoints", 120.0);
    Ticket* t2 = new Ticket("Implement refresh token rotation", 80.0);
    Ticket* t3 = new Ticket("Session timeout validation", 60.0);
    Ticket* t4 = new Ticket("Stripe webhook listener", 150.0);
    Ticket* t5 = new Ticket("Generate customer invoice PDF", 90.0);

    // Assemble OAuth Feature & JWT Feature under Auth Epic
    loginFeature->add(t1);
    loginFeature->add(t2);
    sessionFeature->add(t3);
    authEpic->add(loginFeature);
    authEpic->add(sessionFeature);

    // Assemble Stripe Feature under Billing Epic
    stripeFeature->add(t4);
    stripeFeature->add(t5);
    billingEpic->add(stripeFeature);

    // Assemble Epics under Release
    release->add(authEpic);
    release->add(billingEpic);

    // Display Hierarchical Tree & Aggregated Recursive Cost
    std::cout << "--- 1. Full Release Hierarchy Visualisation ---\n";
    release->print(0);
    std::cout << "\nInitial Total Release Cost: $" << release->getCost() << "\n\n";

    // Full Traversal using BurndownIterator (Member 1)
    std::cout << "--- 2. Full Burndown Traversal ---\n";
    WorkItemIterator* burndown = release->createBurndownIterator();
    int step = 1;
    while (burndown->hasNext()) {
        WorkItem* current = burndown->next();
        std::cout << "  [" << step++ << "] " << current->getName()
                  << " | Sub-items: " << current->getChildCount()
                  << " | Cost: $" << current->getCost() << "\n";
    }
    delete burndown;

    // Two Concurrent Independent Iterators
    std::cout << "\n--- 3. Demonstrating Two Independent Iterators ---\n";
    WorkItemIterator* iterA = release->createBurndownIterator();
    WorkItemIterator* iterB = release->createBurndownIterator();

    std::cout << "Iter A advance 1: " << iterA->next()->getName() << "\n";
    std::cout << "Iter A advance 2: " << iterA->next()->getName() << "\n";
    std::cout << "Iter B advance 1 (independent from Root): " << iterB->next()->getName() << "\n";
    std::cout << "Iter A advance 3: " << iterA->next()->getName() << "\n";

    delete iterA;
    delete iterB;


    // SCENARIO 2: LIFECYCLE PROGRESSION, STACKED DECORATORS & MID-SPRINT RESCOPING


    std::cout << "\n\n>>> SCENARIO 2: Lifecycle Execution & Dynamic Responsibilities\n\n";

    std::cout << "--- 4. Progressing Ticket Lifecycles (State Transitions) ---\n";
    // t1: Backlog -> InProgress -> InReview -> Approved -> Merged
    t1->start();
    t1->submitForReview();
    t1->approve();
    t1->merge();

    // t2: Backlog -> InProgress -> InReview -> Blocked
    t2->start();
    t2->submitForReview();
    t2->block();

    // t4: Backlog -> InProgress -> Blocked (unsupported direct jump tests invalid transition)
    t4->block(); // Invalid transition from Backlog
    t4->start();
    t4->submitForReview();
    t4->block();

    // Dynamically Decorate t2 with Stackable Decorators (Member 3)
    std::cout << "\n--- 5. Dynamic Responsibility Stacking (Decorators) ---\n";
    std::cout << "Detaching 't2' to wrap in runtime decorators...\n";
    loginFeature->remove(t2);

    // Apply PriorityDecorator (adds $35.0 bump and [URGENT] tag)
    WorkItem* urgentTicket = new PriorityDecorator(t2, 35.0);


    // Stack SecurityReviewDecorator on top (adds $50.0 overhead and [security-reviewed] tag)
    WorkItem* fullyDecoratedTicket = new SecurityReviewDecorator(urgentTicket, 50.0);

    // Re-attach decorated ticket back into the hierarchy
    loginFeature->add(fullyDecoratedTicket);

    std::cout << "Decorated WorkItem Name: " << fullyDecoratedTicket->getName() << "\n";
    std::cout << "Decorated WorkItem Cost: $" << fullyDecoratedTicket->getCost() 
              << " (Original: $80.0 + $35.0 Priority + $50.0 Security)\n";
    std::cout << "Updated Release Total Cost: $" << release->getCost() << "\n\n";

    // Filtered Traversal using BlockedTicketIterator (Member 2)
    std::cout << "--- 6. Filtered Standup Traversal (Blocked Tickets Only) ---\n";
    BlockedTicketIterator* blockedIter = new BlockedTicketIterator(release);
    int blockedCount = 1;
    while (blockedIter->hasNext()) {
        WorkItem* blocked = blockedIter->next();
        std::cout << "  [Blocked " << blockedCount++ << "] " 
                  << blocked->getName() << " ($" << blocked->getCost() << ")\n";
    }
    delete blockedIter;


    // SCENARIO 3: TRAVERSAL-MODIFICATION SNAPSHOT POLICY


    std::cout << "\n\n>>> SCENARIO 3: Traversal-Modification Snapshot Policy\n\n";

    std::cout << "Instantiating BurndownIterator snapshot...\n";
    WorkItemIterator* snapshotIter = release->createBurndownIterator();

    std::cout << "Simulating mid-sprint restructuring: Moving 't3' from JWT Feature to OAuth Feature...\n";
    sessionFeature->remove(t3);
    loginFeature->add(t3);

    std::cout << "Resolving blocker on t2: Blocked -> InProgress...\n";
    t2->start();

    std::cout << "\nIterating over previously captured snapshot:\n";
    while (snapshotIter->hasNext()) {
        std::cout << "  -> " << snapshotIter->next()->getName() << "\n";
    }
    delete snapshotIter;


    // MEMORY CLEANUP: POLYMORPHIC DESTRUCTION (Rules 4 & 5)


    std::cout << "\n\n>>> CLEANUP: Polymorphic Cascading Destruction\n";
    std::cout << "Deleting root composite 'Release 4.2'...\n";
    delete release;
    std::cout << "Memory deallocation finished cleanly.\n";

    return 0;
}