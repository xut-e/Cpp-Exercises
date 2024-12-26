//  26. Tenemos un restaurante de buffet libre que ofrece entrada gratuita a los niños menores de 4 años, entrada de 9€ a personas entre 4 y 17 años y entrada 18.95€ a mayores de 18 años.Haz un programa que pida la edad de 5 comensales y luego nos informe del total de beneficios obtenidos.

#include <iostream>

void main() {
	int edadComensal, grupoA = 0, grupoB = 0, grupoC = 0;

	std::cout << "Bienvenido al Buffet Libre ZAORI, por favor, introduzca la edad de los comensales: " << std::endl;
	std::cout << "Comensal 1: ";
	std::cin >> edadComensal;

	if (edadComensal < 4)
	{
		grupoA += 1;
	}
	else if (edadComensal > 18)
	{
		grupoC += 1;
	}
	else
	{
		grupoB += 1;
	}
	std::cout << "Comensal 2: ";
	std::cin >> edadComensal;

	if (edadComensal < 4)
	{
		grupoA += 1;
	}
	else if (edadComensal > 18)
	{
		grupoC += 1;
	}
	else
	{
		grupoB += 1;
	}
	std::cout << "Comensal 3: ";
	std::cin >> edadComensal;

	if (edadComensal < 4)
	{
		grupoA += 1;
	}
	else if (edadComensal > 18)
	{
		grupoC += 1;
	}
	else
	{
		grupoB += 1;
	}
	std::cout << "Comensal 4: ";
	std::cin >> edadComensal;

	if (edadComensal < 4)
	{
		grupoA += 1;
	}
	else if (edadComensal > 18)
	{
		grupoC += 1;
	}
	else
	{
		grupoB += 1;
	}
	std::cout << "Comensal 5: ";
	std::cin >> edadComensal;

	if (edadComensal < 4)
	{
		grupoA += 1;
	}
	else if (edadComensal > 18)
	{
		grupoC += 1;
	}
	else
	{
		grupoB += 1;
	}

	std::cout << "El beneficio final (sin contar los gastos de la comida) son: " << grupoB * 9 + grupoC * 18.95 << " euros. Gracias por su visita." << std::endl;
}