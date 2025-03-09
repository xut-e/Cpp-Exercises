/* 1. Crea un programa que pida un número al usuario, el programa almacenará
 el número y seguidamente pedirá otro al usuario. Esto debe hacerse
 infinitamente hasta que el usuario quiera, entonces el programa finalizará
 mostrando todos los números introducidos. */

 #include <iostream>
 #include <queue>
 
 int main() {
     std::queue<int> numeros;
     int numeroIntroducido;
     char opcion;
 
     do
     {
         std::cout << "Introduce un numero: ";
         std::cin >> numeroIntroducido;
         numeros.push(numeroIntroducido);
 
         std::cout << "Deseas continuar? (s/n): ";
         std::cin >> opcion;
 
     } while (opcion == 's' || opcion == 'S');
 
     int tamanyo = numeros.size();
     
     std::cout << std::endl << "Numeros introducidos:" << std::endl << "[";

     while (!numeros.empty())
     {
         std::cout << numeros.front();
         numeros.pop();
         tamanyo--;
 
         if (tamanyo > 0)
         {
             std::cout << ", ";
         }
     }
 
     std::cout << "]" << std::endl;
 }