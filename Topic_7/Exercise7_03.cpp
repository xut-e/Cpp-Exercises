/* 3. Crea un programa que pedirá números de 2 en 2 al usuario. Para cada
 grupo de 2 números el programa almacenará en una estructura distinta los
 números. Al finalizar debe de mostrar para cada par de números cuál era el
 mayor de ambos. */

 #include <iostream>
 #include <queue>
 
 int main() {
     std::queue<int> primeros;
     std::queue<int> segundos;
     char opcion;
     int numero1, numero2;
 
     do
     {
         std::cout << "Introduce el primer numero: ";
         std::cin >> numero1;
 
         std::cout << "Introduce el segundo numero: ";
         std::cin >> numero2;
 
         primeros.push(numero1);
         segundos.push(numero2);
 
         std::cout << "Deseas seguir introduciendo numeros? (s/n): ";
 
         do
         {
             std::cin >> opcion;
         } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');
         
     } while (opcion == 's' || opcion == 'S');
 
     std::cout << "COMPARACION DE NUMEROS" << std::endl;
 
     while (!primeros.empty() && !segundos.empty())
     {
         int num1 = primeros.front(), num2 = segundos.front();
 
         std::cout << std::endl << num1 << " vs " << num2 << std::endl;
 
         if (num1 > num2)
         {
             std::cout << num1 << " es mayor que " << num2 << std::endl;
         }
         else if (num1 < num2)
         {
             std::cout << num2 << " es mayor que " << num1 << std::endl;
         }
         else
         {
             std::cout << num1 << " y " << num2 << " son iguales." << std::endl;
         }
 
         primeros.pop();
         segundos.pop();
     }
 
     return 0;
 }