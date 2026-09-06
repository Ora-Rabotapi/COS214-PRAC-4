#include <iostream>
#include "Group.h"
#include "Ticket.h"
#include "WorkItemIterator.h"

int main() {
    std::cout << "===============================================\n";
    std::cout << "  TASKFORGE MEMBER 1: COMPOSITE & ITERATOR TEST\n";
    std::cout << "===============================================\n\n";

    // 1. Build a 3-level deep hierarchy below root (Rule 6)
    // Root: release
    // Level 1: epics
    // Level 2: features
    // Level 3: tickets
    Group* release = new Group("Release 4.2");

    Group* authEpic = new Group("Auth Overhaul Epic");
    Group* loginFeature = new Group("OAuth Login Feature");
    Ticket* t1 = new Ticket("OAuth endpoint configuration", 120.0);
    Ticket* t2 = new Ticket("Token refresh logic", 80.0);
    loginFeature->add(t1);
    loginFeature->add(t2);
    authEpic->add(loginFeature);

    Group* billingEpic = new Group("Billing Pipeline Epic");
    Group* stripeFeature = new Group("Stripe Gateway Feature");
    Ticket* t3 = new Ticket("Webhook signature verification", 150.0);
    Ticket* t4 = new Ticket("Invoice PDF generation", 90.0);
    stripeFeature->add(t3);
    stripeFeature->add(t4);
    billingEpic->add(stripeFeature);

    release->add(authEpic);
    release->add(billingEpic);

    // 2. Test Recursive Cost Aggregation
    std::cout << "--- 1. Recursive Composition & Costs ---\n";
    release->print(0);
    std::cout << "\nCalculated Total Cost: $" << release->getCost() << " (Expected: $440.0)\n\n";

    // 3. Test Full Traversal via BurndownIterator
    std::cout << "--- 2. BurndownIterator Full Traversal ---\n";
    WorkItemIterator* fullIter = release->createBurndownIterator();
    int count = 1;
    while (fullIter->hasNext()) {
        WorkItem* item = fullIter->next();
        std::cout << "Step " << count++ << ": " << item->getName() 
                  << " | Cost: $" << item->getCost() 
                  << " | Children: " << item->getChildCount() << "\n";
    }
    delete fullIter;

    // 4. Test Two Concurrent, Independent Iterators
    std::cout << "\n--- 3. Two Independent Iterators Running Concurrently ---\n";
    WorkItemIterator* iter1 = release->createBurndownIterator();
    WorkItemIterator* iter2 = release->createBurndownIterator();

    std::cout << "Iter 1, advance 1: " << iter1->next()->getName() << "\n";
    std::cout << "Iter 1, advance 2: " << iter1->next()->getName() << "\n";
    std::cout << "Iter 2, advance 1 (must be independent root): " << iter2->next()->getName() << "\n";
    std::cout << "Iter 1, advance 3: " << iter1->next()->getName() << "\n";

    delete iter1;
    delete iter2;

    // 5. Test Traversal Snapshot Policy Under Structural Mutation
    std::cout << "\n--- 4. Traversal-Modification Snapshot Policy ---\n";
    WorkItemIterator* snapshotIter = release->createBurndownIterator();
    std::cout << "Snapshot iterator instantiated.\n";

    std::cout << "Tree modification: detaching 'Token refresh logic' from OAuth Login...\n";
    loginFeature->remove(t2);

    std::cout << "Walking through snapshot (should safely complete and include detached item):\n";
    while (snapshotIter->hasNext()) {
        std::cout << "  -> " << snapshotIter->next()->getName() << "\n";
    }
    delete snapshotIter;

    // Clean up manually detached pointer to avoid leaks
    delete t2;

    // 6. Test Polymorphic Destruction (Rules 4 & 5)
    std::cout << "\n--- 5. Polymorphic Cascading Deletion ---\n";
    std::cout << "Deleting root 'Release 4.2'...\n";
    delete release;
    std::cout << "Destruction completed successfully.\n";

    return 0;
}