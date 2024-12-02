#include <iostream>

void main() {
	int numeroPedido;
	std::cout << "Introduce un numero de 6 cifras: " << std::endl;
	std::cin >> numeroPedido;

	std::cout << "Unidades: " << numeroPedido % 10 << std::endl;
	std::cout << "Decenas: " << (numeroPedido / 10) % 10 << std::endl;
	std::cout << "Centenas: " << (numeroPedido / 100) % 10 << std::endl;
	std::cout << "Unidades de millar: " << (numeroPedido / 1000) % 10 << std::endl;
	std::cout << "Decenas de millar: " << (numeroPedido / 10000) % 10 << std::endl;
	std::cout << "Centenas de millar: " << (numeroPedido / 100000) % 10 << std::endl;
}