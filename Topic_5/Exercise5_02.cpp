//  2. Crea un programa que muestre todos los elementos de una matriz.

#include <iostream>

void main() {
	const int filas = 4, columnas = 2;

	int matriz[filas][columnas], contador = 0;;

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			matriz[i][j] = contador++;
		}
	}

	std::cout << " _";
	for (int i = 0; i < columnas; i++)
	{
		std::cout << "  ";
	}
	std::cout << "_ " << std::endl;

	for (int i = 0; i < filas; i++)
	{
		if (i < filas - 1)
		{
			std::cout << "| ";
		}
		else
		{
			std::cout << "|_";
		}

		for (int j = 0; j < columnas; j++)
		{
			std::cout << matriz[i][j];

			if (j < columnas - 1)
			{
				std::cout << ", ";
			}
		}

		if (i < filas - 1)
		{
			std::cout << " |" << std::endl;
		}
		else
		{
			std::cout << "_|" << std::endl;
		}

	}

}