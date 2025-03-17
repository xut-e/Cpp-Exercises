/*  11.Crea un programa que pida al usuario tantos números como quiera, al
 finalizar pedirá otro número al usuario para que sea el offset, este debe de
 copiar todos los elementos en otro vector con el offset. Ejemplo offset = 1:
 {0, 1, 2, 3}-> {3, 0, 1, 2}. */

 #include <iostream>
 #include <queue>
 
 int main() {
     std::vector<int> numeros, numerosConOffset;
     int numeroIntroducido, offset;
     char opcion;
 
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
 
     do
     {
         std::cout << "Introduce un valor de offset (debe ser mayor que 0): ";
         std::cin >> offset;
     } while (offset <= 0);
 
     for (size_t i = numeros.size() - offset; i < numeros.size(); i++)
     {
         numerosConOffset.push_back(numeros[i]);
     }
     for (size_t i = 0; i < numeros.size() - offset; i++)
     {
         numerosConOffset.push_back(numeros[i]);
     }
 
     std::cout << "Antes del cambio:" << std::endl << "[";
 
     for (size_t i = 0; i < numeros.size(); i++)
     {
         std::cout << numeros[i];
 
         if (i < numeros.size() - 1)
         {
             std::cout << ", ";
         }
     }
 
     std::cout << "]" << std::endl << "Despues del cambio:" << std::endl << "[";
 
     for (size_t i = 0; i < numerosConOffset.size(); i++)
     {
         std::cout << numerosConOffset[i];
 
         if (i < numerosConOffset.size() - 1)
         {
             std::cout << ", ";
         }
     }
 
     std::cout << "]";
 
     return 0;
 }