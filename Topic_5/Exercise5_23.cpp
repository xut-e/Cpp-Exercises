/* 23. Crear un programa donde el usuario selecciona dos columnas de una matriz
 y les intercambia la posición. */

#include <iostream>

void main() {
	const int filas = 3, columnas = 3;
	int matriz[filas][columnas], columna1, columna2, columna1Vector[filas];

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

	std::cout << "Introduce una de las columnas a cambiar: ";
	std::cin >> columna1;
	columna1 -= 1;

	std::cout << "Introduce la otra columna a cambiar: ";
	std::cin >> columna2;
	columna2 -= 1;

	for (int i = 0; i < filas; i++)
	{
		columna1Vector[i] = matriz[i][columna1];
		matriz[i][columna1] = matriz[i][columna2];
	}

	for (int i = 0; i < filas; i++)
	{
		matriz[i][columna2] = columna1Vector[i];
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
}