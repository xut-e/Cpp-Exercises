/* 9. Crea un programa que pida números al usuario. Tras insertarlos debe de
 verificar si los valores introducidos forman un palíndromo. */

 #include <iostream>
 #include <queue>
 
 int main() {
     std::vector<int> numeros;
     int numeroIntroducido;
     char opcion;
     bool palindromo = true;
 
     do
     {
         std::cout << "Introduce el primer numero: ";
         std::cin >> numeroIntroducido;
 
         numeros.push_back(numeroIntroducido);
 
         std::cout << "Deseas seguir introduciendo numeros? (s/n): ";
 
         do
         {
             std::cin >> opcion;
         } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
 
     } while (opcion == 's' || opcion == 'S');
 
     for (size_t i = 0; i < numeros.size() / 2; i++)
     {
         if (numeros[i] != numeros[numeros.size() - 1 - i])
         {
             palindromo = false;
             break;
         }
     }
 
     if (palindromo)
     {
         std::cout << "Los numeros introducidos forman un palindromo!" << std::endl;
     }
     else
     {
         std::cout << "Los numeros introducidos no forman un palindromo!" << std::endl;
     }
 
     return 0;
 }