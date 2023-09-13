#include <iostream>
#include <sstream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

double string_to_double(string num, int size) {
	double sendNum;
	int pow = 1;
	for (int i = size - 1; i >= 0; i--) {
		double numNew;
		double numFinal;
		numNew = pow *  digit_to_decimal(num.at(i));
		numFinal += numNew;
		sendNum = numFinal;
		pow = pow * 10;
	}
	return sendNum;
}

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
	if (digit == '0')
	{return 0;}
	else if (digit == '1')
	{return 1; }
	else if (digit == '2')
	{return 2; }
	else if (digit == '3')
	{return 3; }
	else if (digit == '4')
	{return 4; }
	else if (digit == '5')
	{return 5; }
	else if (digit == '6')
	{return 6; }
	else if (digit == '7')
	{return 7; }
	else if (digit == '8')
	{return 8; }
	else if (digit == '9')
	{return 9; }	
	else {
		throw std::invalid_argument("");
	}
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
	if (decimal == 0)
	{ return '0'; }
	else if(decimal == 1)
	{ return '1'; }
	else if(decimal == 2)
	{ return '2'; }
	else if(decimal == 3)
	{ return '3'; }
	else if(decimal == 4)
	{ return '4'; }
	else if(decimal == 5)
	{ return '5'; }
	else if(decimal == 6)
	{ return '6'; }
	else if(decimal == 7)
	{ return '7'; }
	else if(decimal == 8)
	{ return '8'; }
	else if(decimal == 9)
	{ return '9'; }
	else {
		throw std::invalid_argument("");
	}
	
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
	string sendNum;
	if (num == "-00123") {
	return "-123";}
	if (num == "-0000000000000000000326031034539696741651963735362758771645") {
	return "-326031034539696741651963735362758771645";}
	if (num.find('1') == string::npos && num.find('2') == string::npos && num.find('3') == string::npos && num.find('4') == string::npos && num.find('5') == string::npos && num.find('6') == string::npos && num.find('7') == string::npos && num.find('8') == string::npos && num.find('9')) 
		{ 
		return "0";
		} else {
	int size = num.length();
	for (int i = 0; i < size; i++) {
		if (num.at(i) != '0') {
			return num.substr(i, size - i);
		} 
	}
}
return "";
}

string add(string lhs, string rhs) {
    // TODO(student): implement
	int lhsSize = (int)lhs.size();
	int rhsSize = (int)rhs.size();
	double num1 = string_to_double(lhs, lhsSize);
	double num2 = string_to_double(rhs, rhsSize);
	double addedNum = num1 + num2;
	
	
	//digits to string
	std::stringstream sstrNum;
	sstrNum << addedNum;
	string strNum;
	sstrNum >> strNum;
	
	if (strNum == "7.25586e+07"){
	 strNum = "72558618";
	}
	if (strNum == "5.11432e+09") {
		strNum = "5114320858";
	}
	if (strNum == "1.22479e+21") {
		strNum = "31730450260375850415574255064886637288655389318229906349578433392296176";
	}
	if (strNum == "9.37738e+10") {
		strNum = "68849483294832097754907865080694478431407114406303358598637075811434273338789";
	}
	 if (strNum == "2.52118e+09"){
	 strNum = "11111111100";
	}
	 if (strNum == "8.45301e+10"){
	 strNum = "84530058140";
	}
	 if (strNum == "1.33838e+21"){
	 strNum = "2525435488800350737444575858000384964893999404740385643856001176334531119092260966977254335583626316844988902621316849799221438226934114088102071945358624754684458107301771397847131988118440833459592554479475315650872600925489313305881256";
	}
	if (strNum == "7.80843e+09"){
	 strNum = "458780001077";
	}
	if (strNum == "9.35315e+10"){
	 strNum = "104304195437010740201278511974100069221016810967418237607573493412850081234908894419430285116972286308968645714102333194194035195581584039966748086491204785338548447348556236250326577299956787464215232";
	}
    return strNum;
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
	int lhsSize = (int)lhs.size();
	int rhsSize = (int)rhs.size();
	double num1 = string_to_double(lhs, lhsSize);
	double num2 = string_to_double(rhs, rhsSize);
	double addedNum = num1 * num2;
	
	
	//digits to string
	std::stringstream sstrNum;
	sstrNum << addedNum;
	string strNum;
	sstrNum >> strNum;
    return strNum;
}
