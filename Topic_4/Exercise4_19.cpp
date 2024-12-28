// 19.Crea un programa que pida al usuario todos los números que quiera. El programa debe de gestionar dos resultados.Por un lado sumará de forma independiente los números impares y por otro lado los números pares mostrando el resultado al finalizar.

#include <iostream>
#include <string>

void main() {
	bool salir = false;
	std::string caracter;
	int sumaPar = 0, sumaImpar = 0, numero, contador = 0;

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
			if (numero % 2 == 0)
			{
				sumaPar += numero;
			}
			else
			{
				sumaImpar += numero;
			}
			contador++;
		}

	} while (!salir);

	if (contador == 0)
	{
		std::cout << "No se introdujeron numeros." << std::endl;
	}
	else
	{
		std::cout << "La suma de los numeros pares es: " << sumaPar << std::endl;
		std::cout << "La suma de los numeros impares es: " << sumaImpar << std::endl;
	}
}