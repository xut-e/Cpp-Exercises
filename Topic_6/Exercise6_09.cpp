/* 9. Crea un programa que dadas dos strings con el formato
[número_versión].[número_subversión].[número_parche] (ejemplo 1.4.5)
identifique cuál de ambas versiones está más actualizada.*/

#include <iostream>
#include <string>

int main() {
    std::string v1, v2;
    int contadorNumeros = 0;
    int version_v1 = 0, subversion_v1 = 0, parche_v1 = 0;
    int version_v2 = 0, subversion_v2 = 0, parche_v2 = 0;

    std::cout << "Introduce una version ([version].[subversion].[parche] Ej: 1.4.5): ";
    std::getline(std::cin, v1);
    std::cout << "Introduce otra version: ";
    std::getline(std::cin, v2);

    contadorNumeros = 0;
    for (int i = 0; i < v1.length(); i++) {
        if (v1[i] == '.')
        {
            break;
        }
        version_v1 = version_v1 * 10 + (v1[i] - '0');
        contadorNumeros++;
    }

    contadorNumeros++;
    subversion_v1 = 0;
    for (int i = contadorNumeros; i < v1.length(); i++) {
        if (v1[i] == '.')
        {
            break;
        }
        subversion_v1 = subversion_v1 * 10 + (v1[i] - '0');
        contadorNumeros++;
    }

    contadorNumeros++;
    parche_v1 = 0;
    for (int i = contadorNumeros; i < v1.length(); i++) {
        parche_v1 = parche_v1 * 10 + (v1[i] - '0');
    }

    contadorNumeros = 0;
    for (int i = 0; i < v2.length(); i++) {
        if (v2[i] == '.')
        {
            break;
        }
        
        version_v2 = version_v2 * 10 + (v2[i] - '0');
        contadorNumeros++;
    }

    contadorNumeros++;
    subversion_v2 = 0;
    for (int i = contadorNumeros; i < v2.length(); i++) {
        if (v2[i] == '.')
        {
            break;
        }
            
        subversion_v2 = subversion_v2 * 10 + (v2[i] - '0');
        contadorNumeros++;
    }

    contadorNumeros++;
    parche_v2 = 0;
    for (int i = contadorNumeros; i < v2.length(); i++) {
        parche_v2 = parche_v2 * 10 + (v2[i] - '0');
    }

    if (version_v1 > version_v2) {
        std::cout << "La version 1 es la mas reciente." << std::endl;
    }
    else if (version_v1 < version_v2) {
        std::cout << "La version 2 es la mas reciente." << std::endl;
    }
    else {
        if (subversion_v1 > subversion_v2) {
            std::cout << "La version 1 es la mas reciente." << std::endl;
        }
        else if (subversion_v1 < subversion_v2) {
            std::cout << "La version 2 es la mas reciente." << std::endl;
        }
        else {
            if (parche_v1 > parche_v2) {
                std::cout << "La version 1 es la mas reciente." << std::endl;
            }
            else if (parche_v1 < parche_v2) {
                std::cout << "La version 2 es la mas reciente." << std::endl;
            }
            else {
                std::cout << "Son la misma version." << std::endl;
            }
        }
    }

    return 0;
}