/* 5. Crear un programa que multiplique todos los elementos de un array por un
 número ingresado por el usuario y luego muestre el resultado. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], multiplicador;

	for (int i = 0; i < times; i++)
	{
		std::cout << "Introduzca la posicion " << i + 1 << " del vector: ";
		std::cin >> posicion;
		vector[i] = posicion;
	}

	std::cout << "A continuacion ingreese el numero por el que quiere multiplicar su vector: ";
	std::cin >> multiplicador;

	std::cout << "Su vector original es:" << std::endl;

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

	std::cout << "Su nuevo vector es:" << std::endl;

	std::cout << "[";

	for (int i = 0; i < times; i++)
	{
		std::cout << multiplicador * vector[i];

		if (i < times - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]" << std::endl;
}