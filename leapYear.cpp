#include <iostream>

using namespace std;

main (){
    int year;
    cout << "input a year";
    cin >> year;
    if(year % 4 == 0 and year % 100 != 0 or year % 400 == 0) //Condición de año bisiesto                                              
      cout << "is leap year" << endl;
    else
      cout << "is not a leap year" << endl;
}