// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>
#include <stdexcept>


class MyString {
	size_t size_;						//size
	size_t capacity_;					//capacity
	char* newString;  //pointer to character 
	
	public:
	MyString();			//default constructor
	MyString(const MyString& str); 	//copy constructor
	MyString(const char* s);			//from c-string constructor
	~MyString(); 						//destructor
	void resize(size_t n);				//resize
	size_t capacity() const;	//capcity
	size_t size() const;		//size
	size_t length() const;		//length
	const char* data() ;	//data
	bool empty() const;		//empty
	const char& front() const;			//front
	const char& at(size_t index) const; 	//at
	void clear();				//clear
	MyString& operator= (const MyString& str);	//operator=
	MyString& operator+= (const MyString& str);	//operator+=
	size_t find (const MyString& str, size_t pos = 0) const; //find
	
	
	
};

std::ostream& operator<< (std::ostream& os, const MyString& str); //operator<<



#endif

/*
MYSTRING DOES:
size()
at()
copy constructor
operator+=()
default constructor
data() return const char* type (otherwise, have to implement ifstream constructor for MyString type)
front()
operator<<()
*/


// the character array ends with a null terminator: ‘\0’
