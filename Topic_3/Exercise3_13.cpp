// 13. Consulta la página oficial de C++ y mira cómo funciona la funcionalidad de random.Intenta generar un valor numérico aleatorio entre 10 y 1, 000.

#include <iostream>
#include <time.h>
void main() {
	srand(time(0));

	int numeroAleatorio = rand() % (1000 - 10 + 1) + 10;

	std::cout << numeroAleatorio << std::endl;
}