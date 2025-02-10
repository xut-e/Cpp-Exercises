/* 13. Crea un programa que identifique la palabra más repetida en dos frases
 distintas. */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string frase1, frase2, palabraMasRepetida;
     int palabrasFrase1 = 1, palabrasFrase2 = 1, repeticionesMaximas = 0;
 
     std::cout << "Introduce una frase: ";
     std::getline(std::cin, frase1);
     std::cout << "Introduce otra frase: ";
     std::getline(std::cin, frase2);
 
     std::string frasesCombinadas = frase1 + " " + frase2;
 
     for (int i = 0; i < frasesCombinadas.length(); i++)
     {
         std::string palabraActual;
         int j = i;
 
         while (j < frasesCombinadas.length() && frasesCombinadas[j] != ' ')
         {
             palabraActual += frasesCombinadas[j];
             j++;
         }
 
         int contadorRepeticiones = 0;
 
         for (int k = 0; k < frasesCombinadas.length(); k++)
         {
             std::string palabraAComparar;
             int	l = k;
 
             while (l < frasesCombinadas.length() && frasesCombinadas[l] != ' ')
             {
                 palabraAComparar += frasesCombinadas[l];
                 l++;
             }
 
             if (palabraActual == palabraAComparar)
             {
                 contadorRepeticiones++;
             }
 
             k = l;
         }
 
         if (contadorRepeticiones > repeticionesMaximas && palabraActual != " ")
         {
             repeticionesMaximas = contadorRepeticiones;
             palabraMasRepetida = palabraActual;
         }
 
         i = j;
     }
 
     if (repeticionesMaximas > 1)
     {
         std::cout << "La palabra mas repetida es: " << palabraMasRepetida << std::endl;
     }
     else
     {
         std::cout << "No hay palabras repetidas." << std::endl;
     }
 
     return 0;
 }