#include "boolean_functions.h"

#include <iostream>

using std::cin, std::cout, std::endl;

void booleanLogic1()
{
    cout << "--- Boolean Logic 1 ---" << endl;

    cout << " x | NOT x" << endl;
    cout << "---+-------" << endl;
    cout << " 0 |   1" << endl;
    cout << " 1 |   0" << endl;

    cout << endl;
}

void booleanLogic2()
{
    cout << "--- Boolean Logic 2 ---" << endl;

    cout << " x | y | x OR y" << endl;
    cout << "---+---+--------" << endl;
    cout << " 0 | 0 |   0" << endl;
    cout << " 0 | 1 |   1" << endl;
    cout << " 1 | 0 |   1" << endl;
    cout << " 1 | 1 |   1" << endl;

    cout << endl;
}

void booleanLogic3()
{
    cout << "--- Boolean Logic 3 ---" << endl;

    cout << " x | y | x AND y" << endl;
    cout << "---+---+---------" << endl;
    cout << " 0 | 0 |    0" << endl;
    cout << " 0 | 1 |    0" << endl;
    cout << " 1 | 0 |    0" << endl;
    cout << " 1 | 1 |    1" << endl;

    cout << endl;
}

void booleanLogic4()
{
    cout << "--- Boolean Logic 4 ---" << endl;

    cout << " x | y | x XOR y" << endl;
    cout << "---+---+---------" << endl;
    cout << " 0 | 0 |    0" << endl;
    cout << " 0 | 1 |    1" << endl;
    cout << " 1 | 0 |    1" << endl;
    cout << " 1 | 1 |    0" << endl;

    cout << endl;
}

void booleanLogic5()
{
    cout << "--- Boolean Logic 5 ---" << endl;

    bool x, y, z;
    cout << "Enter 0 or 1 values for x, y, and z: ";
    cin >> x >> y >> z;
    bool value = false; // TODO: Fill this in
    if (x == true) {
        value = true;
    }
    else if (y == true) {   
        value = true;
    }
    else if (z == true) {
        value = true;
    }
    else { 
        value = false;}


    cout << x << " OR " << y << " OR " << z << " = " << value << endl;

    cout << endl;
}

void booleanLogic6()
{
    cout << "--- Boolean Logic 6 ---" << endl;

    bool x, y, z;
    cout << "Enter 0 or 1 values for x, y, and z: ";
    cin >> x >> y >> z;
    bool value = false; // TODO: Fill this in
    if (x == true && y == true && z == true) {
        value = true;
    }
    else {
        value = false;
    }

    cout << x << " AND " << y << " AND " << z << " = " << value << endl;

    cout << endl;
}

void booleanLogic7()
{
    cout << "--- Boolean Logic 7 ---" << endl;

    bool x, y, z;
    cout << "Enter 0 or 1 values for x, y, and z: ";
    cin >> x >> y >> z;
    bool value = false; // TODO: Fill this in
    if (x == true && y == false && z == false) {
        value = true;
    }
    else if ( x == false && y == true && z == false) {
        value = true;
    }
    else if ( x == false && y == false && z == true) {
        value = true;
    }
    else {
        value = false;
    }
    
    cout << x << " XOR " << y << " XOR " << z << " = " << value << endl;

    cout << endl;
}