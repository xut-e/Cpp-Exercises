/*  6. Crea un programa que pida al usuario todos los números que quiera. Al
 finalizar mostrará el número mayor y menor de los insertados. */

 #include <iostream>
 #include <vector>
 
 int main() {
     std::vector<int> numeros;
     int numeroIntroducido, numeroMayor, numeroMenor;
     char opcion;
 
     do
     {
         std::cout << "Introduce un numero: ";
         std::cin >> numeroIntroducido;
 
         if (numeros.empty())
         {
             numeroMayor = numeroIntroducido;
             numeroMenor = numeroIntroducido;
         }
 
         numeros.push_back(numeroIntroducido);
 
         std::cout << "Deseas continuar? (s/n): ";
 
         do
         {
             std::cin >> opcion;
         } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
 
     } while (opcion == 's' || opcion == 'S');
     
 
     for (size_t i = 0; i < numeros.size(); i++)
     {
         if (numeroMayor < numeros[i])
         {
             numeroMayor = numeros[i];
         }
         if (numeroMenor > numeros[i])
         {
             numeroMenor = numeros[i];
         }
     }
 
     std::cout << std::endl;
 
     std::cout << "El mayor numero introducido fue: " << numeroMayor << std::endl;
     std::cout << "El menor numero introducido fue: " << numeroMenor << std::endl;
 
     return 0;
 }