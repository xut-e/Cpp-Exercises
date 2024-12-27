// 14. Crea un programa que pida un número al usuario y muestre en orden tal cantidad de números primos empezando por el 1.

#include <iostream>

void main() {
	int numero, contador = 0, numeroPrimo = 2;

	std::cout << "Introduce un numero: ";
	std::cin >> numero;

	while (contador < numero)
	{
		bool esPrimo = true;

		for (int i = 2; i < numeroPrimo; i++)
		{
			if (numeroPrimo % i == 0)
			{
				esPrimo = false;
				break;
			}
		}
		if (esPrimo)
		{
			std::cout << numeroPrimo << std::endl;
			contador++;
		}
		numeroPrimo++;
	}
}