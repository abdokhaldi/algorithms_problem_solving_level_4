// num_of_d-h-m-s_in_year_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool checkTypeYear(int Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }


int ReadYear() {
    cout << "enter Year : ";
    int Year;
    cin >> Year;
    return Year;
}


int NumberOfDaysInYear(int Year) {
    return  checkTypeYear(Year) ? 366 : 365;
 }
int NumberOfHoursInYear(int Year) {
    return NumberOfDaysInYear(Year) * 24;
}
int NumberOfMinutesInYear(int Year) {
    return  NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecondsInYear(int Year) {
    return  NumberOfMinutesInYear(Year) * 60;
}


int main()
{
    int Year = ReadYear();

    cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInYear(Year) << endl;
    cout << "\nNumber of Hours    in Year [" << Year << "] is " << NumberOfHoursInYear(Year) << endl;
    cout << "\nNumber of Minutes    in Year [" << Year << "] is " << NumberOfMinutesInYear(Year) << endl;
    cout << "\nNumber of Seconds   in Year [" << Year << "] is " << NumberOfSecondsInYear(Year) << endl;

    system("pause>0");
    return 0;
}

