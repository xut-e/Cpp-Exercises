/* 16. Crear un programa que encuentre la moda en un array de enteros. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], frecuenciaMaxima = 0, modas[times], cantidadModas = 0;

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
		int contador = 0;

		for (int j = 0; j < times; j++)
		{
			if (vector[j] == vector[i])
			{
				contador++;
			}
		}

		if (contador > frecuenciaMaxima)
		{
			frecuenciaMaxima = contador;
			modas[0] = vector[i];
			cantidadModas = 1;
		}
		else if (contador == frecuenciaMaxima)
		{
			bool agregado = false;

			for (int k = 0; k < cantidadModas; k++)
			{
				if (modas[k] == vector[i])
				{
					agregado = true;
					break;
				}
			}
			if (!agregado)
			{
				modas[cantidadModas] = vector[i];
				cantidadModas++;
			}
		}
	}

	if (frecuenciaMaxima == 1) {
		std::cout << "No hay moda, todos los numeros son diferentes." << std::endl;
	}
	else if (cantidadModas == 1) {
		std::cout << "La moda es " << modas[0] << " (aparece " << frecuenciaMaxima << " veces)." << std::endl;
	}
	else {
		std::cout << "Las modas son: ";
		for (int i = 0; i < cantidadModas; i++) {
			std::cout << modas[i];
			if (i < cantidadModas - 1) {
				std::cout << ", ";
			}
		}
		std::cout << " (aparecen " << frecuenciaMaxima << " veces cada una)." << std::endl;
	}
}