/* Hundir la Flota
 La siguiente práctica pretende que el alumno desarrolle una réplica del
 juego de tablero Hundir la Flota para ordenador con tal de que demuestre los
 conocimientos adquiridos durante el transcurso de la materia.

  Tablero (2 puntos)
 Al iniciar el programa este generará el tablero de juego para cada jugador el
 cual se actualiza tras cada acción de uno de ellos.
 ● Elprograma inicializará automáticamente los tableros de juego.
 ● El tablero será de 10x10 y mostrará sus casillas mediante el símbolo ~.
 ● El tablero puede visualizarse mediante la consola de comandos.

 Barcos (3 puntos)
 Tras generar el tablero el programa colocara aleatoriamente los barcos en el
 tablero de cada jugador.
 ● Cadajugador dispondrá de un barco de 3, 4, 5 y 6 espacios.
 ● Dosbarcos no pueden coincidir en una casilla.
 ● Losbarcos sólo pueden colocarse verticalmente u horizontalmente.
 ● Unbarco no puede salir de los límites del mapa.
 ● Losbarcos serán colocados aleatoriamente en el tablero.
 ● Sólo al inicio del primer turno se mostrarán los barcos de ambos jugadores
 para poder debugar correctamente.

 Gameplay (3 puntos)
 En cada turno el programa pedirá al usuario que introduzca fila y columna
 que quiere atacar. Tras ello actualiza el tablero con el resultado. Gana aquel
 jugador que hunda primero todos los barcos rivales.
 ● Losturnos se intercalan correctamente y cada jugador ataca al tablero rival.
 ● Tras cada turno se visualiza actualizado el tablero de ambos jugadores.
 ● El tablero muestra los fallos (X) y los aciertos (O).
 ● El juego finaliza indicando el jugador vencedor.
 ● Encadaturno se solicitará al jugador correspondiente fila y columna a
 atacar siendo la 1, 1 la casilla superior izquierda y la 10, 10 la inferior
 derecha.

 Code Review (2 puntos)
 Se aplican y presentan buenas prácticas de programación.
 ● Usocorrecto del tipo de variables.
 ● Constancia en la nomenclatura de variables.
 ● Código comentado.
 ● Sinuso de magic numbers.
 ● Sinvariables sin uso.
 ● Sinpresentar graves errores de rendimiento.

  */

#include <iostream>
#include <time.h>
#include <Windows.h>

int main() {
	int const filas = 10, columnas = 10, numeroBarcos = 6;
	char tableroJugador1[filas][columnas], tableroJugador2[filas][columnas], tableroGameplayJugador1[filas][columnas], tableroGameplayJugador2[filas][columnas];
	int cantidadOsJugador1 = 0, cantidadOsJugador2 = 0;
	int fila, columna;
	srand(time(0));

#pragma region tableros

	// Inicializo los dos tableros.
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			tableroJugador1[i][j] = '~';
			tableroJugador2[i][j] = '~';
			tableroGameplayJugador1[i][j] = '~';
			tableroGameplayJugador2[i][j] = '~';
		}
	}

	// Imprimo ambos tableros para previsualizarlos.
	std::cout << "TABLERO JUGADOR 1:" << std::endl;

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			std::cout << " " << tableroJugador1[i][j];

		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "TABLERO JUGADOR 2:" << std::endl;

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			std::cout << " " << tableroJugador2[i][j];

		}
		std::cout << std::endl;
	}

#pragma endregion

	std::cout << std::endl << "Presiona cualquier tecla para colocar los barcos: ";
	std::cin.get(); // Detectamos cualquier tecla. Esta parte me la dijo la IA.

