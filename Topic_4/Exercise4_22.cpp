// 22. Al iniciar el programa este generará un número aleatorio entre 0 y 20. El usuario tendrá 5 intentos para acertar el número.Si no acierta el programa le indicará si el número a acertar es mayor o menor.Si no acierta tras los 5 intentos le indicara cuál era el número que debía acertar.

#include <iostream>
#include <time.h>

void main() {
	int contador = 0, numeroAleatorio, numero;
	srand(time(0));
	bool acierto = false;

	numeroAleatorio = rand() % (20 - 0 + 1) + 0;
	
	std::cout << "Introduzca un numero para adivinar: ";
	std::cin >> numero;

	while (contador < 5)
	{ 
		if (contador != 0)
		{
			std::cout << "Introduzca otro numero para adivinar: ";
			std::cin >> numero;
		}
		if (numero > numeroAleatorio)
		{
			std::cout << "El numero que debe adivinar es menor que el numero introducido." << std::endl;
		}
		else if (numero < numeroAleatorio)
		{
			std::cout << "El numero que debe adivinar es mayor que el numero introducido." << std::endl;
		}
		else
		{
			std::cout << "Enhorabuena! Has acertado el numero." << std::endl;
			acierto = true;
			break;
		}

		contador++;
	}

	if (!acierto)
	{
		std::cout << "El numero que debias acertar era: " << numeroAleatorio << std::endl;
	}
}