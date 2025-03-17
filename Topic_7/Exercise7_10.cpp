/*  10.Crea un programa que pida números al usuario. Tras insertarlos el programa
 pedirá al usuario dos números, los cambiará de posición y mostrará el
 resultado. */

 #include <iostream>
 #include <queue>
 
 int main() {
     std::vector<int> numeros;
     int numeroIntroducido, posicion1, posicion2;
     char opcion;
     bool palindromo = true, opcionesCorrectas;
 
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
 
     std::cout << "Introduce una posicion para cambiar (1-" << numeros.size() << "): ";
     do
     {
         std::cin >> posicion1;
         posicion1--;
 
         if (posicion1 < 0 || posicion1 >= numeros.size())
         {
             std::cout << "Posicion elegida fuera del rango, elija otra: ";
         }
     } while (posicion1 < 0 || posicion1 >= numeros.size());
 
     std::cout << "Introduce otra posicion para cambiar (1-" << numeros.size() << "): ";
     do
     {
         std::cin >> posicion2;
         posicion2--;
 
         if (posicion2 < 0 || posicion2 >= numeros.size())
         {
             std::cout << "Posicion elegida fuera del rango, elija otra posicion: ";
         }
 
         if (posicion1 == posicion2)
         {
             std::cout << "Cambiar un numero por su propia posicion no tiene sentido, elija otra posicion: ";
         }
     } while ((posicion2 < 0 || posicion2 >= numeros.size()) || posicion2 == posicion1);
 
     std::cout << "Antes del cambio:" << std::endl << "[";
 
     for (size_t i = 0; i < numeros.size(); i++)
     {
         std::cout << numeros[i];
 
         if (i < numeros.size() - 1)
         {
             std::cout << ", ";
         }
     }
 
     std::swap(numeros[posicion1], numeros[posicion2]);
 
     std::cout << "]" << std::endl << "Despues del cambio:" << std::endl << "[";
 
     for (size_t i = 0; i < numeros.size(); i++)
     {
         std::cout << numeros[i];
 
         if (i < numeros.size() - 1)
         {
             std::cout << ", ";
         }
     }
 
     std::cout << "]";
 
     return 0;
 }