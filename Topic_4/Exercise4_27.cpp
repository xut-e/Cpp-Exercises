// 27. Replicando el ejercicio anterior en este caso crea un programa que genere el árbol de forma invertida.

#include <iostream>


void main() {
	int numero;

	std::cout << "Introduce un numero: ";
	std::cin >> numero;

	for (int i = numero; i >= 1; i--)
	{
		for (int j = 0; j < numero - i; j++)
		{
			std::cout << " ";
		}
		for (int k = 1; k < i; k++)
		{
			std::cout << "* ";
		}
		std::cout << std::endl;
	}
}