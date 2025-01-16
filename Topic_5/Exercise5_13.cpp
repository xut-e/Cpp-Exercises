/* 13. Crear un programa que busque un elemento en un array de enteros y
 devuelva su posición. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], posicionesElementoBuscado[times] = {}, elementoBuscado, cantidadEncontrada = 0, cantidadRestante;
	bool elementoBuscadoEncontrado = false;

	for (int i = 0; i < times; i++)
	{
		std::cout << "Introduzca la posicion " << i + 1 << " del vector: ";
		std::cin >> posicion;
		vector[i] = posicion;
	}

	std::cout << "Introduzca el elemento a buscar: ";
	std::cin >> elementoBuscado;

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
		if (elementoBuscado == vector[i])
		{
			elementoBuscadoEncontrado = true;
			posicionesElementoBuscado[i] = 1;
		}
	}

	if (!elementoBuscadoEncontrado)
	{
		std::cout << "El elemento " << elementoBuscado << " no se encuentra dentro del vector." << std::endl;
	}
	else
	{
		for (int i = 0; i < times; i++)
		{
			if (vector[i] == elementoBuscado)
			{
				cantidadEncontrada += 1;
			}
		}
		cantidadRestante = cantidadEncontrada;
		std::cout << "El elemento " << elementoBuscado << " se encuentra en la posicion: ";

		for (int i = 0; i < times; i++)
		{
			if (posicionesElementoBuscado[i] == 1 && cantidadRestante == 1)
			{
				std::cout << " y " << i + 1 << "." << std::endl;
			}
			else if (posicionesElementoBuscado[i] == 1 && cantidadEncontrada == cantidadRestante)
			{
				std::cout << i + 1;
				cantidadRestante -= 1;
			}
			else if (posicionesElementoBuscado[i] == 1)
			{
				std::cout << ", " << i + 1;
				cantidadRestante -= 1;
			}
		}
	}
}