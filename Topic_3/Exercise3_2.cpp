//2. Crea un programa que determine si un número introducido por el usuario es positivo, negativo o cero.

#include <iostream>

void main() {
	int numero;

	std::cout << "Introduce un numero: ";
	std::cin >> numero;

	if (numero > 0) {
		std::cout << "El numero introducido es positivo." << std::endl;
	}
	else if (numero < 0) {
		std::cout << "El numero introducido es negativo." << std::endl;
	}
	else {
		std::cout << "El numero introducido es cero." << std::endl;
	}
}