// 29. Crea un programa que pedirá al usuario una cantidad de dinero, el interés anual y durante cuántos años desea invertirlo.Debe de mostrar para cada año el beneficio obtenido anual y el beneficio total desde que inició la inversión.

#include <iostream>
#include <cmath>

void main() {
	float cantidad, interes, dineroGenerado, interesTotalGenerado = 0;
	int anyos;

	std::cout << "Introduce la cantidad de dinero que quieres invertir: ";
	std::cin >> cantidad;
	std::cout << "Introduce el interes generado por tu dinero (en porcentaje): ";
	std::cin >> interes;
	std::cout << "Introduce la cantidad de anyos durante la que quieres invertir: ";
	std::cin >> anyos;

	for (int i = 0; i < anyos; i++)
	{
		dineroGenerado = cantidad * std::pow(1 + interes / 100, i + 1) - cantidad;
		interesTotalGenerado += dineroGenerado;

		std::cout << "El beneficio obtenido durante el anyo " << i + 1 << " sera: " << dineroGenerado << " euros." << std::endl;
		std::cout << "El beneficio total desde el comienzo es de " << interesTotalGenerado << " euros." << std::endl;
		
		cantidad += dineroGenerado;
	}
}