/* 28.Crear un programa que sume los elementos en posiciones impares de un
array y después les reste por aquellos números impares que se encuentren
en las posiciones pares del array. */

#include <iostream>

void main()
{
	int const times = 5;
	int posicion, vector[times], resultado = 0;

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
    
	for (int i = 0; i < times; i++)
	{
    	if (i % 2 == 0)
    	{
        	resultado += vector[i];
    	}
    	else
    	{
        	if (vector[i] % 2 != 0)
        	{
            	resultado -= vector[i];
        	}
    	}
	}
    
	std::cout << "El resultado de las operaciones pertinentes es: " << resultado << std::endl;
}
