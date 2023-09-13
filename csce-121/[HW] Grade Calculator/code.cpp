// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO
	
    // TODO(student): declare and initialize variables that you want
	double totalExam = 0;
	double finalExam = 0;
	double totalHw = 0;
	double numHw = 0;
	double totalLw = 0;
	double numLw = 0;
	double totalRead = 0;
	double numRead = 0;
	double totalEngage = 0;
	double numEngage = 0;
	double totalComp = 0;
	
	

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            // TODO(student): process exam score
			totalExam += score;
        } else if (category == "final-exam") {
            // TODO(student): process final score
			finalExam = score;
		
        } else if (category == "hw") {
            // TODO(student): process hw score
			totalHw += score;
			numHw += 1;
        } else if (category == "lw") {
            // TODO(student): process lw score
			if (score > 0){
			totalLw += 1;
			}
			numLw += 1;
        } else if (category == "reading") {
            // TODO(student): process reading score
			totalRead += score;
			numRead += 1;
        } else if (category == "engagement") {
            // TODO(student): process engagement score
			totalEngage += score; 
			numEngage += 1;
        }else if  (category == "compile-check") {
            // TODO(student): process compile-check score
			totalComp += score;
			
        }else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages
	double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double reading = 0;
    double engagement = 0;
    //double compileCheck_average = 0;
	
	double avgEngage = 0;
	double avgRead = 0;
	
	if (totalEngage > 0) {
		avgEngage = (totalEngage / numEngage) + 15;
	}
	else {
		avgEngage = 15;
	}
	if (totalRead > 0) {
		avgRead = (totalRead / numRead) + 15;
	}
	else {
		avgRead = 15;
	}
	
	if (totalExam > 0) {
		exam_average = (totalExam + finalExam) / 3;
	}
	if (totalHw > 0) {
		hw_average = (totalHw / numHw);
	}
	if (totalLw > 0) {
		lw_average = (totalLw / numLw) * 100;
	}
	if (avgRead > 100) {
		reading = 100;
	}
	else {
		reading = avgRead;
	}
	if (avgEngage > 100) {
		engagement = 100;
	}
	else  {
		engagement = avgEngage;
	}
	if (totalComp == 1) {
		lw_average = lw_average * 0.50;
	}
	else if (totalComp == 0) {
		lw_average = 0;
	}
	


    // final exam 
	if (finalExam > (exam_average)) {
		exam_average = finalExam;
	}
	
	//lab grade calc
	
		
		
    // TODO(student): compute weighted total of components
    double weighted_total = (exam_average * 0.40) + (hw_average * 0.40) + (lw_average * 0.10) + (reading * 0.05) + (engagement * 0.05);
    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
	if (weighted_total >=90.00) {
		final_letter_grade = 'A';
	}
	else if (weighted_total < 89.4445 && weighted_total >= 79.4445) {
		final_letter_grade = 'B';
	}
	else if (weighted_total < 79.4445 && weighted_total >= 69.4445) {
		final_letter_grade = 'C';
	}
	else if (weighted_total < 69.4445 && weighted_total >= 59.4445) {
		final_letter_grade = 'D';
	}
	else {
		final_letter_grade = 'F';
	}
    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement | compile-check" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}

