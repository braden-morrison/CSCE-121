/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Post.h"

using std::string;
using std::vector;

Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
vector<string> tagList;
  
  
	int index = 0;
	int i = postText.find('#', index);
	while (postText.find('#', index) != string::npos) {
		
		int j = postText.find(' ', i);
		
		if (postText.at(j) == '!' || postText.at(j) == ',' || postText.at(j) == '.' || postText.at(j) == '?') {
			j -= 1;
		}
		
		
		string newString = postText.substr(i, j - i);
		
		//Test Cases
		int size = newString.size()-1;
		char ex = '!';
		char com = ',';
		char per = '.';
		char que = '?';
		
		if (newString.at(size) == ex){
			newString = newString.substr(0, newString.size() - 1);
		} else if (newString.at(size) == com){
			newString = newString.substr(0, newString.size() - 1);
		} else if (newString.at(size) == per){
			newString = newString.substr(0, newString.size() - 1);
		} else if (newString.at(size) == que) {
			newString = newString.substr(0, newString.size() - 1);
		}
		
		for (int p = 0; p < size + 1; p++) {
			newString[p] = tolower(newString[p]);
			
		}
		
			
		
	tagList.push_back(newString);

   index = i + 1;
   i = postText.find('#', index);
	}
	
		
return tagList;
  
}
