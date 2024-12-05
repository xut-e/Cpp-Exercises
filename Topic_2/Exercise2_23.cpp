// 23. Crea un programa que dada una temperatura en Fahrenheit la convierta en Celsius.
#include <iostream>

void main() {
	float farenheit;

	std::cout << "Introduce una temperatura en farenheit: ";
	std::cin >> farenheit;

	std::cout << farenheit << " F equivalen a " << (5.0 / 9.0) * (farenheit - 32) << " C." << std::endl;
}