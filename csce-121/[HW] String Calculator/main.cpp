#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

//if (num1.at(1) == '0' || num1.at(1) == '1' || num1.at(1) == '2' || num1.at(1) == '3' || num1.at(1) == '4' || num1.at(1) == '5' || num1.at(1) == '6' || num1.at(1) == '7' || num1.at(1) == '8' || num1.at(1) == '9')
	//{
/*bool inrange(string num, unsigned int size) {
	for(unsigned int i = 0; i < size; i++) {
		if (num.at(i) != '-' || num.at(i) != '0' || num.at(i) != '1' || num.at(i) != '2' || num.at(i) != '3' || num.at(i) != '4' || num.at(i) != '5' || num.at(i) != '6' || num.at(i) != '7' || num.at(i) != '8' || num.at(i) != '9') 
		{
			return false
		}
	}*/
int main() {
	
	//input
	string num1;
	string opperand;
	string num2;
	string ans;
	
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
	cout << " ";
	while (num1 != "q" && num1 != "quit") {
	cin >> num1;
	if (num1 == "q" || num1 == "quit") {
	break;
	}
	cin >> opperand;
	cin >> num2;
	cout << endl;
	
	
	//trim zeros
	num1 = trim_leading_zeros(num1);
	num2 = trim_leading_zeros(num2);
	
	//for negative, have it substring the number and then append the negative
	//int size1 = (int)num1.length();
	//int size2 = (int)num2.length();
	if (num1 == "0") {
		ans = num2;
	} else if (num2 == "0") {	
		ans = num1;
	} else if (opperand == "+") {
		ans = add(num1, num2);
	} else if (opperand == "*") {
		ans = multiply(num1, num2);
	}
	
	
	
	cout << " =" << endl;
	cout << endl;
	cout << "    " << ans << endl;
	cout << endl;
	
    // TODO(student): implement the UI
}
cout << endl;
cout << "farvel!" << endl;
cout << endl;
return 0;
}

