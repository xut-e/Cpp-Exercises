/*  4. Crear un programa que pida una frase al usuario y cuente la cantidad de
 palabras que hay. */

#include <iostream>
#include <string>

int main() {
	std::string frase;
	int contadorPalabras = 1;

	std::cout << "Introduzca una frase: ";
	std::getline(std::cin, frase);

	for (int i = 0; i < frase.length(); i++)
	{
		if (frase[i] == ' '  && (frase[i + 1] != ' ' && frase[i + 1] != '\0'))
		{
			contadorPalabras++;
		}
	}

	std::cout << "La cantidad de palabras es " << contadorPalabras;

	return 0;
}