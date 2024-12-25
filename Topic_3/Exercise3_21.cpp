//  21. Crea un programa que nos pregunte si queremos calcular el área de un círculo, un cuadrado o un triángulo.De acuerdo a lo que nos indique el usuario deberemos de preguntar los valores necesarios para su cálculo y seguidamente mostrar el resultado.Si no elige una opción válida debemos indicarlo.

#include <iostream>
#include <cmath>

void main() {
	double pi = std::atan(1) * 4;
	char opcion;
	std::cout << "CALCULADORA DE AREA" << std::endl;

	std::cout << "Puedes usar esta calculadora para calcular el area de un: " << std::endl << "\t" << "a) Circulo." << std::endl << "\t" << "b) Cuadrado." << std::endl << "\t" << "c) Triangulo." << std::endl << "Introduce a continuacion tu opcion elegida: ";
	std::cin >> opcion;

	switch (opcion)
	{
	case 'a': case 'A':
		float radio;

		std::cout << "Introduzca el radio de su circulo: ";
		std::cin >> radio;

		std::cout << "El area de su circulo equivale a " << pi * radio * radio << " unidades cuadradas." << std::endl;
		break;
	case 'b': case 'B':
		float lado;

		std::cout << "Introduzca el lado de su cuadrado: ";
		std::cin >> lado;

		std::cout << "El area de su cuadrado equivale a " << lado * lado << " unidades cuadradas." << std::endl;
		break;
	case 'c': case 'C':
		int caso;

		std::cout << "En este caso puede usar varios metodos para calcular el area de su triangulo dependiendo de los datos de los que disponga:" << std::endl << "\t" << "1) Base y altura." << std::endl << "\t" << "2) Tres lados." << std::endl << "\t" << "3) Dos lados y su angulo formado." << std::endl;
		
		std::cout << "Elija su opcion: ";
		std::cin >> caso;

		switch (caso)
		{
		case 1:
			float base, altura;

			std::cout << "Introduzca el valor de la base del triangulo: ";
			std::cin >> base;
			std::cout << "Introduzca el valor de la altura del triangulo: ";
			std::cin >> altura;

			std::cout << "El area de su triangulo equivale a " << 0.5 * base * altura << " unidades cuadradas." << std::endl;

			break;
		case 2:
			float lado1, lado2, lado3, semiperimetro;

			std::cout << "Introduzca el valor del lado a: ";
			std::cin >> lado1;
			std::cout << "Introduzca el valor del lado b: ";
			std::cin >> lado2;
			std::cout << "Introduzca el valor del lado c: ";
			std::cin >> lado3;

			semiperimetro = (lado1 + lado2 + lado3) / 2;
			
			std::cout << "El area de su triangulo equivale a " << sqrt(semiperimetro * (semiperimetro - lado1) * (semiperimetro - lado2) * (semiperimetro - lado3)) << " unidades cuadradas." << std::endl;

			break;
		case 3:
			float ladoA, ladoB, angulo;

			std::cout << "Introduzca el valor del lado a: ";
			std::cin >> ladoA;
			std::cout << "Introduzca el valor del lado b: ";
			std::cin >> ladoB;
			std::cout << "Introduce el angulo entre ellos en grados: ";
			std::cin >> angulo;

			std::cout << "El area de su triangulo equivale a " << 0.5 * ladoA * ladoB * sin(angulo * pi / 180) << " unidades cuadradas." << std::endl;


			break;
		default:
			std::cout << "La opcion introducida no es valida." << std::endl;
			break;
		}
		break;

	default:
		std::cout << "La opcion introducida no es valida." << std::endl;
		break;
	}
}