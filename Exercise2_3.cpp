//3. Pregunta por pantalla el nombre del usuario y luego le saludas mencionando su nombre.

#include <iostream>

void main() {
	std::string nombre;

	std::cout << "Buenas, cual es tu nombre?: ";
	std::cin >> nombre;
	std::cout << "Encantado, " << nombre << std::endl;
}