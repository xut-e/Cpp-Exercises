// 17.Crea un programa que pida al usuario dos números. El programa debe de mencionar todos los números naturales que haya comprendidos entre ambos empezando siempre del menor al mayor.

#include <iostream>

void main() {
	int numeroInicio, numeroFin;

	std::cout << "Introduzca el numero de origen: ";
	std::cin >> numeroInicio;
	std::cout << "Introduzca el numero de fin: ";
	std::cin >> numeroFin;

	if (numeroInicio > numeroFin)
	{
		for (int i = numeroFin; i <= numeroInicio; i++)
		{
			std::cout << i << std::endl;
		}
	}
	else if (numeroInicio < numeroFin)
	{
		for (int i = numeroInicio; i <= numeroFin; i++)
		{
			std::cout << i << std::endl;
		}
	}
	else
	{
		std::cout << "El numero de inicio y el numero final no pueden ser el mismo." << std::endl;
	}
	
}