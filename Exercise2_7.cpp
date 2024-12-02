#include <iostream>

void main() {
	int numero;
	int numeroNegado;

	std::cout << "Introduce un numero: " << std::endl;
	std::cin >> numero;

	numeroNegado = (-1) * numero;

	std::cout << "El valor negado del numero que introdugiste es: " << numeroNegado << std::endl;
}