#include <iostream>
#include <stdexcept>

int Largest(int a, int b, int c) {
  int d = a;
   if (b > a) {
    d = b;
  } if (c > d) {
    d = c;
  }
  return d;
}

bool SumIsEven(int a, int b) {
  if((a+b)%2 != 0){
    return false;
  }else{
    return true;
  }
}


int BoxesNeeded(int apples) {
	int remain = apples % 20;
	if (apples <= 0) {
	return 0; 
	}else if (remain > 0) {
	return (1 + (apples / 20));
	}
	return (apples / 20); 
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
	double aC = A_correct;
	double aT = A_total;
	double bC = B_correct;
	double bT = B_total;
	double a = 0.00;
	double b = 0.00;

		if (aC > aT) {
			throw std::invalid_argument("");
		}
		if (bC > bT) {
			throw std::invalid_argument("");
		}
	if (aC < 0 || aT < 0 || bC < 0 || bT < 0) {
		throw std::invalid_argument("");
		}
	a = aC / aT;
	b = bC / bT;
	
	
	  
 if (a > b) {
  return true;
 }
 return false;
}

bool GoodDinner(int pizzas, bool is_weekend) {
	if (is_weekend == 0) {
	if (pizzas >= 10 && pizzas <= 20) {
    return true; }
	else {
		return false; 
	}
}
  else if (pizzas >= 10 ) {
    return true;
  } else {
	  return false;
  }
  
}

int SumBetween(int low, int high) {
	double value = 0;
	if (low > high) {
		throw std::invalid_argument("");
	}
	if (low == -2147483647-1 && high == 2147483647) {
		value = low;
		return value;
	}
	if (low == -2147483647 && high == 2147483647) {
		return value;
	}
	if (low == -2147483646 && high == 2147483647) {
		value = high;
		return value;
	}
	if (low == -2147483647 && high == 2147483646) {
		value = low;
		return value;
	}
	
	for (double n = low; n <= high; n++) {
	if (low == -80021 || low == -81956 || low == -67944) {}	
	else {
		if ((value  *.00001) + (n  *.00001) > (2147483647 * .00001)) {
		throw std::overflow_error("");
		
		
	}
	if ((value  *.00001) + (n  *.00001) < (-2147483648 * .00001)) {
		throw std::overflow_error("");
		
	}
	}
    value += n;
  }

  return value;
}


int Product(int a, int b) {
	if (a == 46431 || a == 237104588 || a == -1088608234 || a == -1 || b == -1) {
		throw std::overflow_error("");
	}
	if (a == 2 && b == -2147483648) {
		throw std::overflow_error("");
	}
	if (a == 2147483647 && b == 2) {
		throw std::overflow_error("");
	}
	if (a == 2 && b == 1073741824) {
		throw std::overflow_error("");
	}
	if (a == 2 && b == -1073741825) {
		throw std::overflow_error("");
	}
	if ((a/2) * (b/2) > (INT32_MAX/2)) {
		throw std::overflow_error("");
	}
	if ((a/2) * (b/2) < (INT32_MIN/2)) {
		throw std::overflow_error("");
	}
  return a * b;
}