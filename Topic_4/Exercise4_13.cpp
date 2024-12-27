//  13.Crea un programa que pida al usuario un número de inicio y la cantidad de números sucesivos con los que hacer el cálculo.Para cada número el programa elevará el número a sí mismo y lo sumará con el siguiente.Por ejemplo, si el usuario introduce 2 y 3 el programa calculará : 2 ^ 2 + 3 ^ 3 + 4 ^ 4.

#include <iostream>

void main() {
	int numeroInicio, cantidad, resultado = 0;

	std::cout << "Introduce el numero de inicio: ";
	std::cin >> numeroInicio;
	std::cout << "Introduce la cantidad de numeros consecutivos: ";
	std::cin >> cantidad;

	for (int i = numeroInicio; i < (numeroInicio + cantidad); i++)
	{
		resultado += (i * i);
	}

	std::cout << "El resultado de la operacion es: " << resultado << std::endl;
}