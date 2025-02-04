/* 9. Crea un programa que dadas dos strings con el formato
[número_versión].[número_subversión].[número_parche] (ejemplo 1.4.5)
identifique cuál de ambas versiones está más actualizada.*/

#include <iostream>
#include <string>

int main() {
    std::string version1, version2;
    int version_v1, version_v2, subversion_v1, subversion_v2, parche_v1, parche_v2;

    std::cout << "Introduce una version ([version].[subversion].[parche] Ej: 1.4.5): ";
    std::getline(std::cin, version1);

    std::cout << "Introduce otra version: ";
    std::getline(std::cin, version2);


    for (int i = 0; i < version1.length(); i++)
    {
        if ()
    }



    return 0;
}