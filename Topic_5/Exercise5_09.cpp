/* 9. Crear un programa que cuente la cantidad de números pares en un array de
 números enteros. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], pares = 0;

	for (int i = 0; i < times; i++)
	{
		std::cout << "Introduzca la posicion " << i + 1 << " del vector: ";
		std::cin >> posicion;
		vector[i] = posicion;
	}

	std::cout << "Su vector es:" << std::endl;

	std::cout << "[";

	for (int i = 0; i < times; i++)
	{
		std::cout << vector[i];

		if (i < times - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]" << std::endl;

	for (int i = 0; i < times; i++)
	{
		if (vector[i] % 2 == 0)
		{
			pares++;
		}
	}

	std::cout << "El numero de pares en su vector es " << pares << "." << std::endl;
}