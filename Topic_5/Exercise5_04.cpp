/* 4. Crear un programa que sume todos los elementos de un array de enteros. y
 luego muestre el resultado. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], sumaTotal = 0;

	for (int i = 0; i < times; i++)
	{
		std::cout << "Introduzca la posicion " << i + 1 << " del vector: ";
		std::cin >> posicion;
		vector[i] = posicion;
	}

	std::cout << "[";

	for (int i = 0; i < times; i++)
	{
		std::cout << vector[i];

		if (i < times - 1)
		{
			std::cout << ", ";
		}

		sumaTotal += vector[i];
	}

	std::cout << "]" << std::endl;

	std::cout << "La suma total es: " << sumaTotal << std::endl;
}