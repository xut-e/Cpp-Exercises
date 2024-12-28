// 20.Crea un programa donde el usuario podrá añadir números sin parar hasta que lo indique.El programa debe de mostrar tras cada número cuál ha sido el número mayor introducido y cuál el menor hasta el momento siendo el mismo la primera vez que introduce un número.

#include <iostream>
#include <string>

void main() {
	bool salir = false;
	std::string caracter;
	int mayorNumero, menorNumero, numero, contador = 0;

	std::cout << "Bienvenido a la sumadora infinita (presione 'q' para salir)." << std::endl;

	do
	{
		bool numeroValido = true;

		std::cout << "Introduzca un numero: ";
		std::cin >> caracter;

		int i = 0;

		if (caracter[0] == '-')
		{
			i = 1;
		}

		while (i < caracter.length())
		{
			if (caracter[i] < '0' || caracter[i] > '9')
			{
				numeroValido = false;
				break;
			}
			i++;
		}

		if (caracter == "q" || caracter == "Q")
		{
			salir = true;
		}
		else if (!numeroValido)
		{
			std::cout << "Caracter no valido introducido." << std::endl;
		}
		else
		{
			numero = std::stoi(caracter);

			if (contador == 0)
			{
				mayorNumero = numero;
				menorNumero = numero;
			}
			
			if (numero > mayorNumero)
			{
				mayorNumero = numero;
			}
			else if (numero < menorNumero)
			{
				menorNumero = numero;
			}

			std::cout << "El mayor numero introducido es: " << mayorNumero << std::endl;
			std::cout << "El menor numero introducido es: " << menorNumero << std::endl;

			contador++;
		}

	} while (!salir);

	if (contador == 0)
	{
		std::cout << "No se introdujeron numeros." << std::endl;
	}
}