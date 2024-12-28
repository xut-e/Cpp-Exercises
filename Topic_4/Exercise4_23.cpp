// 23. Crea un programa que simule el juego de piedra, papel o tijera. El jugador introducirá una de las 3 opciones y al darle enter el programa generará su opción y a continuación mostrará el resultado al jugador.Gana el mejor de 5.

#include <iostream>
#include <time.h>
#include <Windows.h>

void main() {
	int movimiento;
	srand(time(0));
	int contadorJugadas = 0, humanoPuntuacion = 0, maquinaPuntuacion = 0;
	
	
	std::cout << "Bienvenido a piedra papel o tijeras, el clasico. SIN TONTERIAS!" << std::endl;
	Sleep(1000);
	std::cout << "Quien se alzara ganador? Quienm competira en la liga de las estrellas? Sera la maquina? O podran los humanos derrotarla?" << std::endl;
	Sleep(1000);
	
	while (humanoPuntuacion < 3 && maquinaPuntuacion < 3)
	{
		std::cout << "Elije tu movimiento: " << std::endl << "\t" << "1) Piedra." << std::endl << "\t" << "2) Papel." << std::endl << "\t" << "3) Tijeras." << std::endl;
		std::cin >> movimiento;

		int movimientoMaquina = rand() % (3 - 1 + 1) + 1;

		switch (movimiento)
		{
		case 1:
			std::cout << "Tu movimiento: Piedra." << std::endl;
			break;
		case 2:
			std::cout << "Tu movimiento: Papel." << std::endl;
			break;
		case 3:
			std::cout << "Tu movimiento: Tijeras." << std::endl;
			break;
		default:
			std::cout << "Movimiento no valido." << std::endl;
			Sleep(1000);
			std::cout << "Has sido..." << std::endl;
			Sleep(1500);
			std::cout << "D E S ";
			Sleep(200);
			std::cout << "C A ";
			Sleep(200);
			std::cout << "L I "; 
			Sleep(200);
			std::cout << "F I ";
			Sleep(200);
			std::cout << "C A ";
			Sleep(200);
			std::cout << "D O !" << std::endl;

			break;
		}

		std::cout << "Movimiento de la maquina: ";

		if (movimientoMaquina == 1)
		{
			std::cout << "Piedra." << std::endl;
		}
		else if (movimientoMaquina == 2)
		{
			std::cout << "Papel." << std::endl;

		}
		else if (movimientoMaquina == 3)
		{
			std::cout << "Tijeras." << std::endl;

		}

		if (movimiento == movimientoMaquina)
		{
			std::cout << "Eso fue un EEEEEEMPATEEEEE!!!" << std::endl;
		}
		else if (movimiento == 1)
		{
			if (movimientoMaquina == 2)
			{
				std::cout << "La maquina gana esta ronda." << std::endl;
				maquinaPuntuacion++;
			}
			else if (movimientoMaquina == 3)
			{
				std::cout << "Tu ganas esta ronda." << std::endl;
				humanoPuntuacion++;
			}
		}
		else if (movimiento == 2)
		{
			if (movimientoMaquina == 1)
			{
				std::cout << "Tu ganas esta ronda." << std::endl;
				humanoPuntuacion++;
			}
			else if (movimientoMaquina == 3)
			{
				std::cout << "La maquina gana esta ronda." << std::endl;
				maquinaPuntuacion++;
			}
		}
		else if (movimiento == 3)
		{
			if (movimientoMaquina == 1)
			{
				std::cout << "La maquina gana esta ronda." << std::endl;
				maquinaPuntuacion++;
			}
			else if (movimientoMaquina == 2)
			{
				std::cout << "Tu ganas esta ronda." << std::endl;
				humanoPuntuacion++;
			}
		}
	}

	Sleep(1000);

	if (maquinaPuntuacion == 3)
	{
		std::cout << "La maquina ha ganado." << std::endl;
	}
	else
	{
		std::cout << "Has ganado." << std::endl;

	}
}