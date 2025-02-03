/* 6. Crea un programa que recibirá una palabra y modificará su primera letra. Si
 es en mayúscula la escribirá en minúscula y viceversa. */

#include <iostream>
#include <string>

int main() {
	std::string palabra;

	std::cout << "Introduzca una palabra: ";
	std::cin >> palabra;

	if (int(palabra[0]) >= 65 && int(palabra[0]) <= 90)
	{
		palabra[0] += 32;

		for (int i = 0; i < palabra.length(); i++)
		{
			std::cout << palabra[i];
		}
	}
	else if (int(palabra[0]) >= 97 && int(palabra[0]) <= 122)
	{
		palabra[0] -= 32;

		for (int i = 0; i < palabra.length(); i++)
		{
			std::cout << palabra[i];
		}
	}
	else
	{
		std::cout << "La primera letra es un caracter especial y no se puede cambiar." << std::endl;
	}


	return 0;
}