#pragma region barcosJugador1

	// Con este bucle iteramos entre los tamaños del barco.
	for (int i = 3; i <= 6; i++)
	{
		// Convertimos la variable de iteración i (que a su vez es el tamaño de los barcos) en un char para poder meterlo en la matriz del tablero. Esta parte le pregunté a la IA cómo hacerlo y me dió varias opciones, elegí esta.
		char tamanyoBarco = i + '0';

		// Booleano para saber cuándo un barco ha sido colocado.
		bool barcoColocado = false;

		// En caso de que un barco haya sido colocado, salimos del bucle y aumentamos una iteración el for anterior para pasar al siguiente tamaño de barco.
		while (!barcoColocado)
		{
			// Generamos una posicion aleatoria del 0 al 9 (tamaño del tablero) para filas y columnas que se regenera en caso de que no haya sido posible colocar un barco desde la posicion aleatoria en ninguna posición.
			int posicionAleatoriaFila = rand() % filas, posicionAleatoriaColumna = rand() % columnas;

			// Bucle para iterar entre las posiciones posibles (como en un cuadrante [1: Derecha, 2: Arriba, 3: Izquierda, 4: Abajo]).
			for (int j = 1; j <= 4; j++)
			{
				// Booleano para saber si un barco esta intentando ser superpuesto sobre otro, false para que en caso de no entrar en la condición de colocación se interprete como que no se ha podido colocar.
				bool superpuesto = false;

				// Comprobamos si la posición inicial es agua o barco. Si es agua procedemos a hacer más comprobaciones. Si no, regeneramos la posición inicial.
				if (tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna] == '~')
				{
					// Para la direccion 1 (derecha) y además comprobamos si el barco queda dentro del tablero e inicia el for.
					if (j == 1 && posicionAleatoriaColumna + i <= 9)
					{
						// Con este bucle iteramos entre las posiciones que ocupará el barco. Sumamos k en la columna porque la dirección es derecha.
						for (int k = 0; k < i; k++)
						{
							// Comprobamos si esas posiciones son agua o un barco. Si es diferente a agua decimos que está superpuesto y salimos del bucle.
							if (tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna + k] != '~')
							{
								superpuesto = true;
								break;
							}
						}
						// Si no está superpuesto cambiamos la posición correspondiente por el numero correspondiente al barco actual y declaramos barcoColocado como true para que sepamos que un barco ha sido colocado y salimos del bucle.
						if (!superpuesto)
						{
							for (int k = 0; k < i; k++)
							{
								tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna + k] = tamanyoBarco;
							}
							barcoColocado = true;
							break;
						}
					}
					// Para la direccion 2 (arriba) y además comprobamos si el barco queda dentro del tablero e inicia el for.
					else if (j == 2 && posicionAleatoriaFila - i >= 0)
					{
						// Con este bucle iteramos entre las posiciones que ocupará el barco. Restamos k en la fila porque la dirección es arriba.
						for (int k = 0; k < i; k++)
						{
							// Comprobamos si esas posiciones son agua o un barco. Si es diferente a agua decimos que está superpuesto y salimos del bucle.
							if (tableroJugador1[posicionAleatoriaFila - k][posicionAleatoriaColumna] != '~')
							{
								superpuesto = true;
								break;
							}
						}
						// Si no está superpuesto cambiamos la posición correspondiente por el numero correspondiente al barco actual y declaramos barcoColocado como true para que sepamos que un barco ha sido colocado y salimos del bucle.
						if (!superpuesto)
						{
							for (int k = 0; k < i; k++)
							{
								tableroJugador1[posicionAleatoriaFila - k][posicionAleatoriaColumna] = tamanyoBarco;
							}
							barcoColocado = true;
							break;
						}
					}
					// Para la direccion 3 (izquierda) y además comprobamos si el barco queda dentro del tablero e inicia el for.
					else if (j == 3 && posicionAleatoriaColumna - i >= 0)
					{
						// Con este bucle iteramos entre las posiciones que ocupará el barco. Restamos k en la columna porque la dirección es arriba.
						for (int k = 0; k < i; k++)
						{
							// Comprobamos si esas posiciones son agua o un barco. Si es diferente a agua decimos que está superpuesto y salimos del bucle.
							if (tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna - k] != '~')
							{
								superpuesto = true;
								break;
							}
						}
						// Si no está superpuesto cambiamos la posición correspondiente por el numero correspondiente al barco actual y declaramos barcoColocado como true para que sepamos que un barco ha sido colocado y salimos del bucle.
						if (!superpuesto)
						{
							for (int k = 0; k < i; k++)
							{
								tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna - k] = tamanyoBarco;
							}
							barcoColocado = true;
							break;
						}
					}
					// Para la direccion 4 (abajo) y además comprobamos si el barco queda dentro del tablero e inicia el for.
					else if (j == 4 && posicionAleatoriaFila + i <= 9)
					{
						// Con este bucle iteramos entre las posiciones que ocupará el barco. Sumamos k en la fila porque la dirección es arriba.
						for (int k = 0; k < i; k++)
						{
							// Comprobamos si esas posiciones son agua o un barco. Si es diferente a agua decimos que está superpuesto y salimos del bucle.
							if (tableroJugador1[posicionAleatoriaFila + k][posicionAleatoriaColumna] != '~')
							{
								superpuesto = true;
								break;
							}
						}
						// Si no está superpuesto cambiamos la posición correspondiente por el numero correspondiente al barco actual y declaramos barcoColocado como true para que sepamos que un barco ha sido colocado y salimos del bucle.
						if (!superpuesto)
						{
							for (int k = 0; k < i; k++)
							{
								tableroJugador1[posicionAleatoriaFila + k][posicionAleatoriaColumna] = tamanyoBarco;
							}
							barcoColocado = true;
							break;
						}
					}
				}
			}
		}
	}

