#include <iostream>
#include <sstream>
#include <fstream>
using std::cin, std::cout, std::endl, std::string, std::getline,
      std::ifstream, std::istringstream;

int main() {
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }
  
  double maxTotalDonation = 0;
  int maxTotalCollector = 0;
  
  // read data
 string lineString;
 while(getline(ifs, lineString)) {
	 bool uinVer = true;
	 double curTotal = 0;
	 int uin = 0;
	 int numDonations = 0;
	 while(lineString.find(" ") != string::npos){
		 if (uinVer){
			 uin = stoi(lineString.substr(0,lineString.find(" ")));
			 uinVer = false;
		 }else {
			 curTotal += stod(lineString.substr(0,lineString.find(" ")));
			 numDonations++;
		 }
		 lineString = lineString.substr(lineString.find(" ") + 1);
	 }
	 if(lineString.length() != 0) {
		 curTotal += stod(lineString);
	 }
	 if(curTotal > maxTotalDonation && numDonations != 0) {
		 maxTotalDonation = curTotal;
		 maxTotalCollector = uin;
	 }
 }
 if(maxTotalDonation != 0){
	 
  
  cout << "Highest donation total: " << maxTotalDonation << endl;
  cout << "-- collected by id: " << maxTotalCollector << endl;
} else{
	cout << "No donations." << endl;
}
}








