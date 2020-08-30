#ifndef PEOPLE_CPP
#define PEOPLE_CPP

#include "main.hpp"

Node::Node(){
    // Constructor
    cout << "Node Constructed" << endl;
    this->age = -1;
    this->name = NULL;
    this->pid = -1;
    this->current = false;
    this->prev = NULL;
    this->next = NULL;
}

Node::~Node(){
    // Destructor 
    // This function is called when the object is freed.
    cout << "Bye Bye " << this->name << " !" << endl;
}

int Node::getPid(){
    return this->pid;
}
void Node::setPid(int _pid){
    this->pid = _pid;
}

void Node::printNode(){
    cout << this->pid << " " 
        << this->name << " "
        << this->age << "years old ";
    if(current){
    cout << "  <-" << endl;
    }
    else{
    cout << endl;
    }
}

void Node::setCurrent(){
    this->current = !(this->current);
}

char* Node::getName(){
    return this->name;
}

void Node::getOut(){
    prev->next = this->next;
    next->prev = this->prev;
    this->prev = NULL;
    this->next = NULL;
}

#endif