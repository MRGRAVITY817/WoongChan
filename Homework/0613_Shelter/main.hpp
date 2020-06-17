#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
using namespace std;


class People{
    private: 
        int age; // Size 4
        int height; // Size 4
        char* name; // Size 8 
        int pid; // Size 4
    public: 
        bool current; // Size 1

        People();
        People(char* name, int age, int height, int pid);
        People(const People& p);
        ~People();
        int getPid();
        void setPid(int _pid);
        char* getName();
        void setCurrent();
        void printPeople();
        void getOut();
};

class Shelter{
    private:
        People* head;
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