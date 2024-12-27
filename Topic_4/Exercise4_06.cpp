// 6. Crea un programa que pida la edad y el año de nacimiento del usuario. El programa debe de mostrar cuántos años tenía en cada año desde que nació.

#include <iostream>

void main() {
	int edad, anyoNacimiento;

	std::cout << "Introduzca su edad: ";
	std::cin >> edad;
	std::cout << "Introduzca su anyo de nacimiento: ";
	std::cin >> anyoNacimiento;

	for (int i = anyoNacimiento; i <= anyoNacimiento + edad; i++)
	{
		if (i < anyoNacimiento + edad)
		{
			std::cout << "En el anyo " << i << " tenia " << i - anyoNacimiento << " anyos." << std::endl;
		}
		else
		{
			std::cout << "En el anyo " << i << " tiene " << i - anyoNacimiento << " anyos." << std::endl;
		}
	}
}