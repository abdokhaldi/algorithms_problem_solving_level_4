

#include <iostream>

using namespace std;


struct stDate {
    short Day;
    short Month;
    short Year;
};

short ReadDay() {
    short Day;
    cout << "Enter Day : ";
    cin >> Day;
    return Day;
}

short ReadMonth() {
    short Month;
    cout << "Enter Month : ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << " Enter Year : ";
    cin >> Year;
    return Year;
}

stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month , short Year) {
    if (Month < 1 || Month > 12) {
        return 0;
    }

    short Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : Days[Month - 1]; 
}



stDate DecreaseDateByOnDay(stDate Date) {
    if (Date.Day == 1) {
        if (Date.Month == 1) {
           
            Date.Month = 12; 
            Date.Day = 31;
            Date.Year--; 
           
        }
        else {
            
            Date.Month --;
            Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
           }
        
    }
    else {
        Date.Day--;
    }

    
    return Date;
}

stDate DecreaseDateByXdays( short Days , stDate Date) {
    for (short i = 1; i <= Days; i++) {
        Date = DecreaseDateByOnDay(Date);
    }
    return Date;
}

stDate DecreaseDateByOneWeak( stDate Date) {
        for(short i=1;i<=7;i++){
        Date = DecreaseDateByOnDay(Date);
       }
    return Date;
}

stDate DecreaseDateByXweak(short Weak ,  stDate Date) {

    for (short i = 1; i <= Weak; i++) {
        Date = DecreaseDateByOneWeak(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date) {

    if (Date.Month == 1) {
        Date.Month = 12;
        Date.Year--;
    }
    else {
        Date.Month--;
    }

  short  NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
   if(Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaseDateByXMonth(short Months , stDate Date) {
    
    for (short i = 1; i <= Months; i++) {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear( stDate Date) {
    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYearFaster(short Years , stDate Date) {
    Date.Year -= Years;
    return Date;
}

 stDate DecreaseDateByXYear(short Years, stDate Date) {
     for (short i = 1; i <= Years; i++) {
         Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
stDate DecreaseDateByOneDecade(stDate Date) {
    Date.Year -= 10;
    return Date;
}

stDate DecreaseDateByXDecade(short Decade , stDate Date) {
    for (short i = 1; i <= Decade*10; i++) {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadeFaster(short Decade, stDate Date) {
    
    Date.Year -= Decade * 10;
    return Date;
}

stDate DecraseByOneCentury(stDate Date) {
    Date.Year -= 100;
    return Date;
}

stDate DecraseByOneMillennium(stDate Date) {
    Date.Year -= 1000 ;
    return Date;
}


int main()
{
    stDate Date1 = ReadFullDate();

    Date1 = DecreaseDateByOnDay(Date1);
    cout << "\n the date after substruction of one day :        " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXdays(10, Date1);
    cout << "\n the date after substruction of 10 days :        " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneWeak(Date1);
    cout << "\n the date after substruction of One Weak :       " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXweak(10,Date1);
    cout << "\n the date after substruction of 10 Weaks :       " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneMonth( Date1);
    cout << "\n the date after substruction of One Month :      " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXMonth(10, Date1);
    cout << "\n the date after substruction of 10 Months :      " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneYear(Date1);
    cout << "\n the date after substruction of One Year :       " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXYear(10, Date1); 
    cout << "\n the date after substruction 10 Year :           " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXYearFaster(10, Date1);
    cout << "\n the date after substruction 10 Year Faster way:           " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByOneDecade(Date1);
    cout << "\n the date after substruction one decade  :       " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXDecade(10,Date1);
    cout << "\n the date after substruction 10 decade  :        " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecreaseDateByXDecadeFaster(10, Date1);
    cout << "\n the date after substruction 10 decade Faster way  :        " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecraseByOneCentury(Date1);
    cout << "\n the date after substruction of one century  :   " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = DecraseByOneMillennium(Date1);
    cout << "\n the date after substruction of one Millenium  : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    
}

