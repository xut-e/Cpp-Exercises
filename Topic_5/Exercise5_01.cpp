// 1. Crear un programa que inicialice un array de enteros y muestre sus elementos en pantalla.

#include <iostream>

void main() {
	const int length = 5;
	int array[length];

	std::cout << "[";

	for (int i = 0; i < length; i++)
	{
		std::cout << i;

		if (i < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "]" << std::endl;
}