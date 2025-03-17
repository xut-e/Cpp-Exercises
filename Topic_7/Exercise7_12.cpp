/* 12. Crea un programa que pida varias palabras al usuario, cuando finalice el
usuario debe de introducir una palabra a buscar. El programa deberá indicar
cuantas veces y en qué posiciones se encuentra la palabra. */

#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string palabraIntroducida, palabraABuscar;
	std::vector<std::string> diccionario;
    std::vector<int> posiciones;
    char opcion;
    int contador = 0;

    do
    {
        std::cout << "Introduce una palabra: ";
        std::cin >> palabraIntroducida;

        diccionario.push_back(palabraIntroducida);

        std::cout << "Deseas continuar introduciendo palabras? (s/n): ";

        do
        {
            std::cin >> opcion;
        } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');

    } while (opcion == 's' || opcion == 'S');

    std::cout << "Introduce la palabra a buscar: ";
    std::cin >> palabraABuscar;

    for (size_t i = 0; i < diccionario.size(); i++)
    {
        bool mismaPalabra = true;

        if (diccionario[i].length() == palabraABuscar.length())
        {
            for (size_t j = 0; j < diccionario[i].length(); j++)
            {
                if (diccionario[i][j] != palabraABuscar[j])
                {
                    mismaPalabra = false;
                    break;
                }
            }
            
            if (mismaPalabra)
            {
                contador++;
                posiciones.push_back(i + 1);
            }
        }
        
    }

    std::cout << "La palabra " << palabraABuscar << " aparece un total de " << contador;
    if (contador == 1)
    {
        std::cout << " vez." << std::endl;
        std::cout << "La posicione en las que aparece es: ";
    }
    else
    {
        std::cout << " veces." << std::endl;
        std::cout << "Las posiciones en las que aparece son: ";
    }

    std::cout << "[";

    for (size_t i = 0; i < posiciones.size(); i++)
    {
        std::cout << posiciones[i];

        if (i < posiciones.size() - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;
    

	return 0;
}


