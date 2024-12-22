// 16. Crea un programa que pida un año de origen y un año de destino y calcule los años que han pasado, los años que faltan para llegar o si se tratan del mismo año.

#include <iostream>

void main() {
	int anyoOrigen, anyoDestino, anyoActual = 2024;

	std::cout << "Introduzca el anyo de origen: ";
	std::cin >> anyoOrigen;
	std::cout << "Introduzca el anyo de destino: ";
	std::cin >> anyoDestino;

	if (anyoOrigen == anyoDestino)
	{
		std::cout << "Es el mismo anyo." << std::endl;
	}
	else if (anyoOrigen == anyoActual)
	{
		std::cout << "Faltan " << anyoDestino - anyoActual << " anyos para llegar." << std::endl;
	}
	else
	{
		std::cout << "Han pasado " << anyoDestino - anyoOrigen << " anyos." << std::endl;
	}
}