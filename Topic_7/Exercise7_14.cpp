/* 14.Crea un programa que permita al usuario introducir números, eliminarlos y
finalizar el programa. La opción de eliminar debe de pedir al usuario qué
número desea eliminar y mostrar el resultado tras la eliminación. */

#include <iostream>
#include <list>

int main() {
    std::list<int> numeros;
    int numeroIntroducido, numeroAEliminar, contador;
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

    std::cout << std::endl << "Numeros:" << std::endl << "[";

    contador = 0;

    for (int i : numeros)
    {
        if (contador > 0)
        {
            std::cout << ", ";
        }

        std::cout << i;

        contador++;
    }

    std::cout << "]" << std::endl;

    std::cout << "Quieres eliminar algun numero? (s/n): ";

    do
    {
        std::cin >> opcion;
    } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');

    if (opcion == 's' || opcion == 'S')
    {
        do
        {

            std::cout << "Introduce un numero a eliminar: ";
            std::cin >> numeroAEliminar;

            numeros.remove(numeroAEliminar);

            std::cout << std::endl << "Ultima actualizacion:" << std::endl << "[";

            contador = 0;

            for (int i : numeros)
            {
                if (contador > 0)
                {
                    std::cout << ", ";
                }

                std::cout << i;

                contador++;
            }

            std::cout << "]" << std::endl;

            std::cout << "Deseas continuar eliminando numeros? (s/n): ";

            do
            {
                std::cin >> opcion;
            } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');


        } while (opcion == 's' || opcion == 'S');
    }

	return 0;
}

