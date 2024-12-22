// 17. Crea un programa que determine si una letra introducida es vocal o consonante.

#include <iostream>

void main() {
	char letra;

	std::cout << "Introduzca una letra: ";
	std::cin >> letra;

	if (letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u')
	{
		if (letra != '1' && letra != '2' && letra != '3' && letra != '4' && letra != '5' && letra != '6' && letra != '7' && letra != '8' && letra != '9' && letra != '0' && letra != 'º' && letra != '\'' && letra != '¡' && letra != '`' && letra != '+' && letra != '´' && letra != 'ç' && letra != ',' && letra != '.' && letra != '-' && letra != 'Ç')
		{
			std::cout << "La letra introducida es una consonante." << std::endl;
		}
		else
		{
			std::cout << "El carcater introducido no es una letra." << std::endl;
		}
	}
	else
	{
		std::cout << "La letra introducida es una vocal." << std::endl;
	}
}