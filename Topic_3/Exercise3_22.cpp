//  22. En una pizzería ofrecen pizzas vegetarianas y pizzas que no. Define un total de 8 pizzas distintas entre las que se encuentren ambos tipos.Cuando inicie el programa preguntará al usuario que tipo de pizza quiere y deberá de mostrar sólo las vegetarianas si se pide o en caso contrario debe de mostrarlas todas.El usuario deberá de elegir una de ellas y seguidamente el programa confirmará el pedido.Si elige una que no se encuentre en el menú informaremos de ello y finalizamos el programa.

#include <iostream>
#include <Windows.h>

void main() {
	std::string pizza1 = "Margarita", pizza2 = "Cuatro Quesos", pizza3 = "Verduras", pizza4 = "Pepperoni", pizza5 = "Hawaiana", pizza6 = "Mexicana", pizza7 = "BBQ", pizza8 = "Carnes Frias";
	int opcion, eleccion;

	std::cout << "PIZZERIA" << std::endl;
	std::cout << "Deseas una pizza exclusivamente vegetariana?: " << std::endl << "\t" << "1. Si." << std::endl << "\t" << "2. No." << std::endl << "Selecciona una opcion: ";
	std::cin >> opcion;

	if (opcion == 1)
	{
		std::cout << "Pizzas vegetarianas disponibles: " << std::endl;
		std::cout << "1. " << pizza1 << std::endl;
		std::cout << "2. " << pizza2 << std::endl;
		std::cout << "3. " << pizza3 << std::endl;

	}
	else if (opcion == 2)
	{
		std::cout << "Pizzas disponibles: " << std::endl;
		std::cout << "1. " << pizza1 << std::endl;
		std::cout << "2. " << pizza2 << std::endl;
		std::cout << "3. " << pizza3 << std::endl;
		std::cout << "4. " << pizza4 << std::endl;
		std::cout << "5. " << pizza5 << std::endl;
		std::cout << "6. " << pizza6 << std::endl;
		std::cout << "7. " << pizza7 << std::endl;
		std::cout << "8. " << pizza8 << std::endl;
	}
	else
	{
		std::cout << "Opcion no valida. Saliendo..." << std::endl;
		Sleep(1000);
		exit(0);
	}

	std::cout << "Seleccione la pizza deseada: ";
	std::cin >> eleccion;

	if (opcion == 1)
	{
		switch (eleccion)
		{
		case 1:
			std::cout << "Has pedido la pizza: " << pizza1 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		case 2:
			std::cout << "Has pedido la pizza: " << pizza2 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		case 3:
			std::cout << "Has pedido la pizza: " << pizza3 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		default:
			std::cout << "Esa pizza no se encuentra disponible." << std::endl;
			break;
		}
	}
	else
	{
		switch (eleccion)
		{
		case 1:
			std::cout << "Has pedido la pizza: " << pizza1 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		case 2:
			std::cout << "Has pedido la pizza: " << pizza2 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		case 3:
			std::cout << "Has pedido la pizza: " << pizza3 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		case 4:
			std::cout << "Has pedido la pizza: " << pizza4 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		case 5:
			std::cout << "Has pedido la pizza: " << pizza5 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		case 6:
			std::cout << "Has pedido la pizza: " << pizza6 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		case 7:
			std::cout << "Has pedido la pizza: " << pizza7 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		case 8:
			std::cout << "Has pedido la pizza: " << pizza8 << "." << std::endl;
			Sleep(1000);
			std::cout << "Preparando..." << std::endl;
			Sleep(1000);
			break;
		default:
			std::cout << "Esa pizza no se encuentra disponible." << std::endl;
			break;
		}
	}
}