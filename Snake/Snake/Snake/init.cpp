#include "init.h"
#include <iostream>
#include <time.h>
#include "Const.h"

int FRAME_RATE = 150; //IA

void inicializarTablero(char tablero[HEIGHT][WIDTH]) {

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i == 0 || i == HEIGHT - 1)
			{
				tablero[i][j] = '-';
			}
			else if (j == 0 || j == WIDTH - 1)
			{
				tablero[i][j] = '|';
			}
			else
			{
				tablero[i][j] = ESPACIO;
			}
			
		}
	}
}

void modificarTablero(char tablero[HEIGHT][WIDTH], elementosJuego& elementos) {

	inicializarTablero(tablero);

	tablero[elementos.manzana.x][elementos.manzana.y] = MANZANA;

	tablero[elementos.snake[0].x][elementos.snake[0].y] = CABEZA_SNAKE;

	for (int i = 1; i < elementos.snake.size(); i++)
	{
		tablero[elementos.snake[i].x][elementos.snake[i].y] = CUERPO_SNAKE;
	}
}

void printarTablero(char tablero[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			std::cout << tablero[i][j];
		}
		std::cout << std::endl;
	}
}

Posicion elegirPosicionManzana(char tablero[HEIGHT][WIDTH]) {
	

	bool posicionValida = false;
	int x, y;
	do
	{
		x = rand() % (WIDTH - 2) + 1;
		y = rand() % (HEIGHT - 2) + 1;

		if (tablero[x][y] == ESPACIO)
		{
			posicionValida = true;
		}

	} while (!posicionValida);

	return { x, y };
}

elementosJuego inicializarJuego(char tablero[HEIGHT][WIDTH]) {
	elementosJuego juego;


	juego.manzana = {elegirPosicionManzana(tablero)};
	juego.snake.push_back({POSICION_INICIAL_SERPIENTE_X, POSICION_INICIAL_SERPIENTE_Y});
	
	return { juego };
}

void comprobarColisiones(Posicion nuevaCabeza, bool& bGameOver, elementosJuego& juego) {

	if (nuevaCabeza.x <= 0 || nuevaCabeza.x >= HEIGHT - 1 || nuevaCabeza.y <= 0 || nuevaCabeza.y >= WIDTH - 1)
	{
		bGameOver = true;
	}

	for (size_t i = 1; i < juego.snake.size(); i++) {
		if (nuevaCabeza.x == juego.snake[i].x && nuevaCabeza.y == juego.snake[i].y) {
			bGameOver = true;
			break;
		}
	}
}

void controlarSnakeYManzana(elementosJuego& juego, Posicion nuevaCabeza, char tablero[HEIGHT][WIDTH], int& puntuacion) {

	// Este condicional junto con la linea de insert me lo dijo la IA porque yo estaba intentando a�adirlo al final y no me sal�a
	if (nuevaCabeza.x == juego.manzana.x && nuevaCabeza.y == juego.manzana.y)
	{
		juego.manzana = elegirPosicionManzana(tablero);
		puntuacion += 15;
	}
	else
	{
		juego.snake.pop_back();
	}
}
