// Programa elaborado por Jareanny Diaz
// Universidad Santa María
// Programación I
// elaborado 25-4-2021
#include <iostream>
#include <cmath>

using namespace std;

bool esPrimo(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int contador = 0;


    for (int i = 500000; contador < 10; i++) {
        int division = i / 14;
        double raiz = sqrt(division);
        int raizInt = sqrt(division);

        if (!(raiz - raizInt != 0) && esPrimo(raizInt) && raizInt % 10 == 3 && i % 14 == 0) {
            cout << i << " - " << division << " - " << raizInt << endl;
            contador++;
        }
    }

    return 0;
}

/*1.- Elabore un programa que presente en pantalla los primeros diez (10) números que:
a.- Que sean divisibles exactamente entre catorce (14).
b.- Que el resultado de su división entre catorce (14) al sacarle la raíz cuadrada de un numero entero (sin parte decimal).
c.- Que el resultado de la raíz sea un numero primo (Divisible de forma exacta solamente entre el mismo y entre 1) que termine en tres (3).
El rango a revisar es desde 500000 hasta que consiga los diez (10) números.
En la pantalla deberá presentarse el número, su división entre catorce (14) y la raíz cuadrada de ese resultado: 
Numero – División entre 14 – Raíz Cuadrada y numero Primo
521486 – 37249 - 193

*/