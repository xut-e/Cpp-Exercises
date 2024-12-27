// 10.Crea un programa que irán sumando los números que le de el usuario infinitamente.Cada vez que sume un número le pedirá si quiere continuar o salir.Asegúrate que al menos pida un número usando el bucle do while.

#include <iostream>

void main() {
	int numero, resultado = 0;
	bool salir = 0;

	do
	{
		std::cout << "Introduzca un numero: ";
		std::cin >> numero;

		resultado += numero;

		std::cout << "Desea salir del programa y obtener el resultado?" << std::endl << "\t" << "-Salir (1)." << std::endl << "\t" << "-No salir (0)." << std::endl;
		std::cin >> salir;
	} while (!salir);

	std::cout << "El resultado de su suma es: " << resultado << std::endl;
}