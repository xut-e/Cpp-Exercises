/* 27.Crear un programa que determine si un array es un palíndromo. */

#include <iostream>

int const times = 4;
char array[times], posicion;
bool palindromo = true;

void main()
{
	for (int i = 0; i < times; i++)
	{
    	std::cout << "Introduzca la posicion " << i + 1 << " del array: ";
    	std::cin >> posicion;
    	array[i] = posicion;
	}

	std::cout << "Su array es:" << std::endl;

	std::cout << "[";

	for (int i = 0; i < times; i++)
	{
    	std::cout << array[i];

    	if (i < times - 1)
    	{
        	std::cout << ", ";
    	}
	}

	std::cout << "]" << std::endl;
    
	if (times % 2 == 0)
	{
    	int posicionMitadIzquierda = times / 2 - 1, posicionMitadDerecha = times / 2;
   	 
    	for (int i = 0; i < times / 2; i++)
    	{
        	if (array[posicionMitadIzquierda - i] != array[posicionMitadDerecha + i])
        	{
            	palindromo = false;
            	break;
        	}
    	}
	}
	else
	{
    	float posicionMitad = float(times) / 2 - 0.5;
   	 
    	for (int i = 0; i < times / 2; i++)
    	{
        	if (array[int(posicionMitad) - i] != array[int(posicionMitad) + i])
        	{
            	palindromo = false;
            	break;
        	}
    	}
	}
    
	if (palindromo)
	{
    	std::cout << "Su array es un palindromo." << std::endl;
	}
	else
	{
    	std::cout << "Su array no es un palindromo." << std::endl;
	}
}
