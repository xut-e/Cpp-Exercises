/* 14.Crear un programa que reciba dos palabras con la misma cantidad de letras
 y las combine. Por ejemplo: palabra1 = hola, palabra2 = sopa. Resultado
 =hsoolpaa. */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string palabra1, palabra2, palabrasCombinadas;
     bool palabraValida, mismasLetras;
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
         mismasLetras = true;
         std::cout << "Introduce otra palabra: ";
         std::getline(std::cin, palabra2);
         if (palabra2.length() == palabra1.length())
         {
             for (int i = 0; i < palabra1.length(); i++)
             {
                 if (palabra2[i] == ' ')
                 {
                     palabraValida = false;
                     break;
                 }
             }
         }
         else
         {
             std::cout << "Las palabras no tienen las mismas letras." << std::endl;
             mismasLetras = false;
         }
         
         if (!palabraValida)
         {
             std::cout << "Lo introducido no corresponde con una palabra." << std::endl;
         }
     } while (!(palabraValida && mismasLetras));
 
     for (int i = 0; i < palabra1.length(); i++)
     {
         std::cout << palabra1[i] << palabra2[i];
     }
 
     std::cout << std::endl;
 
     return 0;
 }