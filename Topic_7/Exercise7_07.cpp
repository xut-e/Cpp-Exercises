/* 7. Crea un programa que pida indefinidamente números al usuario. Al finalizar
 mostrará el primer número que no se repita en toda la estructura. */

 #include <iostream>
 #include <vector>
 
 int main() {
     std::vector<int> numeros;
     int numeroIntroducido, numeroNoRepetido = -1;
     char opcion;
     bool repetido = false, encontrado = false;
 
     do
     {
         std::cout << "Introduce un numero: ";
         std::cin >> numeroIntroducido;
 
         numeros.push_back(numeroIntroducido);
 
         std::cout << "Deseas continuar? (s/n): ";
 
         do
         {
             std::cin >> opcion;
         } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
 
     } while (opcion == 's' || opcion == 'S');
     
 
     
 
     for (size_t i = 0; i < numeros.size(); i++) {
         bool repetido = false;
 
         for (size_t j = 0; j < numeros.size(); j++) {
             if (i != j && numeros[i] == numeros[j]) {
                 repetido = true;
                 break;
             }
         }
 
         if (!repetido) {
             numeroNoRepetido = numeros[i];
             encontrado = true;
             break;
         }
     }
 
     if (encontrado) {
         std::cout << "El primer numero no repetido es: " << numeroNoRepetido << std::endl;
     }
     else {
         std::cout << "No hay ningun numero unico en la lista." << std::endl;
     }
 
     return 0;
 }