/*
Programa que simula una bomba que explota en 5 minutos. El usuario puede desactivar la bomba ingresando 
un código secreto. Si el usuario no ingresa el código secreto, la bomba explota. 
Por cada intento fallido se resta 1 minuto del tiempo restante.

El código secreto es: af

creadores: 
    - Gustavo Alviarez
    - Jareanny Diaz
    - Cristian Hernandez
*/

#include <iostream>
#include <conio.h> // Biblioteca para utilizar kbhit() y getch()
#include <windows.h> // Biblioteca para utilizar Sleep()

using namespace std;

main() {

    // Variables de tiempo en segundos, la primera representa los 5 minutos totales
    // y la segunda el tiempo restante
    const int tiempoTotal = 5 * 60; // 5 minutos en segundos
    int tiempoRestante = tiempoTotal;

    // Mostrar tiempo restante cada segundo, hasta que el tiempo restante sea 0
    while (tiempoRestante > 0) {
        // Mostrar tiempo restante
        cout << "Tiempo restante: " << tiempoRestante / 60 << ":" << tiempoRestante % 60<< "\n";
        if (kbhit()) { // Si el usuario ha ingresado algo por teclado
            char c1 = getch(); // Leer primer caracter
            char c2 = getch(); // Leer segundo caracter
            if ((c1 == 'a' || c1 == 'A') && (c2 == 'f' || c2 == 'F')) { // Si el código ingresado es correcto
                cout << "¡Bomba desactivada!\n";
                return 0;
            } else { // Si el código ingresado es incorrecto restamos 1 minuto del tiempo restante
                cout << "Codigo incorrecto. Se reduce 1 minuto del tiempo restante.\n";
                tiempoRestante -= 60;
            }
        } else { // Si el usuario no ha ingresado nada por teclado
            tiempoRestante--;
            Sleep(1000); // Esperar 1 segundo
        }
    }

    cout << "¡BOOOOOM, La bomba ha explotado!\n";
}