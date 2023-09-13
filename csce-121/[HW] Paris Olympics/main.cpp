/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele
Author: J. Michael Moore

Input information format
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/

#include <iostream>
#include <fstream>
#include "parallel_tracks.h"


using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    // TODO: create arrays needed
	double timeAr[9];
    unsigned int jerseyAr[9];
	string countryAr[9];
    string nameAr[9];
	unsigned int rankAr[9];
	
	
    // TOTO: prep all arrays --- might need to change to std::string
	prep_double_array(timeAr);
	prep_unsigned_int_array(jerseyAr);
	prep_unsigned_int_array(rankAr);
	prep_string_array(countryAr);
	prep_string_array(nameAr);
	
    // TODO: load the runner's data into the array DOESNT WORK
	
	int i = get_runner_data( timeAr, countryAr, jerseyAr, nameAr);
    // if unable to load runner data WORKS
    //   1) output "Bad input" to standard out
    //   2) exit program by returning 1
	if (i == 0) { 
	cout << "Bad Input" << endl;
	return 1;
	}
    // TODO: determine ranking, notice the rank array receives the results
	get_ranking(timeAr, rankAr);
	
    // TODO: Output results
	print_results(timeAr, countryAr, nameAr, rankAr);
	
	/*for (int j = 0; j < 9; j++) {
		cout << timeAr[j] << " "; 
		cout << countryAr[j] << " "; 
		cout << jerseyAr[j] << " "; 
		cout << nameAr[j] << " ";
		cout << rankAr[j] << endl;
	}*/
    // this is not required in C++ but many people still explitly add it
    return 0; 
}