//14. Crea un programa que pida 3 números al usuario y muestre el valor promedio de ellos.

#include <iostream>

void main() {
	float numero1;
	float numero2;
	float numero3;

	std::cout << "Introduzca el primer numero para hacer la media: " << std::endl;
	std::cin >> numero1;
	std::cout << "Introduzca el segundo numero para hacer la media: " << std::endl;
	std::cin >> numero2;
	std::cout << "Introduzca el tercer y ultimo numero para hacer la media: " << std::endl;
	std::cin >> numero3;

	std::cout << "La media de los tres numeros introducidos es: " << (numero1 + numero2 + numero3) / 3 << std::endl;
}