//12. Crea un programa que al pedir un número muestre su tabla de multiplicar entera del 1 al 10.

#include <iostream>

void main() {
	unsigned short numero;

	std::cout << "Introduzca un numero: " << std::endl;
	std::cin >> numero;

	std::cout << "La tabla de multiplicar del numero " << numero << " es:" << std::endl << std::endl;
	std::cout << "\t" << " 1 x " << numero << " = " << numero * 1 << std::endl;
	std::cout << "\t" << " 2 x " << numero << " = " << numero * 2 << std::endl;
	std::cout << "\t" << " 3 x " << numero << " = " << numero * 3 << std::endl;
	std::cout << "\t" << " 4 x " << numero << " = " << numero * 4 << std::endl;
	std::cout << "\t" << " 5 x " << numero << " = " << numero * 5 << std::endl;
	std::cout << "\t" << " 6 x " << numero << " = " << numero * 6 << std::endl;
	std::cout << "\t" << " 7 x " << numero << " = " << numero * 7 << std::endl;
	std::cout << "\t" << " 8 x " << numero << " = " << numero * 8 << std::endl;
	std::cout << "\t" << " 9 x " << numero << " = " << numero * 9 << std::endl;
	std::cout << "\t" << "10 x " << numero << " = " << numero * 10 << std::endl;
}