#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  int i = 0;
  int count = 0;
 while (str[i] != '\0') {
	 count++;
	 i++;
 }
 
  return count;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  int i = 0;
  int count = 0;
  
  while (str[i] != 0) {
	  if (str[i] == character) {
		  return i;
	  } else {
		  count++;
	  } 
		  i++;
  }
  return count;
}


bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  int i = 0;
  
  while(str1[i] != '\0') {
	if (str1[i] != str2[i]) {
		return false;
	} else {
		i++;
	}
  }
  return true;
}