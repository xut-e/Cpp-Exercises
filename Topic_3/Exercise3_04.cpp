// 4. Crea un programa que determine si un año introducido por el usuario es bisiesto o no.

#include <iostream>

void main() {
	int anyo;

	std::cout << "Introduce el anyo que deseas comprobar: ";
	std::cin >> anyo;

	if (anyo % 4 == 0) {
		std::cout << "El anyo introducido es bisiesto.";
	}
	else {
		std::cout << "El anyo introducido no es bisiesto.";
	}
}