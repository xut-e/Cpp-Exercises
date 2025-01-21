/* 26. Crear un programa que muestre el array en forma inversa, es decir, desde el
último elemento hasta el primero. */

#include <iostream>

int const times = 5;
int vector[times], posicion;

void main()
{
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
    
    
	std::cout << "Su vector del reves es:" << std::endl;
   	 
    	std::cout << "[";
    
	for (int i = times - 1; i >= 0; i--)
	{
    	std::cout << vector[i];
   	 
    	if (i > 0)
    	{
        	std::cout << ", ";
    	}
	}
    
	std::cout << "]";
}
