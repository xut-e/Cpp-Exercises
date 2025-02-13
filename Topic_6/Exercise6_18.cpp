/* 18. Crea un programa que sea capaz de verificar si una palabra introducida es
 un palíndromo. */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string palabra;
     std::cout << "Introduce una palabra: ";
     std::cin >> palabra;
 
     bool palindromo = true;
 
     for (size_t i = 0; i < palabra.length() / 2; i++) {
         if (palabra[i] != palabra[palabra.length() - 1 - i]) {
             palindromo = false;
             break;
         }
     }
 
     if (palindromo) {
         std::cout << "La palabra introducida (" << palabra << ") es un palindromo." << std::endl;
     }
     else {
         std::cout << "La palabra introducida (" << palabra << ") no es un palindromo." << std::endl;
     }
 
     return 0;
 }