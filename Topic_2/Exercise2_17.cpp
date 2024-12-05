//17. Crea un programa donde el usuario ingresa una cantidad económica, unas tasas de interés y unos meses.El programa debe de mostrar los intereses y el total con los intereses.

#include <iostream>
#include <cmath>

void main() {
	float dineroInicial;
	float interes;
	float meses;

	std::cout << "Introduce una cantidad de dinero: " << std::endl;
	std::cin >> dineroInicial;

	std::cout << "Introduce la tasa de interes anual en tanto por ciento: " << std::endl;
	std::cin >> interes;

	std::cout << "Introduce una cantidad de meses: " << std::endl;
	std::cin >> meses;

	std::cout << "Si el tipo de interes es simple:" << std::endl << "\t" << "- El interes generado sera: " << dineroInicial * (interes / 100) * (meses / 12) << std::endl << "\t" << "- El dinero total sera: " << dineroInicial * (interes / 100) * (meses / 12) + dineroInicial << std::endl;
	std::cout << "Si el tipo de interes es compuesto:" << std::endl << "\t" << "- El interes generado sera: " << dineroInicial * pow(1 + (interes / 100)/ 12, meses) - dineroInicial << std::endl << "\t" << "- El dinero total sera: " << dineroInicial * pow(1 + (interes / 100) / 12, meses) << std::endl;
}