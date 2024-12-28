// 16.Crea un programa que pedirá un número al usuario y mostrará todos los números de forma descendente hasta llegar al 0. Asegúrate que no se pueden añadir números negativos, si es el caso debe pedir un nuevo número.

#include <iostream>

void main() {
	int numero;

	do
	{
		std::cout << "Introduce un numero: ";
		std::cin >> numero;

		if (numero < 0)
		{
			std::cout << "No se pueden utilizar numeros negativos." << std::endl;
		}
	} while (numero < 0);

	for (int i = numero; i >= 0 ; i--)
	{
		std::cout << i << std::endl;
	}
}