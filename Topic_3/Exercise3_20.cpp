//  20. Crea un programa que nos sirva para saber los ingredientes que pide un cliente para su bocadillo.El programa preguntará por 6 ingredientes distintos y luego debe de repetir sólo aquellos ingredientes que haya pedido el cliente.

#include <iostream>

void main() {
	std::string ing1 = "Lomo", ing2 = "Queso", ing3 = "Bacon", ing4 = "Tomate", ing5 = "Cebolla", ing6 = "Lechuga";
	bool res1, res2, res3, res4, res5, res6;

	std::cout << "A continuacion, seleccione los ingredientes que quiere (con un 1) y los que no quiere (con un 0)" << std::endl;
	std::cout << ing1 << ": ";
	std::cin >> res1;
	std::cout << ing2 << ": ";
	std::cin >> res2;
	std::cout << ing3 << ": ";
	std::cin >> res3;
	std::cout << ing4 << ": ";
	std::cin >> res4;
	std::cout << ing5 << ": ";
	std::cin >> res5;
	std::cout << ing6 << ": ";
	std::cin >> res6;

	std::cout << "Su bocadillo se vera tal que: " << std::endl;
	std::cout << "PAN" << std::endl;
	if (res1 == 1)
	{
		std::cout << ing1 << std::endl;
	}
	if (res2 == 1)
	{
		std::cout << ing2 << std::endl;
	}
	if (res3 == 1)
	{
		std::cout << ing3 << std::endl;
	}
	if (res4 == 1)
	{
		std::cout << ing4 << std::endl;
	}
	if (res5 == 1)
	{
		std::cout << ing5 << std::endl;
	}
	if (res6 == 1)
	{
		std::cout << ing6 << std::endl;
	}
	std::cout << "PAN" << std::endl;
}