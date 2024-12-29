// 28. Crea un programa que pidiendo un número al usuario lo convierta a binario y lo muestre por pantalla.

#include <iostream>
#include <cmath>

void main() {
	int numero, bits;

	std::cout << "Introduce un numero: ";
	std::cin >> numero;

	if (numero < 0)
	{
		std::cout << "El numero debe ser positivo." << std::endl;
	}
	else
	{
		if (numero == 0)
		{
			bits = 1;
		}
		else
		{
			bits = std::log2(numero) + 1;
		}

		std::cout << "El numero " << numero << " en binario es: ";

		for (int i = bits - 1; i >= 0; i--)
		{
			if (numero / (std::pow(2, i)) >= 1)
			{
				std::cout << "1 ";
				numero -= std::pow(2, i);
			}
			else
			{
				std::cout << "0 ";
			}
		}
	}
}