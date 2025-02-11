/* 15.Crea un programa que reciba dos palabras sin importar la cantidad de letras
 y las combine. Deberá alternar una letra de cada palabra y cuando una de
 las dos palabras se quede sin letras deberá escribir todas las letras
 restantes seguidas. */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string palabra1, palabra2, palabrasCombinadas, palabraMasLarga, palabraMasCorta;
     bool palabraValida;
     do
     {
         palabraValida = true;
         std::cout << "Introduce una palabra: ";
         std::getline(std::cin, palabra1);
 
         for (int i = 0; i < palabra1.length(); i++)
         {
             if (palabra1[i] == ' ')
             {
                 palabraValida = false;
                 break;
             }
         }
 
         if (!palabraValida)
         {
             std::cout << "Lo introducido no corresponde con una palabra." << std::endl;
         }
 
     } while (!palabraValida);
     
     do
     {
         palabraValida = true;
         std::cout << "Introduce otra palabra: ";
         std::getline(std::cin, palabra2);
         
         for (int i = 0; i < palabra2.length(); i++)
         {
             if (palabra2[i] == ' ')
             {
                 palabraValida = false;
                 break;
             }
         }
 
         if (!palabraValida)
         {
             std::cout << "Lo introducido no corresponde con una palabra." << std::endl;
         }
 
     } while (!palabraValida);
 
     if (palabra1.length() > palabra2.length())
     {
         palabraMasLarga = palabra1;
         palabraMasCorta = palabra2;
     }
     else
     {
         palabraMasLarga = palabra2;
         palabraMasCorta = palabra1;
     }
 
     for (int i = 0; i < palabraMasCorta.length(); i++)
     {
         std::cout << palabraMasLarga[i] << palabraMasCorta[i];
     }
 
     for (int i = palabraMasCorta.length(); i < palabraMasLarga.length(); i++)
     {
         std::cout << palabraMasLarga[i];
     }
 
     std::cout << std::endl;
 
     return 0;
 }