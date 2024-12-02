//6. Crea un programa que reciba dos números y ejecute las operaciones matemáticas (suma, resta, multiplicación, división, módulo) mostrando su resultado por pantalla.

#include <iostream>

void main() {
	int numeroUno;
	int numeroDos;

	std::cout << "Inserta un numero: " << std::endl;
	std::cin >> numeroUno;
	std::cout << "Inserta otro numero: " << std::endl;
	std::cin >> numeroDos;

	std::cout << "Suma: " << numeroUno + numeroDos << "\t" << "Resta: " << numeroUno - numeroDos << "\t" << "Multiplicacion: " << numeroUno * numeroDos << "\t" << "Division: " << numeroUno / numeroDos << "\t" << "Modulo: " << numeroUno % numeroDos <<std::endl;
}