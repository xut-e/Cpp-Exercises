//25. Crea un programa que al introducir una cantidad económica en euros nos muestre la combinación de billetes y monedas más eficiente para obtener esa cantidad.Por ejemplo, si introduzco 1, 124€ me debe de mostrar como resultado 2 billetes de 500€, 1 de 100€, 1 de 20€, y dos monedas de 4€.

#include <iostream>

void main() {
	float euros;
	

	std::cout << "Introduzca una cantidad de dinero en euros: ";
	std::cin >> euros;

	int eurosEnCentimos = euros * 100;

	//Billetes.

	int billetes500 = eurosEnCentimos / 50000;
	eurosEnCentimos -= billetes500 * 50000;

	int billetes200 = eurosEnCentimos / 20000;
	eurosEnCentimos -= billetes200 * 20000;

	int billetes100 = eurosEnCentimos / 10000;
	eurosEnCentimos -= billetes100 * 10000;

	int billetes50 = eurosEnCentimos / 5000;
	eurosEnCentimos -= billetes50 * 5000;

	int billetes20 = eurosEnCentimos / 2000;
	eurosEnCentimos -= billetes20 * 2000;

	int billetes10 = eurosEnCentimos / 1000;
	eurosEnCentimos -= billetes10 * 1000;

	int billetes5 = eurosEnCentimos / 500;
	eurosEnCentimos -= billetes5 * 500;

	//Monedas.

	int monedas2 = eurosEnCentimos / 200;
	eurosEnCentimos -= monedas2 * 200;

	int monedas1 = eurosEnCentimos / 100;
	eurosEnCentimos -= monedas1 * 100;

	int monedas05 = eurosEnCentimos / 50;
	eurosEnCentimos -= monedas05 * 50;

	int monedas02 = eurosEnCentimos / 20;
	eurosEnCentimos -= monedas02 * 20;

	int monedas01 = eurosEnCentimos / 10;
	eurosEnCentimos -= monedas01 * 10;

	int monedas005 = eurosEnCentimos / 5;
	eurosEnCentimos -= monedas005 * 5;

	int monedas002 = eurosEnCentimos / 2;
	eurosEnCentimos -= monedas002 * 2;

	int monedas001 = eurosEnCentimos / 1;
	eurosEnCentimos -= monedas001 * 1;

	std::cout << "El resultado mas eficiente es:" << std::endl;
	std::cout << "\t" << "- "  << billetes500 * (billetes500 > 0) << " billetes de 500 euros." << std::endl;
	std::cout << "\t" << "- " << billetes200 * (billetes200 > 0) << " billetes de 200 euros." << std::endl;
	std::cout << "\t" << "- " << billetes100 * (billetes100 > 0) << " billetes de 100 euros." << std::endl;
	std::cout << "\t" << "- " << billetes50 * (billetes50 > 0) << " billetes de 50 euros." << std::endl;
	std::cout << "\t" << "- " << billetes20 * (billetes20 > 0) << " billetes de 20 euros." << std::endl;
	std::cout << "\t" << "- " << billetes10 * (billetes10 > 0) << " billetes de 10 euros." << std::endl;
	std::cout << "\t" << "- " << billetes5 * (billetes5 > 0) << " billetes de 5 euros." << std::endl;

	std::cout << "\t" << "- " << monedas2 * (monedas2 > 0) << " monedas de 2 euros." << std::endl;
	std::cout << "\t" << "- " << monedas1 * (monedas1 > 0) << " monedas de 1 euros." << std::endl;
	std::cout << "\t" << "- " << monedas05 * (monedas05 > 0) << " monedas de 0.5 euros." << std::endl;
	std::cout << "\t" << "- " << monedas02 * (monedas02 > 0) << " monedas de 0.2 euros." << std::endl;
	std::cout << "\t" << "- " << monedas01 * (monedas01 > 0) << " monedas de 0.1 euros." << std::endl;
	std::cout << "\t" << "- " << monedas005 * (monedas005 > 0) << " monedas de 0.05 euros." << std::endl;
	std::cout << "\t" << "- " << monedas002 * (monedas002 > 0) << " monedas de 0.02 euros." << std::endl;
	std::cout << "\t" << "- " << monedas001 * (monedas001 > 0) << " monedas de 0.01 euros." << std::endl;
}