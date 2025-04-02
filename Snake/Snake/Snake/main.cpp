#include "Init.h"
#include "keyboard.h"
#include "Const.h"
#include <time.h>
#include <iostream>
#include <chrono>
#include <thread>

int main() {

    srand(time(0));

    char tablero[HEIGHT][WIDTH];
    inicializarTablero(tablero);

    elementosJuego juego = inicializarJuego(tablero);

    Posicion nuevaCabeza = juego.snake[0];

    bool bGameOver = false;
    int direccion = 0; //0: derecha, 1: arriba, 2: izquierda, 3: abajo
    int puntuacion = 0;
    int opcion, velocidad;

    std::cout << "                        WELCOME" << std::endl;
    std::cout << "                           TO" << std::endl;
    std::cout << "            _____ ____    ____  __  _    ___" << std::endl;
    std::cout << "           / ___/|    \\  /    ||  |/ ]  /  _]" << std::endl;
    std::cout << "          (   \\_ |  _  ||  o  ||  ' /  /  [_ " << std::endl;
    std::cout << "           \\__  ||  |  ||     ||    \\ |    _]" << std::endl;
    std::cout << "           /  \\ ||  |  ||  _  ||     ||    [_" << std::endl;
    std::cout << "           \\    ||  |  ||  |  ||  .  ||     |" << std::endl;
    std::cout << "            \\___||__|__||__|__||__|\\_||_____|" << std::endl;
    std::cout << "                       (the game)" << std::endl << std::endl;
    
    system("pause");

    std::cout << "                   MENU" << std::endl;
    std::cout << "\t" << "1) Jugar." << std::endl;
    std::cout << "\t" << "2) Cambiar dificultad." << std::endl;

    do
    {
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;
    } while (opcion != 1 && opcion != 2);
    //While game is not over execute game loop

    if (opcion == 2)
    {
        std::cout << "Elige una dificultad entre 50 y 300, por defecto 150 (mayor numero -> menor dificultad): ";

        do
        {
            std::cin >> velocidad;
        } while (velocidad < 50 || velocidad > 300);

        FRAME_RATE = velocidad;
    }
    
    while (!bGameOver) {

        if (IsWPressed() && direccion != 3)
        {
            direccion = 1;
        }
        if (IsAPressed() && direccion != 0)
        {
            direccion = 2;
        }
        if (IsSPressed() && direccion != 1)
        {
            direccion = 3;
        }
        if (IsDPressed() && direccion != 2)
        {
            direccion = 0;
        }

        

        switch (direccion)
        {
        case 0:
            nuevaCabeza.y++;
            break;
        case 1:
            nuevaCabeza.x--;
            break;
        case 2:
            nuevaCabeza.y--;
            break;
        case 3:
            nuevaCabeza.x++;
            break;
        }

        juego.snake.insert(juego.snake.begin(), nuevaCabeza);

        comprobarColisiones(nuevaCabeza, bGameOver, juego);

        if (!bGameOver) {
            controlarSnakeYManzana(juego, nuevaCabeza, tablero, puntuacion);
        }
        else
        {
            break; // Salir del bucle del juego
        }

        

        system("cls");

        modificarTablero(tablero, juego);

        std::cout << "Score: " << puntuacion << std::endl;

        printarTablero(tablero);

        //Sleep main thread to control game speed execution
        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));

        puntuacion += (juego.snake.size() - 1);
    }
    // He a�adido este pause porque dependiendo de la velocidad, sobre todo con las velocidades m�s altas, a veces se cerraba el juego sin dejarte ver la puntuaci�n.
    system("pause");

    return 0;
}
