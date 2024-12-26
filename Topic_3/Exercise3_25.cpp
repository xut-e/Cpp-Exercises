//  25. Crea un programa que preguntara el tipo sanguíneo al usuario y a que grupo sanguíneo quiere donar.El programa debe indicar si es posible donar al grupo que desea.

#include <iostream>
#include <Windows.h>

void main() {
	std::string grupoDonante, grupoRecibidor;

	std::cout << "PUEDO DONAR?" << std::endl << "Grupos: " << std::endl << "\t" << "0-" << std::endl << "\t" << "0+" << std::endl << "\t" << "AB-" << std::endl << "\t" << "AB+" << std::endl << "\t" << "B-" << std::endl << "\t" << "B+" << std::endl << "\t" << "A-" << std::endl << "\t" << "A+" << std::endl << "Especifique su grupo sanguineo : ";
	std::cin >> grupoDonante;
	std::cout << "Indique a que grupo desea donar : ";
	std::cin >> grupoRecibidor;

	if (grupoRecibidor != "A+" && grupoRecibidor != "A-" && grupoRecibidor != "B+" && grupoRecibidor != "B-" && grupoRecibidor != "AB+" && grupoRecibidor != "AB-" && grupoRecibidor != "0+"&& grupoRecibidor != "0-")
	{
		std::cout << "Grupo de recibidor no existente." << std::endl;
		if (grupoRecibidor == "O+" || grupoRecibidor == "O-")
		{
			std::cout << "Asegurate de que has puesto 'cero' y no 'o'." << std::endl;
		}
		exit(0);
	}

	if (grupoDonante == "0-")
	{
		std::cout << "Puedes donar! :)" << std::endl;
	}
	else if (grupoDonante == "0+")
	{
		if (grupoRecibidor == "A+" || grupoRecibidor == "B+" || grupoRecibidor == "AB+" || grupoRecibidor == "0+")
		{
			std::cout << "Puedes donar! :)" << std::endl;
		}
		else
		{
			std::cout << "No puedes donar! :(" << std::endl;
		}
	}
	else if (grupoDonante == "AB-")
	{
		if (grupoRecibidor == "AB+" || grupoRecibidor == "AB-")
		{
			std::cout << "Puedes donar! :)" << std::endl;
		}
		else
		{
			std::cout << "No puedes donar! :(" << std::endl;
		}
	}
	else if (grupoDonante == "AB+")
	{
		if (grupoRecibidor == "AB+")
		{
			std::cout << "Puedes donar! :)" << std::endl;
		}
		else
		{
			std::cout << "No puedes donar! :(" << std::endl;
		}
	}
	else if (grupoDonante == "B-")
	{
		if (grupoRecibidor == "B+" || grupoRecibidor == "B-" || grupoRecibidor == "AB+" || grupoRecibidor == "AB-")
		{
			std::cout << "Puedes donar! :)" << std::endl;
		}
		else
		{
			std::cout << "No puedes donar! :(" << std::endl;
		}
	}
	else if (grupoDonante == "B+")
	{
		if (grupoRecibidor == "B+" || grupoRecibidor == "AB+")
		{
			std::cout << "Puedes donar! :)" << std::endl;
		}
		else
		{
			std::cout << "No puedes donar! :(" << std::endl;
		}
	}
	else if (grupoDonante == "A-")
	{
		if (grupoRecibidor == "A+" || grupoRecibidor == "A-" || grupoRecibidor == "AB+" || grupoRecibidor == "AB-")
		{
			std::cout << "Puedes donar! :)" << std::endl;
		}
		else
		{
			std::cout << "No puedes donar! :(" << std::endl;
		}
	}
	else if (grupoDonante == "A+")
	{
		if (grupoRecibidor == "A+" || grupoRecibidor == "AB+")
		{
			std::cout << "Puedes donar! :)" << std::endl;
		}
		else
		{
			std::cout << "No puedes donar! :(" << std::endl;
		}
	}
	else
	{
		std::cout << "Grupo donante no existente." << std::endl;
		if (grupoDonante == "O+" || grupoDonante == "O-" )
		{
			std::cout << "Asegurate de que has puesto 'cero' y no 'o'." << std::endl;
		}
	}
}