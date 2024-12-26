//  2. Crea un programa que imprima todos los números pares que se encuentren entre el 0 y el 50 usando un bucle for.

#include <iostream>

void main() {
	for (int i = 0; i < 50; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << i << std::endl;
		}
	}
}