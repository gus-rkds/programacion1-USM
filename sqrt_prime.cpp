/*
Programa que determina los primeros 10 números en un rango
(mínimo 100000 - máximo 200000000) que sus
raíces cuadradas son números primos que terminan en siete(7)
Elaborado por Gustavo Alviarez - USM
fecha: abril 2023
Rev. 0.

*/

#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int num)
{
  /* función para comprobar si un número es primo
  retorna true si es primo, false de lo contrario*/
  for (int i = 2; i <= num / 2; i++)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}

bool last_is_seven(int num)
{
  /* función para comprobar si un número termina en 7
   retorna true si termina en 7, false de lo contrario*/
  int last_digit = num % 10;
  if (last_digit == 7)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int arr[10];
  int counter = 0;

  int min, max;

  /*pide y verifica el rango menor*/
  cout << "Ingrese el rango MENOR a evaluar (100000<=rango menor<200000000): ";
  cin >> min;
  if (min < 100000 or min >= 200000000)
  {
    cout << "El rango ingresado no es valido" << endl;
    return 0;
  }

  /*pide y verifica el rango mayor*/
  cout << "Ingrese el rango MAYOR a evaluar (100000<=rango menor<200000000): ";
  cin >> max;
  if (max < 100000 or max >= 200000000)
  {
    cout << "El rango ingresado no es valido" << endl;
    return 0;
  }

  /* crea un array de los 10 primeros numeros cuya raiz es prima y termina en 7 */
  for (int i = min; i <= max; i++)
  {
    double square = sqrt(i);
    if (is_prime(square) && last_is_seven(square))
    {
      arr[counter] = i;
      counter++;
    }
    if (counter == 10)
    {
      break;
    }
  }

  /*pinta el array creado*/
  cout << "Los primeros 10 numeros cuya raiz cuadrada es un numero primo que termina en 7 son: ";
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}