/* 33. Crea un programa que simule el juego de la ruleta pero sólo con colores. El
 jugador tendrá 500€ y antes de iniciar la ronda podrá elegir cuánto apostar y
 a que color. Si acierta duplica lo apostado. Pierde si se queda sin dinero y
 gana al alcanzar los 2,000€. */


#include <iostream>
#include <time.h>

void main() {
	int apuesta, apuestaGanadora, cantidadApostada, dineroActual = 500;

	srand(time(0));

	std::cout << "Bienvenido a RULETA DE CASINO" << std::endl;

	do
	{
		do
		{
			do
			{
				std::cout << "Introduzca la cantidad de dinero que quiere apostar: ";
				std::cin >> cantidadApostada;

				if (cantidadApostada > dineroActual && cantidadApostada > 0)
				{
					std::cout << "No puedes apostar tanto dinero, solo dispones de " << dineroActual << " euros." << std::endl;
				}
				else if (cantidadApostada <= 0)
				{
					std::cout << "No puedes no apostar o apostar numeros negativos." << std::endl;
				}

			} while (cantidadApostada > dineroActual || cantidadApostada <= 0);

			dineroActual -= cantidadApostada;

			std::cout << "Las apuestas permitidas son:" << std::endl << "\t" << "1) Rojo." << std::endl << "\t" << "2) Negro." << std::endl << "\t" << "3) Verde (cero)." << std::endl;

			do
			{
				std::cout << "Introduzca su apuesta: ";
				std::cin >> apuesta;

				if (apuesta != 1 && apuesta != 2 && apuesta != 3)
				{
					std::cout << "Apuesta no valida." << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}
			} while (apuesta != 1 && apuesta != 2 && apuesta != 3);
			
			int numeroAleatorio = rand() % (36 - 0 + 1) + 0;

			if (numeroAleatorio == 0)
			{
				apuestaGanadora = 3;
			}
			else if (numeroAleatorio % 2 == 0 && numeroAleatorio != 0)
			{
				apuestaGanadora = 1;
			}
			else if (numeroAleatorio % 2 != 0 && numeroAleatorio != 0)
			{
				apuestaGanadora = 2;
			}
			

			switch (apuesta)
			{
			case 1:

				if (apuesta == apuestaGanadora)
				{
					std::cout << "Apuesta ganada! Has ganado " << cantidadApostada * 2 << " euros." << std::endl;
					dineroActual += cantidadApostada * 2;
				}
				else
				{
					std::cout << "Has perdido tu apuesta de " << cantidadApostada << " euros." << std::endl;
				}
				break;
			case 2:
				if (apuesta == apuestaGanadora)
				{
					std::cout << "Apuesta ganada! Has ganado " << cantidadApostada * 2 << " euros." << std::endl;
					dineroActual += cantidadApostada * 2;
				}
				else
				{
					std::cout << "Has perdido tu apuesta de " << cantidadApostada << " euros." << std::endl;
				}
				break;
			case 3:
				if (apuesta == apuestaGanadora)
				{
					std::cout << "Apuesta ganada! Has ganado " << cantidadApostada * 36 << " euros." << std::endl;
					dineroActual += cantidadApostada * 36;
				}
				else
				{
					std::cout << "Has perdido tu apuesta de " << cantidadApostada << " euros." << std::endl;
				}
				break;
			default:
				std::cout << "Opcion no valida." << std::endl;
				break;
			}
		} while (apuesta != 1 && apuesta != 2 && apuesta != 3);
		
	} while (dineroActual < 2000 && dineroActual > 0);

	if (dineroActual >= 2000)
	{
		std::cout << "Enhorabuena, has ganado!" << std::endl;
	}
	else if (dineroActual <=0)
	{
		std::cout << "Vaya, has perdido :(" << std::endl;
	}
}