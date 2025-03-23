/* 4- Crear juego ahorcado:----
El programa selecciona aleatoriamente una palabra de una lista predefinida.
 Muestra al jugador la longitud de la palabra.
 El jugador intenta adivinar una letra por turno.
 El jugador tiene un límite de intentos por palabra.
 Cuando le quedan 2 intentos se le revela una letra no mostrada. */

 #include <iostream>
 #include <vector>
 #include <string>
 #include <time.h>
 
 std::vector<std::string> inicializarDiccionario() {
     return { "gato", "perro", "casa", "árbol", "sol", "luna", "montaña", "río", "coche", "avión", "computadora", "libro", "silla", "mesa", "ventana", "puerta", "jardín", "flor", "pelota", "camisa", "zapato", "reloj", "botella", "lámpara", "teléfono", "guitarra", "piano", "televisión", "espejo", "cuchara", "tenedor", "cuchillo", "plato", "vaso", "sombrero", "bufanda", "abrigo", "pantalón", "falda", "vestido", "calcetín", "bolsillo", "maleta", "billete", "moneda", "llave", "martillo", "tornillo", "clavo", "destornillador" };
 }
 
 std::string seleccionarPalabra(std::vector<std::string> listaPalabras) {
     int numeroAleatorio = rand() % listaPalabras.size();
     std::string palabraSeleccionada = listaPalabras[numeroAleatorio];
     return palabraSeleccionada;
 }
 
 std::vector<char> inicializarFormaPalabra(std::string palabraAAdivinar) {
     std::vector<char> formaPalabraAAdivinar;
 
     for (size_t i = 0; i < palabraAAdivinar.size(); i++) {
         formaPalabraAAdivinar.push_back('_');
     }
 
     return formaPalabraAAdivinar;
 }
 
 bool palabraAdivinada(std::string palabraAAdivinar, std::vector<char>& palabraMostrarUsuario) {
     std::string palabramostrarusuario;
 
     for (size_t i = 0; i < palabraMostrarUsuario.size(); i++) {
         palabramostrarusuario += palabraMostrarUsuario[i];
     }
 
     return palabraAAdivinar == palabramostrarusuario;
 }
 
 bool letraIntentada(std::vector<char> listaLetrasIntentadas, char letraIntroducida) {
     for (size_t i = 0; i < listaLetrasIntentadas.size(); i++) {
         if (letraIntroducida == listaLetrasIntentadas[i]) {
             return false;
         }
     }
     return true;
 }
 
 std::vector<char> comprobarLetra(char letraIntroducida, std::vector<char>& palabraMostrarUsuario, std::string palabraAAdivinar, std::vector<char>& letrasIntentadas) {
     for (size_t i = 0; i < palabraAAdivinar.size(); i++) {
         if (letraIntroducida == palabraAAdivinar[i]) {
             palabraMostrarUsuario[i] = letraIntroducida;
         }
     }
     letrasIntentadas.push_back(letraIntroducida);
     return palabraMostrarUsuario;
 }
 
 void jugar(std::string palabraAAdivinar) {
     int intentos = 0, turno = 1, pistas = 1;
     std::vector<char> palabraMostrarAlUsuario = inicializarFormaPalabra(palabraAAdivinar), letrasIntentadas = {};
     char letraIntroducida;
 
     while (intentos < palabraAAdivinar.size() && !palabraAdivinada(palabraAAdivinar, palabraMostrarAlUsuario)) {
         std::cout << "Turno: " << turno << std::endl;
         std::cout << "Palabra: ";
 
         for (size_t i = 0; i < palabraMostrarAlUsuario.size(); i++) {
             std::cout << palabraMostrarAlUsuario[i] << " ";
         }
         std::cout << std::endl;
 
         std::cout << "Letras intentadas: ";
 
         for (size_t i = 0; i < letrasIntentadas.size(); i++) {
             std::cout << letrasIntentadas[i];
 
             if (i < letrasIntentadas.size() - 1) {
                 std::cout << ", ";
             }
         }
         std::cout << std::endl;
 
         std::cout << "Intentos restantes: " << palabraAAdivinar.size() - intentos << std::endl;
 
         std::cout << "Introduce una letra: ";
 
         do {
             std::cin >> letraIntroducida;
         } while (!letraIntentada(letrasIntentadas, letraIntroducida));
 
         bool letraEnPalabra = false;
         for (size_t i = 0; i < palabraAAdivinar.size(); i++) {
             if (letraIntroducida == palabraAAdivinar[i]) {
                 letraEnPalabra = true;
                 break;
             }
         }
 
         if (!letraEnPalabra) {
             intentos++;
         }
 
         palabraMostrarAlUsuario = comprobarLetra(letraIntroducida, palabraMostrarAlUsuario, palabraAAdivinar, letrasIntentadas);
 
         if (intentos == palabraAAdivinar.size() - 2 && pistas > 0) {
             for (size_t i = 0; i < palabraAAdivinar.size(); i++) {
                 if (palabraMostrarAlUsuario[i] == '_') {
                     palabraMostrarAlUsuario[i] = palabraAAdivinar[i];
                     break;
                 }
             }
             pistas--;
         }
 
         turno++;
 
         system("cls");
     }
 
     if (palabraAdivinada(palabraAAdivinar, palabraMostrarAlUsuario)) {
         std::cout << "Enhorabuena, has adivinado la palabra! La palabra era: " << palabraAAdivinar << std::endl;
     }
     else {
         std::cout << "Vaya, no has adivinado la palabra! La palabra era: " << palabraAAdivinar << std::endl;
     }
 }
 
 int main() {
     srand(time(0));
 
     std::vector<std::string> palabras = inicializarDiccionario();
 
     std::string palabraSeleccionada = seleccionarPalabra(palabras);
 
     jugar(palabraSeleccionada);
 
     return 0;
 }