/* 22. Crear un programa que sume dos arrays elemento por elemento y almacene
 el resultado en un tercer array. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector1[times], vector2[times], vector3[times];

	
	for (int i = 0; i < times; i++)
	{
		std::cout << "Introduzca la posicion " << i + 1 << " del vector 1: ";
		std::cin >> posicion;
		vector1[i] = posicion;
	}

	for (int i = 0; i < times; i++)
	{
		std::cout << "Introduzca la posicion " << i + 1 << " del vector 2: ";
		std::cin >> posicion;
		vector2[i] = posicion;
	}
	
	
	
	std::cout << "Su vector 1 es:" << std::endl;

	std::cout << "[";

	for (int i = 0; i < times; i++)
	{
		std::cout << vector1[i];

		if (i < times - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]" << std::endl;

	std::cout << "Su vector 2 es:" << std::endl;

	std::cout << "[";

	for (int i = 0; i < times; i++)
	{
		std::cout << vector2[i];

		if (i < times - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]" << std::endl;

	for (int i = 0; i < times; i++)
	{
		vector3[i] = vector1[i] + vector2[i];
	}

	std::cout << "Su vector suma es:" << std::endl;

	std::cout << "[";

	for (int i = 0; i < times; i++)
	{
		std::cout << vector3[i];

		if (i < times - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]" << std::endl;
}