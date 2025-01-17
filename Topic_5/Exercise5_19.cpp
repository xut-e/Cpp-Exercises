/* 19. Crear un programa pida varios números al usuario y los almacene en un
array. Si ingresa un número ya existente debe de solicitar otro. */

#include <iostream>

void main() {
	int const times = 5;
	int posicion, vector[times] = {};
	bool repetido;

	
		for (int i = 0; i < times; i++)
		{
			repetido = false;
			do
			{
				std::cout << "Introduzca la posicion " << i + 1 << " del vector: ";
				std::cin >> posicion;

				for (int j = 0; j < i; j++)
				{
					if (posicion == vector[j])
					{
						repetido = true;
						std::cout << "Numero repetido." << std::endl;
						break;
					}
					else
					{
						repetido = false;
					}
				}
			} while (repetido);

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

}