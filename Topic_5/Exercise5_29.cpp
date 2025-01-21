/* 29. Crear un programa que calcule el resultado en multiplicar el elemento mayor
y el elemento menor de un array. */

#include <iostream>

void main()
{
	int const times = 5;
	int posicion, vector[times], menor, mayor;

	for (int i = 0; i < times; i++)
	{
    	std::cout << "Introduzca la posicion " << i + 1 << " del vector: ";
    	std::cin >> posicion;
    	vector[i] = posicion;
	}

	std::cout << "Su vector es:" << std::endl;

	std::cout << "[";

	for (int i = 0; i < times; i++)
	{
    	std::cout << vector[i];

    	if (i < times - 1)
    	{
        	std::cout << ", ";
    	}
	}

	std::cout << "]" << std::endl;
    
	menor = vector[0];
	mayor = vector[0];
    
	for (int i = 0; i < times; i++)
	{
    	if (vector[i] < menor)
    	{
        	menor = vector[i];
    	}
    	else if (vector[i] > mayor)
    	{
        	mayor = vector[i];
    	}
	}
    
	std::cout << "El resultado de multiplicar el menor elemento del array por el mayor es: " << mayor * menor << std::endl;
}
