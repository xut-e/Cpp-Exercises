//13. Crea un programa que pida una cantidad en gramos y muestre de resultado su equivalencia en kilogramos y miligramos.

#include <iostream>

void main() {
	float gramos;

	std::cout << "Introduzca una cantidad en gramos: " << std::endl;
	std::cin >> gramos;

	std::cout << "La equivalencia de los " << gramos << " gramos que ha introducido es:" << std::endl;
	std::cout << "\t" << "- " << gramos / 1000 << " kilogramos." << std::endl;
	std::cout << "\t" << "- " << gramos * 1000 << " miligramos." << std::endl;
}