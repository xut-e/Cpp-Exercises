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

	// Pongo cada uno de los barcos de manera aleatoria asegurandome dee que no coinciden en ninguna casilla.
	for (int i = 3; i < numeroBarcos + 1; i++)
	{
		// Convertimos i (que es el tamaño del barco) en un char con su mismo valor para poder almacenarlo en nuestros tableros.
		char tamanyoBarco = i + '0'; // La IA me ha dicho varias maneras de converir una variable int en char y he eelegido esta.

		// Booleano para saber cuando un barco esta bien puesto y se puede pasar al siguiente.
		bool barcoBienPuesto = false;

		// Bucle do while para que se ejecute una vez antes de comprobar si el barco esta bieen puesto.
		do
		{
			// Booleano para saber si la posición del barco es válida.
			bool superpuesto = false;

			// Generación de números aleatorios para determinar posición (fila y columna) y dirección (como en cuadrantes [1: Derecha, 2: Arriba, 3: Izquierda, 4: Abajo])
			int posicionAleatoriaFila = rand() % filas, posicionAleatoriaColumna = rand() % columnas, direccionAleatoria = rand() % (4 - 1 + 1) + 1;

			// Primereo nos aseguramos de que esa posición original no esté ocupada por otro barco, en caso de que lo esté no hacemos nada y como barcoBienPuesto es false, se repetirá el bucle.
			if (tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna] == '~')
			{
				// Aquí escribimos lo que pasará en cada caso de dirección aleatoria.

				// Para este caso en el que la direccion es derecha, recorremos aquellas posiciones con la misma fila pero incrementando la columna tantas veces como el tamaño del barco sea y comprobamos que no se pase del tamaño de la matriz (i es el tamaño del barco).
				if (direccionAleatoria == 1 && posicionAleatoriaColumna + (i - 1) <= 9)
				{
					// Primero nos aseguramos de que el barco no estará superpuesto y en caso de que lo esté salimos del bucle para encontrar otra posición.
					for (int j = 0; j < i; j++)
					{
						if (tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna + j] != '~')
						{
							superpuesto = true;
							break;
						}
					}

					// Si no está superpuesto, entonces colocamos el barco.
					if (!superpuesto)
					{
						for (int j = 0; j < i; j++)
						{
							if (tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna + j] != '~')
							{
								tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna + j] = tamanyoBarco;
							}
						}

						// Declaramos que el barco ha sido bien puesto y que podemos pasar al siguiente.
						barcoBienPuesto = true;
					}
				}
				// Para este caso en el que la direccion es arriba, recorremos aquellas posiciones con la misma columna pero decrementando la fila tantas veces como el tamaño del barco sea y comprobamos que no se pase del tamaño de la matriz (i es el tamaño del barco).
				else if (direccionAleatoria == 2 && posicionAleatoriaFila - (i - 1) >= 0)
				{
					// Primero nos aseguramos de que el barco no estará superpuesto y en caso de que lo esté salimos del bucle para encontrar otra posición.
					for (int j = 0; j < i; j++)
					{
						if (tableroJugador1[posicionAleatoriaFila - j][posicionAleatoriaColumna] != '~')
						{
							superpuesto = true;
							break;
						}
					}

					// Si no está superpuesto, entonces colocamos el barco.
					if (!superpuesto)
					{
						for (int j = 0; j < i; j++)
						{
							tableroJugador1[posicionAleatoriaFila - j][posicionAleatoriaColumna] = tamanyoBarco;
						}

						// Declaramos que el barco ha sido bien puesto y que podemos pasar al siguiente.
						barcoBienPuesto = true;
					}
				}
				// Para este caso en el que la direccion es izquierda, recorremos aquellas posiciones con la misma fila pero decrementando la columna tantas veces como el tamaño del barco sea y comprobamos que no se pase del tamaño de la matriz (i es el tamaño del barco).
				else if (direccionAleatoria == 3 && posicionAleatoriaColumna - (i - 1) >= 0)
				{
					// Primero nos aseguramos de que el barco no estará superpuesto y en caso de que lo esté salimos del bucle para encontrar otra posición.
					for (int j = 0; j < i; j++)
					{
						if (tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna - j] != '~')
						{
							superpuesto = true;
							break;
						}
					}

					// Si no está superpuesto, entonces colocamos el barco.
					if (!superpuesto)
					{
						for (int j = 0; j < i; j++)
						{
							tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna - j] = tamanyoBarco;
						}

						// Declaramos que el barco ha sido bien puesto y que podemos pasar al siguiente.
						barcoBienPuesto = true;
					}
				}
				// Para este caso en el que la direccion es abajo, recorremos aquellas posiciones con la misma columna pero incrementando la fila tantas veces como el tamaño del barco sea y comprobamos que no se pase del tamaño de la matriz (i es el tamaño del barco).
				else if (direccionAleatoria == 4 && posicionAleatoriaFila + (i - 1) <= 9)
				{
					// Primero nos aseguramos de que el barco no estará superpuesto y en caso de que lo esté salimos del bucle para encontrar otra posición.
					for (int j = 0; j < i; j++)
					{
						if (tableroJugador1[posicionAleatoriaFila + j][posicionAleatoriaColumna] != '~')
						{
							superpuesto = true;
							break;
						}
					}

					// Si no está superpuesto, entonces colocamos el barco.
					if (!superpuesto)
					{
						for (int j = 0; j < i; j++)
						{
							tableroJugador1[posicionAleatoriaFila + j][posicionAleatoriaColumna] = tamanyoBarco;
						}

						// Declaramos que el barco ha sido bien puesto y que podemos pasar al siguiente.
						barcoBienPuesto = true;
					}
				}
			}
		} while (!barcoBienPuesto);
	}

	// Igual que lo hemos hecho para el jugador 1 lo hacemos para el jugador 2:



	// Pongo cada uno de los barcos de manera aleatoria asegurandome dee que no coinciden en ninguna casilla.
	for (int i = 3; i < numeroBarcos + 1; i++)
	{
		// Convertimos i (que es el tamaño del barco) en un char con su mismo valor para poder almacenarlo en nuestros tableros.
		char tamanyoBarco = i + '0'; // La IA me ha dicho varias maneras de converir una variable int en char y he eelegido esta.

		// Booleano para saber cuando un barco esta bien puesto y se puede pasar al siguiente.
		bool barcoBienPuesto = false;

		// Bucle do while para que se ejecute una vez antes de comprobar si el barco esta bieen puesto.
		do
		{
			// Booleano para saber si la posición del barco es válida.
			bool superpuesto = false;

			// Generación de números aleatorios para determinar posición (fila y columna) y dirección (como en cuadrantes [1: Derecha, 2: Arriba, 3: Izquierda, 4: Abajo])
			int posicionAleatoriaFila = rand() % (9 - 0 + 1) + 0, posicionAleatoriaColumna = rand() % (9 - 0 + 1) + 0, direccionAleatoria = rand() % (4 - 1 + 1) + 1;

			// Primereo nos aseguramos de que esa posición original no esté ocupada por otro barco, en caso de que lo esté no hacemos nada y como barcoBienPuesto es false, se repetirá el bucle.
			if (tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna] == '~')
			{
				// Aquí escribimos lo que pasará en cada caso de dirección aleatoria.

				// Para este caso en el que la direccion es derecha, recorremos aquellas posiciones con la misma fila pero incrementando la columna tantas veces como el tamaño del barco sea y comprobamos que no se pase del tamaño de la matriz (i es el tamaño del barco).
				if (direccionAleatoria == 1 && posicionAleatoriaColumna + (i - 1) <= 9)
				{
					// Primero nos aseguramos de que el barco no estará superpuesto y en caso de que lo esté salimos del bucle para encontrar otra posición.
					for (int j = 0; j < i; j++)
					{
						if (tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna + j] != '~')
						{
							superpuesto = true;
							break;
						}
					}

					// Si no está superpuesto, entonces colocamos el barco.
					if (!superpuesto)
					{
						for (int j = 0; j < i; j++)
						{
							if (tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna + j] != '~')
							{
								tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna + j] = tamanyoBarco;
							}
						}

						// Declaramos que el barco ha sido bien puesto y que podemos pasar al siguiente.
						barcoBienPuesto = true;
					}
				}
				// Para este caso en el que la direccion es arriba, recorremos aquellas posiciones con la misma columna pero decrementando la fila tantas veces como el tamaño del barco sea y comprobamos que no se pase del tamaño de la matriz (i es el tamaño del barco).
				else if (direccionAleatoria == 2 && posicionAleatoriaFila - (i - 1) >= 0)
				{
					// Primero nos aseguramos de que el barco no estará superpuesto y en caso de que lo esté salimos del bucle para encontrar otra posición.
					for (int j = 0; j < i; j++)
					{
						if (tableroJugador2[posicionAleatoriaFila - j][posicionAleatoriaColumna] != '~')
						{
							superpuesto = true;
							break;
						}
					}

					// Si no está superpuesto, entonces colocamos el barco.
					if (!superpuesto)
					{
						for (int j = 0; j < i; j++)
						{
							tableroJugador2[posicionAleatoriaFila - j][posicionAleatoriaColumna] = tamanyoBarco;
						}

						// Declaramos que el barco ha sido bien puesto y que podemos pasar al siguiente.
						barcoBienPuesto = true;
					}
				}
				// Para este caso en el que la direccion es izquierda, recorremos aquellas posiciones con la misma fila pero decrementando la columna tantas veces como el tamaño del barco sea y comprobamos que no se pase del tamaño de la matriz (i es el tamaño del barco).
				else if (direccionAleatoria == 3 && posicionAleatoriaColumna - (i - 1) >= 0)
				{
					// Primero nos aseguramos de que el barco no estará superpuesto y en caso de que lo esté salimos del bucle para encontrar otra posición.
					for (int j = 0; j < i; j++)
					{
						if (tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna - j] != '~')
						{
							superpuesto = true;
							break;
						}
					}

					// Si no está superpuesto, entonces colocamos el barco.
					if (!superpuesto)
					{
						for (int j = 0; j < i; j++)
						{
							tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna - j] = tamanyoBarco;
						}

						// Declaramos que el barco ha sido bien puesto y que podemos pasar al siguiente.
						barcoBienPuesto = true;
					}
				}
				// Para este caso en el que la direccion es abajo, recorremos aquellas posiciones con la misma columna pero incrementando la fila tantas veces como el tamaño del barco sea y comprobamos que no se pase del tamaño de la matriz (i es el tamaño del barco).
				else if (direccionAleatoria == 4 && posicionAleatoriaFila + (i - 1) <= 9)
				{
					// Primero nos aseguramos de que el barco no estará superpuesto y en caso de que lo esté salimos del bucle para encontrar otra posición.
					for (int j = 0; j < i; j++)
					{
						if (tableroJugador2[posicionAleatoriaFila + j][posicionAleatoriaColumna] != '~')
						{
							superpuesto = true;
							break;
						}
					}

					// Si no está superpuesto, entonces colocamos el barco.
					if (!superpuesto)
					{
						for (int j = 0; j < i; j++)
						{
							tableroJugador2[posicionAleatoriaFila + j][posicionAleatoriaColumna] = tamanyoBarco;
						}

						// Declaramos que el barco ha sido bien puesto y que podemos pasar al siguiente.
						barcoBienPuesto = true;
					}
				}
			}
		} while (!barcoBienPuesto);
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