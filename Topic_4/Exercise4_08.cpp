//  8. Crea un programa que pida al usuario letras. El usuario puede empezar con una vocal o una consonante, mientras vaya alternando entre vocal y consonante el programa seguirá pidiendo más letras.Si en algún momento el usuario no alterna entre ambas el programa finaliza mostrando al usuario la cantidad de letras totales que ha alternado.

#include <iostream>
#include <Windows.h>

void main() {
	char letraActual, letraAnterior;
	int contador = 0;
	bool esVocalActual, esVocalAnterior;

	std::cout << "Ingrese una letra: ";
	std::cin >> letraActual;

	if (!((letraActual >= 'A' && letraActual <= 'Z') || (letraActual >= 'a' && letraActual <= 'z')))
	{
		std::cout << "Debe introducir una LETRA." << std::endl;
		exit(1);
	}

	if (letraActual >= 'A' && letraActual <= 'Z')
	{
		letraActual = letraActual + ('a' - 'A');
	}

	esVocalActual = (letraActual == 'a' || letraActual == 'e' || letraActual == 'i' || letraActual == 'o' || letraActual == 'u');
	letraAnterior = letraActual;
	esVocalAnterior = esVocalActual;
	contador++;

	while (true)
	{
		std::cout << "Ingrese otra letra: ";
		std::cin >> letraActual;

		if (!((letraActual >= 'A' && letraActual <= 'Z') || (letraActual >= 'a' && letraActual <= 'z')))
		{
			std::cout << "Debe introducir una LETRA." << std::endl;
			exit(1);
		}

		if (letraActual >= 'A' && letraActual <= 'Z')
		{
			letraActual = letraActual + ('a' - 'A');
		}

		esVocalActual = (letraActual == 'a' || letraActual == 'e' || letraActual == 'i' || letraActual == 'o' || letraActual == 'u');

		if (esVocalActual == esVocalAnterior)
		{
			std::cout << "No has alternado entre vocales y consonantes." << std::endl << "Total de letras alternadas: " << contador << std::endl;
			break;
		}
		letraAnterior = letraActual;
		esVocalAnterior = esVocalActual;
		contador++;
	}
}