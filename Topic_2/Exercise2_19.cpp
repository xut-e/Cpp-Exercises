//19. Crea un programa que pida la hora, minutos y segundos actuales al usuario y muestre el resultado en milisegundos.

#include <iostream>

void main() {
	int horas;
	int minutos;
	int segundos;

	std::cout << "A continuacuion introduce el tiempo pasado en horas, minutos y segundos: " << std::endl;
	std::cout << "Horas: ";
	std::cin >> horas;
	std::cout << "Minutos: ";
	std::cin >> minutos;
	std::cout << "Segundos: ";
	std::cin >> segundos;

	std::cout << "El tiempo pasado en milisegundos es: " << 1000 * (horas * 60 * 60 + minutos * 60 + segundos) << " milisegundos." << std::endl;
}