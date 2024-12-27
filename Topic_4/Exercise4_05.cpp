//   5. Crea un programa capaz de elevar un número a otro. El usuario añadirá la base y el exponente y seguidamente el programa mostrará el resultado.

#include <iostream>

void main() {
	int base, exponente, resultado = 1;

	std::cout << "Introduzca la base: ";
	std::cin >> base;
	std::cout << "Introduzca el exponente ";
	std::cin >> exponente;

	for (int i = 1; i <= exponente ; i++)
	{
		resultado = resultado * base;
	}

	std::cout << "El resultado de " << base << "^" << exponente << " es: " << resultado << std::endl;
}