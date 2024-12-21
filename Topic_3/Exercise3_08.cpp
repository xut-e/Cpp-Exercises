// 8. Crea un programa que al iniciar pedirá el número de DNI y la letra por separado. El programa debe de confirmar si la letra insertada corresponde con el número de DNI.

#include <iostream>

void main() {
	int numeroDNI;
	char letraDNI;
	int restoDNI;

	std::cout << "Introduzca el numero de su DNI sin la letra: ";
	std::cin >> numeroDNI;
	std::cout << "Introduzca la letra de su DNI (en mayuscula): ";
	std::cin >> letraDNI;

	restoDNI = numeroDNI % 23;

	if (restoDNI == 0 && letraDNI == 'T')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 1 && letraDNI == 'R')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 2 && letraDNI == 'W')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 3 && letraDNI == 'A')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 4 && letraDNI == 'G')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 5 && letraDNI == 'M')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 6 && letraDNI == 'Y')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 7 && letraDNI == 'F')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 8 && letraDNI == 'P')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 9 && letraDNI == 'D')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 10 && letraDNI == 'X')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 11 && letraDNI == 'B')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 12 && letraDNI == 'N')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 13 && letraDNI == 'J')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 14 && letraDNI == 'Z')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 15 && letraDNI == 'S')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 16 && letraDNI == 'Q')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 17 && letraDNI == 'V')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 18 && letraDNI == 'H')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 19 && letraDNI == 'L')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 20 && letraDNI == 'C')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 21 && letraDNI == 'K')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else if (restoDNI == 22 && letraDNI == 'E')
	{
		std::cout << "La letra de su DNI es correcta." << std::endl;
	}
	else 
	{
		std::cout << "La letra de su DNI es incorrecta." << std::endl;
	}
}