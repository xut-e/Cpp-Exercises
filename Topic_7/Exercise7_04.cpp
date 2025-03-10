/* 4. Crea un programa que pida indefinidamente números al usuario hasta que
 este quiera parar. El programa debe de separar los números pares e
 impares en distintas estructuras de almacenamiento. Al final imprimirá los
 números pares y luego los impares. */

 #include <iostream>
 #include <queue>
 
 int main() {
     std::queue<int> pares, impares;
     int numeroIntroducido;
     char opcion;
 
     do
     {
         std::cout << "Introduce un numero: ";
         std::cin >> numeroIntroducido;
         if (numeroIntroducido % 2 == 0)
         {
             pares.push(numeroIntroducido);
         }
         else
         {
             impares.push(numeroIntroducido);
 
         }
 
         std::cout << "Deseas continuar? (s/n): ";
 
         do
         {
             std::cin >> opcion;
         } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
         
     } while (opcion == 's' || opcion == 'S');
 
     std::cout << std::endl << "Numeros pares:" << std::endl;
     while (!pares.empty())
     {
         std::cout << pares.front() << " ";
         pares.pop();
     }
 
     std::cout << std::endl << "Numeros impares:" << std::endl;
     while (!impares.empty())
     {
         std::cout << impares.front() << " ";
         impares.pop();
     }
 
     return 0;
 }