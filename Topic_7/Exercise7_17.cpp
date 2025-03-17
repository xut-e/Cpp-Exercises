/* 17. Crea un programa que pida números al usuario, al finalizar debe de
reordenar todos los valores aleatoriamente y mostrar el resultado. */

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

int main() {
    std::vector<int> numeros;
    int numeroIntroducido;
    char opcion;
    srand(time(NULL));

    do
    {
        std::cout << "Introduce un numero: ";
        std::cin >> numeroIntroducido;

        numeros.push_back(numeroIntroducido);

        std::cout << "Deseas continuar introduciendo numeros? (s/n): ";

        do
        {
            std::cin >> opcion;
        } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');

    } while (opcion == 's' || opcion == 'S');

    std::cout << "Numeros ordenados:" << std::endl << "[";
    for (size_t i = 0; i < numeros.size(); i++) {
        std::cout << numeros[i];
        if (i < numeros.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    for (int i = 0; i < numeros.size(); i++)
    {
        int numeroRandom = rand() % numeros.size();

        std::swap(numeros[i], numeros[numeroRandom]);
    }

    std::cout << "Numeros desordenados:" << std::endl << "[";
    for (size_t i = 0; i < numeros.size(); i++) {
        std::cout << numeros[i];
        if (i < numeros.size() - 1) 
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}



