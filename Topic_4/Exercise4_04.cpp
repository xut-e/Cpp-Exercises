//  4. Crea un programa que pida dos números al usuario (origen y final). El programa irá recorriendo los números y de forma alternativa irá sumando y multiplicandolos entre ellos.Al final debe mostrar el resultado del cálculo.

#include <iostream>

void main() {
	int numeroOrigen, numeroDestino, contador = 0, resultado = 0;

	std::cout << "Introduzca el numero de origen: ";
	std::cin >> numeroOrigen;
	std::cout << "Introduzca el numero de destino: ";
	std::cin >> numeroDestino;

	if (numeroDestino <= numeroOrigen)
	{
		std::cout << "El numero de destino no puede ser menor o igual al numero de origen." << std::endl;
	}
	else
	{
		for (int i = numeroOrigen; i <= numeroDestino ; i++)
		{
			if (contador % 2 == 0)
			{
				resultado = resultado * i;
			}
			else
			{
				resultado = resultado + i;
			}
			contador++;
		}

		std::cout << "El resultado es " << resultado << "." << std::endl;
	}
}