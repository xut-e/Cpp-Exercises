/* 16. Crea un programa que pida palabras al usuario, al finalizar debe de mostrar
las palabras en orden pero escritas del revés. */

#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<std::string> palabras;
    std::string palabraIntroducida;
    char opcion;

    do
    {
        std::cout << "Introduce una palabra: ";
        std::cin >> palabraIntroducida;

        palabras.push(palabraIntroducida);

        std::cout << "Deseas continuar introduciendo palabras? (s/n): ";

        do
        {
            std::cin >> opcion;
        } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');

    } while (opcion == 's' || opcion == 'S');

    std::cout << "[";

    while (!palabras.empty())
    {
        std::cout << palabras.top() << " ";
        palabras.pop();
    }

    std::cout << "]";

	return 0;
}

