// 3. Crea un programa que pida un número al usuario y compute su factorial.

#include <iostream>

void main() {
	int numero;
	long factorial = 1;

	std::cout << "Introduzca un numero: ";
	std::cin >> numero;

	for (int i = 1; i <= numero; i++)
	{
		factorial *= i;
	}
	std::cout << "El factorial de " << numero << " es " << factorial << "." << std::endl;
}