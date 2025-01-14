/* 10. Crear un programa que pida 5 números al usuario. Luego ordenar estos
valores de mayor a menor en el array y mostrar el resultado. */

#include <iostream>

void main() {

	const int times = 5;
	int vector[times], numeroUsuario, numeroGuardado;
	
	for (int i = 0; i < times; i++)
	{
		std::cout << "Introduzca la posicion " << i + 1 << " del array: ";
		std::cin >> vector[i];
	}

	std::cout << "Su vector es:" << std::endl << "[";

	for (int i = 0; i < times; i++)
	{
		std::cout << vector[i];

		if (i < times - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]";

	
	
	for (int i = 0; i < times; i++)
	{
		for (int j = i + 1; j < times; j++)
		{
			if (vector[i] < vector[j])
			{
				numeroGuardado = vector[i];
				vector[i] = vector[j];
				vector[j] = numeroGuardado;
			}
		}
	}

	std::cout << std::endl << "Su vector ordenado de mayor a menor es:" << std::endl << "[";

	for (int i = 0; i < times; i++)
	{
		std::cout << vector[i];

		if (i < times - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]";
}
