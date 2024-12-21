// 10. Tenemos 3 interruptores seguidos. Crea un programa que al iniciarse pregunte al usuario si están encendidos o apagados.El programa debe determinar si la bombilla a la que están conectados está encendida.La bombilla está encendida si dos interruptores consecutivos están encendidos.

#include <iostream>

void main() {
	bool interruptor1, interruptor2, interruptor3;

	std::cout << "Debes especificar si los interruptores estan encedidos (1) o apagados (0)." << std::endl;

	std::cout << "Primer interruptor: ";
	std::cin >> interruptor1;
	std::cout << "Segundo interruptor: ";
	std::cin >> interruptor2;
	std::cout << "Tercer interruptor: ";
	std::cin >> interruptor3;

	if ((interruptor1 && interruptor2) || (interruptor2 && interruptor3)) 
	{
		std::cout << "La bombilla esta encendida." << std::endl;
	}
	else
	{
		std::cout << "La bombilla esta apagada." << std::endl;
	}
}