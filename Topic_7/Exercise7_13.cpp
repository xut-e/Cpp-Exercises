/* 13.Crea un programa que pedirá números al usuario. Cuando finalice el
programa debe de indicar cual es el número más pequeño, eliminarlo y
mostrar el resultado. */

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> numeros;
    int numeroIntroducido, numeroMenor, posicionNumeroMenor;
    char opcion;

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

    numeroMenor = numeroIntroducido;

    for (size_t i = 0; i < numeros.size(); i++)
    {
        if (numeros[i] < numeroMenor)
        {
            numeroMenor = numeros[i];
        }
    }

    std::cout << "El numero menor es: " << numeroMenor << std::endl;
    
    std::cout << "Antes de la modificacion:" << std::endl << "[";

    for (size_t i = 0; i < numeros.size(); i++)
    {
        std::cout << numeros[i];

        if (i < numeros.size() - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;

    for (size_t i = 0; i < numeros.size(); i++)
    {
        if (numeroMenor == numeros[i])
        {
            posicionNumeroMenor = i;
            break;
        }
    }

    numeros.erase(numeros.begin() + posicionNumeroMenor);

    std::cout << "Despues de la modificacion:" << std::endl << "[";

    for (size_t i = 0; i < numeros.size(); i++)
    {
        std::cout << numeros[i];

        if (i < numeros.size() - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;

	return 0;
}

