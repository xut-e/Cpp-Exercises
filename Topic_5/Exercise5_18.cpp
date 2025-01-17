/* 18. Crea un programa que identifique si una matriz se trata de una matriz
mágica. */

#include <iostream>

void main() {

	const int filas = 4, columnas = 4, diagonales = 2;
	int matriz[filas][columnas], numeroUsuario, numeroGuardado, sumaFilas[filas] = {}, sumaColumnas[columnas] = {}, sumaDiagonales[diagonales] = {};
	bool matrizMagica = true;

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
		std::cout << "Una matriz no cuadrada no puede ser magica." << std::endl;
	}
	else
	{
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				sumaFilas[i] += matriz[i][j];
			}
		}
		std::cout << std::endl;
		for (int i = 0; i < columnas; i++)
		{
			for (int j = 0; j < filas; j++)
			{
				sumaColumnas[i] += matriz[j][i];
			}

		}
		std::cout << std::endl;
		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				if (i == j)
				{
					sumaDiagonales[0] += matriz[i][j];
				}
				else if (i + j == filas - 1)
				{
					sumaDiagonales[1] += matriz[i][j];
				}
			}
		}
		for (int i = 0; i < filas; i++)
		{
			if (sumaFilas[i] != sumaFilas[0] || sumaColumnas[i] != sumaColumnas[0])
			{
				matrizMagica = false;
				break;
			}
		}	
		if (sumaFilas[0] != sumaColumnas[0] || sumaFilas[0] != sumaDiagonales[0] || sumaDiagonales[0] != sumaDiagonales[1])
		{
			matrizMagica = false;
		}
	}

	if (matrizMagica)
	{
		std::cout << "Su matriz es una matriz magica!" << std::endl;
	}
	else
	{
		std::cout << "Su matriz NO es una matriz magica." << std::endl;
	}
}