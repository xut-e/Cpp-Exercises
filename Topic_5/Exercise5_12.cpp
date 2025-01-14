/* 12. Crea un programa que identifique si una matriz se trata de una matriz
identidad. */

#include <iostream>

void main() {

	const int filas = 3, columnas = 3;
	int matriz[filas][columnas], numeroUsuario, numeroGuardado, filaMatriz;
	
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			std::cout << "Introduzca la posicion (" << i + 1 << ", " << j + 1 << ") de la matriz: ";
			std::cin >> matriz[i][j];
		}
	}

	std::cout << "Su matriz es:" << std::endl;

	for (int i = 0; i < filas; i++)
	{
		std::cout << "|";

		for (int j = 0; j < columnas; j++)
		{
			std::cout << matriz[i][j];

			if (j < columnas - 1)
			{
				std::cout << ", ";
			}
		}

		std::cout << "|" << std::endl;
	}

	if (filas != columnas)
	{
		std::cout << "Una matriz no cuadrada no puede ser identidad." << std::endl;
	}
	else
	{
		for (int i = 0; i < filas; i++)
		{
			if (matriz[i][i] == 1)
			{
				filaMatriz = 0;

				for (int j = 0; j < columnas; j++)
				{
					filaMatriz += matriz[i][j];
				}
				if (filaMatriz == 1)
				{
					std::cout << "Esta matriz es identidad." << std::endl;
				}
				else
				{
					std::cout << "Esta matriz no es identidad." << std::endl;
				}
			}
			else
			{
				std::cout << "Esta matriz no es identidad." << std::endl;
			}
		}
	}
}
