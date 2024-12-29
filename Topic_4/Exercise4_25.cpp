/*  25.Modifica el ejercicio anterior para que el interior esté vacío. Ejemplo:
 * * * *
 *     *
 *     *
 * * * *    */
#include <iostream>


void main() {
	int numero;

	std::cout << "Introduce un numero: ";
	std::cin >> numero;

	for (int i = 1; i < numero + 1; i++)
	{
		for (int j = 1; j < numero + 1; j++)
		{
			if (i == 1 || j == 1 || i == numero || j == numero)
			{
				std::cout << "* ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}