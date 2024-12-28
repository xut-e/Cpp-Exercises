// 18. Crea un programa que permita al usuario añadir tantos números como quiera.Al final, cuando ya no quiera añadir más números el programa debe de mostrar el promedio de todos los números añadidos.

#include <iostream>
#include <string>

void main() {
	bool salir = false;
	std::string caracter;
	int suma = 0, contador = 0, numero;
	float resultado;

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
			suma += numero;
			contador++;
		}

	} while (!salir);

	if (contador == 0)
	{
		std::cout << "No se introdujeron numeros." << std::endl;
	}
	else
	{
		resultado = (float)suma / contador;
		std::cout << "El promedio de los numeros metidos es: " << resultado << std::endl;
	}
}