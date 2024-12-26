// 30. En una empresa de acuerdo a los méritos del trabajador se le asigna una nota de rendimiento(-1 a 1) que afecta a su nómina.Aunque es posible obtener un valor negativo por mal rendimiento la nómina nunca puede decrementar.Haz un programa que pregunte el sueldo del trabajador e individualmente los siguientes méritos.Al final debe de mostrar el sueldo del trabajador teniendo en cuenta que lo máximo que puede subir el sueldo es un 25 % si su rendimiento es de 1.

#include <iostream>

void main() {
	float puntuacion = 0.0, sueldo, aumento;
	bool limpieza, educacion, puntualidad, tareas, peloteo;

	std::cout << "Introduzca su sueldo: ";
	std::cin >> sueldo;
	std::cout << std::endl;

	std::cout << "De los siguientes meritos indique los que cumple (con un 1) y los que no cumple (con un 0): " << std::endl << std::endl;
	std::cout << "\t" << "-Limpieza del puesto de trabajo: ";
	std::cin >> limpieza;
	std::cout << "\t" << "-Educacion: ";
	std::cin >> educacion;
	std::cout << "\t" << "-Puntualidad: ";
	std::cin >> puntualidad;
	std::cout << "\t" << "-Pulido de las tareas: ";
	std::cin >> tareas;
	std::cout << "\t" << "-Peloteo al jefe: ";
	std::cin >> peloteo;

	if (limpieza > 0)
	{
		puntuacion += 0.2;
	}
	else
	{
		puntuacion -= 0.2;
	}
	if (educacion > 0)
	{
		puntuacion += 0.1;
	}
	else
	{
		puntuacion -= 0.1;
	}
	if (puntualidad > 0)
	{
		puntuacion += 0.15;
	}
	else
	{
		puntuacion -= 0.15;
	}
	if (tareas > 0)
	{
		puntuacion += 0.25;
	}
	else
	{
		puntuacion -= 0.25;
	}
	if (peloteo > 0)
	{
		puntuacion += 0.3;
	}
	else
	{
		puntuacion -= 0.3;
	}

	puntuacion++;

	aumento = puntuacion * 0.25 / 2;

	std::cout << std::endl << "Tu sueldo final es de " << sueldo * (1 + aumento) << " euros." << std::endl;
}