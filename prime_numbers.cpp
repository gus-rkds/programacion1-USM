/* Este programa imprime los números primos que terminan en 7 entre 10000 y 100000.

Para eso se crearon dos funciones: is_seven y is_prime. La primera recibe un número y devuelve true si el último dígito es 7 y false si no lo es. La segunda recibe un número y devuelve true si es primo y false si no lo es. Luego, en el main, se itera sobre los números entre 10000 y 100000 y se llama a las funciones is_seven y is_prime para cada número. Si el número es primo y termina en 7, se imprime.

Elaborado por: Gustavo Alviarez 
fecha: 18/03/2023
*/

#include <iostream>
using namespace std;

bool last_is_seven(int number) {
  int last_digit = number % 10;
  if ( last_digit == 7 ) {
    return true;
  } else {
    return false;
  }
}

bool is_prime(int number) {
  for ( int i = 2; i <= number/2; i++ ) {
    if ( number % i == 0 ) {
      return false;
    }
  }
  return true;
}

int main() {
  int number;
  for ( int i = 10000; i <= 100000; i++ ) {
    if ( last_is_seven(i) and is_prime(i) ) {
      cout << i << endl;
      }
    }
}
