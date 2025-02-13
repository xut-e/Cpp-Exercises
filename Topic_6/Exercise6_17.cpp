/*  17.Crear un programa que reciba una frase. El programa debe mostrar en cada
 línea de texto una palabra de las que forman la frase. */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string frase;
 
     std::cout << "Introduce una frase: ";
     std::getline(std::cin, frase);
 
     for (int i = 0; i < frase.length(); i++)
     {
         if (frase[i] == ' ')
         {
             std::cout << "\n";
         }
         else
         {
             std::cout << frase[i];
         }
     }
     std::cout << std::endl;
 }