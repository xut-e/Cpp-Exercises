// 12. Crea un programa que pida dos números al usuario. Debe de determinar cuál de los dos es el mayor o si son iguales.

#include <iostream>

void main() {
	float numero1, numero2;

	std::cout << "Introduce el primer numero: ";
	std::cin >> numero1;
	std::cout << "Introduce el segundo numero: ";
	std::cin >> numero2;

	if (numero1 > numero2)
	{
		std::cout << "El numero " << numero1 << " es mayor que el numero " << numero2 << "." << std::endl;
	}
	else if (numero1 < numero2)
	{
		std::cout << "El numero " << numero1 << " es menor que el numero " << numero2 << "." << std::endl;
	}
	else
	{
		std::cout << "El numero " << numero1 << " es igual que el numero " << numero2 << "." << std::endl;
	}
}