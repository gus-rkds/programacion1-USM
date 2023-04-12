/*
Este programa imprime los primeros 20 numeros a partir del 100000 que cumplen las siguientes condiciones:
- La raiz cuadrada del numero es un numero primo
- La raiz cuadrada del numero termina en 7
- La raiz cuadrada del numero es entera

Programa elaborado por Gustavo Alviarez
Universidad Santa María
Programación I
elaborado 12-4-2023
*/
#include <iostream>
#include <cmath>

using namespace std;

// funcion que devuelve verdadero o falso si el numero es primo o no
bool esPrimo(int num)
{
  // función para comprobar si un número es primo o no
  for (int i = 2; i <= num / 2; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}

main() {
    // contador que va incrementando para saber cuantos numeros se han encontrado
    int contador = 0;

    // ciclo que recorre los numeros desde 100000 hasta que se encuentren los 20 numeros que cumplan
    for (int i = 100000; contador < 20; i++) {
        // guardamos la raiz cuadrada en int y double para verificar si es entera
        double raiz = sqrt(i);
        int raizInt = sqrt(i);
        // si la raiz del numero es entera, es primo y termina en 7, se imprime el numero y su raiz cuadrada
        if (!(raiz - raizInt != 0) && esPrimo(raizInt) && raizInt % 10 == 7 ) {
            cout << i << " - " << raizInt << endl;
            contador++;
        }
    }

}
