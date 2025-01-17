/*  20. Crear un programa que dado un array ya con elementos pida al usuario un
 número y una posición. El programa debe de “borrar” el elemento del array
 en la posición indicada. mover todos los elementos del array una posición
 ocupando el elemento a borrar y añadir el número del usuario en la última
 posición. Ejemplo {3,5 7}. El usuario introduce el número 1 y la posición 0.
 Resultado: {5, 7, 1}
 */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times], posicionBorrar, numeroAnyadir;

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

	std::cout << "Introduzca el numero que quiere insertar: ";
	std::cin >> numeroAnyadir;

	std::cout << "Ahora introduzca la posicion que desea eliminar: ";
	std::cin >> posicionBorrar;

	for (int i = posicionBorrar - 1; i < times; i++)
	{
		if (i == times - 1)
		{
			vector[times - 1] = numeroAnyadir;
		}
		else
		{
			vector[i] = vector[i + 1];
		}
	}

	std::cout << "Su nuevo vector es:" << std::endl;

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

}