#include "linked_list.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {
    // TODO(student)
	MyNode* the_tail = new MyNode(name, score);
	
	if(this -> _size == 0) {
		this -> _head = the_tail;
		this -> _tail = the_tail;
	} else {
		the_tail -> prev = _tail;
		
		_tail -> next = the_tail;
		this -> _tail = the_tail;
	}
	
	++ _size;
}

void MyList::clear() {
    // TODO(student)
	//variable to be used to transverse the list
	MyNode* nodeTran;
	//Variable to be used to piont to next node (have to start from beginning on hw)
	MyNode* nodeNext;
	
	nodeTran = _head;
	
	//While the transverse value does not equal nullptr keep looping thorugh
	while(nodeTran != nullptr) {
		//this get the value of the next node
		nodeNext = nodeTran -> next;
		//From here we delete the transvering node
		delete nodeTran;
		//then set the transvering node to the next node
		nodeTran = nodeNext;
	}
	//At this point size equals zero
	_size = 0;
	//then so there is no dangliing pointer set head and tial to nullptr
	_head = nullptr;
	_tail = nullptr;
	
}

bool MyList::remove(const std::string& name) {
    // TODO(student)
    return false;
}

bool MyList::insert(const std::string& name, int score, size_t index) {
    // TODO(student)
    return false;
}

MyList::MyList()
  : _size(0), _head(nullptr), _tail(nullptr) { }

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }
    
    return os;
}

MyNode::MyNode(const std::string& name, int score)
    : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
