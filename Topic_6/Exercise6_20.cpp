/* 20. Crea un programa que pueda validar si una cadena de caracteres
introducida por el usuario tiene un formato de correo correcto:
nombre@dominio.dominio. */

#include <iostream>
#include <string>

int main() {
	std::string correo,nombre, dominio1, dominio2;
	bool formatoCorrecto;

	do
	{
		int contadorArrobas = 0, contadorPuntos = 0;
		formatoCorrecto = true;

		std::cout << "Introduce tu correo electronico (formato: nombre@dominio.dominio): ";
		std::getline(std::cin, correo);

		for (int i = 0; i < correo.length(); i++)
		{
			if (correo[i] == '@')
			{
				contadorArrobas++;
			}
			else if (correo[i] == '.')
			{
				contadorPuntos++;
			}
			else if (correo[i] == ' ')
			{
				std::cout << "Formato incorrecto." << std::endl;
				formatoCorrecto = false;
				break;
			}
		}
		if (formatoCorrecto)
		{
			if (contadorArrobas != 1 || contadorPuntos != 1)
			{
				std::cout << "Formato incorrecto." << std::endl;
				formatoCorrecto = false;
			}
			else if (formatoCorrecto)
			{
				int posicionArroba, posicionPunto;

				for (int i = 0; i < correo.length(); i++)
				{
					if (correo[i] == '@')
					{
						posicionArroba = i;
						break;
					}
					else
					{
						nombre += correo[i];
					}
				}

				for (int i = posicionArroba + 1; i < correo.length(); i++)
				{
					if (correo[i] == '.')
					{
						posicionPunto = i;
						break;
					}
					else
					{
						dominio1 += correo[i];
					}
				}

				for (int i = posicionPunto + 1; i < correo.length(); i++)
				{

					dominio2 += correo[i];

				}

				if (nombre.length() < 1 || dominio1.length() < 1 || dominio2.length() < 1)
				{
					std::cout << "Longitud invalida." << std::endl;
					formatoCorrecto = false;
				}
				else
				{
					for (int i = 0; i < dominio2.length(); i++)
					{
						if (dominio2[i] < 'A' || (dominio2[i] > 'Z' && dominio2[i] < 'a') || dominio2[i] > 'z')
						{
							std::cout << "El final del dominio no puede contener esos caracteres." << std::endl;
							formatoCorrecto = false;
							break;
						}
					}
				}
				
			}
		}

	} while (!formatoCorrecto);
	
	std::cout << "Correo electronico correcto. Tu correo es: " << nombre << "@" << dominio1 << "." << dominio2 << std::endl;

	return 0;
}

