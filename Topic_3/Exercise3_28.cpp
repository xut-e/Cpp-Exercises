//  28.Escribe un programa que pida una distancia en metros y de el resultado en kilómetros, hectómetros, decámetros y metros.Debe de escribir correctamente añadiendo, e y cuando corresponda y sin añadir unidades con valor 0. Por ejemplo al introducir 7037 metros el resultado esperado sería 7km, 3dam y 7m.

#include <iostream>

void main() {
	int metrosUsuario, kilometros, hectometros, decametros, metros;
	bool primeraUnidad = true;

	std::cout << "Introduzca una distancia en metros: ";
	std::cin >> metrosUsuario;
	
	kilometros = metrosUsuario / 1000;
	metrosUsuario -= kilometros * 1000;
	hectometros = metrosUsuario / 100;
	metrosUsuario -= hectometros * 100;
	decametros = metrosUsuario / 10;
	metrosUsuario -= decametros * 10;
	metros = metrosUsuario / 1;
	metrosUsuario -= metros * 1;

	std::cout << "La distancia es: ";

	if (kilometros > 0)
	{
		std::cout << kilometros << " km";
		primeraUnidad = false;
	}
	if (hectometros > 0)
	{
		if (!primeraUnidad)
		{
			if (decametros == 0 && metros == 0)
			{
				std::cout << " y ";
			}
			else
			{
				std::cout << ", ";
			}
		}
		
		std::cout << hectometros << " hm";
		primeraUnidad = false;
	}
	if (decametros > 0)
	{
		if (!primeraUnidad)
		{
			if (metros == 0)
			{
				std::cout << " y ";
			}
			else
			{
				std::cout << ", ";
			}
		}
		
		std::cout << decametros << " dam";
		primeraUnidad = false;
	}
	if (metros > 0)
	{
		if (!primeraUnidad)
		{
			std::cout << " y ";
		}
		std::cout << metros << " m";
	}
	std::cout << std::endl;
}