//5. Genera un programa que obtenga el siguiente resultado (incluyendo el aspecto visual).


#include <iostream>
#include <string>
//Incluimos las librerías.

void main() {
	//Declaramos las variables necesarias.
	std::string nombre;
	unsigned short edad;
	std::string calle;
	unsigned short numeroCalle;

	//Pedimos los datos con el formato pedido.
	std::cout << "Dime tu nombre" << std::endl;
	std::cin >> nombre;
	std::cout << std::endl;
	std::cout << "Dime tu edad" << std::endl;
	std::cin >> edad;
	std::cout << std::endl;
	std::cin.ignore();
	std::cout << "Dime tu calle" << std::endl;
	std::getline(std::cin, calle);
	std::cout << std::endl;
	std::cout << "Dime munero de tu calle" << std::endl;
	std::cin >> numeroCalle;
	std::cout << std::endl;

	//Presentamos los datos con el formato pedido.
	std::cout << "===============" << std::endl;
	std::cout << "   Sus Datos   " << std::endl;
	std::cout << "===============" << std::endl;
	std::cout << "Su nombre es: " << nombre << std::endl;
	std::cout << "Su edad es: " << edad << std::endl;
	std::cout << "Usted vive en: " << calle << " " << numeroCalle << std::endl;
}