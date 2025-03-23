/* 3- Crear juego de adivinar el número:----
 El programa selecciona aleatoriamente un número secreto en un rango
 específico.
 El jugador intenta adivinar el número secreto.
 Después de cada intento, el programa proporciona pistas al jugador,
 indicando si el número secreto es mayor o menor que la suposición del
 jugador.
 El jugador continúa hasta que adivina correctamente el número secreto. Al
 acertarlo se le indica la cantidad de intentos realizados. */

 #define RANGO_MIN_DEFAULT 1
 #define RANGO_MAX_DEFAULT 100
 
 #include <iostream>
 #include <time.h>
 #include <vector>
 
 std::vector<int> ingresarRango(std::vector<int>& rango) {
     int minimo, maximo;
 
     std::cout << "Introduzca el numero minimo del nuevo rango: ";
     std::cin >> minimo;
 
     rango[0] = minimo;
 
     std::cout << "Introduzca el numero maximo del nuevo rango: ";
     std::cin >> maximo;
 
     rango[1] = maximo;
 
     return rango;
 }
 
 int elegirNumeroAleatorio(std::vector<int>& rango) {
 
     return rango[0] + rand() % (rango[1] - rango[0] + 1);
 }
 
 int mayorMenorIgual(int numeroAleatorio, int numeroUsuario) {
     if (numeroUsuario < numeroAleatorio)
     {
         return 0;
     }
     else if (numeroUsuario > numeroAleatorio)
     {
         return 2;
     }
     else
     {
         return 1;
     }
 }
 
 void jugar(std::vector<int>& rango) {
     int numeroAleatorio = elegirNumeroAleatorio(rango), numeroUsuario, respuesta;
 
     do
     {
         std::cout << "Introduce un numero para adivinar: ";
         std::cin >> numeroUsuario;
 
         respuesta = mayorMenorIgual(numeroAleatorio, numeroUsuario);
 
         if (respuesta == 0)
         {
             std::cout << "El numero que has introducido es menor!" << std::endl;
         }
         else if (respuesta == 1)
         {
             std::cout << "Has acertado el numero, enhorabuena!" << std::endl;
         }
         else if (respuesta == 2)
         {
             std::cout << "El numero que has introducido es mayor!" << std::endl;
         }
     } while (respuesta != 1);
     
 
 
 }
 
 int main() {
     int opcion;
     std::vector<int> rango = {RANGO_MIN_DEFAULT, RANGO_MAX_DEFAULT};
     srand(time(0));
 
     std::cout << "Introduce un nuevo rango o juega con el rango por defecto (1-100)." << std::endl << "\t" << "1) Nuevo rango." << std::endl << "\t" << "2) Rango por defecto." << std::endl;
     std::cout << "Elige una opcion: ";
     do
     {
         std::cin >> opcion;
     } while (opcion != 1 && opcion != 2);
 
     if (opcion == 1)
     {
         ingresarRango(rango);
     }
 
     jugar(rango);
 
     return 0;
 }