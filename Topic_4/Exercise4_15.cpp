// 15. Crea un programa que pida un número al usuario y muestre en orden tal cantidad de números primos pero omitiendo 1 de cada 2 números a mostrar.

#include <iostream>

void main() {
	int numero, contador = 0, numeroPrimo = 2, contadorImpresos = 0;

	std::cout << "Introduce un numero: ";
	std::cin >> numero;

	while (contadorImpresos < numero)
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
			contador++;
			if (contador % 2 != 0)
			{
				std::cout << numeroPrimo << std::endl;
				contadorImpresos++;
			}
			
		}
		numeroPrimo++;
	}
}