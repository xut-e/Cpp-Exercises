// 11. Crea un programa que haga la conversación de € a ¥, $ y £ usando valores actuales.

#include <iostream>

void main() {
	float euros;
	float tasaUSD = 1.05;
	float tasaJPY = 157.04;
	float tasaGBP = 0.83;

	std::cout << "Introduzca su cantidad en euros: " << std::endl;
	std::cin >> euros;

	std::cout << "El valor actual de sus " << euros << " euros es de:" << std::endl;
	std::cout << "\t" << "- " << euros * tasaUSD << " dolares americanos." << std::endl;
	std::cout << "\t" << "- " << euros * tasaJPY << " yenes (japoneses)." << std::endl;
	std::cout << "\t" << "- " << euros * tasaGBP << " libras esterlinas." << std::endl;
}