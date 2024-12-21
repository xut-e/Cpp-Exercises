// 3. Crea un programa que determine si un número introducido por el usuario es múltiplo de otro.

#include <iostream>

void main() {
	int numeroUno;
	int numeroDos;

	std::cout << "Intruduce el primer numero: ";
	std::cin >> numeroUno;
	std::cout << "Intruduce el segundo numero: ";
	std::cin >> numeroDos;

	if (numeroDos % numeroUno == 0) {
		std::cout << numeroDos << " es multiplo de " << numeroUno << std::endl;
	}
	else if(numeroUno % numeroDos == 0) {
		std::cout << numeroUno << " es multiplo de " << numeroDos << std::endl;
	}
	else {
		std::cout << "Los numeros introducidos no son multiplos.";
	}
}