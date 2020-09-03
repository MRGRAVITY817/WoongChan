#include <iostream>
using namespace std;

class Node {
	public:
		int peopleNumber;
		Node* next;
		// Constructor
		Node(){
			cout << "I am constructed!" << endl;
			this->peopleNumber = 3333333;
			this->next = NULL;
		}
		Node(int _peopleNumber){
			this->peopleNumber = _peopleNumber;
			this->next = NULL;
			cout << this->peopleNumber << "I am constructed!" << endl;
		}
		~Node(){
			cout << "I am free!" << endl;
		}
		void printData(){
			cout << this->peopleNumber << "People in container" << endl;
			return;
		}
};


int main(){
    // Create Nodes
        Node* sample0 = new Node();
	Node* sample1 = new Node();
	Node* sample2 = new Node();
	Node* sample3 = new Node();
	
	Node* firstContainer = new Node(14);
	Node* secondContainer = new Node(6);
	Node* thirdContainer = new Node(1);
	Node* fourthContainer = new Node(19);
	Node* fifthContainer = new Node(8);
	Node* sixthContainer = new Node(44);

	// Linking the nodes to list
	firstContainer->next = secondContainer;
	secondContainer->next = thirdContainer;
	thirdContainer->next = fourthContainer;
	fourthContainer->next = fifthContainer;
	fifthContainer->next = sixthContainer;

	// Iterating through link nodes
	Node* iter = firstContainer;
	for(int i=0; i<6; ++i){
		iter->printData();
		iter = iter->next;
	}

	delete firstContainer;
	delete secondContainer;
	delete thirdContainer;
	delete fourthContainer;
	delete fifthContainer;
	delete sixthContainer;

    return 0;
}
