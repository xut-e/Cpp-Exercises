/* 8. Crear un programa que pida una frase y remueva las vocales.*/

#include <iostream>
#include <string>

int main() {
    std::string frase;

    std::cout << "Introduce una frase: ";
    std::getline(std::cin, frase);

    int a = 97, e = 101, iLetra = 105, o = 111, u = 117;

    for (int i = 0; i < frase.length(); i++)
    {
        if (int(frase[i]) == a || int(frase[i]) == e || int(frase[i]) == iLetra || int(frase[i]) == o || int(frase[i]) == u || int(frase[i]) == a - 32 || int(frase[i]) == e - 32 || int(frase[i]) == iLetra - 32 || int(frase[i]) == o - 32 || int(frase[i]) == u - 32)
        {
            frase[i] = '\0';
        }
    }

    for (int i = 0; i < frase.length(); i++)
    {
        std::cout << frase[i];
    }

    return 0;
}
