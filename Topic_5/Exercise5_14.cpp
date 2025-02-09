/* 14. Crear un programa que copie los elementos de un array a otro array uno a
 uno. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], vectorCopiado[times];

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
		vectorCopiado[i] = vector[i];
	}

	std::cout << "Su vector copiado es:" << std::endl;

	std::cout << "[";

	for (int i = 0; i < times; i++)
	{
		std::cout << vectorCopiado[i];

		if (i < times - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]" << std::endl;
}