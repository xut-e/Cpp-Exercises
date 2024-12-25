//  23. Crea un programa que le pida la edad al usuario y sus ingresos mensuales. Si es mayor de 18 años y sus ingresos anuales son superiores a 15, 000€ debe de indicarle que haga la declaración.

#include <iostream>

void main() {
	float ingresosMensuales;
	int edad;

	std::cout << "Introduce tu edad: ";
	std::cin >> edad;
	
	if (edad < 18)
	{
		std::cout << "No debes pagar impuestos." << std::endl;
		exit(0);
	}

	std::cout << "Introduce tus ingresos mensuales: ";
	std::cin >> ingresosMensuales;

	if ((ingresosMensuales * 12) > 15000)
	{
		std::cout << "Recuerda que debes hacer la declaracion de la renta." << std::endl;
	}
	else
	{
		std::cout << "No tienes por que hacer la declaracion de la renta." << std::endl;
	}
}