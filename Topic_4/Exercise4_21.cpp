//  21.Crea un programa que permita al usuario insertar números infinitamente preguntando tras cada número si desea añadir otro o salir del programa. Cuando finalice debe de mostrar el mayor número impar introducido y la cantidad de números previos a este que se habían introducido, los números pares aunque no se tengan en cuenta para ser el mayor si deben de incluirse en el recuento de cantidad de números introducidos previamente.

#include <iostream>

void main() {
	bool salir = false;
	int numero, contador = 0, numeroMayor;

	do
	{
		std::cout << "Introduzca un numero: ";
		std::cin >> numero;
		if (contador == 0)
		{
			numeroMayor = numero;
		}

		if (numero % 2 != 0)
		{
			if (numeroMayor < numero)
			{
				numeroMayor = numero;
			}
		}
		contador++;

		std::cout << "Quieres salir del programa? (1 para salir, 0 para permanecer): ";
		std::cin >> salir;

	} while (!salir);

	if (numeroMayor % 2 != 0)
	{
		std::cout << "El mayor numero impar introducido es: " << numeroMayor << std::endl;
		std::cout << "La cantidad de numeros introducidos fue: " << contador << std::endl;
	}
	else
	{
		std::cout << "No se introdujo ningun numero impar." << std::endl;
		std::cout << "La cantidad de numeros introducidos fue: " << contador << std::endl;

	}
}