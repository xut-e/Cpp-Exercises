#include <iostream>

void main() {
	float lado1, lado2, lado3;

	std::cout << "Introduzca el primer lado de su triangulo: ";
	std::cin >> lado1;
	std::cout << "Introduzca el segundo lado de su triangulo: ";
	std::cin >> lado2;
	std::cout << "Introduzca el tercer lado de su triangulo: ";
	std::cin >> lado3;

	if (lado1 == lado2) {
		if (lado2 == lado3) {
			std::cout << "Su triangulo es equilatero." << std::endl;
		}
		else {
			std::cout << "Su triangulo es isosceles." << std::endl;
		}
	}
	else {
		std::cout << "Su triangulo es escaleno." << std::endl;
	}
}