/* 23. Crea un programa que reciba una frase con varias palabras, el programa
 debe de mostrar la frase invertida. */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string frase, fraseInvertida1, fraseInvertida2;
 
     std::cout << "Introduce una frase: ";
 
     std::getline(std::cin, frase);
 
     for (int i = frase.length() - 1; i >= 0; i--)
     {
         fraseInvertida1 += frase[i];
     }
 
     for (int i = frase.length() - 1; i >= 0; i--)
     {
         if (frase[i] == ' ' || i == 0)
         {
             for (int j = i; j < frase.length(); j++)
             {
                 if (frase[j] == ' ' && j > i)
                 {
                     break;
                 }
                 else
                 {
                     if (j == 0)
                     {
                         fraseInvertida2 += ' ';
                     }
 
                     fraseInvertida2 += frase[j];
                 }
 
             }
         }
     }
 
     std::cout << "Frase invertida de la manera 1: " << fraseInvertida1 << std::endl;
 
     std::cout << "Frase invertida de la manera 2:" << fraseInvertida2 << std::endl;
 
     return 0;
 }