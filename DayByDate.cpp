#include <iostream>
#include <string>

using namespace std;

bool es_bisiesto(int anio) {
    /*
    Determina si un año es bisiesto o no.
    */
    return anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0);
}

int dia_de_semana(int dia, int mes, int anio) {
    /*
    Calcula el día de la semana para una fecha dada utilizando el método de congruencia.
    Devuelve un número del 0 al 6, donde 0 es Domingo, 1 es Lunes, 2 es Martes, etc.
    */
    // número de días transcurridos desde el 1 de enero de 1900 hasta la fecha dada
    int num_dias = 0;
    for (int i = 1900; i < anio; i++) {
        num_dias += 365;
        if (es_bisiesto(i)) {
            num_dias++;
        }
    }
    for (int i = 1; i < mes; i++) {
        if (i == 2) {
            if (es_bisiesto(anio)) {
                num_dias += 29;
            } else {
                num_dias += 28;
            }
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            num_dias += 30;
        } else {
            num_dias += 31;
        }
    }
    num_dias += dia - 1;

    // calcular el día de la semana
    int dia_semana_num = (num_dias + 1) % 7;
    return dia_semana_num;
}

int main() {
    // solicitar la fecha al usuario
    int dia, mes, anio;
    cout << "Ingrese el día (1-31): ";
    cin >> dia;
    cout << "Ingrese el mes (1-12): ";
    cin >> mes;
    cout << "Ingrese el año (2021-2050): ";
    cin >> anio;

    // validar la fecha
    if (dia < 1 || dia > 31) {
        cout << "Día inválido." << endl;
    } else if (mes < 1 || mes > 12) {
        cout << "Mes inválido." << endl;
    } else if (anio < 2021 || anio > 2050) {
        cout << "Año inválido." << endl;
    } else {
        // calcular el día de la semana
        string dias_semana[] = {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"};
        int dia_semana_num = dia_de_semana(dia, mes, anio);
        string dia_semana_str = dias_semana[dia_semana_num];
        cout << "El día de la semana para la fecha " << dia << "/" << mes << "/" << anio << " es " << dia_semana_str << "." << endl;
}

return 0;

}

/* En este caso, el método `dia_de_semana` utiliza dos bucles `for` para contar el número de días transcurridos desde el 1 de enero de 1900 hasta la fecha dada. En el primer bucle se cuentan los años completos desde 1900 hasta el año anterior al de la fecha dada, y se suma 365 días por cada año no bisiesto y 366 días por cada año bisiesto. En el segundo bucle se cuentan los meses completos desde enero hasta el mes anterior al de la fecha dada, y se suma el número de días correspondiente a cada mes.

Una vez calculado el número total de días transcurridos, se aplica una fórmula de congruencia para determinar el día de la semana correspondiente. En este caso, se utiliza la fórmula `(num_dias + 1) % 7`, que devuelve un número del 0 al 6, donde 0 representa el domingo, 1 representa el lunes, etc.

Finalmente, el programa utiliza un arreglo de cadenas para asociar cada número del 0 al 6 con el nombre del día de la semana correspondiente.

*/