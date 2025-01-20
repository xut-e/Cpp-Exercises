/* 30.Crear un programa que sume individualmente las columnas de una matriz y
las ordene de acuerdo al resultado de mayor a menor. Por ejemplo:
INPUT
{3, 5, 6}
{8, 9, 2}
{1, 6, 2}
Resultado Suma {12, 20, 10}
OUTPUT
{5, 3, 6}
{9, 8, 2}
{6, 1, 2} */

#include <iostream>

void main()
{
	const int filas = 3, columnas = 3;
	int matriz[filas][columnas], sumaColumnas[columnas] = {}, sumaColumna = 0;
    
	for (int i = 0; i < filas; i++)
	{
    	for (int j = 0; j < columnas; j++)
    	{
        	std::cout << "Introduzca la posicion (" << i + 1 << ", " << j + 1 << ") de la matriz: ";
        	std::cin >> matriz[i][j];
    	}
	}

	std::cout << "Su matriz es:" << std::endl;

	for (int i = 0; i < filas; i++)
	{
    	std::cout << "|";
   	 
    	for (int j = 0; j < columnas; j++)
    	{
        	std::cout << matriz[i][j];
       	 
        	if (j < columnas - 1)
        	{
            	std::cout << ", ";
        	}
    	}
   	 
    	std::cout << "|" << std::endl;
	}
    
	for (int j = 0; j < columnas; j++)
	{
    	for (int i = 0; i < filas; i++)
    	{
        	sumaColumnas[j] += matriz[i][j];
    	}
	}
    
	std::cout << "La suma de las columnas es:" << std::endl << "[";
    
	for (int i = 0; i < columnas; i++)
	{
    	std::cout << sumaColumnas[i];
   	 
    	if (i < columnas - 1)
    	{
        	std::cout << ", ";
    	}
	}
    
	std::cout << "]" << std::endl;
    
	for (int i = 0; i < columnas - 1; i++)
	{
    	for (int j = 0; j < columnas - i - 1; j++)
    	{
        	if (sumaColumnas[j] < sumaColumnas[j + 1])
        	{
            	int variableTemporal = sumaColumnas[j];
            	sumaColumnas[j] = sumaColumnas[j + 1];
            	sumaColumnas[j + 1] = variableTemporal;
           	 
            	for (int k = 0; k < filas; k++)
            	{
                	int tempCol = matriz[k][j];
                	matriz[k][j] = matriz[k][j + 1];
                	matriz[k][j + 1] = tempCol;
            	}
        	}
    	}
	}
	std::cout << "La suma de las columnas ordenada de mayor a menor es:" << std::endl << "[";
    
	for (int i = 0; i < columnas; i++)
	{
    	std::cout << sumaColumnas[i];
   	 
    	if (i < columnas - 1)
    	{
        	std::cout << ", ";
    	}
	}
    
	std::cout << "]" << std::endl;
    
	std::cout << "Su matriz ordenada es:" << std::endl;

	for (int i = 0; i < filas; i++)
	{
    	std::cout << "|";
   	 
    	for (int j = 0; j < columnas; j++)
    	{
        	std::cout << matriz[i][j];
       	 
        	if (j < columnas - 1)
        	{
            	std::cout << ", ";
        	}
    	}
   	 
    	std::cout << "|" << std::endl;
	}
}
