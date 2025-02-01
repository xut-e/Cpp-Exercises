/* 2. Crea un programa que reciba un carácter y sea capaz de identificar si es
 una letra, un número u otra cosa. */

#include <iostream>

int main() {
	char caracterUsuario;

	std::cout << "Introduzca un caracter: ";
	std::cin >> caracterUsuario;

	if (int(caracterUsuario) >= 48 && int(caracterUsuario) <= 57)
	{
		std::cout << "Su caracter \"" << caracterUsuario << "\" es un numero." << std::endl;
	}
	else if (int(caracterUsuario) >= 65 && int(caracterUsuario) <= 90 || int(caracterUsuario) >= 97 && int(caracterUsuario) <= 122)
	{
		std::cout << "Su caracter \"" << caracterUsuario << "\" es una letra." << std::endl;
	}
	else
	{
		std::cout << "Su caracter \"" << caracterUsuario << "\" es un caracter especial." << std::endl;
	}

    return 0;
}