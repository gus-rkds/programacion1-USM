/*
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
    // contador para saber cuantos numeros se han encontrado
    int contador = 0;

    // ciclo que recorre los numeros desde 500000 hasta que se encuentren los 10 numeros que cumplan las condiciones
    for (int i = 10000; contador < 20; i++) {
        // raiz cuadrada del numero en su version double y int para verificar si es entero
        double raiz = sqrt(i);
        int raizInt = sqrt(i);
        // si la raiz del numero es entera, es primo y termina en 3, se imprime el numero, su division entre 14 y la raiz cuadrada
        if (!(raiz - raizInt != 0) && esPrimo(raizInt) && raizInt % 10 == 7 ) {
            cout << i << " - " << raizInt << endl;
            contador++;
        }
    }

}
