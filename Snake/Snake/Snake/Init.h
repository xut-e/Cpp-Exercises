#pragma once
#include "Structs.h"
#include "Const.h"
#include <vector>

void inicializarTablero(char tablero[HEIGHT][WIDTH]);
elementosJuego inicializarJuego(char tablero[HEIGHT][WIDTH]);
void modificarTablero(char tablero[HEIGHT][WIDTH], elementosJuego& elementos);
void printarTablero(char tablero[HEIGHT][WIDTH]);
Posicion elegirPosicionManzana(char tablero[HEIGHT][WIDTH]);
void comprobarColisiones(Posicion nuevaCabeza, bool& bGameOver, elementosJuego& juego);
void controlarSnakeYManzana(elementosJuego& juego, Posicion nuevaCabeza, char tablero[HEIGHT][WIDTH], int& puntuacion);
