//1. Crea un programa que determine si un número introducido por el usuario es par o impar.

#include <iostream>

void main() {
	int numero;

	std::cout << "Introduce un numero y te dire si es par o impar: ";
	std::cin >> numero;

	if (numero % 2 != 0) {
		std::cout << "El numero introducido es impar." << std::endl;
	}
	else {
		std::cout << "El numero introducido es par." << std::endl;
	}
}