/* 25. Crear un programa que sustituya todos los números repetidos de un array
 por 0. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], aparecidos[times] = {0};

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
		bool repetido = false;

		for (int j = 0; j < i; j++)
		{
			if (vector[i] == aparecidos[j])
			{
				repetido = true;
				break;
			}
		}
		if (repetido)
		{
			vector[i] = 0;
		}
		else
		{
			aparecidos[i] = vector[i];
		}
	}

	std::cout << "Su vector nuevo es:" << std::endl;

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
} 