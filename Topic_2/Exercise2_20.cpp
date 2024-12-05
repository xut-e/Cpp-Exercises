//20. Crea un programa que al introducir una cantidad de milisegundos muestre la cantidad de horas, minutos y segundos que representa.

#include <iostream>

void main() {
	int milisegundos;

	std::cout << "Introduce una cantidad de milisegundos para calcular a cuantas horas, minutos y segundos equivale: ";
	std::cin >> milisegundos;

	std::cout << "La cantidad de milisegundos introducida equivale a: " << milisegundos / 1000 / 3600 << " h " << milisegundos / 1000 % 3600 / 60 << " m " << milisegundos / 1000 % 60 << " s." << std::endl;
}