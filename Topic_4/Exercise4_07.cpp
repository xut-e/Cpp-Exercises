//  7. Crea un programa que pida dos números al usuario. El primero será la cantidad de números a mostrar y el segundo los saltos entre números.El programa empezando por 0 mostrará tantos números como haya pedido el usuario pero saltando entre número y número la cantidad que haya indicado al usuario.

#include <iostream>

void main() {
	int cantidad, salto, numero = 0;

	std::cout << "Introduzca la cantidad de numeros que desea mostrar: ";
	std::cin >> cantidad;
	std::cout << "Introduzcca el salto entre numeros: ";
	std::cin >> salto;

	for (int i = 0; i < cantidad; i++)
	{
		std::cout << numero << std::endl;
		numero = numero + 3;
	}
}