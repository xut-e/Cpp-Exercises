//10. Crea un programa que pida el radio de un círculo al usuario y con ello calcule su área y perímetro.

#include <iostream>
#include <cmath>

void main() {
	float radio;
	double pi = std::atan(1) * 4;
	std::cout << "Introduzca el radio de su circulo en metros: " << std::endl;
	std::cin >> radio;

	std::cout << "El area de su circulo es " << radio * radio * pi << " m cuadrados y el perimetro es " << 2 * pi * radio << " m." << std::endl;

}