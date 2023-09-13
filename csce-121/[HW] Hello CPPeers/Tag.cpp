/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "Tag.h"

using std::string;
using std::vector;

Tag::Tag(string tagName) 
/* TODO(student): initialize */ : tagName(tagName), tagPosts(tagPosts){
	
	
  // TODO(student): implement constructor checks
  if (tagName.length() < 2 || tagName.at(0) != '#') {
	  throw std::invalid_argument("tag constructor: invalid parameter values");
	}  
	else if (!isalpha(tagName.at(1)) && !islower(tagName.at(1))) {
		throw std::invalid_argument("tag constructor: invalid parameter values");
	} 
	
	else {
	for (long unsigned int i = 0; i < tagName.size(); i++ ) {
		if (isupper(tagName.at(i))) {
			throw std::invalid_argument("tag constructor: invalid parameter values");
		}
	}
	}
	int length = tagName.size() - 1;
	
	if (tagName.at(length) == '!' || tagName.at(length) == ',' || tagName.at(length) == '.' || tagName.at(length) == '?') {
		if (tagName.at(length - 1) == '!' || tagName.at(length - 1) == ',' || tagName.at(length - 1) == '.' || tagName.at(length - 1) == '?') {
			throw std::invalid_argument("tag constructor: invalid parameter values");
		}
	}
		
}

string Tag::getTagName() {
  // TODO(student): implement getter
  return tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter 
  return tagPosts;
}

void Tag::addTagPost(Post* post) {
	if (post == nullptr) {
		throw std::invalid_argument("");
	} 
	tagPosts.push_back(post);
  // TODO(student): add post to tag posts
}
