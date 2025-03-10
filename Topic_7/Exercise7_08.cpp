/* 8. Crea un programa que pedirá al usuario números de 3 en 3. Cada vez que
 pida los números almacenará cada número en una estructura distinta. Al
 finalizar debe de mostrar la suma de las 3 estructuras por separado y el total
 de sumar las 3. */

 #include <iostream>
 #include <queue>
 
 int main() {
     std::vector<int> primeros, segundos, terceros, sumaTotal;
     char opcion;
     int numero1, numero2, numero3, resultado1 = 0, resultado2 = 0, resultado3 = 0;
 
     do
     {
         std::cout << "Introduce el primer numero: ";
         std::cin >> numero1;
 
         std::cout << "Introduce el segundo numero: ";
         std::cin >> numero2;
 
         std::cout << "Introduce el tercer numero: ";
         std::cin >> numero3;
 
         primeros.push_back(numero1);
         segundos.push_back(numero2);
         terceros.push_back(numero3);
 
         std::cout << "Deseas seguir introduciendo numeros? (s/n): ";
 
         do
         {
             std::cin >> opcion;
         } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
 
     } while (opcion == 's' || opcion == 'S');
 
     for (size_t i = 0; i < primeros.size(); i++)
     {
         resultado1 += primeros[i];
         resultado2 += segundos[i];
         resultado3 += terceros[i];
         sumaTotal.push_back(primeros[i] + segundos[i] + terceros[i]);
     }
 
     std::cout << "La suma de los primeros numeros es: " << resultado1 << std::endl;
     std::cout << "La suma de los segundos numeros es: " << resultado2 << std::endl;
     std::cout << "La suma de los terceros numeros es: " << resultado3 << std::endl;
     std::cout << "La suma de todas las estructuras resulta en: " << std::endl << "[";
 
     for (size_t i = 0; i < sumaTotal.size(); i++)
     {
         std::cout << sumaTotal[i];
 
         if (i < sumaTotal.size() - 1)
         {
             std::cout << ", ";
         }
     }
 
     std::cout << "]" << std::endl;
 
     return 0;
 }