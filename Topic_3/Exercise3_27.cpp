// 27. Crea un programa que calcule la nota final a un alumno. El programa pedirá la nota del examen(60 % nota final), nota de los ejercicios(30 % nota final) y nota de actitud(10 % nota final).

#include <iostream>

void main() {
	float examen, ejercicios, actitud;

	std::cout << "Introduzca la nota del examen (60%): ";
	std::cin >> examen;
	std::cout << "Introduzca la nota de los ejercicios (30%): ";
	std::cin >> ejercicios;
	std::cout << "Introduzca la nota de la actitud (10%): ";
	std::cin >> actitud;

	std::cout << "Su nota final es de: " << examen * 0.60 + ejercicios * 0.3 + actitud * 0.1 << " puntos." << std::endl;
}