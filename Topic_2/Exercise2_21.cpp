//21. Crea un programa que se le introduzca un día, un mes y un año y calcule cuantos segundos han pasado desde el 1 de enero del año 0.

#include <iostream>

void main() {
	long double dia;
	long double mes;
	long double anyo;

	std::cout << "Introduce el dia: ";
	std::cin >> dia;
	std::cout << "Introduce el mes: ";
	std::cin >> mes;
	std::cout << "Introduce el anyo: ";
	std::cin >> anyo;

	std::cout << "Desde el 1 de enero del anyo 0 han pasado " << (anyo * 365 + ((mes - 1) * 30) + dia) * 24 * 3600 << " segundos.";
}