// 18. Crea un programa que pregunte la edad al usuario y muestre por pantalla si es mayor de edad.

#include <iostream>

void main() {
	int edadUsuario;

	std::cout << "Introduzca su edad: ";
	std::cin >> edadUsuario;

	if (edadUsuario >= 18)
	{
		std::cout << "Eres mayor de edad, en Espanya." << std::endl;
	}
	else
	{
		std::cout << "Eres menor de edad, en Espanya." << std::endl;
	}
}