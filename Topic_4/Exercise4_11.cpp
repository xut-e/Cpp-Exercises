// 11. Crea un programa que pida un número al usuario y muestre su tabla de multiplicar del 0 al 9.

#include <iostream>

void main() {
	int numero;

	std::cout << "Introduzca un numero: ";
	std::cin >> numero;

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " x " << numero << " = " << i * numero << std::endl;
	}
}