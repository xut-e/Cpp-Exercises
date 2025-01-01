/* 32. El usuario tendrá 100€ y para ganar debe de llegar a los 1,000€, al alcanzar
 la cifra de 0€ o 500€ se le informará del resultado. Al inicio de cada ronda se
 le pedirá la cantidad a apostar y seguidamente el programa elegirá
 aleatoriamente si gana o pierde. Cuando gane el jugador podrá hacer un
 doble o nada. Si decide doblar se vuelve a ejecutar el aleatorio, si decide
 parar obtiene los beneficios y se da paso a una nueva ronda. */


#include <iostream>
#include <time.h>

void main() {
	int dineroActual, apuesta, flag = 0;

	srand(time(0));

	dineroActual = 100;

	std::cout << "Bienvenido a SUERTE Y FORTUNA." << std::endl;

	do
	{
		std::cout << "Introduce la cantidad a apostar: ";
		do
		{
			std::cin >> apuesta;

			if (apuesta > dineroActual && apuesta > 0)
			{
				std::cout << "No puedes apostar tanto dinero, solo dispones de " << dineroActual << " euros." << std::endl;
			}
			else if (apuesta <= 0)
			{
				std::cout << "No puedes no apostar o apostar numeros negativos." << std::endl;
			}

		} while (apuesta > dineroActual || apuesta <= 0);

		dineroActual -= apuesta;

		int numeroAleatorio = rand() % (1 - 0 + 1) + 0, respuesta;

		if (numeroAleatorio == 1)
		{
			std::cout << "Enhorabuena, has ganado esta ronda." << std::endl;
			std::cout << "Deseas hacer doble o nada?" << std::endl << "\t" << "1) Si." << std::endl << "\t" << "2) No." << std::endl;
			std::cin >> respuesta;

			if (respuesta == 1)
			{
				int numeroAleatorioDos = rand() % (1 - 0 + 1) + 0;

				if (numeroAleatorioDos == 1)
				{
					std::cout << "Enhorabuena, has ganado el doble o nada. Obtuviste " << apuesta * 4 << " euros." << std::endl;

					dineroActual += apuesta * 4;
				}
				else
				{
					std::cout << "Vaya, has perdido... Que pena >:)" << std::endl;

					if ((dineroActual + apuesta) >= 500 && flag > 0 && dineroActual < 500)
					{
						flag--;
					}
				}
			}
			else
			{
				std::cout << "Enhorabuena, has ganado esta ronda. Obtuviste " << apuesta * 2 << " euros." << std::endl;

				dineroActual += apuesta * 2;
			}
		}
		else
		{
			std::cout << "Vaya, has perdido... Que pena >:)" << std::endl;

			if ((dineroActual + apuesta) >= 500 && flag > 0 && dineroActual < 500)
			{
				flag--;
			}
		}

		if (dineroActual >= 500)
		{
			if (flag == 0)
			{
				std::cout << "Has llegado a la mitad del juego. Has conseguido juntar 500 euros." << std::endl;
			}

			flag++;
		}
		else if (dineroActual >= 1000)
		{
			std::cout << "Enhorabuena, has ganado el juego." << std::endl;
		}
		else if (dineroActual <= 0)
		{
			std::cout << "Has perdido todo tu dinero." << std::endl;
		}

	} while (!(dineroActual <= 0) && !(dineroActual >= 1000));
}