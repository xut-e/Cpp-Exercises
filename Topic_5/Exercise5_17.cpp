/* 17. Crear un programa que calcule la media (promedio) de un array de números
enteros. */

#include <iostream>

void main() {

	int const times = 5;
	int posicion, vector[times], suma = 0;

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
		suma += vector[i];
	}

	float media = float(suma) / times;

	std::cout << "La media de los elementos de tu vector es " << media << "." << std::endl;
}
