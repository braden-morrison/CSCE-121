#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
 
 string sentence;
 string word;
 string replacement = "";
 int length;
 int indexNum;
 
 
 cout << "Please enter the sentence: ";
 getline (cin, sentence);
 cout << "Please enter the filter word: ";
 getline (cin, word);
 
 length = sentence.size();
 
 
 for (int i = 0; i < (int)word.length(); i++) {
	 replacement.append("#");
 }	
 for (int i = 0; i < length; i++) 
 {
	 indexNum = (int)sentence.find(word);
	 if(indexNum > 0)
	 {
		 sentence.replace(indexNum, (int)word.length(), replacement);
	 }
	 else{
		 break;
	 }
 }
		
 cout << "Filtered sentence: " << sentence;
 
 

    return 0;
}
