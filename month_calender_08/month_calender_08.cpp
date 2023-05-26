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



string MonthShortName(short Month, short Year) {

    if (Month < 1 || Month >12) {
        return "0";
   }

    string arrMonths[13] = { "January","February","March","Abril", "May","June", "Julay","Augest", "September" ,"October","November", "December"};

   return   (arrMonths[Month - 1]);
}






short NumberOfDaysInMonth(short Month, short Year) {

    if (Month < 1 || Month > 12) {
        return 0;
    }

    short arr31Days[13] = { 31,28,31,30, 31,30, 31,31, 30,31, 30,31 };

    return Month == 2 ? (checkTypeYear(Year) ? 29 : 28) : (arr31Days[Month - 1]);
}

short DayOfWeekOrder(short Day, short Month, short Year) {
    short a, y, m;     a = (14 - Month) / 12;     y = Year - a;   
    m = Month + (12 * a) - 2;
   
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7; 
}

void PrintCalender(short Month, short Year) {
  int Current = DayOfWeekOrder(1,Month,Year);
  int NumberOfDays = NumberOfDaysInMonth(Month,Year);

  printf("\n_______________%s_______________\n\n" , MonthShortName(Month, Year).c_str());

  //print columns 
  printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

  int i;
  for (i = 0; i < Current; i++) 
      printf("     ");

      for (int j = 1; j <= NumberOfDays; j++) {
          printf("%5d", j);
          if (++i == 7){
              i = 0;   
              printf("\n"); 
          }     
  }
  printf("\n  _________________________________\n");
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    PrintCalender(Month, Year);
   
   
   

    system("pause>0");
    return 0;
}

