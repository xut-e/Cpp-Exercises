//15. Crea un programa que al introducir una velocidad en km / h y un tiempo en horas nos indique que distancia habremos recorrido en m.

#include <iostream>

void main() {
	float velocidadKmH;
	float horas;
	

	std::cout << "Introduce la velocidad aproximada en km/h: " << std::endl;
	std::cin >> velocidadKmH;
	std::cout << "Introduce el tiempo pasado aproximado en h: " << std::endl;
	std::cin >> horas;

	std::cout << "La distancia recorrida es de aproximadamente " << velocidadKmH * horas * 1000 << " m.";
}