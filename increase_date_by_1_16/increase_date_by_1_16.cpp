
#include <iostream>

using namespace std;

short ReadDay() {
    cout << "please enter day : ";
    short Day;
    cin >> Day;
    return Day + 1;
}

short ReadMonth() {
    cout << "please enter Month : ";
    short Month ;
    cin >> Month;
    return Month;
}

short ReadYear() {
    cout << "please enter Year : ";
    short Year;
    cin >> Year;
    return Year;
}


struct stDate {
    short Day;
    short Month;
    short Year;
};

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year) {

    if (Month < 1 || Month>12)
        return  0;

    int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}



stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

bool isLastMonthInYear(short Month) {
    return (Month == 12) ;
}
bool isLastDayInMonth( stDate Date ) {
    return  ( Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year) );
}

stDate increaseDateByOneDay(stDate Date) {
   
    if(isLastDayInMonth(Date) ){

        if (isLastMonthInYear(Date.Month)) {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else {
         
        Date.Day++;
       }
  
  
    return Date;
}


int main()
{
    stDate Date1 = ReadFullDate();
  
    Date1 = increaseDateByOneDay(Date1);

    cout << " The Date After Adding One Day :   "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
}
