#include <iostream>
#include <math.h>

using namespace std;

main (){
    //crear array de 50 espacios, vacio
    int array[100];
    int counter = 0;
    //crear variables para guardar min y max
    int min;
    int max;
    
    //pedir valor minimo
    cout << "ingresa rango minimo (1-1000000)" << endl;
    cin >> min;
    //pedir valor maximo
    cout << "ingresa rango maximo (1-1000000)" << endl;
    cin >> max;
    //validar que min y max esten entre 1 y 1000000
    if (min < 1 or min > 1000000 or max < 1 or max > 1000000){
        cout << "rango invalido";
    }
    //validar que min sea menor que max
    if (min > max){
        cout <<
        "min es mayor a max";
    }
    // llenar array con un for del valor min al max
    for (int i = min; i <= max; i++) { 
        // verifica que el i es divisible entre 9
        double cube = cbrt(i);
        int cubeInt = cbrt(i);
        if (i % 2 != 0 and !(cube - cubeInt != 0))
        {
            array[counter] = i;
            cout << "este es el i: " << array[counter] << endl;
            cout << "esta es su raiz cubica: " << cube<< endl;
            counter++;
        }
    }

    
}

