// leap_year_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool CheckYearType(int Year) {

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
   
}

void printYearType(int Year) {
    if (CheckYearType(Year)) {
        cout << "Yeas , the Year  [" << Year << "] is a Leap Year .";
    }
    else {
        cout << " No , the Year  [" << Year << "] is Not a Leap Year .";
    }
}

int ReadYear() {
    int year;
    cout << " enter year : ";
    cin >> year;
    return year;
}

int main()
{
    int Year = ReadYear();
    printYearType(Year);
}

