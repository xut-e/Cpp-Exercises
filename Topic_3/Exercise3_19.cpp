// 19. Crea un programa que tenga almacenado un usuario y una contraseña. Al iniciarse preguntará ambos datos al usuario y mostrará por pantalla si el acceso es correcto o si ha cometido un error en el usuario, la contraseña o ambas cosas.

#include <iostream>
#include <Windows.h>

void main() {
	std::string usuario = "admin", contrasenya = "adm1np@ssw0rd";
	std::string usuarioIntroducido, contrasenyaIntroducida;

	std::cout << "PORTAL DE INICIO DE SESION" << std::endl;
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
			std::cout << "Usuario y contrasenya incorrectos." << std::endl;
		}
		else if (usuarioIntroducido != usuario)
		{
			std::cout << "Usuario incorrecto." << std::endl;
		}
		else
		{
			std::cout << "Contrasenya incorrecta." << std::endl;
		}
	}
}