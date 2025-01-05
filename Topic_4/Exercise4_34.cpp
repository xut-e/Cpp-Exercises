/* 34.Crea un programa que haga la recreación del juego de casino 21 Blackjack.
 El usuario iniciará con 500€ y debe de alcanzar los 2,000€ para ganar.
 Pierde si se queda sin dinero. Al inicio de la ronda se le mostrará la cantidad
 que tiene y se le pedirá la cantidad a apostar. Primero jugará él, cada vez
 que se roba una carta el programa indicará la carta robada (solo
 trabajaremos con números del 1 al 10, sin pilas ni colores), cuanto lleva
 acumulado y le dará la opción de plantarse o seguir robando. Una vez
 finalizado su turno el programa recrea la banca y le mostrará paso a paso
 sus jugadas, al finalizar si no ha alcanzado los 2,000€ ni ha perdido se
 iniciará de nuevo la ronda pidiendo cantidad a apostar. */

#include <iostream>
#include <time.h>

void main() {
    int dineroActual = 500, cartaSacada, cartaNueva = 1, contador, cantidadTotalUsuario, cantidadTotalDealer;
    float cantidadApostada;
    srand(time(0));
 
    std::cout << "Bienvenido a BLACK JACK" << std::endl;

    while (dineroActual < 2000 && dineroActual > 0)
    {
        cantidadTotalUsuario = 0;
        cantidadTotalDealer = 0;

        do
        {
            std::cout << "Introduzca la cantidad de dinero que desea apostar: ";
            std::cin >> cantidadApostada;

            if (cantidadApostada < 0)
            {
                std::cout << "No puedes apostar dinero negativo." << std::endl;
            }
            else if (cantidadApostada == 0)
            {
                std::cout << "No puedes apostar 0 euros." << std::endl;
            }
            else if (cantidadApostada > dineroActual)
            {
                std::cout << "No dispones de tanto dinero, solo tienes " << dineroActual << " euros." << std::endl;
            }
        } while (cantidadApostada <= 0 || cantidadApostada > dineroActual);

        dineroActual -= cantidadApostada;

        while (cantidadTotalUsuario < 21)
        {
       
            cartaSacada = rand() % (10 - 1 + 1) + 1;
            
            while (cartaNueva == 1)
            {
                cantidadTotalUsuario += cartaSacada;

                std::cout << "Has sacado un " << cartaSacada << "." << std::endl;
                std::cout << "Llevas un total de " << cantidadTotalUsuario << " puntos." << std::endl;
                if (cantidadTotalUsuario > 21)
                {
                    break;
                }

                std::cout << "Deseas sacar otra carta?" << std::endl << "\t" << "1) Si." << std::endl << "\t" << "2) No." << std::endl;
                
                do
                {
                    std::cout << "Elige una respuesta: ";
                    std::cin >> cartaNueva;

                    if (cartaNueva != 1 && cartaNueva != 2)
                    {
                        std::cout << "Respuesta no valida." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        cartaNueva = 3;
                    }

                } while (cartaNueva != 1 && cartaNueva != 2);
                #pragma endregion

                if (cartaNueva == 1)
                {
                     cartaSacada = rand() % (10 - 1 + 1) + 1;

                }
                else
                {
                    std::cout << "Te has plantado con " << cantidadTotalUsuario << " puntos." << std::endl;
                    break;
                }
            }
            break;
        }
        if (cantidadTotalUsuario > 21)
        {
            cantidadTotalDealer = 21;
        }
        while (cantidadTotalDealer < 21)
        {
        
            cartaSacada = rand() % (10 - 1 + 1) + 1;

            while (cantidadTotalDealer < 17)
            {
                cantidadTotalDealer += cartaSacada;

                std::cout << "El dealer ha sacado un " << cartaSacada << "." << std::endl;
                std::cout << "Lleva un total de " << cantidadTotalDealer << " puntos." << std::endl;

                


                if (cantidadTotalDealer < 17)
                {
                    cartaSacada = rand() % (10 - 1 + 1) + 1;
                }
                else
                {
                    std::cout << "El dealer se ha plantado con " << cantidadTotalDealer << " puntos." << std::endl;
                    break;
                }
            }
            break;
        }

        if (cantidadTotalUsuario == 21 && cantidadTotalDealer != 21)
        {
            std::cout << "Enhorabuena, has ganado esta ronda con Blackjack! Ganas " << cantidadApostada * (5 / 2) << " euros." << std::endl;
            dineroActual += cantidadApostada * (5 / 2);
        }
        else if (cantidadTotalUsuario < 21 && (cantidadTotalDealer < cantidadTotalUsuario || cantidadTotalDealer > 21))
        {
            std::cout << "Has ganado esta ronda! Ganas " << cantidadApostada * 2 << " euros." << std::endl;
            dineroActual += cantidadApostada * 2;
        }
        else if (cantidadTotalDealer == 21 && cantidadTotalUsuario != 21)
        {
            std::cout << "Has perdido esta ronda! Pierdes tu apuesta." << std::endl;

        }
        else if (cantidadTotalDealer < 21 && (cantidadTotalUsuario < cantidadTotalDealer || cantidadTotalUsuario > 21))
        {
            std::cout << "Has perdido esta ronda! Pierdes tu apuesta." << std::endl;

        }
        else if (cantidadTotalDealer == cantidadTotalUsuario)
        {
            std::cout << "Ha sido un empate! Te corresponden " << cantidadApostada << " euros." << std::endl;
            dineroActual += cantidadApostada;
        }

        cartaNueva = 1;
        std::cout << "Actualmente tienes " << dineroActual << " euros." << std::endl;
    }

    if (dineroActual >= 2000)
    {
        std::cout << "Enhorabuena, has ganado!" << std::endl;
    }
    else if (dineroActual <= 0)
    {
        std::cout << "Vaya, has perdido :(" << std::endl;
    }
}