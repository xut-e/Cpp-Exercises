// 11. Crea un programa que pida dos números para luego dividirlos, sin embargo debe de tener en cuenta que no es posible dividir algo entre 0.

#include <iostream>

void main() {
	float dividendo, divisor;

	std::cout << "Introduce el dividendo: ";
	std::cin >> dividendo;
	std::cout << "Introduce el divisor: ";
	std::cin >> divisor;

	if (divisor != 0) 
	{
		std::cout << "El resultado de la division es " << dividendo / divisor << "." << std::endl;
	}
	else
	{
		std::cout << "No es posible dividir entre 0." << std::endl;
	}
}