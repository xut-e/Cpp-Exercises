// 7. Crea un programa que pida al usuario un número del 1 al 12 e imprima la cantidad de días que tiene ese mes.

#include <iostream>

void main() {
    short unsigned numero;

    std::cout << "Introduzca un numero del 1 al 12: ";
    std::cin >> numero;

    if (numero == 2) {
        std::cout << "El mes " << numero << " tiene 28 dias en anyo normal y 29 en bisiesto." << std::endl;
    }
    else if (numero % 2 == 0) {
        if (numero <= 7) {
            std::cout << "El mes " << numero << " tiene 30 dias." << std::endl;
        }
        else {
            std::cout << "El mes " << numero << " tiene 31 dias." << std::endl;
        }
    }
    else {
        if (numero <= 7) {
            std::cout << "El mes " << numero << " tiene 31 dias." << std::endl;
        }
        else {
            std::cout << "El mes " << numero << " tiene 30 dias." << std::endl;
        }
    }
}