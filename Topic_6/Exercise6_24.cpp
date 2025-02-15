/* 24. Crea un programa que pida una frase al usuario y seguidamente un
 carácter. El programa debe de indicar cuantas veces aparece el carácter en
 la frase introducida. */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string frase;
     char caracterABuscar;
     int contador = 0;
 
     std::cout << "Introduce una frase: ";
     std::getline(std::cin, frase);
 
     std::cout << "Introduce un caracter para saber cuantas veces aparece: ";
     std::cin >> caracterABuscar;
 
     for (int i = 0; i < frase.length(); i++)
     {
         if (frase[i] == caracterABuscar)
         {
             contador++;
         }
     }
 
     std::cout << "Tu caracter se repite un total de " << contador << " veces." << std::endl;
 
     
     return 0;
 }