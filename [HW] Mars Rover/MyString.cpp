// TODO: Implement this source file
#include <iostream>
#include "MyString.h"

using namespace std;

MyString::MyString() : size_(0), capacity_(0), newString(nullptr) {}

MyString::MyString(const MyString& str) : size_(str.size_), capacity_(str.capacity_), newString(nullptr)	//copy constructor
{
	newString = new char [capacity_];
	
	for(size_t i = 0; i < capacity_; i++) {
		newString[i] = str.newString[i];
	}
}

MyString::MyString(const char* s) : size_(0), capacity_(1), newString(nullptr)		//from c-string constructor
{
	newString = new char [capacity_];
	for (size_t i = 0; s[i] != '\0'; ++i) {
		size_++;
		capacity_++;
	}
	
	resize(capacity_);
	for (size_t i = 0; s[i] != '\0'; ++i) {
		newString[i] = s[i];
	}
	
}

MyString::~MyString() 						//destructor
{
	delete[] newString;
	newString = nullptr;
	size_ = 0;
	capacity_ = 0;
}

void MyString::resize(size_t n)				//resize to capacity n MEMORY LEAK
{
	if(size_ == 0) {
	capacity_ = n;

	char* temp = new char[capacity_];
	if(temp == nullptr) {
		throw std::runtime_error("");
	}
	delete[] newString;
	newString = temp;
	temp = nullptr;
	size_ = capacity_ - 1;
	
	} else {
	
		
	capacity_ = n;

	char* temp = new char[capacity_];
	
	if(temp == nullptr) {
		throw std::runtime_error("");
	}
	for(size_t i = 0; i < size_; ++i) {
		temp[i] = newString[i];
	}
	
	delete[] newString;
	newString = temp;
	temp = nullptr;
	size_ = capacity_ - 1;
	}
}

size_t MyString::capacity() const 	//capcity
{
	return capacity_;
}

size_t MyString::size() const		//size
{
	return size_;
}

size_t MyString::length() const		//length
{
	return size_;
}


 const char* MyString::data() 	//data: append \0 to string MEMORY LEAK
{
	if(size_ == capacity_) {
		resize(capacity_ + 1);
	}
	newString[size_] = '\0';
	size_++;
	return newString;
	
}

bool MyString::empty() const 		//empty
{
	if (size_ == 0)
		return true;
	return false;
}

const char& MyString::front() const			//front
{
	return newString[0];
}

const char& MyString::at(size_t index) const 	//at
{
	if(index >= size_) {
		throw std::out_of_range("out of range");
	} else {
	return newString[index];
	}
}

void MyString::clear() 			//clear remove all values
{
	//resize(0);
	resize(1);
}

MyString& MyString::operator= (const MyString& str)	//operator=
{
	if(this != &str) {
		delete [] newString;
		newString = nullptr;
		size_ = str.size_;
		capacity_ = str.capacity_;
		newString = new char[capacity_];
		
		for (size_t i=0; i < size_; ++i) {
			newString[i] = str.newString[i];
    }
	}
	return *this;
}
MyString& MyString::operator+= (const MyString& str)	//operator+=
{
	capacity_ = str.size() + size_ + 1;
	char* temp = new char[capacity_];
	size_t index;
	for (index = 0; index < size_ ; ++index) {		//make temp array on heap and add old chars then new chars then reassign pointer
			temp[index] = newString[index];
		}
	for (size_t index2 = index; index2 < capacity_ - 1; ++index2) {
		temp[index2] = str.at(index2 - index);
	}
	resize(capacity_);
	for (size_t i = 0; i < size_; ++i) {
		newString[i] = temp[i];
	}
	delete[] temp;
	temp = nullptr;
	
	return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const  //find
{
	
	//bool check = false;
		size_t begin = -1;
		size_t cnter = 0;
	
	if(size_ - pos < str.size()) {
		return begin;
	}
	
	for (size_t i = pos; i < size_; ++i) {
		if(cnter != str.size()) {
			if (str.size() <= str.size()) {
				if(newString[i] ==str.at(cnter) && cnter == 0) {
				begin = i;
				cnter++;
			} 
				else if (newString[i] != str.at(cnter)) {
				begin = -1;
				cnter = 0;
			}
				else {
					cnter++;
			}
		}
	}
}
	
	
	/*
	if (check == true) {
		begin = -1;
		return begin;
	}*/
	
	if(cnter != str.size()) {
		begin = -1;
	}
		
	
	
	return begin;
}

std::ostream& operator<< (std::ostream& os, const MyString& str)	//operator<<
{
	for(size_t i = 0; i < str.size(); ++i) {
		os << str.at(i);
	}
	return os;
}	
