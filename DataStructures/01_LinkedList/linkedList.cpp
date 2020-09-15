#include <iostream>
using namespace std;

class Node {
  public:

    int peopleNumber;
    Node* prev;
    Node* next;
    // Constructor

    Node(){
      this->peopleNumber = 0;
      this->prev= NULL;
      this->next = NULL;
    }

    Node(int _peopleNumber){
      this->peopleNumber = _peopleNumber;
      this->prev= NULL;
      this->next = NULL;
    }

		~Node(){
		}

		void printData(){
			cout << this->peopleNumber << " People in container" << endl;
			return;
		}

    void insertNext(Node* newNode){
      // If next seat is not empty, ask next person again. 
      if(this->next!=NULL){
        this->next->insertNext(newNode);
      }
      // If next seat is empty, then sit on next seat.
      else{
        this->next = newNode;
        newNode->prev = this;
      }
    }
    
    void deleteNode(Node* delNode){
      // If next seat in not delNode
      if(this->next!=delNode){
        this->next->deleteNode(delNode);
      }
      else if(this->next==delNode){
        // this->next = delNode->next;
        this->next = delNode->next;
        delNode->next->prev = this;
        delNode->next = NULL;
        delNode->prev = NULL;
        delete delNode;
      }
      else if(this==delNode){
        cout << "If you delete this node, you will have to " << endl;
        cout << "bring other node to call linked list." << endl;
        cout << "Proceed? (y/n): ";
        char yesOrNo;
        cin >> yesOrNo;
        if(yesOrNo=='y' || yesOrNo=='Y'){
          this->next = NULL;
          this->prev = NULL;
        }
        else{
          return;
        }
      }

      
    }
    
    void changeSeat(Node* changeNode, int Number){
      if(Number==1){
        // change Node will be gone, so left and right
        // have to point each other
        changeNode->prev->next = changeNode->next;
        changeNode->next->prev = changeNode->prev;
        // Link for head
        changeNode->next = this;
        this->prev = changeNode;
      }

      static int iter = 1;
      if(iter!=Number){
        iter++;
        this->next->changeSeat(changeNode, Number);
      }
      else if(iter==Number){
        // change Node will be gone, so left and right
        // have to point each other
        changeNode->prev->next = changeNode->next;
        changeNode->next->prev = changeNode->prev;
        // left point me, I point left.
        // right point me, I point right.
        Node* tmp = this->next; // Because we don't want to lose next address.
        this->next = changeNode;
        changeNode->prev = this;
        changeNode->next = tmp;
        tmp->prev = changeNode;
      }

    }

    void swapSeat(Node* nodeOne, Node* nodeTwo){
      Node* tmp1 = nodeTwo->next;

      // Node-one family solve!
      nodeOne->prev->next = nodeTwo;
      nodeTwo->prev = nodeOne->prev;
      nodeTwo->next = nodeOne->next;
      nodeOne->next->prev = nodeTwo;
       // Node-two family solve!
      nodeTwo->next->next = nodeOne;
      nodeOne->prev = nodeTwo->next;
      nodeOne->next = tmp1;
      tmp1->prev = nodeOne;
    }
};

/*
class LinkedList{
  public:
    Node* head;
    LinkedList(){
      this->head = NULL;
    }
    LinkedList(Node* newHead){
      this->head = newHead;
    }
    void changeHead(){
      this->head = this->head->next;
    }
};
*/

int main(){

	Node* firstContainer = new Node(1);
	Node* secondContainer = new Node(2);
	Node* thirdContainer = new Node(3);
	Node* fourthContainer = new Node(4);
	Node* fifthContainer = new Node(5);
	Node* sixthContainer = new Node(6);

	// Linking the nodes to list
  /*
	firstContainer->next = secondContainer;
	secondContainer->next = thirdContainer;
	thirdContainer->next = fourthContainer;
	fourthContainer->next = fifthContainer;
	fifthContainer->next = sixthContainer;
  */
  firstContainer->insertNext(secondContainer);
  firstContainer->insertNext(thirdContainer);
  firstContainer->insertNext(fourthContainer);
  firstContainer->insertNext(fifthContainer);
  firstContainer->insertNext(sixthContainer);

	// Iterating through link nodes
  cout << "Iterating through link nodes"<< endl;
	Node* iter = firstContainer;
	for(int i=0; i<6; ++i){
		iter->printData();
		iter = iter->next;
	}
  cout << endl;

  // Swap seat between Second and Fourth
  cout << "Swap seat between Second and Fourth"<< endl;
  firstContainer->swapSeat(secondContainer, fourthContainer);
  iter = firstContainer;
	for(int i=0; i<6; ++i){
		iter->printData();
		iter = iter->next;
	}
  cout << endl;

  
  cout << "Delete Fourth Container"<< endl;
  firstContainer->deleteNode(fourthContainer);
  iter = firstContainer;
	for(int i=0; i<5; ++i){
		iter->printData();
		iter = iter->next;
	}
  cout << endl;

  
  cout << "Change Second Conatiner to 4th place"<< endl;
  firstContainer->changeSeat(secondContainer, 4);
  iter = firstContainer;
	for(int i=0; i<5; ++i){
		iter->printData();
		iter = iter->next;
	}
  cout << endl;


  /*
	delete firstContainer;
	delete secondContainer;
	delete thirdContainer;
	delete fourthContainer;
	delete fifthContainer;
	delete sixthContainer;
  */

  return 0;
}
