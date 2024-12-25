//  24. Tenemos 3 grupos de personas. Grupo A formado por hombres menores de 35 años.El grupo B formado por mujeres menores de 40 años y el grupo C formado por el resto de personas.Crea un programa que pida el sexo y la edad al usuario y le informe de que grupo le corresponde.

#include <iostream>

void main() {
	int edad;
	char genero;

	std::cout << "Introduce tu edad: ";
	std::cin >> edad;
	std::cout << "Introduce tu genero: " << std::endl << "\t" << "F) Femenino." << std::endl << "\t" << "M) Masculino." << std::endl;
	std::cin >> genero;
	switch (genero)
	{
	case 'm': case 'M':
		if (edad < 35)
		{
			std::cout << "Usted pertenece al grupo A." << std::endl;
		}
		else
		{
			std::cout << "Usted pertenece al grupo C." << std::endl;
		}
		break;
	case 'f': case 'F':
		if (edad < 40)
		{
			std::cout << "Usted pertenece al grupo B." << std::endl;
		}
		else
		{
			std::cout << "Usted pertenece al grupo C." << std::endl;
		}
		break;
	default:
		std::cout << "Grupo no valido." << std::endl;
		break;
	}
}