#pragma endregion


#pragma region barcosJugador2

	// Con este bucle iteramos entre los tamaños del barco.
	for (int i = 3; i <= 6; i++)
	{
		// Convertimos la variable de iteración i (que a su vez es el tamaño de los barcos) en un char para poder meterlo en la matriz del tablero. Esta parte le pregunté a la IA cómo hacerlo y me dió varias opciones, elegí esta.
		char tamanyoBarco = i + '0';

		// Booleano para saber cuándo un barco ha sido colocado.
		bool barcoColocado = false;

		// En caso de que un barco haya sido colocado, salimos del bucle y aumentamos una iteración el for anterior para pasar al siguiente tamaño de barco.
		while (!barcoColocado)
		{
			// Generamos una posicion aleatoria del 0 al 9 (tamaño del tablero) para filas y columnas que se regenera en caso de que no haya sido posible colocar un barco desde la posicion aleatoria en ninguna posición.
			int posicionAleatoriaFila = rand() % filas, posicionAleatoriaColumna = rand() % columnas;

			// Bucle para iterar entre las posiciones posibles (como en un cuadrante [1: Derecha, 2: Arriba, 3: Izquierda, 4: Abajo]).
			for (int j = 1; j <= 4; j++)
			{
				// Booleano para saber si un barco esta intentando ser superpuesto sobre otro, false para que en caso de no entrar en la condición de colocación se interprete como que no se ha podido colocar.
				bool superpuesto = false;

				// Comprobamos si la posición inicial es agua o barco. Si es agua procedemos a hacer más comprobaciones. Si no, regeneramos la posición inicial.
				if (tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna] == '~')
				{
					// Para la direccion 1 (derecha) y además comprobamos si el barco queda dentro del tablero e inicia el for.
					if (j == 1 && posicionAleatoriaColumna + i <= 9)
					{
						// Con este bucle iteramos entre las posiciones que ocupará el barco. Sumamos k en la columna porque la dirección es derecha.
						for (int k = 0; k < i; k++)
						{
							// Comprobamos si esas posiciones son agua o un barco. Si es diferente a agua decimos que está superpuesto y salimos del bucle.
							if (tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna + k] != '~')
							{
								superpuesto = true;
								break;
							}
						}
						// Si no está superpuesto cambiamos la posición correspondiente por el numero correspondiente al barco actual y declaramos barcoColocado como true para que sepamos que un barco ha sido colocado y salimos del bucle.
						if (!superpuesto)
						{
							for (int k = 0; k < i; k++)
							{
								tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna + k] = tamanyoBarco;
							}
							barcoColocado = true;
							break;
						}
					}
					// Para la direccion 2 (arriba) y además comprobamos si el barco queda dentro del tablero e inicia el for.
					else if (j == 2 && posicionAleatoriaFila - i >= 0)
					{
						// Con este bucle iteramos entre las posiciones que ocupará el barco. Restamos k en la fila porque la dirección es arriba.
						for (int k = 0; k < i; k++)
						{
							// Comprobamos si esas posiciones son agua o un barco. Si es diferente a agua decimos que está superpuesto y salimos del bucle.
							if (tableroJugador2[posicionAleatoriaFila - k][posicionAleatoriaColumna] != '~')
							{
								superpuesto = true;
								break;
							}
						}
						// Si no está superpuesto cambiamos la posición correspondiente por el numero correspondiente al barco actual y declaramos barcoColocado como true para que sepamos que un barco ha sido colocado y salimos del bucle.
						if (!superpuesto)
						{
							for (int k = 0; k < i; k++)
							{
								tableroJugador2[posicionAleatoriaFila - k][posicionAleatoriaColumna] = tamanyoBarco;
							}
							barcoColocado = true;
							break;
						}
					}
					// Para la direccion 3 (izquierda) y además comprobamos si el barco queda dentro del tablero e inicia el for.
					else if (j == 3 && posicionAleatoriaColumna - i >= 0)
					{
						// Con este bucle iteramos entre las posiciones que ocupará el barco. Restamos k en la columna porque la dirección es arriba.
						for (int k = 0; k < i; k++)
						{
							// Comprobamos si esas posiciones son agua o un barco. Si es diferente a agua decimos que está superpuesto y salimos del bucle.
							if (tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna - k] != '~')
							{
								superpuesto = true;
								break;
							}
						}
						// Si no está superpuesto cambiamos la posición correspondiente por el numero correspondiente al barco actual y declaramos barcoColocado como true para que sepamos que un barco ha sido colocado y salimos del bucle.
						if (!superpuesto)
						{
							for (int k = 0; k < i; k++)
							{
								tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna - k] = tamanyoBarco;
							}
							barcoColocado = true;
							break;
						}
					}
					// Para la direccion 4 (abajo) y además comprobamos si el barco queda dentro del tablero e inicia el for.
					else if (j == 4 && posicionAleatoriaFila + i <= 9)
					{
						// Con este bucle iteramos entre las posiciones que ocupará el barco. Sumamos k en la fila porque la dirección es arriba.
						for (int k = 0; k < i; k++)
						{
							// Comprobamos si esas posiciones son agua o un barco. Si es diferente a agua decimos que está superpuesto y salimos del bucle.
							if (tableroJugador2[posicionAleatoriaFila + k][posicionAleatoriaColumna] != '~')
							{
								superpuesto = true;
								break;
							}
						}
						// Si no está superpuesto cambiamos la posición correspondiente por el numero correspondiente al barco actual y declaramos barcoColocado como true para que sepamos que un barco ha sido colocado y salimos del bucle.
						if (!superpuesto)
						{
							for (int k = 0; k < i; k++)
							{
								tableroJugador2[posicionAleatoriaFila + k][posicionAleatoriaColumna] = tamanyoBarco;
							}
							barcoColocado = true;
							break;
						}
					}
				}
			}
		}
	}

