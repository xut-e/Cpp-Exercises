/* 12.Crea un programa que identifique el carácter más repetido en una frase. */

#include <iostream>
#include <string>

int main() {
    std::string frase;
    int repeticiones[256] = { 0 };
    int mayorRepetido = 0, contador = 0;
    
    std::cout << "Introduce una frase: ";
    std::getline(std::cin, frase);

    for (int i = 0; i < frase.length(); i++)
    {
        repeticiones[int(frase[i])]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (mayorRepetido < repeticiones[i])
        {
            mayorRepetido = repeticiones[i];
        }
    }

    std::cout << "El caracter mas repetido fue: ";

    for (int i = 0; i < 256; i++)
    {
        if (repeticiones[i] == mayorRepetido)
        {
            std::cout << "\"" << char(i) << "\"";
            contador++;
        }
        
    }

    std::cout << std::endl;

    return 0;
}