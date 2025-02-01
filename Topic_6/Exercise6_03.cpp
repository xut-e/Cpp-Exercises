/* 3. Haz un programa que pida al usuario 3 palabras y luego las muestre en
 pantalla separado por comas. */

#include <iostream>
#include <string>

int main() {
	int const length = 3;
	std::string palabras[length];

	for (int i = 0; i < length; i++)
	{
		std::cout << "Introduzca una palabra: ";
		std::cin >> palabras[i];
	}
	
	std::cout << "Sus palabras son: ";
	for (int i = 0; i < length; i++)
	{
		std::cout << palabras[i];

		if (i < length - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "." << std::endl;

    return 0;
}