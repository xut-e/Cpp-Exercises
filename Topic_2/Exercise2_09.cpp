//9. Crea un programa que pida al usuario el lado de un cuadrado y con ello calcule su área.

#include <iostream>

void main() {
	float ladoCuadrado;

	std::cout << "Ingrese el lado de su cuadrado (en metros): " << std::endl;
	std::cin >> ladoCuadrado;

	std::cout << "El area de su cuadrado es " << ladoCuadrado * ladoCuadrado << " metros cuadrados." << std::endl;
}