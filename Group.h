#ifndef GROUP_H
#define GROUP_H
#include "WorkItem.h"
#include <vector>
#include <string>

class Group: public WorkItem{
    private:
    std::string name;
    std::vector<WorkItem*> children;

    public:
    Group(const std::string& groupName);
    virtual ~Group();

    void add(WorkItem* item) override;
    void remove(WorkItem* item) override;
    std::string getName() const override;
    double getCost() const override;
    void print(int index=0) const override;
    WorkItemIterator* createBurndownIterator() override;
    const std::vector<WorkItem*>& getChildren() const;
};

#endif