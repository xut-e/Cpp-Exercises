/* 24. Crear un programa que encuentre el segundo valor más grande en un array
 de enteros. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], maximo, maximoAnterior;

	for (int i = 0; i < times; i++)
	{
		std::cout << "Introduzca la posicion " << i + 1 << " del vector: ";
		std::cin >> posicion;
		vector[i] = posicion;
	}

	maximo = vector[0];

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
		if (vector[i] > maximo)
		{
			maximoAnterior = maximo;
			maximo = vector[i];
		}
	}

	std::cout << "El segundo valor maximo es " << maximoAnterior << "." << std::endl;
} 