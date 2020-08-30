#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
using namespace std;

class Node {
    private: 
        int age;
        char* name;
        int pid;
        bool current;
        // Linking Previous & Next nodes with pointer
        Node* prev;
        Node* next;
    public:
        // Constructors and methods
        Node();
        Node(int _age, char* _name);
        ~Node();
        int getPid();
        void setPid(int _pid);
        char* getName();
        void printNode();
        void setCurrent();
        void getOut();
};

class Shelter{
    private:
        Node* head;
        int maxPeople;
        int peopleCount;
    public:
        Shelter();
        ~Shelter();

        // Original functions
        int peopleNumber();
        void changeCurrentPerson();
        void peopleList();
        void addPerson();

        // Homework functions
        void changePid();
        void removePeople();
        void resizeShelter();
};

#endif