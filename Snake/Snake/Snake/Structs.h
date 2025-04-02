#pragma once
#include <vector>

struct Posicion {
	int x = 0;
	int y = 0;
};



struct elementosJuego {
	Posicion manzana;

	std::vector<Posicion> snake;
	// La posici�n 0 del vector Posicion "snake" es la cabeza, el resto se a�ade al capturar manzanas.
};