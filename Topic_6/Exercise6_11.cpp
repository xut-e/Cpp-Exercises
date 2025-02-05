/* 11.Crear un programa que pida una frase y cambie la vocal ‘a’ y ‘e’ por la X. */

#include <iostream>
#include <string>

int main() {
    std::string frase, fraseNueva;
    
    std::cout << "Introduce una frase: ";
    std::getline(std::cin, frase);

    for (int i = 0; i < frase.length(); i++)
    {
        if (int(frase[i]) == 65  || int(frase[i]) == 69)
        {
            fraseNueva += 'X';
        }
        else if (int(frase[i]) == 97 || int(frase[i]) == 101)
        {
            fraseNueva += 'x';
        }
        else
        {
            fraseNueva += frase[i];
        }
    }

    for (int i = 0; i < fraseNueva.length(); i++)
    {
        std::cout << fraseNueva[i];
    }
    std::cout << std::endl;

    return 0;
}