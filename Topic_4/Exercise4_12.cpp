// 12. Crea un programa que imprima todas las tablas de multiplicar del 1 al 10 usando bucles anidados.

#include <iostream>

void main() {
	for (int i = 1; i < 11; i++)
	{
		std::cout << "Tabla del " << i << ":" << std::endl;
		for (int j = 0; j < 10; j++)
		{
			std::cout << i << " x " << j << " = " << i * j << std::endl;
		}
		std::cout << std::endl;
	}
}