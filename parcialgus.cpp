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
    int numero = 500000;

    while (contador < 10) {
        int division = numero / 14;
        double raiz = sqrt(division);

        if (raiz == floor(raiz) && esPrimo((int)raiz) && (int)raiz % 10 == 3) {
            cout << numero << " - " << division << " - " << (int)raiz << endl;
            contador++;
        }

        numero++;
    }

    return 0;
}

/*
La función esPrimo verifica si un número dado es primo o no. La función main 
utiliza un ciclo while para iterar a través de los números desde 500000 en adelante, 
y se detiene cuando se encuentran los primeros 10 números que cumplen con las 
especificaciones. Para cada número, se calcula su división entre 14 y su raíz cuadrada. 
Luego, se verifica si la raíz cuadrada es un número entero y si es primo y termina en 3. 
Si se cumplen todas estas condiciones, se muestra el número, su división entre 14 
y la raíz cuadrada
*/