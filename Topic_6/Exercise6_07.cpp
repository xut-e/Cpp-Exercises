/* 7. Crea un programa que pida el nombre completo del usuario y sus apellidos.
 El programa luego debe de mostrar el nombre de esa persona bajo el
 formato de apellido1 apellido2, nombre. */

#include <iostream>
#include <string>

int main() {
	std::string nombreYApellidos;
	char nombre[20] = { 0 }, apellido1[20] = { 0 }, apellido2[20] = { 0 };
	int terminoNombre, terminoApellido1;

	std::cout << "Introduzca una palabra: ";
	std::getline(std::cin, nombreYApellidos);

	for (int i = 0; i < nombreYApellidos.length(); i++)
	{
		if (nombreYApellidos[i] == ' ')
		{
			terminoNombre = i;
			break;
		}
		nombre[i] = nombreYApellidos[i];
	}

	for (int i = terminoNombre + 1; i < nombreYApellidos.length(); i++)
	{
		if (nombreYApellidos[i] == ' ')
		{
			terminoApellido1 = i;
			break;
		}
		apellido1[i - (terminoNombre + 1)] = nombreYApellidos[i];
	}

	for (int i = terminoApellido1 + 1; i < nombreYApellidos.length(); i++)
	{
		if (nombreYApellidos[i] == '\0')
		{
			break;
		}
		apellido2[i - (terminoApellido1 + 1)] = nombreYApellidos[i];
	}

	std::cout << "Bienvenido, ";
	for (int i = 0; i < 15; i++)
	{
		if (apellido1[i] != ' ')
		{
			std::cout << apellido1[i];
		}
		else
		{
			break;
		}
	}

	std::cout << ' ';

	for (int i = 0; i < 15; i++)
	{
		if (apellido2[i] != ' ')
		{
			std::cout << apellido2[i];
		}
		else
		{
			break;
		}
	}

	std::cout << ", ";

	for (int i = 0; i < 15; i++)
	{
		if (nombre[i] != ' ')
		{
			std::cout << nombre[i];
		}
		else
		{
			break;
		}
	}
	
	std::cout << "." << std::endl;

	return 0;
}