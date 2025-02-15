/* 25. Crea un programa que identifique si dos palabras introducidas son
 anagramas entre ellas. */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string palabra1, palabra2, caracteresUsados;
     int suma = 0;
     
 
     std::cout << "Introduce una palabra: ";
     std::cin >> palabra1;
 
     std::cout << "Introduce otra palabra: ";
     std::cin >> palabra2;
 
     if (palabra1.length() == palabra2.length())
     {
         if (palabra1 == palabra2)
         {
             std::cout << "Es la misma palabra." << std::endl;
         }
         else
         {
             for (int i = 0; i < palabra1.length(); i++)
             {
                 caracteresUsados += palabra1[i];
             }
 
             for (int i = 0; i < palabra2.length(); i++)
             {
                 for (int j = 0; j < caracteresUsados.length(); j++)
                 {
                     if (palabra2[i] == caracteresUsados[j])
                     {
                         caracteresUsados[j] = '0';
                         break;
                     }
                 }
             }
 
             for (int i = 0; i < caracteresUsados.length(); i++)
             {
                 suma += int(caracteresUsados[i]);
             }
 
             if (suma == 48 * palabra1.length())
             {
                 std::cout << "Es un anagrama." << std::endl;
             }
             else
             {
                 std::cout << "No es un anagrama." << std::endl;
             }
         }
     }
     else
     {
         std::cout << "No es un anagrama." << std::endl;
     }
     
     return 0;
 }