/*
Programa elaborado por Jareanny Diaz
Universidad Santa María
Programación I
elaborado 12-4-2023
*/
#include <iostream>
#include <cmath>

using namespace std;

// funcion que devuelve verdadero o falso si el numero es primo o no
bool esPrimo(int n) {
    // si el numero es menor o igual a 1, no es primo
    if (n <= 1) {
        return false;
    }
    // ciclo que recorre los numeros desde 2 hasta la raiz cuadrada del numero
    for (int i = 2; i <= sqrt(n); i++) {
        // si el numero es divisible por alguno de los numeros entre 2 y la raiz cuadrada, no es primo
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

main() {
    // contador para saber cuantos numeros se han encontrado
    int contador = 0;

    // ciclo que recorre los numeros desde 500000 hasta que se encuentren los 10 numeros que cumplan las condiciones
    for (int i = 500000; contador < 10; i++) {
        // division del numero entre 14
        int division = i / 14;
        // raiz cuadrada del numero en su version double y int para verificar si es entero
        double raiz = sqrt(division);
        int raizInt = sqrt(division);
        // si la raiz del numero es entera, es primo y termina en 3, se imprime el numero, su division entre 14 y la raiz cuadrada
        if (!(raiz - raizInt != 0) && esPrimo(raizInt) && raizInt % 10 == 3 && i % 14 == 0) {
            cout << i << " - " << division << " - " << raizInt << endl;
            contador++;
        }
    }

}
