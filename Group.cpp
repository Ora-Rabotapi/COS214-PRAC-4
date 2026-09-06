#include "Group.h"
#include "BurndownIterator.h"
#include <iostream>
#include <algorithm>

Group::Group(const std::string& groupName):name(groupName){}

Group::~Group(){
    for(std::vector<WorkItem*>::iterator it=children.begin();it!=children.end();++it){
        delete *it;
    }
    children.clear();
}

void Group::add(WorkItem* item){
    if(item!=nullptr){
        children.push_back(item);
    }
}

void Group::remove(WorkItem* item){
    std::vector<WorkItem*>::iterator it=std::find(children.begin(),children.end(),item);
    if(it!=children.end()){
        children.erase(it);
    }
}

std::string Group::getName() const{
    return name;
}

double Group::getCost() const{
    double total=0.0;
    for(std::vector<WorkItem*>::const_iterator it=children.begin();it!=children.end();++it){
        total+=(*it)->getCost();
    }
    return total;
}

void Group::print(int indent) const{
    for(int i=0;i<indent;i++){
        std::cout<<" ";
    }
    std::cout<<"+ [Group: "<<name<<"] (Subtotal: $"<<getCost()<<")"<<std::endl;
    for(std::vector<WorkItem*>::const_iterator it=children.begin();it!=children.end();++it){
        (*it)->print(indent+1);
    }
}

WorkItemIterator* Group::createBurndownIterator(){
    return new BurndownIterator(this);
}

const std::vector<WorkItem*>& Group::getChildren()const {
    return children;
}