// number_to_text_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


string  numberToText(long long  Number) {

    if (Number == 0) {
        return "";
    }

    if (Number >= 1 && Number <= 19) {
        string  number_words[] = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
        };
        return number_words[Number] + " ";
    }

   
    if (Number >= 20 && Number <= 99) {
        string  number_words[] = {
      "","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
        };
        return   number_words[Number / 10] + " " + numberToText(Number % 10);
    }
   
    if (Number >= 100 && Number <= 199) {
        return "one handred " + numberToText(Number % 100);
    }

    if (Number >= 200 && Number <= 999) {
        return numberToText(Number / 100) + " handred " + numberToText(Number % 100);
    }


    if (Number >= 1000 && Number <= 1999) { 
        return "One Thousand " + numberToText(Number % 1000);
    }

    if (Number >= 2000 && Number <= 999999) { 
        return   numberToText(Number / 1000) + "Thousands " + numberToText(Number % 1000); 
    }

    if (Number >= 1000000 && Number <= 1999999) {
        return "one million " + numberToText(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999) {
        return   numberToText(Number / 1000000) + " millions " + numberToText(Number % 1000000);
    }
    if (Number >= 1000000000 && Number <= 1999999999) {
        return "one billion " + numberToText(Number % 1000000000);
    }
    else {
        return numberToText(Number / 1000000000) + " billions " + numberToText(Number % 1000000000);
    }

}

long long ReadNumber() {
   long long Number;
    cout << "enter number : \n";
    cin >> Number;
    return Number;
}

int main()
{
   long long Number = ReadNumber();
   cout <<  numberToText(Number);
   system("pause>0");
   return 0;

}

