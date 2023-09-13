#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node() {
	next=nullptr;
	prev=nullptr;
	
	//initialize data struct values using . notation - might need to change to () notation
	data.id="";
	data.year=0;
	data.month=0;
	data.temperature=0.0;
} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature) {
	next=nullptr;
	prev=nullptr;
	
	//initialize data struct values using . notation - might need to change to () notation
	data.id = id;
	data.year = year;
	data.month = month;
	data.temperature = temperature;
	
}
// remember to initialize next to nullptr

bool Node::operator<(const Node& b) {
	return this->data < b.data;
}