#pragma endregion

	system("cls");

	// Imprimimos los dos tableros.
	std::cout << "TABLERO JUGADOR 1:" << std::endl;

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			std::cout << " " << tableroJugador1[i][j];

		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "TABLERO JUGADOR 2:" << std::endl;

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			std::cout << " " << tableroJugador2[i][j];

		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "Presiona cualquier tecla para empezar a jugar: ";
	std::cin.get(); // Detectamos cualquier tecla. Esta parte me la dijo la IA.

	std::cin.ignore(); // Limpiamos la entrada para que no se vuelva a activar sola.

#pragma region gameplay

	while (cantidadOsJugador1 < 18 && cantidadOsJugador2 < 18)
	{
		// Limpiamos la pantalla. Esta parte me la dijo la IA.
		system("cls");

		// Indicamos a los jugadores de quién es el turno.
		std::cout << "TURNO JUGADOR 1:" << std::endl;

		//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
		std::cout << "TABLERO DEL JUGADOR 2:" << std::endl;

		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				std::cout << " " << tableroGameplayJugador2[i][j];

			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		do
		{
			do
			{
				std::cout << "Introduzca la posicion de fila que desea atacar: ";
				std::cin >> fila;
				fila--;

				if (fila > 9 || fila < 0)
				{
					std::cout << "Esa posicion no es valida, debe de estar entre 1 y 10." << std::endl << std::endl;
				}

			} while (fila > 9 || fila < 0);

			do
			{
				std::cout << "Introduzca la posicion de columna que desea atacar: ";
				std::cin >> columna;
				columna--;

				if (columna > 9 || columna < 0)
				{
					std::cout << "Esa posicion no es valida, debe de estar entre 1 y 10." << std::endl << std::endl;
				}

			} while (columna > 9 || columna < 0);

			if (tableroGameplayJugador2[fila][columna] != '~')
			{
				std::cout << "Esa posicion ya ha sido atacada." << std::endl;
			}

		} while (tableroGameplayJugador2[fila][columna] != '~');
		
		if (tableroJugador2[fila][columna] == '~')
		{
			tableroGameplayJugador2[fila][columna] = 'X';
		}
		else
		{
			tableroGameplayJugador2[fila][columna] = 'O';
			cantidadOsJugador1++;

			if (cantidadOsJugador1 == 18)
			{
				break;
			}
		}

		// Limpiamos la pantalla. Esta parte me la dijo la IA.
		system("cls");

		// Indicamos a los jugadores de quién es el turno.
		std::cout << "TURNO JUGADOR 1:" << std::endl;

		//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
		std::cout << "TABLERO DEL JUGADOR 2:" << std::endl;

		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				std::cout << " " << tableroGameplayJugador2[i][j];

			}
			std::cout << std::endl;
		}

		Sleep(1500);

		// Limpiamos la pantalla. Esta parte me la dijo la IA.
		system("cls");

		// Indicamos a los jugadores de quién es el turno.
		std::cout << "TURNO JUGADOR 2:" << std::endl;

		//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
		std::cout << "TABLERO DEL JUGADOR 1:" << std::endl;

		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				std::cout << " " << tableroGameplayJugador1[i][j];

			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		do
		{
			do
			{
				std::cout << "Introduzca la posicion de fila que desea atacar: ";
				std::cin >> fila;
				fila--;

				if (fila > 9 || fila < 0)
				{
					std::cout << "Esa posicion no es valida, debe de estar entre 1 y 10." << std::endl << std::endl;
				}

			} while (fila > 9 || fila < 0);

			do
			{
				std::cout << "Introduzca la posicion de columna que desea atacar: ";
				std::cin >> columna;
				columna--;

				if (columna > 9 || columna < 0)
				{
					std::cout << "Esa posicion no es valida, debe de estar entre 1 y 10." << std::endl << std::endl;
				}

			} while (columna > 9 || columna < 0);

			if (tableroGameplayJugador1[fila][columna] != '~')
			{
				std::cout << "Esa posicion ya ha sido atacada." << std::endl;
			}

		} while (tableroGameplayJugador1[fila][columna] != '~');

		if (tableroJugador1[fila][columna] == '~')
		{
			tableroGameplayJugador1[fila][columna] = 'X';
		}
		else
		{
			tableroGameplayJugador1[fila][columna] = 'O';
			cantidadOsJugador2++;

			if (cantidadOsJugador2 == 18)
			{
				break;
			}
		}

		// Limpiamos la pantalla. Esta parte me la dijo la IA.
		system("cls");

		// Indicamos a los jugadores de quién es el turno.
		std::cout << "TURNO JUGADOR 2:" << std::endl;

		//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
		std::cout << "TABLERO DEL JUGADOR 1:" << std::endl;

		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				std::cout << " " << tableroGameplayJugador1[i][j];

			}
			std::cout << std::endl;
		}

		Sleep(1500);
	}

	if (cantidadOsJugador1 >= 18)
	{
		//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
		std::cout << "TABLERO DEL JUGADOR 2:" << std::endl;

		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				std::cout << " " << tableroGameplayJugador2[i][j];

			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "El jugador 1 gana! Enhorabuena, has hundido la flota de tu rival." << std::endl;
	}
	else if (cantidadOsJugador2 >= 18)
	{
		//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
		std::cout << "TABLERO DEL JUGADOR 1:" << std::endl;

		for (int i = 0; i < filas; i++)
		{
			for (int j = 0; j < columnas; j++)
			{
				std::cout << " " << tableroGameplayJugador1[i][j];

			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "El jugador 2 gana! Enhorabuena, has hundido la flota de tu rival." << std::endl;
	}

#pragma endregion

	return 0;
}