// date1_less_than_date2_13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct sDate {
    short Day;
    short Month;
    short Year;
};




short ReadDay() {
    short Day;
    cout << " Enter Day : ";
    cin >> Day;
    return Day;
}

short ReadMonth() {
    short Month;
    cout << " Enter Month : ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << " Enter Year : ";
    cin >> Year;
    return Year;
}

bool isDate1LessThanDate2(sDate Date1, sDate Date2) {

    return (Date1.Year == Date2.Year)   ? (( Date1.Month == Date2.Month ) ? ((Date1.Day == Date2.Day) ? true : false) : false ) : false ;
    
}

sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;

}

int main()
{
    sDate Date1 = ReadFullDate();
    cout << "\n\n";
    sDate Date2 = ReadFullDate();

    if (isDate1LessThanDate2(Date1, Date2)) {
        cout << " Yes , Date 1 Equals to date 2 .";
    }
    else {
        cout << " No , Date 1 is Not Equals to  date 2 .";
    }

}

