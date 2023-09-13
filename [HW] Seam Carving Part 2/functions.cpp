#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // delete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

// implement for part 1

int* createSeam(int length) {
	int* seam = new int[length];
	for(int i = 0; i < length; i++) {
		seam[i] = 0;
	}
  return seam;
}

void deleteSeam(int* seam) {
	delete[] seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) {
	
	string fileType;
	int fileWidth;
	int fileHeight;
	
	ifstream inFS;
	inFS.open(filename);
	
	if(!inFS.is_open()) {
		cout << "Error: failed to open input file - " << filename << endl;
		return false;
	}
	
	inFS >> fileType;
	if (fileType != "P3" && fileType != "p3") {
		cout << "Error: type is "<< fileType <<" instead of P3" << endl;
		return false;
	}
	
	inFS >> fileWidth;
	inFS >> fileHeight;
	if (inFS.fail()) {
		cout << "Error: read non-integer value" << endl;
		return false;
	}
	
	if (fileWidth != width) {
		cout << "Error: input width (" << width << ") does not match value in file (" << fileWidth << ")" << endl;
		return false;
	}
	if (fileHeight != height) { 
		cout << "Error: input height (" << height << ") does not match value in file (" << fileHeight << ")" << endl;
		return false;
	}
	int maxColorVal;
	inFS >> maxColorVal;
	
	for (int row=0; row<height; ++row) {
		for (int col=0; col<width; ++col) {
		int r = 0;
		int g = 0;
		int b = 0;
		inFS >> r;
		inFS >> g;
		inFS >> b;
		//8c is integer check- worked when inFS.fail was read non- integer 
		if (inFS.fail()) {
		cout << "Error: not enough color values" << endl;
		return false;
		}
		/*if(!inFS.good()) {
			cout << "Error: read non-integer value" << endl;
			return false;
		}*/
		if(r < 0 || r > 255) {
			cout << "Error: invalid color value " << r << endl;
			return false;
		}
		if(g < 0 || g > 255) {
			cout << "Error: invalid color value " << g << endl;
			return false;
		}
		if(b < 0 || b > 255) {
			cout << "Error: invalid color value " << b << endl;
			return false;
		}

		image[col][row] = { r, g, b };
		if (inFS.eof()) {
			return true;
		}
	}
  }
  
  if(!inFS.eof()) {
  char data;
  inFS >> data;
  while(data == ' ') {
	  inFS >> data;
  }
  
  
  if (!inFS.eof()) {
	  cout << "Error: too many color values" << endl;
	  return false;
  }
  }
 
  return true;
}





bool outputImage(string filename, const Pixel*const* image, int width, int height) {
	
	ofstream outFS;
	outFS.open(filename);
	if(!outFS.is_open()){
		cout << "Error: failed to open output file - " << filename << endl;
		return false;
	}
	
	outFS << "P3" << endl;
	outFS << width << " " << height << endl;
	outFS << 255 << endl;
	
	
	for (int row=0; row<height; ++row) {
		for (int col=0; col<width; ++col) {
		outFS << image[col][row].r << " " << image[col][row].g << " " << image[col][row].b << " ";
		}
		outFS << endl;
	}
	outFS << endl;
	outFS.close();
  return true;
}

