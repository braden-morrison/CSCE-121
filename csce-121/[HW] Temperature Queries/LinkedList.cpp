#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList(): head(nullptr), tail(nullptr) {} //default constructor
	// Implement this function

LinkedList::~LinkedList()  { //destructor
	// Implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr) { //copy constructor
	// Implement this function
	Node* cur = source.head;
	while(cur != nullptr) {
		insert(cur->data.id, cur->data.year, cur->data.month, cur->data.temperature);
		cur = cur->next;
	}
		
		
}

LinkedList& LinkedList::operator=(const LinkedList& source) { //copy constructor
	// Implement this function
	if(this != &source) {
		clear();
		Node* cur = source.head;
		while(cur != nullptr) {
			insert(cur->data.id, cur->data.year, cur->data.month, cur->data.temperature);
			cur = cur->next;
		}
	}
	return *this;
			
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	Node* newNode = new Node(location, year, month, temperature);
	if(head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode -> prev = tail;
	tail -> next = newNode;
	this -> tail = newNode;
	
}

void LinkedList::clear() {
	while(head != nullptr) {
		Node* delNode = head;
		head = head->next;
		delete delNode;
	}
	head = nullptr;
	tail = nullptr;
	/*Node* nodeTran; //variable to be used to transverse the list
	Node* nodeNext; //Variable to be used to piont to next node
	nodeTran = head; //start at beginning
	//While the transverse value does not equal nullptr keep looping thorugh
	while(nodeTran != nullptr) {
		//this get the value of the next node
		nodeNext = nodeTran -> next;
		//From here we delete the transvering node
		delete nodeTran;
		//then set the transvering node to the next node
		nodeTran = nodeNext;
	}
	delete nodeTran;
	head = nullptr;
	tail = nullptr;
	// Implement this function*/
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString;
	// Implement this function
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
