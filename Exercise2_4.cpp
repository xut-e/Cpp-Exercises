#include <iostream>
#include <string>

void main() {
	std::string nombre;
	short unsigned edad;
	std::string comidaFavorita;

	std::cout << "Como te llamas?: ";
	std::cin >> nombre;
	std::cout << "Cuantos anyos tienes?: ";
	std::cin >> edad;
	std::cin.ignore();
	std::cout << "Cual es tu comida favorita?: ";
	std::getline(std::cin, comidaFavorita);
	std::cout << nombre << "\t" << edad << "\t" << comidaFavorita;
}