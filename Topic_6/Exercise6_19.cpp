/* 19.Crea un programa que pida una frase al usuario. Seguidamente el programa
 realizará una función de reemplazar pidiendo al usuario un fragmento a
 buscar dentro de la frase inicial y un nuevo texto por el que va a ser
 reemplazado. No necesariamente deben de coincidir la longitud de los
 textos.
 */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string frase, textoAReemplazar, textoReemplazado, nuevaFrase;
     bool datosCorrectos;
     int puntoDePartida;
     
     std::cout << "Introduzca una frase: ";
     std::getline(std::cin, frase);
 
     system("cls");
 
     std::cout << "Su frase es:" << std::endl << frase << std::endl; 
 
     do
     {
         std::cout << "Introduzca la parte del texto que desea reemplazar: ";
         std::getline(std::cin, textoAReemplazar);
 
         for (int i = 0; i < frase.length(); i++)
         {
             datosCorrectos = true;
 
             if (textoAReemplazar[0] == frase[i])
             {
                 for (int j = 0; j < textoAReemplazar.length(); j++)
                 {
                     if (textoAReemplazar[j] != frase[i + j])
                     {
                         datosCorrectos = false;
                         break;
                     }
                 }
                 if (datosCorrectos)
                 {
                     puntoDePartida = i;
                     break;
                 }
             }
             else
             {
                 datosCorrectos = false;
             }
         }
 
         if (!datosCorrectos)
         {
             std::cout << "Ninguna parte coincide con el texto escrito." << std::endl;
         }
 
     } while (!datosCorrectos);
 
     std::cout << "Introduzca el texto a escribir en su lugar: ";
     std::getline(std::cin, textoReemplazado);
 
     for (int i = 0; i < puntoDePartida; i++)
     {
         nuevaFrase += frase[i];
     }
 
     nuevaFrase += textoReemplazado;
 
     for (int i = puntoDePartida + textoAReemplazar.length(); i < frase.length(); i++)
     {
         nuevaFrase += frase[i];
     }
 
     std::cout << "Tu nueva frase es: " << nuevaFrase << std::endl;
 
     return 0;
 }