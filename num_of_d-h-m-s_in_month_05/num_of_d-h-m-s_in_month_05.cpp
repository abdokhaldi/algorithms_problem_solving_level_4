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

int NumberOfDaysInMonth(short Month ,short Year) {
    if (Month < 1 || Month >12) {
        return 0;
   }
    if (Month == 2) {
        return checkTypeYear(Year) ? 29 : 28;
    }

    short arr31Days[7] = {1,3,5,7,8,10,12};
    for (int i = 1;i<= sizeof(arr31Days) ;i++) {
        if (arr31Days[i-1] == Month) {
            return 31;
        }
    }

    return 30;
}

int NumberOfHoursInMonth(short Month,short Year) {
    return NumberOfDaysInMonth( Month ,Year) * 24;
}
int NumberOfMinutesInMonth(short Month,short Year) {
    return  NumberOfHoursInMonth(Month, Year) * 60;
}
int NumberOfSecondsInMonth(short Month,short Year) {
    return  NumberOfMinutesInMonth(Month ,Year) * 60;
}


int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumber of Days    in Month [" << Year << "] is " << NumberOfDaysInMonth(Month,Year) << endl;
    cout << "\nNumber of Hours    in Month [" << Year << "] is " << NumberOfHoursInMonth(Month, Year) << endl;
    cout << "\nNumber of Minutes    in Month [" << Year << "] is " << NumberOfMinutesInMonth(Month, Year) << endl;
    cout << "\nNumber of Seconds   in Month [" << Year << "] is " << NumberOfSecondsInMonth(Month, Year) << endl;

    system("pause>0");
    return 0;
}

