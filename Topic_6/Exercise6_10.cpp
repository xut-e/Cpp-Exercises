/* 10.Crea una programa que transforme una frase en un acrónimo de ella usando
 la inicial de cada palabra que forma la frase. */

#include <iostream>
#include <string>

int main() {
    std::string frase, acronimo;

    std::cout << "Introduce una frase: ";
    std::getline(std::cin, frase);

    for (int i = 0; i < frase.length(); i++)
    {
        if (i == 0 && frase[i] != ' ')
        {
            acronimo += frase[i];
        }
        else if (frase[i] == ' ' && i < frase.length() - 1)
        {
            acronimo += frase[i + 1];
        }
    }

    

    for (int i = 0; i < acronimo.length(); i++)
    {
        std::cout << acronimo[i];
    }
    std::cout << std::endl;

    return 0;
}