/* 24.El usuario introduce un número que representa el tamaño de un cuadrado. El programa debe de mostrar por pantalla un cuadrado formado por los caracteres* del mismo tamaño que el número introducido.Por ejemplo si es 4 el resultado debe ser :
****
****
****
**** */
#include <iostream>


void main() {
	int numero;

	std::cout << "Introduce un numero: ";
	std::cin >> numero;

	for (int i = 0; i < numero; i++)
	{
		for (int j = 0; j < numero; j++)
		{
			std::cout << "* ";
		}
		std::cout << std::endl;
	}
}