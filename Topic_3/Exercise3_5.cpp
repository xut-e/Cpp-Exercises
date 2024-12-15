#include <iostream>

void main() {
	int numero1, numero2;

	std::cout << "Introduce dos numeros a continuacion.Introducir dos pares sumara los numeros, mientras que si no lo son, se restara el segundo al primero." << std::endl << "Introduce el primer numero: ";
	std::cin >> numero1;
	std::cout << "Introduce el segundo numero: ";
	std::cin >> numero2;

	if (numero1 % 2 == 0 && numero2 % 2 == 0) {
		std::cout << "El resultado es: " << numero1 + numero2;
	}
	else {
		std::cout << "El resultado es: " << numero1 - numero2;
	}
}