/* En este caso, el método `dayOfWeek` utiliza dos bucles `for` para contar el número de 
días transcurridos desde el 1 de enero de 1900 hasta la fecha dada. En el primer bucle 
se cuentan los años completos desde 1900 hasta el año anterior al de la fecha dada,
y se suma 365 días por cada año no bisiesto y 366 días por cada año bisiesto. 
En el segundo bucle se cuentan los meses completos desde enero hasta el mes anterior 
al de la fecha dada, y se suma el número de días correspondiente a cada mes.

Una vez calculado el número total de días transcurridos, se aplica una fórmula de 
congruencia para determinar el día de la Week correspondiente. En este caso, se utiliza 
la fórmula `(numDays + 1) % 7`, que devuelve un número del 0 al 6, donde 0 representa 
el domingo, 1 representa el lunes, etc.

Finalmente, el programa utiliza un arreglo de cadenas para asociar cada número del 0 al 6 
con el nombre del día de la Week correspondiente.

*/

#include <iostream>
#include <string>

using namespace std;

bool isYearLeap(int year) {
    // Determina si un año es bisiesto o no.
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int dayOfWeek(int day, int month, int year) {
    /*
    Calcula el día de la sem para una fecha dada utilizando el método de congruencia.
    Devuelve un número del 0 al 6, donde 0 es Domingo, 1 es Lunes, 2 es Martes, etc.
    */
    // número de días transcurridos desde el 1 de enero de 1900 hasta la fecha dada
    int numDays = 0;
    for (int i = 1900; i < year; i++) {
        numDays += 365;
        if (isYearLeap(i)) {
            numDays++;
        }
    }
    for (int i = 1; i < month; i++) {
        if (i == 2) {
            if (isYearLeap(year)) {
                numDays += 29;
            } else {
                numDays += 28;
            }
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            numDays += 30;
        } else {
            numDays += 31;
        }
    }
    numDays += day - 1;

    // calcular el día de la sem
    int dayWeekNum = (numDays + 1) % 7;
    return dayWeekNum;
}

int main() {
    // solicitar la fecha al usuario
    int day, month, year;
    cout << "Ingrese el día (1-31): ";
    cin >> day;
    cout << "Ingrese el month (1-12): ";
    cin >> month;
    cout << "Ingrese el año (2021-2050): ";
    cin >> year;

    // validar la fecha
    if (day < 1 || day > 31) {
        cout << "Día inválido." << endl;
    } else if (month < 1 || month > 12) {
        cout << "month inválido." << endl;
    } else if (year < 2021 || year > 2050) {
        cout << "Año inválido." << endl;
    } else {
        // calcular el día de la sem
        string daysWeek[] = {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"};
        int dayWeekNum = dayOfWeek(day, month, year);
        string dayWeekStr = daysWeek[dayWeekNum];
        cout << "El día de la semana para la fecha " << day << "/" << month << "/" << year << " es " << dayWeekStr << "." << endl;
}

return 0;

}

