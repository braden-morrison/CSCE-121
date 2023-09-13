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
	int *ary = new int[length];
	for(int i = 0; i < length; i++) {
		ary[i] = 0;
	}
  return ary;
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

if (width < 3) {
	totalX = 0;
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
	totalY = 0;
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
/* 

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
  return 0;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
  return 0;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
  return nullptr;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
  return nullptr;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
}


void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
}
*/
