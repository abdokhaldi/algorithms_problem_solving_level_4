
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
    short Month;
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
    return (Month == 12);
}
bool isLastDayInMonth(stDate Date) {
    return  (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}


stDate IncreaseDateByOneDay(stDate Date) {

    if (isLastDayInMonth(Date)) { 
    if (isLastMonthInYear(Date.Month)) { 
        Date.Month = 1; 
        Date.Day = 1; 
        Date.Year++; 
    } else { 
        Date.Day = 1;
        Date.Month++;
      } 
    } 
    else { 
        Date.Day++;
    }  
    return Date; 
}

 stDate IncreaseDateByOneWeek(stDate Date) { 
     for (int i = 1; i <= 7; i++) { 
         Date = IncreaseDateByOneDay(Date);
     }
     return Date; 
 } 
 
 stDate IncreaseDateByXWeeks(short Weeks, stDate Date) { 
     for (short i = 1; i <= Weeks; i++) {
         Date = IncreaseDateByOneWeek(Date);
     } return Date; 
 }

 stDate IncreaseDateByOneMonth(stDate Date) {
     if (Date.Month == 12) { 
         Date.Month = 1; 
         Date.Year++;
     }
     else { 
         Date.Month++; 
     } 
     //last check day in date should not exceed max days in the current month
     // example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
     // be 28/2/2022
     short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

     if (Date.Day > NumberOfDaysInCurrentMonth)     {
         Date.Day = NumberOfDaysInCurrentMonth;   
     }

     return Date;
 }

 stDate IncreaseDateByXDays(short Days, stDate Date) {
     for (short i = 1; i <= Days; i++)     { 
         Date = IncreaseDateByOneDay(Date);  
     } 
     return Date; 
 }
 stDate IncreaseDateByXMonths(short Months, stDate Date) {
     for (short i = 1; i <= Months; i++)     {
         Date = IncreaseDateByOneMonth(Date);  
     }
     return Date ; 
 } 


 stDate IncreaseDateByOneYear(stDate Date) {
     Date.Year;
     return Date; 
 }

 stDate IncreaseDateByXYears(short Years, stDate Date) {

     for (short i = 1; i <= Years; i++) {
         Date = IncreaseDateByOneYear(Date); 
     }
     return Date;
 } 

 stDate IncreaseDateByXYearsFaster(short Years, stDate Date) { 
         Date.Year += Years;
         return Date;
 }

 stDate IncreaseDateByOneDecade(stDate Date) { 
     //Period of 10 years
     
     Date.Year += 10; 
     return Date; 
 } 

 stDate IncreaseDateByXDecades(short Decade, stDate Date) { 
     for (short i = 1; i <= Decade * 10; i++)     { 
         Date = IncreaseDateByOneYear(Date);  
     } 
     return Date; 
 } 
 stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date) {
     Date.Year += Decade * 10; 
     return Date;
 } 


 stDate IncreaseDateByOneCentury(stDate Date) {
     //Period of 100 years 
     Date.Year += 100;
     return Date; 
 } 
 
 stDate IncreaseDateByOneMillennium(stDate Date) { 
     //Period of 1000 years
     Date.Year += 1000; 
     return Date;
 } 


int main()
{
   

    stDate Date1 = ReadFullDate();
   
    cout << "\ndate after adding : \n";


    Date1 = IncreaseDateByOneDay(Date1);   
    cout << "\n01-Adding one day is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
      
   
    Date1 = IncreaseDateByXDays(10, Date1);
    cout << "\n02-The Date After Adding 10  Days :   "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;


    Date1 = IncreaseDateByOneWeek(Date1);    
    cout << "\n03-Adding one week is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXWeeks(10, Date1);  
    cout << "\n04-Adding 10 weeks is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneMonth(Date1);  
    cout << "\n05-Adding one month is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXMonths(5, Date1);    
    cout << "\n06-Adding 5 months is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneYear(Date1);
    cout << "\n07-Adding one year is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXYearsFaster(10, Date1);  
    cout << "\n09-Adding 10 Years (faster) is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneDecade(Date1);   
    cout << "\n10-Adding one Decade is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDecades(10, Date1); 
    cout << "\n11-Adding 10 Decades is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByXDecadesFaster(10, Date1); 
    cout << "\n12-Adding 10 Decade (faster) is: "
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneCentury(Date1);  
    cout << "\n13-Adding One Century is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

    Date1 = IncreaseDateByOneMillennium(Date1);   
    cout << "\n14-Adding One Millennium is: " 
        << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
}
