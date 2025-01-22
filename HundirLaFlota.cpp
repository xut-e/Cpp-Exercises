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


  */

#include <iostream>
#include <time.h>

int main() {
	int const filas = 10, columnas = 10, numeroBarcos = 6;
	char tableroJugador1[filas][columnas], tableroJugador2[filas][columnas];
	srand(time(0));

#pragma region tableros

	// Inicializo los dos tableros.
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			tableroJugador1[i][j] = '~';
			tableroJugador2[i][j] = '~';
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

#pragma region barcos

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
					// Para la direccion 1 (derecha) y además comprobamos si el barco queda dentro del tablero inicia el for.
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
					// Para la direccion 2 (arriba) y además comprobamos si el barco queda dentro del tablero inicia el for.
					else if (j == 2 && posicionAleatoriaFila - i >= 0)
					{
						for (int k = 0; k < i; k++)
						{
							if (tableroJugador1[posicionAleatoriaFila - k][posicionAleatoriaColumna] != '~')
							{
								superpuesto = true;
								break;
							}
						}
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
					else if (j == 3 && posicionAleatoriaColumna - i >= 0)
					{
						for (int k = 0; k < i; k++)
						{
							if (tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna - k] != '~')
							{
								superpuesto = true;
								break;
							}
						}
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
					else if (j == 4 && posicionAleatoriaFila + i >= 0)
					{
						for (int k = 0; k < i; k++)
						{
							if (tableroJugador1[posicionAleatoriaFila + k][posicionAleatoriaColumna] != '~')
							{
								superpuesto = true;
								break;
							}
						}
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

	// Acto seguido imprimimos los tableros para ver el resultado:

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
}



