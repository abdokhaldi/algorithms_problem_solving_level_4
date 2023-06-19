

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
    cout << "Enter Day : ";
    cin >> Day;
    return Day;
}

struct stDate {
    short Day;
    short Month;
    short Year;
};

stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
   Date.Year = ReadYear();
    
   return Date;
}

bool IsLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month,short Year) {
    if (Month < 1 || Month > 12) {
        return 0;
    }

    short Days[12] = { 31,28,31,30,31,30,31,30,31,30,31,30 };
    return (Month == 2) ? (IsLeapYear(Year)? 29:28) : Days[Month-1];

}

short DayOfWeakOrder(short Day, short Month, short Year) {
    short a, y, m;    

    a = (14 - Month) / 12;   
    y = Year - a;  
    m = Month + (12 * a) - 2;

    // Gregorian://0:sun, 1:Mon, 2:Tue...etc

    short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7; 
    return d;
} 

short DayOfWeakOrder(stDate Date) {
    return DayOfWeakOrder(Date.Day, Date.Month, Date.Year);
}

bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}


stDate IncreaseDateByOneDay(stDate Date) { 
    if (IsLastDayInMonth(Date)) { 
    if (IsLastMonthInYear(Date.Month)) {
        Date.Month = 1; 
        Date.Day = 1; 
        Date.Year++; 
    } else { 
        Date.Day = 1;   
        Date.Month++;   
      } 
         } else { 
        Date.Day++; 
    } 
    return Date; 
}


bool IsDate1BeforDate2(stDate Date1, stDate Date2 ) {
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false )) : false);
}

short GetDiferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay=false) {
    int Days = 0;
    while (IsDate1BeforDate2(Date1,Date2 ) ) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

string  DayShortName(short Day) {

    string arrWeekDays[7] = { "Sunday", "Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday" };
    return arrWeekDays[Day];
}



bool IsEndOfWeak(stDate Date) {
    return (DayOfWeakOrder(Date) == 6);
}

bool IsWeakEnd(stDate Date) {
    short DayIndex = DayOfWeakOrder(Date.Day, Date.Month , Date.Year);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBussinessDay( stDate Date) {
   
    return !IsWeakEnd(Date);
}



short DaysUntilTheEndOfWeak(stDate Date) {
   
    return (6 - DayOfWeakOrder(Date));
}

short DaysUntilTheEndOfMonth(stDate Date ) {
    stDate EndOfMonthDate;

    EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GetDiferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(stDate Date) {
    stDate EndOfYearDate;

    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;

   return   GetDiferenceInDays(Date, EndOfYearDate, true);
}


stDate GetSystemDate() {
    stDate Date;

    time_t CurrentTime = time(&CurrentTime);
    tm localTime;
    localtime_s(&localTime, &CurrentTime);

    Date.Day = localTime.tm_mday;
    Date.Month = localTime.tm_mon + 1;
    Date.Year = localTime.tm_year + 1900;

    return Date;
}



int main()
{
    stDate Date = GetSystemDate();

    cout << "\n\n today is  " << DayShortName(DayOfWeakOrder(Date) ) << " : "
        << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

   
        if (IsEndOfWeak(Date)) {
            cout << "Yes , it is end of weak \n";
        }
        else {
            cout << "No , it is not end of weak \n";
        }
    
   
        if (IsWeakEnd(Date)) {
            cout << "Yes , it is a weak end \n";
        }
        else {
            cout << "No , it is not a weak  end \n";
        }
 
   
        if (IsBussinessDay(Date)) {
            cout << "Yes , it is a businness day \n";
        }
        else {
            cout << "No , it is not a businness day \n";
        }
    
    
    cout << "days until the end of weak is : " << DaysUntilTheEndOfWeak(Date);
    cout << "\ndays until the end of Month is : " <<  DaysUntilTheEndOfMonth(Date);
    cout << "\ndays until the end of Year is : " << DaysUntilTheEndOfYear(Date);
   

    system("pause>0");
    return 0;
}

