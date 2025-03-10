/* 2. Crea un programa que pida una cifra al usuario. El programa generará
 aleatoriamente y almacenará tantas cifras como haya indicado el usuario.
 Tras ello mostrará todas las cifras generadas. */

 #include <iostream>
 #include <vector>
 #include <time.h>
 
 int main() {
     std::vector<int> cifras;
     int cantidad;
     srand(time(0));
     
     std::cout << "Introduce una cantidad de cifras: ";
     std::cin >> cantidad;
 
     for (int i = 0; i < cantidad; i++)
     {
         int numeroAleatorio = rand() % 100;
         cifras.push_back(numeroAleatorio);
     }
 
     std::cout << std::endl << "Las cifras generadas son:" << std::endl << "[";
 
     for (size_t i = 0; i < cifras.size(); i++)
     {
         std::cout << cifras[i];
 
         if (i < cifras.size() - 1)
         {
             std::cout << ", ";
         }
     }
 
     std::cout << "]" << std::endl;
 }