/* 7. Crear un programa que recorre un array de enteros y luego muestre el valor
 máximo y el valor mínimo. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], multiplicador, maximo, minimo;

	for (int i = 0; i < times; i++)
	{
		std::cout << "Introduzca la posicion " << i + 1 << " del vector: ";
		std::cin >> posicion;
		vector[i] = posicion;
	}

	maximo = vector[0];
	minimo = vector[0];

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
		if (vector[i] < minimo)
		{
			minimo = vector[i];
		}
		if (vector[i] > maximo)
		{
			maximo = vector[i];
		}
	}

	std::cout << "El numero menor en su vector es " << minimo << " y el mayor es " << maximo << "." << std::endl;
}