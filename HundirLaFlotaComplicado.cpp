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

#define FILAS 10
#define COLUMNAS 10

int main() {
	char tableroJugador1[FILAS][COLUMNAS], tableroJugador2[FILAS][COLUMNAS], tableroGameplayJugador1[FILAS][COLUMNAS], tableroGameplayJugador2[FILAS][COLUMNAS];
	int cantidadOsJugador1 = 0, cantidadOsJugador2 = 0, barcoMasPequenyo = 3, barcoMasGrande = 6;
	int fila, columna, cantidadOsTotal = 0, contadorTurno = 0;
	char opcionPaginaPrincipal, opcionPaginaConfiguracion, opcionPaginaBarcos;
	bool todoListo = false;
	srand(time(0));








	std::cout << "                                Bienvenido a" << std::endl << std::endl;


	std::cout << " _  _  _  _  __ _  ____  __  ____    __     __     ____  __     __  ____  __" << std::endl;
	std::cout << "/ )( \\/ )( \\(  ( \\(    \\(  )(  _ \\  (  )   / _\\   (  __)(  )   /  \\(_  _)/ _\\ " << std::endl;
	std::cout << ") __ () \\/ (/    / ) D ( )(  )   /  / (_/\\/    \\   ) _) / (_/\\(  O ) )( /    \\ " << std::endl;
	std::cout << "\\_)(_/\\____/\\_)__)(____/(__)(__\\_)  \\____/\\_/\\_/  (__)  \\____/ \\__/ (__)_/\\_/" << std::endl << std::endl;


	std::cout << "                                 (el juego)" << std::endl << std::endl;


	std::cout << "                               PAGINA INICIAL" << std::endl;

	std::cout << "1) Jugar (valores predeterminados)." << std::endl;
	std::cout << "2) Configuracion." << std::endl;
	while (!todoListo)
	{
		do
		{
			std::cout << "Seleccione una opcion1: ";
			std::cin >> opcionPaginaPrincipal;

			if (opcionPaginaPrincipal != '1' && opcionPaginaPrincipal != '2')
			{
				std::cout << "Esa opcion no es valida." << std::endl;
			}
		} while (opcionPaginaPrincipal != '1' && opcionPaginaPrincipal != '2');

		if (opcionPaginaPrincipal == '1')
		{
			system("cls");

			std::cout << "                      COLOCACION DE LOS BARCOS" << std::endl << std::endl;

			std::cout << "1) Colocacion aleatoria." << std::endl;
			std::cout << "2) Colocacion manual." << std::endl;
			std::cout << "3) Volver a la pagina de inicio." << std::endl;

			do
			{
				std::cout << "Seleccione una opcion2: ";
				std::cin >> opcionPaginaBarcos;

				if (opcionPaginaBarcos != '1' && opcionPaginaBarcos != '2' && opcionPaginaBarcos != '3')
				{
					std::cout << "Esa opcion no es valida." << std::endl;
				}
			} while (opcionPaginaBarcos != '1' && opcionPaginaBarcos != '2' && opcionPaginaBarcos != '3');

#pragma region tableros

			// Inicializo los dos tableros.
			for (int i = 0; i < FILAS; i++)
			{
				for (int j = 0; j < COLUMNAS; j++)
				{
					tableroJugador1[i][j] = '~';
					tableroJugador2[i][j] = '~';
					tableroGameplayJugador1[i][j] = '~';
					tableroGameplayJugador2[i][j] = '~';
				}
			}

			// Imprimo ambos tableros para previsualizarlos.
			std::cout << "TABLERO JUGADOR 1:" << std::endl;

			for (int i = 0; i < FILAS; i++)
			{
				for (int j = 0; j < COLUMNAS; j++)
				{
					std::cout << " " << tableroJugador1[i][j];

				}
				std::cout << std::endl;
			}

			std::cout << std::endl;

			std::cout << "TABLERO JUGADOR 2:" << std::endl;

			for (int i = 0; i < FILAS; i++)
			{
				for (int j = 0; j < COLUMNAS; j++)
				{
					std::cout << " " << tableroJugador2[i][j];

				}
				std::cout << std::endl;
			}

#pragma endregion

			// Definimos cuál es la cantidad total de Os para ganar.
			for (int i = barcoMasPequenyo; i < barcoMasGrande + 1; i++)
			{
				cantidadOsTotal += i;
			}

			if (opcionPaginaBarcos == '1')
			{
#pragma region barcosJugadores

				// Con este bucle iteramos entre los tamaños del barco.
				for (int i = barcoMasPequenyo; i <= barcoMasGrande; i++)
				{
					// Convertimos la variable de iteración i (que a su vez es el tamaño de los barcos) en un char para poder meterlo en la matriz del tablero. Esta parte le pregunté a la IA cómo hacerlo y me dió varias opciones, elegí esta.
					char tamanyoBarco = i + '0';

					// Booleano para saber cuándo un barco ha sido colocado.
					bool barcoColocado = false;

					// En caso de que un barco haya sido colocado, salimos del bucle y aumentamos una iteración el for anterior para pasar al siguiente tamaño de barco.
					while (!barcoColocado)
					{
						// Generamos una posicion aleatoria del 0 al 9 (tamaño del tablero) para FILAS y COLUMNAS que se regenera en caso de que no haya sido posible colocar un barco desde la posicion aleatoria en ninguna posición.
						int posicionAleatoriaFila = rand() % FILAS, posicionAleatoriaColumna = rand() % COLUMNAS;

						// Bucle para iterar entre las posiciones posibles (como en un cuadrante [1: Derecha, 2: Arriba, 3: Izquierda, 4: Abajo]).
						for (int j = 1; j <= 4; j++)
						{
							// Booleano para saber si un barco esta intentando ser superpuesto sobre otro, false para que en caso de no entrar en la condición de colocación se interprete como que no se ha podido colocar.
							bool superpuesto = false;

							// Comprobamos si la posición inicial es agua o barco. Si es agua procedemos a hacer más comprobaciones. Si no, regeneramos la posición inicial.
							if (tableroJugador1[posicionAleatoriaFila][posicionAleatoriaColumna] == '~')
							{
								// Para la direccion 1 (derecha) y además comprobamos si el barco queda dentro del tablero e inicia el for.
								if (j == 1 && posicionAleatoriaColumna + i < COLUMNAS)
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
								else if (j == 4 && posicionAleatoriaFila + i < FILAS)
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

					// Hacemos lo mismo para el otro jugador.

					// Convertimos la variable de iteración i (que a su vez es el tamaño de los barcos) en un char para poder meterlo en la matriz del tablero. Esta parte le pregunté a la IA cómo hacerlo y me dió varias opciones, elegí esta.
					tamanyoBarco = i + '0';

					// Booleano para saber cuándo un barco ha sido colocado.
					barcoColocado = false;

					// En caso de que un barco haya sido colocado, salimos del bucle y aumentamos una iteración el for anterior para pasar al siguiente tamaño de barco.
					while (!barcoColocado)
					{
						// Generamos una posicion aleatoria del 0 al 9 (tamaño del tablero) para FILAS y COLUMNAS que se regenera en caso de que no haya sido posible colocar un barco desde la posicion aleatoria en ninguna posición.
						int posicionAleatoriaFila = rand() % FILAS, posicionAleatoriaColumna = rand() % COLUMNAS;

						// Bucle para iterar entre las posiciones posibles (como en un cuadrante [1: Derecha, 2: Arriba, 3: Izquierda, 4: Abajo]).
						for (int j = 1; j <= 4; j++)
						{
							// Booleano para saber si un barco esta intentando ser superpuesto sobre otro, false para que en caso de no entrar en la condición de colocación se interprete como que no se ha podido colocar.
							bool superpuesto = false;

							// Comprobamos si la posición inicial es agua o barco. Si es agua procedemos a hacer más comprobaciones. Si no, regeneramos la posición inicial.
							if (tableroJugador2[posicionAleatoriaFila][posicionAleatoriaColumna] == '~')
							{
								// Para la direccion 1 (derecha) y además comprobamos si el barco queda dentro del tablero e inicia el for.
								if (j == 1 && posicionAleatoriaColumna + i < COLUMNAS)
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
								else if (j == 4 && posicionAleatoriaFila + i < FILAS)
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
			}
			else if (opcionPaginaBarcos == '2')
			{
				bool barcosJugador1Colocados = false, barcosJugador2Colocados = false;
				int turnoColocar = 0;
				while (!barcosJugador1Colocados || !barcosJugador2Colocados)
				{
					bool barcoColocado = false, imposibleColocar, posibleColocarDerecha, posibleColocarArriba, posibleColocarIzquierda, posibleColocarAbajo;
					int filaColocar, columnaColocar, direccionColocar;

					system("cls");

					if (turnoColocar % 2 == 0)
					{
#pragma region colocacion_manual_Jugador_1

						std::cout << "JUGADOR 1, coloque sus barcos:" << std::endl << std::endl;

						while (!barcosJugador1Colocados)
						{
							for (int i = barcoMasPequenyo; i <= barcoMasGrande; i++)
							{
								barcoColocado = false;
								char tamanyoBarco = i + '0';

								while (!barcoColocado)
								{
									for (int i = 0; i < FILAS; i++)
									{
										for (int j = 0; j < COLUMNAS; j++)
										{
											std::cout << " " << tableroGameplayJugador1[i][j];

										}
										std::cout << std::endl;
									}

									std::cout << std::endl;

									do
									{
										imposibleColocar = false;
										posibleColocarAbajo = true;
										posibleColocarArriba = true;
										posibleColocarDerecha = true;
										posibleColocarIzquierda = true;

										do
										{
											std::cout << "Seleccione la fila en la que desea colocar el barco de tamanyo " << i << ": ";
											std::cin >> filaColocar;
											filaColocar--;

											if (filaColocar < 0 || filaColocar > FILAS - 1)
											{
												std::cout << "Esa fila no existe." << std::endl;
											}
										} while (filaColocar < 0 || filaColocar > FILAS - 1);


										do
										{
											std::cout << "Seleccione la columna en la que desea colocar el barco de tamanyo " << i << ": ";
											std::cin >> columnaColocar;
											columnaColocar--;

											if (columnaColocar < 0 || columnaColocar > COLUMNAS - 1)
											{
												std::cout << "Esa columna no existe." << std::endl;
											}
										} while (columnaColocar < 0 || columnaColocar > COLUMNAS - 1);

										for (int j = 0; j < FILAS; j++)
										{
											for (int k = 0; k < COLUMNAS; k++)
											{
												for (int l = 0; l < 4; l++)
												{
													if (l == 0 && columnaColocar + (i - 1) > COLUMNAS)
													{
														for (int m = 0; m < i; m++)
														{
															if (tableroGameplayJugador1[j][k + m] != '~')
															{
																posibleColocarDerecha = false;
																break;
															}
														}
													}
													else if (l == 1 && filaColocar - (i - 1) < 0)
													{
														for (int m = 0; m < i; m++)
														{
															if (tableroGameplayJugador1[j - m][k] != '~')
															{
																posibleColocarArriba = false;
																break;
															}
														}
													}
													else if (l == 2 && columnaColocar - (i - 1) < 0)
													{
														for (int m = 0; m < i; m++)
														{
															if (tableroGameplayJugador1[j][k - m] != '~')
															{
																posibleColocarIzquierda = false;
																break;
															}
														}
													}
													else if (l == 3 && filaColocar + (i - 1) > FILAS)
													{
														for (int m = 0; m < i; m++)
														{
															if (tableroGameplayJugador1[j + m][k] != '~')
															{
																posibleColocarAbajo = false;
																break;
															}
														}
													}
													else
													{
														if (filaColocar + i >= FILAS)
														{
															posibleColocarAbajo = false;
														}
														else if (columnaColocar - i <= 0)
														{
															posibleColocarIzquierda = false;
														}
														else if (filaColocar - i <= 0)
														{
															posibleColocarArriba = false;
														}
														else if (columnaColocar + i >= COLUMNAS)
														{
															posibleColocarDerecha = false;
														}
													}

												}
											}
										}

										if (!posibleColocarAbajo && !posibleColocarArriba && !posibleColocarDerecha && !posibleColocarIzquierda)
										{
											imposibleColocar = true;
											std::cout << "No es posible colocar este barco." << std::endl;
										}


									} while (imposibleColocar);



									std::cout << "Direcciones posibles:" << std::endl;
									std::cout << "1) Derecha." << std::endl;
									std::cout << "2) Arriba." << std::endl;
									std::cout << "3) Izquierda." << std::endl;
									std::cout << "4) Abajo." << std::endl;

									do
									{
										std::cout << "Seleccione una opcion3: ";
										std::cin >> direccionColocar;

										if (direccionColocar != 1 && direccionColocar != 2 && direccionColocar != 3 && direccionColocar != 4)
										{
											std::cout << "Esa direccion no existe." << std::endl;
										}

									} while ((direccionColocar != 1 && direccionColocar != 2 && direccionColocar != 3 && direccionColocar != 4));


									if (direccionColocar == 1 && posibleColocarDerecha)
									{
										for (int l = 0; l < i; l++)
										{
											tableroGameplayJugador1[filaColocar][columnaColocar + l] = tamanyoBarco;
										}
										barcoColocado = true;
									}
									else if (direccionColocar == 2 && posibleColocarArriba)
									{
										for (int l = 0; l < i; l++)
										{
											tableroGameplayJugador1[filaColocar - l][columnaColocar] = tamanyoBarco;
										}
										barcoColocado = true;
									}
									else if (direccionColocar == 3 && posibleColocarIzquierda)
									{
										for (int l = 0; l < i; l++)
										{
											tableroGameplayJugador1[filaColocar][columnaColocar - l] = tamanyoBarco;
										}
										barcoColocado = true;
									}
									else if (direccionColocar == 4 && posibleColocarAbajo)
									{
										for (int l = 0; l < i; l++)
										{
											tableroGameplayJugador1[filaColocar + l][columnaColocar] = tamanyoBarco;
										}
										barcoColocado = true;
									}

									system("cls");
									if (i == barcoMasGrande && barcoColocado)
									{
										barcosJugador1Colocados = true;
										turnoColocar++;
										break;
									}

									if (!barcoColocado)
									{
										std::cout << "El barco no se puede colocar en esa posicion." << std::endl;
									}

									std::cout << "JUGADOR 1, coloque sus barcos:" << std::endl << std::endl;
								}
							}
						}
#pragma endregion
					}
					else
					{

#pragma region colocacion_manual_Jugador_2

						std::cout << "JUGADOR 2, coloque sus barcos:" << std::endl << std::endl;

						while (!barcosJugador2Colocados)
						{
							for (int i = barcoMasPequenyo; i <= barcoMasGrande; i++)
							{
								barcoColocado = false;
								char tamanyoBarco = i + '0';

								while (!barcoColocado)
								{
									for (int i = 0; i < FILAS; i++)
									{
										for (int j = 0; j < COLUMNAS; j++)
										{
											std::cout << " " << tableroGameplayJugador2[i][j];

										}
										std::cout << std::endl;
									}

									std::cout << std::endl;

									do
									{
										imposibleColocar = false;
										posibleColocarAbajo = true;
										posibleColocarArriba = true;
										posibleColocarDerecha = true;
										posibleColocarIzquierda = true;

										do
										{
											std::cout << "Seleccione la fila en la que desea colocar el barco de tamanyo " << i << ": ";
											std::cin >> filaColocar;
											filaColocar--;

											if (filaColocar < 0 || filaColocar > FILAS - 1)
											{
												std::cout << "Esa fila no existe." << std::endl;
											}
										} while (filaColocar < 0 || filaColocar > FILAS - 1);


										do
										{
											std::cout << "Seleccione la columna en la que desea colocar el barco de tamanyo " << i << ": ";
											std::cin >> columnaColocar;
											columnaColocar--;

											if (columnaColocar < 0 || columnaColocar > COLUMNAS - 1)
											{
												std::cout << "Esa columna no existe." << std::endl;
											}
										} while (columnaColocar < 0 || columnaColocar > COLUMNAS - 1);

										for (int j = 0; j < FILAS; j++)
										{
											for (int k = 0; k < COLUMNAS; k++)
											{
												for (int l = 0; l < 4; l++)
												{
													if (l == 0 && columnaColocar + (i - 1) > COLUMNAS)
													{
														for (int m = 0; m < i; m++)
														{
															if (tableroGameplayJugador2[j][k + m] != '~')
															{
																posibleColocarDerecha = false;
																break;
															}
														}
													}
													else if (l == 1 && filaColocar - (i - 1) < 0)
													{
														for (int m = 0; m < i; m++)
														{
															if (tableroGameplayJugador2[j - m][k] != '~')
															{
																posibleColocarArriba = false;
																break;
															}
														}
													}
													else if (l == 2 && columnaColocar - (i - 1) < 0)
													{
														for (int m = 0; m < i; m++)
														{
															if (tableroGameplayJugador2[j][k - m] != '~')
															{
																posibleColocarIzquierda = false;
																break;
															}
														}
													}
													else if (l == 3 && filaColocar + (i - 1) > FILAS)
													{
														for (int m = 0; m < i; m++)
														{
															if (tableroGameplayJugador2[j + m][k] != '~')
															{
																posibleColocarAbajo = false;
																break;
															}
														}
													}
													else
													{
														if (filaColocar + i >= FILAS)
														{
															posibleColocarAbajo = false;
														}
														else if (columnaColocar - i <= 0)
														{
															posibleColocarIzquierda = false;
														}
														else if (filaColocar - i <= 0)
														{
															posibleColocarArriba = false;
														}
														else if (columnaColocar + i >= COLUMNAS)
														{
															posibleColocarDerecha = false;
														}
													}

												}
											}
										}

										if (!posibleColocarAbajo && !posibleColocarArriba && !posibleColocarDerecha && !posibleColocarIzquierda)
										{
											imposibleColocar = true;
											std::cout << "No es posible colocar este barco." << std::endl;
										}


									} while (imposibleColocar);



									std::cout << "Direcciones posibles:" << std::endl;
									std::cout << "1) Derecha." << std::endl;
									std::cout << "2) Arriba." << std::endl;
									std::cout << "3) Izquierda." << std::endl;
									std::cout << "4) Abajo." << std::endl;

									do
									{
										std::cout << "Seleccione una opcion: ";
										std::cin >> direccionColocar;

										if (direccionColocar != 1 && direccionColocar != 2 && direccionColocar != 3 && direccionColocar != 4)
										{
											std::cout << "Esa direccion no existe." << std::endl;
										}

									} while ((direccionColocar != 1 && direccionColocar != 2 && direccionColocar != 3 && direccionColocar != 4));


									if (direccionColocar == 1 && posibleColocarDerecha)
									{
										for (int l = 0; l < i; l++)
										{
											tableroGameplayJugador2[filaColocar][columnaColocar + l] = tamanyoBarco;
										}
										barcoColocado = true;
									}
									else if (direccionColocar == 2 && posibleColocarArriba)
									{
										for (int l = 0; l < i; l++)
										{
											tableroGameplayJugador2[filaColocar - l][columnaColocar] = tamanyoBarco;
										}
										barcoColocado = true;
									}
									else if (direccionColocar == 3 && posibleColocarIzquierda)
									{
										for (int l = 0; l < i; l++)
										{
											tableroGameplayJugador2[filaColocar][columnaColocar - l] = tamanyoBarco;
										}
										barcoColocado = true;
									}
									else if (direccionColocar == 4 && posibleColocarAbajo)
									{
										for (int l = 0; l < i; l++)
										{
											tableroGameplayJugador2[filaColocar + l][columnaColocar] = tamanyoBarco;
										}
										barcoColocado = true;
									}

									system("cls");

									if (i == barcoMasGrande && barcoColocado)
									{
										barcosJugador2Colocados = true;
										todoListo = true;
										break;
									}

									if (!barcoColocado)
									{
										std::cout << "El barco no se puede colocar en esa posicion." << std::endl;
									}

									std::cout << "JUGADOR 2, coloque sus barcos:" << std::endl << std::endl;
								}
							}
						}
#pragma endregion

					}
				}
				
				

				
			}
			else if (opcionPaginaBarcos == '3')
			{
				todoListo = false;
				break;
			}
		}
		else if (opcionPaginaPrincipal == '2')
		{

		}
	}
	




	



	std::cout << std::endl;

	// Detenemos la ejecución del programa hasta que se presione una tecla
	system("pause");










	system("cls");

	// Imprimimos los dos tableros.
	std::cout << "TABLERO JUGADOR 1:" << std::endl;

	for (int i = 0; i < FILAS; i++)
	{
		for (int j = 0; j < COLUMNAS; j++)
		{
			std::cout << " " << tableroJugador1[i][j];

		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "TABLERO JUGADOR 2:" << std::endl;

	for (int i = 0; i < FILAS; i++)
	{
		for (int j = 0; j < COLUMNAS; j++)
		{
			std::cout << " " << tableroJugador2[i][j];

		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Detenemos la ejecución del programa hasta que se presione una tecla
	system("pause");

#pragma region gameplay

	while (cantidadOsJugador1 < cantidadOsTotal && cantidadOsJugador2 < cantidadOsTotal)
	{
		// Limpiamos la pantalla. Esta parte me la dijo la IA.
		system("cls");

		if (contadorTurno % 2 == 0)
		{
			// Indicamos a los jugadores de quién es el turno.
			std::cout << "TURNO JUGADOR 1:" << std::endl << std::endl;

			//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
			std::cout << "TABLERO DEL JUGADOR 2:" << std::endl;

			for (int i = 0; i < FILAS; i++)
			{
				for (int j = 0; j < COLUMNAS; j++)
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

				if (cantidadOsJugador1 == cantidadOsTotal)
				{
					break;
				}
			}

			// Limpiamos la pantalla. Esta parte me la dijo la IA.
			system("cls");

			// Indicamos a los jugadores de quién es el turno.
			std::cout << "TURNO JUGADOR 1:" << std::endl << std::endl;

			//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
			std::cout << "TABLERO DEL JUGADOR 2:" << std::endl;

			for (int i = 0; i < FILAS; i++)
			{
				for (int j = 0; j < COLUMNAS; j++)
				{
					std::cout << " " << tableroGameplayJugador2[i][j];

				}
				std::cout << std::endl;
			}
		}
		else
		{
			// Indicamos a los jugadores de quién es el turno.
			std::cout << "TURNO JUGADOR 2:" << std::endl << std::endl;

			//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
			std::cout << "TABLERO DEL JUGADOR 1:" << std::endl;

			for (int i = 0; i < FILAS; i++)
			{
				for (int j = 0; j < COLUMNAS; j++)
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

				if (cantidadOsJugador2 == cantidadOsTotal)
				{
					break;
				}
			}

			// Limpiamos la pantalla. Esta parte me la dijo la IA.
			system("cls");

			// Indicamos a los jugadores de quién es el turno.
			std::cout << "TURNO JUGADOR 2:" << std::endl << std::endl;

			//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
			std::cout << "TABLERO DEL JUGADOR 1:" << std::endl;

			for (int i = 0; i < FILAS; i++)
			{
				for (int j = 0; j < COLUMNAS; j++)
				{
					std::cout << " " << tableroGameplayJugador1[i][j];

				}
				std::cout << std::endl;
			}
		}

		Sleep(1500);

		contadorTurno++;
	}

	if (cantidadOsJugador1 >= cantidadOsTotal)
	{
		//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
		std::cout << std::endl << "TABLERO DEL JUGADOR 2:" << std::endl;

		for (int i = 0; i < FILAS; i++)
		{
			for (int j = 0; j < COLUMNAS; j++)
			{
				std::cout << " " << tableroGameplayJugador2[i][j];

			}
			std::cout << std::endl;
		}

		std::cout << std::endl;

		std::cout << "El jugador 1 gana! Enhorabuena, has hundido la flota de tu rival." << std::endl;
	}
	else if (cantidadOsJugador2 >= cantidadOsTotal)
	{
		//Imprimimos el tablero del jugador contrario para que el jugador actual pueda visualizar mejor la posición a atacar.
		std::cout << std::endl << "TABLERO DEL JUGADOR 1:" << std::endl;

		for (int i = 0; i < FILAS; i++)
		{
			for (int j = 0; j < COLUMNAS; j++)
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

