// 15. Crea un programa que genere un número aleatorio entre el 1 y el 20. El usuario tendrá 5 intentos para acertar ese número aleatorio.Si acierta el número se le informará de ello, si falla se le informará si el número a acertar es mayor o menor del dicho.

#include <iostream>
#include <time.h>
#include <cstdlib>

void main() {
	srand(time(0));

	int numeroAleatorio = rand() % (20 - 1 + 1) + 1, respuesta;

	srand(time(0));

	std::cout << "Intente adivinar el numero aleatorio entre 1 y 20: ";
	std::cin >> respuesta;

	if (respuesta == numeroAleatorio)
	{
		std::cout << "Enhorabuena, has acertado el numero!" << std::endl;
		exit(0);
	}
	else if (respuesta < numeroAleatorio)
	{
		std::cout << "El numero aleatorio es mayor que el numero introducido." << std::endl;
	}
	else
	{
		std::cout << "El numero aleatorio es menor que el numero introducido." << std::endl;
	}

	std::cout << "Segundo intento: ";
	std::cin >> respuesta;

	if (respuesta == numeroAleatorio)
	{
		std::cout << "Enhorabuena, has acertado el numero!" << std::endl;
		exit(0);
	}
	else if (respuesta < numeroAleatorio)
	{
		std::cout << "El numero aleatorio es mayor que el numero introducido." << std::endl;
	}
	else
	{
		std::cout << "El numero aleatorio es menor que el numero introducido." << std::endl;
	}

	std::cout << "Tercer intento: ";
	std::cin >> respuesta;

	if (respuesta == numeroAleatorio)
	{
		std::cout << "Enhorabuena, has acertado el numero!" << std::endl;
		exit(0);
	}
	else if (respuesta < numeroAleatorio)
	{
		std::cout << "El numero aleatorio es mayor que el numero introducido." << std::endl;
	}
	else
	{
		std::cout << "El numero aleatorio es menor que el numero introducido." << std::endl;
	}

	std::cout << "Cuarto intento: ";
	std::cin >> respuesta;

	if (respuesta == numeroAleatorio)
	{
		std::cout << "Enhorabuena, has acertado el numero!" << std::endl;
		exit(0);
	}
	else if (respuesta < numeroAleatorio)
	{
		std::cout << "El numero aleatorio es mayor que el numero introducido." << std::endl;
	}
	else
	{
		std::cout << "El numero aleatorio es menor que el numero introducido." << std::endl;
	}

	std::cout << "Quinto intento: ";
	std::cin >> respuesta;

	if (respuesta == numeroAleatorio)
	{
		std::cout << "Enhorabuena, has acertado el numero!" << std::endl;
		exit(0);
	}
	else if (respuesta < numeroAleatorio)
	{
		std::cout << "El numero aleatorio es mayor que el numero introducido." << std::endl;
	}
	else
	{
		std::cout << "El numero aleatorio es menor que el numero introducido." << std::endl;
	}
}