/* 5. Crear un programa que pida una frase al usuario y cuente la cantidad de
 letras que hay. */

#include <iostream>
#include <string>

int main() {
	std::string frase;
	int contadorLetras = 0;

	std::cout << "Introduzca una frase: ";
	std::getline(std::cin, frase);

	for (int i = 0; i < frase.length(); i++)
	{
		if ((int(frase[i]) >= 65 && int(frase[i]) <= 90) || (int(frase[i]) >= 97 && int(frase[i]) <= 122))
		{
			contadorLetras++;
		}
	}

	std::cout << "La cantidad de letras es " << contadorLetras;

	return 0;
}