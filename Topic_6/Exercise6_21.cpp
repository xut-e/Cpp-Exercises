/* 21. Crea un programa que pida una contraseña al usuario. La contraseña debe
 de tener una longitud mínima, contener al menos una mayúscula, una
 minúscula, un número y un carácter especial. Debe de informar al usuario
 de si la contraseña no es válida y por qué motivos. Finalmente cuando sea
 valida debe de pedir que la vuelva a escribir, si no la escribe correctamente
 deberá de volver a introducir una contraseña válida y luego validarla.
 */

 #include <iostream>
 #include <string>
 
 int main() {
     std::string contrasenya, contrasenyaRepetida;
     bool contrasenyaValida = false, mayusculas = false, minusculas = false, numeros = false, caracteres = false;
 
     std::cout << "Para que su contrasenya sea valida debee contener al menos:" << std::endl;
     std::cout << "\t" << "- Longitud de 8." << std::endl;
     std::cout << "\t" << "- Una mayuscula." << std::endl;
     std::cout << "\t" << "- Una minuscula." << std::endl;
     std::cout << "\t" << "- Un numero." << std::endl;
     std::cout << "\t" << "- Un caracter especial." << std::endl;
 
     do
     {
         std::cout << "Introduzca una contrasenya : ";
         std::cin >> contrasenya;
 
         if (contrasenya.length() >= 8)
         {
             for (int i = 0; i < contrasenya.length(); i++)
             {
                 if (contrasenya[i] >= 'A' && contrasenya[i] <= 'Z')
                 {
                     mayusculas = true;
                 }
                 
                 if (contrasenya[i] >= 'a' && contrasenya[i] <= 'z')
                 {
                     minusculas = true;
                 }
 
                 if (contrasenya[i] >= '0' && contrasenya[i] <= '9')
                 {
                     numeros = true;
                 }
 
                 if (contrasenya[i] >= char(33) && contrasenya[i] <= char(47) || contrasenya[i] >= char(58) && contrasenya[i] <= char(64) || contrasenya[i] >= char(91) && contrasenya[i] <= char(60) || contrasenya[i] >= char(123) && contrasenya[i] <= char(126))
                 {
                     caracteres = true;
                 }
             }
 
             contrasenyaValida = mayusculas && minusculas && numeros && caracteres;
 
             if (!contrasenyaValida)
             {
                 std::cout << "La contrasenya no es valida. Motivos:" << std::endl;
 
                 if (!mayusculas)
                 {
                     std::cout << "\t" << "No hay suficientes mayusculas." << std::endl;
                 }
                 if (!minusculas)
                 {
                     std::cout << "\t" << "No hay suficientes minusculas." << std::endl;
                 }
                 if (!numeros)
                 {
                     std::cout << "\t" << "No hay suficientes numeros." << std::endl;
                 }
                 if (!caracteres)
                 {
                     std::cout << "\t" << "No hay suficientes caracteres especiales." << std::endl;
                 }
             }
             else
             {
                 std::cout << "Confirma tu contrasenya: ";
                 std::cin >> contrasenyaRepetida;
 
                 if (contrasenya != contrasenyaRepetida)
                 {
                     std::cout << "Las contrasenyas no coinciden." << std::endl;
                 }
             }
 
             
             
         }
         else
         {
             std::cout << "La longitud no es suficiente." << std::endl;
             contrasenyaValida = false;
         }
 
     } while (!contrasenyaValida || contrasenya != contrasenyaRepetida);
 
     std::cout << "Contrasenya establecida con exito!" << std::endl;
 
     return 0;
 }