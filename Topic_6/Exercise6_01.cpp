/* 1. Crea un programa que identifique si una palabra empieza por mayuscula o
minuscula. */

#include <iostream>
#include <string>

int main() {
	std::string palabraUsuario;

	std::cout << "Introduzca una palabra: ";
	std::cin >> palabraUsuario;

	if (int(palabraUsuario[0]) >= 65 && int(palabraUsuario[0]) <= 90)
	{
		std::cout << "Su palabra \"" << palabraUsuario << "\" empieza por mayuscula." << std::endl;
	}
	else if (int(palabraUsuario[0]) >= 97 && int(palabraUsuario[0]) <= 122)
	{
		std::cout << "Su palabra \"" << palabraUsuario << "\" empieza por minuscula." << std::endl;
	}
	else
	{
		std::cout << "Su palabra \"" << palabraUsuario << "\" no empieza por una letra" << std::endl;
	}

    return 0;
}