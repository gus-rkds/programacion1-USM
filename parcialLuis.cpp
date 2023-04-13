#include <iostream>
#include <cmath>

using namespace std;

main() {
    // contador para saber cuantos numeros se han encontrado
    int contador = 0;

    // ciclo que recorre los numeros desde 50000 hasta que se encuentren los 20 numeros que cumplan las condiciones
    for (int i = 50000; contador < 20; i++) {
        // division del numero entre 4 y 6
        int div4 = i / 4;
        int div6 = i / 6;
        // raiz cuadrada del numero en su version double y int para verificar si es entero
        double raiz = sqrt(i);
        int raizInt = sqrt(i);
        // si la raiz del numero es entera, su raiz termina en 4 y el num es divisible entre 4 y 6
        if (!(raiz - raizInt != 0) and raizInt % 10 == 4 and i % 4 == 0 and i % 6 == 0) {
            cout << i << " - " << div4 << " - " << div6 << " - " << raizInt << endl;
            contador++;
        }
    }

}
