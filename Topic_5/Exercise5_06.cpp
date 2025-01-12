/*  6. Crea un programa que para cada elemento de un array de enteros pida un
 número al usuario y lo multiplique por la posición del array equivalente,
 luego muestra el resultado. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], multiplicador;

	for (int i = 0; i < times; i++)
	{
		std::cout << "Introduzca la posicion " << i + 1 << " del vector: ";
		std::cin >> posicion;
		vector[i] = posicion * i;
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
}