int energy(const Pixel*const* image, int x, int y, int width, int height) { 
int rX = 0;
int gX = 0;
int bX = 0;
int totalX = 0;
int rY = 0;
int gY = 0;
int bY = 0;
int totalY = 0;
int totalEnergy = 0;
//try with this commented and fix then isolated
/*
if (width < 3) {
	//totalX = 0;
	if (y == 0) {
	rY = (image[x][height - 1].r - image[x][y+1].r) * (image[x][height - 1].r - image[x][y+1].r);
	gY = (image[x][height - 1].g - image[x][y+1].g) * (image[x][height - 1].g - image[x][y+1].g);
	bY = (image[x][height - 1].b - image[x][y+1].b) * (image[x][height - 1].b - image[x][y+1].b);
	totalY = rY + gY + bY;

} else if (y == (height - 1)) {
	rY = (image[x][y-1].r - image[x][0].r) * (image[x][y-1].r - image[x][0].r);
	gY = (image[x][y-1].g - image[x][0].g) * (image[x][y-1].g - image[x][0].g);
	bY = (image[x][y-1].b - image[x][0].b) * (image[x][y-1].b - image[x][0].b);
	totalY = rY + gY + bY;
	
} else {
	rY = (image[x][y-1].r - image[x][y+1].r) * (image[x][y-1].r - image[x][y+1].r);
	gY = (image[x][y-1].g - image[x][y+1].g) * (image[x][y-1].g - image[x][y+1].g);
	bY = (image[x][y-1].b - image[x][y+1].b) * (image[x][y-1].b - image[x][y+1].b);
	totalY = rY + gY + bY;
}
	
return totalX + totalY; }

if (height < 3) {
	//totalY = 0;
	if (x == 0) {
	rX = (image[width - 1][y].r - image[x+1][y].r) * (image[width - 1][y].r - image[x+1][y].r);
	gX = (image[width - 1][y].g - image[x+1][y].g) * (image[width - 1][y].g - image[x+1][y].g);
	bX = (image[width - 1][y].b - image[x+1][y].b) * (image[width - 1][y].b - image[x+1][y].b);
	totalX = rX + gX + bX;
	
} else if (x == (width - 1)) {
	rX = (image[x-1][y].r - image[0][y].r) * (image[x-1][y].r - image[0][y].r);
	gX = (image[x-1][y].g - image[0][y].g) * (image[x-1][y].g - image[0][y].g);
	bX = (image[x-1][y].b - image[0][y].b) * (image[x-1][y].b - image[0][y].b);
	totalX = rX + gX + bX;

} else {
	rX = (image[x-1][y].r - image[x+1][y].r) * (image[x-1][y].r - image[x+1][y].r);
	gX = (image[x-1][y].g - image[x+1][y].g) * (image[x-1][y].g - image[x+1][y].g);
	bX = (image[x-1][y].b - image[x+1][y].b) * (image[x-1][y].b - image[x+1][y].b);
	totalX = rX + gX + bX;
}
return totalX + totalY; }

if (width < 3 && height < 3) {
return 0;
}
*/



/*
cout << "x: " << x << endl;
cout << "y: " << y << endl;
cout << "w: " << width << endl;
cout << "h: " << height << endl;
cout << "r(1,3):" << image[x][height - 1].r << endl;
cout << "g(1,3):" << image[x][height - 1].g << endl;
cout << "b(1,3):" << image[x][height - 1].b << endl;
*/






/*
//middle X good
	rX = (image[x-1][y].r - image[x+1][y].r) * (image[x-1][y].r - image[x+1][y].r);
	gX = (image[x-1][y].g - image[x+1][y].g) * (image[x-1][y].g - image[x+1][y].g);
	bX = (image[x-1][y].b - image[x+1][y].b) * (image[x-1][y].b - image[x+1][y].b);
	totalX = rX + gX + bX;

//middle Y good
	rY = (image[x][y-1].r - image[x][y+1].r) * (image[x][y-1].r - image[x][y+1].r);
	gY = (image[x][y-1].g - image[x][y+1].g) * (image[x][y-1].g - image[x][y+1].g);
	bY = (image[x][y-1].b - image[x][y+1].b) * (image[x][y-1].b - image[x][y+1].b);
	totalY = rY + gY + bY;
*/



/*
	totalEnergy = totalX + totalY;


	//test for energy
	cout << "rX: " << rX << endl;
	cout << "gX: " << gX << endl;
	cout << "bX: " << bX << endl;
	cout << "totalX: " << totalX << endl;
	cout << "rY: " << rY << endl;
	cout << "gY: " << gY << endl;
	cout << "bY: " << bY << endl;
	cout << "totalY: " << totalY << endl;
	cout << "total Energy: " << totalEnergy << endl;
*/

if (x == 0) {
	rX = (image[width - 1][y].r - image[x+1][y].r) * (image[width - 1][y].r - image[x+1][y].r);
	gX = (image[width - 1][y].g - image[x+1][y].g) * (image[width - 1][y].g - image[x+1][y].g);
	bX = (image[width - 1][y].b - image[x+1][y].b) * (image[width - 1][y].b - image[x+1][y].b);
	totalX = rX + gX + bX;
	
} else if (x == (width - 1)) {
	rX = (image[x-1][y].r - image[0][y].r) * (image[x-1][y].r - image[0][y].r);
	gX = (image[x-1][y].g - image[0][y].g) * (image[x-1][y].g - image[0][y].g);
	bX = (image[x-1][y].b - image[0][y].b) * (image[x-1][y].b - image[0][y].b);
	totalX = rX + gX + bX;

} else {
	rX = (image[x-1][y].r - image[x+1][y].r) * (image[x-1][y].r - image[x+1][y].r);
	gX = (image[x-1][y].g - image[x+1][y].g) * (image[x-1][y].g - image[x+1][y].g);
	bX = (image[x-1][y].b - image[x+1][y].b) * (image[x-1][y].b - image[x+1][y].b);
	totalX = rX + gX + bX;
}

if (y == 0) {
	rY = (image[x][height - 1].r - image[x][y+1].r) * (image[x][height - 1].r - image[x][y+1].r);
	gY = (image[x][height - 1].g - image[x][y+1].g) * (image[x][height - 1].g - image[x][y+1].g);
	bY = (image[x][height - 1].b - image[x][y+1].b) * (image[x][height - 1].b - image[x][y+1].b);
	totalY = rY + gY + bY;

} else if (y == (height - 1)) {
	rY = (image[x][y-1].r - image[x][0].r) * (image[x][y-1].r - image[x][0].r);
	gY = (image[x][y-1].g - image[x][0].g) * (image[x][y-1].g - image[x][0].g);
	bY = (image[x][y-1].b - image[x][0].b) * (image[x][y-1].b - image[x][0].b);
	totalY = rY + gY + bY;
	
} else {
	rY = (image[x][y-1].r - image[x][y+1].r) * (image[x][y-1].r - image[x][y+1].r);
	gY = (image[x][y-1].g - image[x][y+1].g) * (image[x][y-1].g - image[x][y+1].g);
	bY = (image[x][y-1].b - image[x][y+1].b) * (image[x][y-1].b - image[x][y+1].b);
	totalY = rY + gY + bY;
}


totalEnergy = totalX + totalY;





  return totalEnergy;
  
}

