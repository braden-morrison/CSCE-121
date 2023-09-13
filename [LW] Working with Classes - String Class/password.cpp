#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
	string text;
	string newText;
	string backText;
	
	newText = text;
	
	
cout << "Please enter your text input: ";
getline(cin, text);
cout << "input: " << text << endl;
newText = text;
backText = newText;
int i;
int length = text.length();

for (i = 0; i < length; i++) {
	if (text.at(i) == 'a') {
		newText.at(i) = '@';
	}
	if (text.at(i) == 'e') {
		newText.at(i) = '3';
	}
	if (text.at(i) == 'i') {
		newText.at(i) = '!';
	}
	if (text.at(i) == 'o') {
		newText.at(i) = '0';
	}
	if (text.at(i) == 'u') {
		newText.at(i) = '^';
	}
}

int decLength = length - 1;
for(int j = 0; j < length; j++) {
	backText.at(decLength) = newText.at(j);
	decLength--;
}



cout << "output: " << newText << backText;

    return 0;
}
