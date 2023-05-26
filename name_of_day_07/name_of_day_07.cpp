

#include <iostream>

using namespace std;





short ReadYear() {
    short Year;
    cout << "Enter Year : ";
    cin >> Year;
    return Year;
}

short ReadMonth() {
    short Month;
    cout << "enter Month : ";
    cin >> Month;
    return Month;
}

short ReadDay() {
    short Day;
    cout << "Enter Dday : ";
    cin >> Day;
    return Day;
}

short CalculateDay(short Year, short Month , short Day) {
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = (Month + 12) * a - 2;

    short d = ((Day + y) + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    return d;
}

string  DayShortName(short Day) {

    string arrWeekDays[7] = { "Sunday", "Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday" };
    return arrWeekDays[Day];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    cout << "\n\n the date : " << Day << " / " << Month << " / " << Year << endl;
    cout << "the day order : " << CalculateDay(Year, Month, Day) << endl;
   cout << " the day name : "  << DayShortName(CalculateDay(Year, Month, Day)) << endl;

   system("pause>0");
   return 0;
}

