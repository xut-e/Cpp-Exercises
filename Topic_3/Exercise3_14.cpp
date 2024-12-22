// 14. Crea un programa que genere aleatoriamente 2 números entre el 1 y el 10, los muestre al usuario y espere que introduzca el resultado de multiplicar ambas cifras e indique si ha acertado o no.

#include <iostream>
#include <time.h>

void main() {
	int numeroRespuesta;
	int numeroRandom1, numeroRandom2;

	srand(time(0));

	numeroRandom1 = rand() % (10 - 1 + 1) + 1;
	numeroRandom2 = rand() % (10 - 1 + 1) + 1;

	std::cout << "Responda el resultado de la siguiente multiplicacion: " << numeroRandom1 << " x " << numeroRandom2 << " = ";
	std::cin >> numeroRespuesta;

	if (numeroRespuesta == (numeroRandom1 * numeroRandom2))
	{
		std::cout << "Efectivamente ese es el resultado correcto." << std::endl;
	}
	else
	{
		std::cout << "El resultado correcto es " << numeroRandom1 * numeroRandom2 << "." << std::endl;
	}
}