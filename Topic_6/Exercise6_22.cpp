/* 22.Crea un programa que tenga almacenado un diccionario de palabras en
 español- inglés. El usuario podrá introducir una palabra en un idioma y
 luego el programa deberá de ser capaz de mostrar su equivalente en otro
 idioma indicando a qué idioma pertenece cada palabra.
 */

 #include <iostream>
 #include <string>
 
 #define LOGITUD_DICCIONARIO 20
 
 int main() {
     std::string diccionarioEspanyol[LOGITUD_DICCIONARIO] = {"casa", "perro", "feliz", "montanya", "sol", "agua", "árbol", "nube", "cielo", "camino", "río", "libro", "noche", "luz", "fuego", "tierra", "viento", "flor", "mar", "piedra"};
     std::string diccionarioIngles[LOGITUD_DICCIONARIO] = { "house", "dog", "happy", "mountain", "sun", "water", "tree", "cloud", "sky", "path", "river", "book", "night", "light", "fire", "earth", "wind", "flower", "sea", "stone" };
     std::string palabraIntroducida;
     bool palabraEncontrada = false;
     
     std::cout << "Introduce una palabra (Enter a word): ";
     std::cin >> palabraIntroducida;
 
     for (int i = 0; i < LOGITUD_DICCIONARIO; i++)
     {
         if (palabraIntroducida == diccionarioEspanyol[i])
         {
             std::cout << "Su palabra estaba en espanyol: " << palabraIntroducida << std::endl;
             std::cout << "Su palabra en ingles es: " << diccionarioIngles[i] << std::endl;
             palabraEncontrada = true;
             break;
         }
         else if (palabraIntroducida == diccionarioIngles[i])
         {
             std::cout << "Your word was in english: " << palabraIntroducida << std::endl;
             std::cout << "Your word in spanish is: " << diccionarioEspanyol[i] << std::endl;
             palabraEncontrada = true;
             break;
         }
 
         if (!palabraEncontrada && i == LOGITUD_DICCIONARIO - 1)
         {
             std::cout << "Su palabra no se encuentra actualmente en nuestro diccionario." << std::endl;
             std::cout << "Your word is not registered in our diccionaries yet." << std::endl;
         }
     }
 
     return 0;
 }