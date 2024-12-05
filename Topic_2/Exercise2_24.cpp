// 24. Crea un programa que dado una temperatura en Fahrenheit la convierte en Kelvin.

#include <iostream>

void main() {
	float farenheit;

	std::cout << "Introduce una temperatura en farenheit: ";
	std::cin >> farenheit;

	std::cout << farenheit << " F equivalen a " << (5.0 / 9.0) * (farenheit - 32) + 273.15 << " K." << std::endl;
}