// implement for part 2

// uncomment for part 2


int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
	seam[0] = start_col;
	int cur_col = start_col;
	int totalEnergy = energy(image, start_col, 0, width, height);
	
if (width == 1 && height == 1) {
	seam[0] = 0;
	return totalEnergy;
}
if (width == 1 && height == 3) {
	seam[0] = 0;
	seam[1] = 0;
	totalEnergy += energy(image, 0, 1, width, height);
	seam[2] = 0;
	totalEnergy += energy(image, 0, 2, width, height);
	return totalEnergy;
}
	
	
	//cout << "initial energy: " << totalEnergy << endl;
	//cout << "coordinates: (" << cur_col << ",0)" << endl;
	for (int row = 1; row < height; row++) {
		int right = 9999999;
		int forward = 9999999;
		int left = 9999999;
		if (cur_col == 0) { 
			 forward = energy(image, cur_col, row, width, height);
			 left = energy(image, cur_col + 1, row, width, height);
			 //could try having all functions here
		} else if (cur_col == width - 1) {
			 forward = energy(image, cur_col, row, width, height);
			 right = energy(image, cur_col - 1, row, width, height);
		} else {
			 right = energy(image, cur_col - 1, row, width, height);
			 forward = energy(image, cur_col, row, width, height);
			 left = energy(image, cur_col + 1, row, width, height);
		}
		//ties - forward
		if (right == forward && forward == left) {
			seam[row] = cur_col;
			totalEnergy += forward;
			
			//cout << " TIE " << endl;
			//cout << "went forward to " << forward << endl;
		} 
		else if (forward == right && forward < left) {
			seam[row] = cur_col;
			totalEnergy += forward;
			
			//cout << " TIE " << endl;
			//cout << "went forward to " << forward << endl;
		}
		else if (forward == left && forward < right) {
			seam[row] = cur_col;
			totalEnergy += forward;
			
			//cout << " TIE " << endl;
			//cout << "went forward to " << forward << endl;
		}
		//ties - left
		else if (right == left && left < forward) {
			cur_col += 1;
			seam[row] = cur_col;
			totalEnergy += left;
			
			//cout << " TIE " << endl;
			//cout << "went left to " << left << endl;
		}
		//right
		else if (right < forward && right < left) {
			cur_col -= 1;
			seam[row] = cur_col;
			totalEnergy += right;
			
			//cout << "went right to " << right << endl;
		}
		//forward
		else if (forward < right && forward < left) { 
			seam[row] = cur_col;
			totalEnergy += forward;
			
			//cout << "went forward to " << forward << endl;
		}
		//left
		else if (left < right && left < forward) {
			cur_col += 1;
			seam[row] = cur_col;
			totalEnergy += left;
			
			//cout << "went left to " << left << endl;
		}
		
		// cout << "counter : " << counter << endl;
		// counter += 1;
		//cout << "coordinates: (" << cur_col << "," << row << ")" << endl;
		//cout << "new total: " << totalEnergy << endl;
	}
	//cout << "TOTAL: " << totalEnergy << endl;
  return totalEnergy;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
  return 0;
}
/*
int* findMinVerticalSeam(Pixel** image, int width, int height) {
  return nullptr;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
  return nullptr;
}
*/

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
	//use coordinates
	//loop through picture with nested for loops
	//make temp values for everything and replace the selected values
	//put while and if target statement in main
	for (int row = 0; row < height; row++) {
		for (int col = verticalSeam[row]; col < width - 1; col++) {
			image[col][row].r = image[col + 1][row].r;
			image[col][row].g = image[col + 1][row].g;
			image[col][row].b = image[col + 1][row].b;
			
		}
	}
	
	
	
	
}


void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
	for (int col = 0; col < width; col++) {
		for (int row = horizontalSeam[col]; row < height - 1; row++) {
			image[col][row].r = image[col][row + 1].r;
			image[col][row].g = image[col][row + 1].g;
			image[col][row].b = image[col][row + 1].b;
			
		}
	}
	
}


