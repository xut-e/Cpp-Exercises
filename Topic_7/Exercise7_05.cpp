/* 5. Crea un programa que pida indefinidamente números al usuario. Si el
 usuario intenta introducir un número menor del anterior introducido el
 programa debe de informar de ello, no almacenarlo y pedir un nuevo
 número. Al final debe mostrar el resultado. */

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
 
         if (!numeros.empty())
         {
             if (numeroIntroducido < numeros.back())
             {
                 std::cout << "El numero introducido no puede ser menor que el ultimo numero guardado!" << std::endl;
                 continue;
             }
             else
             {
                 numeros.push(numeroIntroducido);
             }
         }
         else
         {
             numeros.push(numeroIntroducido);
         }
 
         std::cout << "Deseas continuar? (s/n): ";
 
         do
         {
             std::cin >> opcion;
         } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
 
     } while (opcion == 's' || opcion == 'S');
     
     int tamanyo = numeros.size();
 
     std::cout << "Los numeros guardados son:" << std::endl << "[";
 
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
 
     return 0;
 }