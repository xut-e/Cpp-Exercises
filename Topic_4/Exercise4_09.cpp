// 9. Crea un programa que tenga hardcodeado un usuario y una contraseña. El usuario deberá de introducir ambos valores correctamente.El programa no finaliza hasta que los introduzca correctamente indicando al usuario si lo que ha introducido incorrecto es el usuario, la contraseña o ambas cosas.

#include <iostream>
#include <Windows.h>

void main() {

	std::string usuario = "admin", contrasenya = "adm1np@ssw0rd";
	std::string usuarioIntroducido, contrasenyaIntroducida;

	std::cout << "PORTAL DE INICIO DE SESION" << std::endl;

	do
	{
		std::cout << "Usuario: ";
		std::cin >> usuarioIntroducido;
		std::cout << "Contrasenya: ";
		std::cin >> contrasenyaIntroducida;

		if (usuarioIntroducido == usuario && contrasenyaIntroducida == contrasenya)
		{
			std::cout << "Inicio de sesion correcto." << std::endl;
			Sleep(500);
			std::cout << "Cargando..." << std::endl;
			Sleep(1000);
		}
		else
		{
			if (usuarioIntroducido != usuario && contrasenyaIntroducida != contrasenya)
			{
				std::cout << "Usuario y contrasenya incorrectos." << std::endl << "Intentelo de nuevo." << std::endl;
			}
			else if (usuarioIntroducido != usuario)
			{
				std::cout << "Usuario incorrecto." << std::endl << "Intentelo de nuevo." << std::endl;
			}
			else
			{
				std::cout << "Contrasenya incorrecta." << std::endl << "Intentelo de nuevo." << std::endl;
			}
		}
	} while (usuarioIntroducido != usuario || contrasenyaIntroducida != contrasenya);
}