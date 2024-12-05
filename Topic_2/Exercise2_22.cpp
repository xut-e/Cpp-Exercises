// 22. Crea un programa que pida al usuario una temperatura en grados Celsius y la pase a Fahrenheit y Kelvin.

#include <iostream>

void main() {
	float celsius;

	std::cout << "Introduce una temperatura en Celsius: ";
	std::cin >> celsius;

	std::cout << celsius << "C equivalen a:" << std::endl << "\t" << "- " << celsius + 273.15 << " K." << std::endl << "\t" << "- " << celsius * 9 / 5 + 32 << " F." << std::endl;
}