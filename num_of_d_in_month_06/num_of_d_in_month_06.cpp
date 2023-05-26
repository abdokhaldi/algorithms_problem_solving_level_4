// num_of_d-h-m-s_in_month_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool checkTypeYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}


short ReadYear() {
    cout << "enter Year : ";
    short Year;
    cin >> Year;
    return Year;
}

short ReadMonth() {

    short Month;
    cout << "enter Month : ";
    cin >> Month;
    return Month;
}

short NumberOfDaysInMonth(short Month, short Year) {

    if (Month < 1 || Month > 12) {
        return 0;
    }

    short arr31Days[13] = { 31,28,31,30, 31,30, 31,31, 30,31, 30,31 };
    
    return Month == 2 ? (checkTypeYear(Year) ? 29 : 28) : (arr31Days[Month-1]);
}



int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days    in Month [" << Year << "] is " << NumberOfDaysInMonth(Month, Year) << endl;
   

    system("pause>0");
    return 0;
}

