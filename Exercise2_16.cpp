//16. Crea un programa que pida al usuario una distancia en metros y muestre su equivalente en millas, yardas, pies y pulgadas(Sistema Imperial).

#include <iostream>

void main() {
	float metros;
	

	std::cout << "Introduzca su distancia en metros: " << std::endl;
	std::cin >> metros;

	std::cout << "La coinversion de sus " << metros << " metros es de:" << std::endl;
	std::cout << "\t" << "- " << metros * 39.3701 / 12 / 3 / 1760 << " millas." << std::endl;
	std::cout << "\t" << "- " << metros * 39.3701 / 12 / 3<< " yardas." << std::endl;
	std::cout << "\t" << "- " << metros * 39.3701 / 12<< " pies." << std::endl;
	std::cout << "\t" << "- " << metros * 39.3701 << " pulgadas." << std::endl;
}