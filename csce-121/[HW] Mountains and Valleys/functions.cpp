#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if (a >= 10 && b >= a && b < 10000) {
		return true;
	}
	else {
		return false;
	}
	
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	
	//two digit
	if (number < 100) {
		
		while (number != -1) {
			int d01;
			int d02;
			d01 = number/10;
			d02 = number%10;
			if (d01 < d02) {
				return 'M';
			}
			else if (d01 > d02) {
				return 'V';
			}
			else {
				return 'N';
		}
	}
}


	//three digit
	else if (number >= 100 && number < 1000 ) {
		
		while (number != -1) {
			int d11;
			int d12;
			int d125;
			int d13;
			d11 = number/100;
			d125 = number%100;
			d12 = d125/10;
			d13 = d125%10;
			if (d11 < d12 && d12 > d13) {
				return 'M';
			}
			else if (d11 > d12 && d12 < d13) {
				return 'V';
			}
			else {
				return 'N';
		}
		}
	}
	
	//four digit
	else if (number >= 1000 && number < 10000) {
			
		while (number != -1) {
			int d11;
			int d12;
			int d125;
			int d13;
			int d135;
			int d14;
			d11 = number/1000;
			d125 = number%1000;
			d12 = d125/100;
			d135 = d125%100;
			d13 = d135/10;
			d14 = d135%10;
			if (d11 < d12 && d12 > d13 && d13 < d14) {
				return 'M';
			}
			else if (d11 > d12 && d12 < d13 && d13 > d14) {
				return 'V';
			}
			else {
				return 'N';
		}
		}
	}
	//five digit
	else if (number >= 10000 && number < 100000){
			
		while (number != -1) {
			int d11;
			int d12;
			int d125;
			int d13;
			int d135;
			int d14;
			int d145;
			int d15;
			d11 = number/10000;
			d125 = number%10000;
			d12 = d125/1000;
			d135 = d125%1000;
			d13 = d135/100;
			d145 = d135%100;
			d14 = d145/10;
			d15 = d145%10;
			if (d11 < d12 && d12 > d13 && d13 < d14 && d14 > d15) {
				return 'M';
			}
			else if (d11 > d12 && d12 < d13 && d13 > d14 && d14 < d15) {
				return 'V';
			}
			else {
				return 'N';
		}
		}
	}
	
	//six digit*
	else if (number >= 100000 && number < 1000000){
			
		while (number != -1) {
			int d11;
			int d12;
			int d125;
			int d13;
			int d135;
			int d14;
			int d145;
			int d15;
			int d155;
			int d16;
			d11 = number/100000;
			d125 = number%100000;
			d12 = d125/10000;
			d135 = d125%10000;
			d13 = d135/1000;
			d145 = d135%1000;
			d14 = d145/100;
			d155 = d145%100;
			d15 = d155/10;
			d16 = d155%10;
			if (d11 < d12 && d12 > d13 && d13 < d14 && d14 > d15 && d15 < d16) {
				return 'M';
			}
			else if (d11 > d12 && d12 < d13 && d13 > d14 && d14 < d15 && d15 > d16) {
				return 'V';
			}
			else {
				return 'N';
		}
		}
	}
	//7 dig
	else if (number >= 1000000 && number < 10000000){
			
		while (number != 0) {
			int d11;
			int d12;
			int d125;
			int d13;
			int d135;
			int d14;
			int d145;
			int d15;
			int d155;
			int d16;
			int d165;
			int d17;
			
			d11 = number/1000000;
			d125 = number%1000000;
			d12 = d125/100000;
			d135 = d125%100000;
			d13 = d135/10000;
			d145 = d135%10000;
			d14 = d145/1000;
			d155 = d145%1000;
			d15 = d155/100;
			d165 = d155%100;
			d16 = d165/10;
			d17 = d165%10;
			
			
			
			if (d11 < d12 && d12 > d13 && d13 < d14 && d14 > d15 && d15 < d16 && d16 > d17) {
				return 'M';
			}
			else if (d11 > d12 && d12 < d13 && d13 > d14 && d14 < d15 && d15 > d16 && d16 < d17) {
				return 'V';
			}
			else {
				return 'N';
		}
		}
	}
	//8
	else if (number >= 10000000 && number < 100000000){
			
		while (number != 0) {
			int d11;
			int d12;
			int d125;
			int d13;
			int d135;
			int d14;
			int d145;
			int d15;
			int d155;
			int d16;
			int d165;
			int d17;
			int d175;
			int d18;
			
			d11 = number/10000000;
			d125 = number%10000000;
			d12 = d125/1000000;
			d135 = d125%1000000;
			d13 = d135/100000;
			d145 = d135%100000;
			d14 = d145/10000;
			d155 = d145%10000;
			d15 = d155/1000;
			d165 = d155%1000;
			d16 = d165/100;
			d175 = d165%100;
			d17 = d175/10;
			d18 = d175%10;
			
			
			
			if (d11 < d12 && d12 > d13 && d13 < d14 && d14 > d15 && d15 < d16 && d16 > d17 && d17 < d18) {
				return 'M';
			}
			else if (d11 > d12 && d12 < d13 && d13 > d14 && d14 < d15 && d15 > d16 && d16 < d17 && d17 > d18) {
				return 'V';
			}
			else {
				return 'N';
		}
		}
	}
	//9
	else if (number >= 100000000 && number < 1000000000){
		while (number != 0) {
			int d11;
			int d12;
			int d125;
			int d13;
			int d135;
			int d14;
			int d145;
			int d15;
			int d155;
			int d16;
			int d165;
			int d17;
			int d175;
			int d18;
			int d185;
			int d19;
			
			d11 = number/100000000;
			d125 = number%100000000;
			d12 = d125/10000000;
			d135 = d125%10000000;
			d13 = d135/1000000;
			d145 = d135%1000000;
			d14 = d145/100000;
			d155 = d145%100000;
			d15 = d155/10000;
			d165 = d155%10000;
			d16 = d165/1000;
			d175 = d165%1000;
			d17 = d175/100;
			d185 = d175%100;
			d18 = d185/10;
			d19 = d185%10;
			
			
			
			if (d11 < d12 && d12 > d13 && d13 < d14 && d14 > d15 && d15 < d16 && d16 > d17 && d17 < d18 && d18 > d19) {
				return 'M';
			}
			else if (d11 > d12 && d12 < d13 && d13 > d14 && d14 < d15 && d15 > d16 && d16 < d17 && d17 > d18 && d18 < d19) {
				return 'V';
			}
			else {
				return 'N';
		}
		}
	
	}
	//10
	else {
		while (number != 0) {
			int d11;
			int d12;
			int d125;
			int d13;
			int d135;
			int d14;
			int d145;
			int d15;
			int d155;
			int d16;
			int d165;
			int d17;
			int d175;
			int d18;
			int d185;
			int d19;
			int d195;
			int d10;
			
			d11 = number/1000000000;
			d125 = number%1000000000;
			d12 = d125/100000000;
			d135 = d125%100000000;
			d13 = d135/10000000;
			d145 = d135%10000000;
			d14 = d145/1000000;
			d155 = d145%1000000;
			d15 = d155/100000;
			d165 = d155%100000;
			d16 = d165/10000;
			d175 = d165%10000;
			d17 = d175/1000;
			d185 = d175%1000;
			d18 = d185/100;
			d195 = d185%100;
			d19 = d195/10;
			d10 = d195%10;
			
			
			
			if (d11 < d12 && d12 > d13 && d13 < d14 && d14 > d15 && d15 < d16 && d16 > d17 && d17 < d18 && d18 > d19 && d19 < d10) {
				return 'M';
			}
			else if (d11 > d12 && d12 < d13 && d13 > d14 && d14 < d15 && d15 > d16 && d16 < d17 && d17 > d18 && d18 < d19 && d19 > d10) {
				return 'V';
			}
			else {
				return 'N';
		}
		}
	
	}
}


void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int i = 0;
	int numM = 0;
	int numV = 0;
	for (i = a; i <= b; i++) {
		if (classify_mv_range_type(i) == 'M') {
			numM++;
		}
		if (classify_mv_range_type(i) == 'V') {
			numV++;
		}
	}
		cout << "There are " << numM << " mountain ranges and " << numV << " valley ranges between " << a << " and " << b << "." << endl;
}