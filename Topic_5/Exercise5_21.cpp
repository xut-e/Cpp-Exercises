/* 21. Crear un programa que copie los números de un array a otro pero
 añadiendo primero los pares y luego los impares en el segundo array.
 */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], vectorNuevo[times], contadorPar = 0;

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
			vectorNuevo[contadorPar] = vector[i];
			contadorPar++;
		}
	}

	int contadorImpar = contadorPar;

	for (int i = 0; i < times; i++)
	{
		if (vector[i] % 2 != 0)
		{
			vectorNuevo[contadorImpar] = vector[i];
			contadorImpar++;
		}
	}

	std::cout << "Su nuevo vector es:" << std::endl;

	std::cout << "[";

	for (int i = 0; i < times; i++)
	{
		std::cout << vectorNuevo[i];

		if (i < times - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]" << std::endl;
}