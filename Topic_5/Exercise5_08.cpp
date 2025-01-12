/* 8. Crear un programa que identifique el número mayor y menor de cada
 columna de una matriz bidimensional. */

#include <iostream>

void main() {
	int const timesFilas = 5, timesColumnas = 3;
	int posicion, matriz[timesFilas][timesColumnas], maximo, minimo;

	for (int i = 0; i < timesFilas; i++)
	{
		for (int j = 0; j < timesColumnas; j++)
		{
			std::cout << "Introduzca la posicion (" << i + 1 << ", " << j + 1 << ") de la matriz: ";
			std::cin >> posicion;
			matriz[i][j] = posicion;
		}
	}

	minimo = matriz[0][0];
	maximo = matriz[0][0];

	std::cout << "Tu matriz es:" << std::endl;
	
	for (int i = 0; i < timesFilas; i++)
	{
		std::cout << "|";
		for (int j = 0; j < timesColumnas; j++)
		{
			std::cout << matriz[i][j];

			if (matriz[i][j] < minimo)
			{
				minimo = matriz[i][j];
			}
			if (matriz[i][j] > maximo)
			{
				maximo = matriz[i][j];
			}

			if (j < timesColumnas - 1)
			{
				std::cout << ", ";
			}
		}

		std::cout << "|" << std::endl;
	}

	std::cout << "El numero menor en su vector es " << minimo << " y el mayor es " << maximo << "." << std::endl;
}