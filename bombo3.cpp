#include <iostream>
#include <conio.h> // Biblioteca para utilizar kbhit() y getch()
#include <windows.h>

using namespace std;

int main() {
    const int tiempoTotal = 5 * 60; // 5 minutos en segundos
    int tiempoRestante = tiempoTotal;

    while (tiempoRestante > 0) {
        cout << "Tiempo restante: " << tiempoRestante / 60 << ":" << tiempoRestante % 60 << "\n";
        if (kbhit()) { // Si el usuario ha ingresado algo por teclado
            char c1 = getch(); // Leer primer caracter
            char c2 = getch(); // Leer segundo caracter
            if (c1 == 'a' && c2 == 'b') { // Si el código ingresado es correcto
                cout << "¡Bomba desactivada!\n";
                return 0;
            } else { // Si el código ingresado es incorrecto
                cout << "Codigo incorrecto. Se reduce 1 minuto del tiempo restante.\n";
                tiempoRestante -= 60;
            }
        } else { // Si el usuario no ha ingresado nada por teclado
            tiempoRestante--;
            Sleep(1000); // Esperar 1 segundo
        }
    }

    cout << "¡La bomba ha explotado!\n";
    return 0;
}
